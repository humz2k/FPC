from . import lex
from . import parse
import os
import re

def transpile(fname,target):

    token_file = os.path.dirname(__file__) + "/tokens.txt"

    TARGET = target

    with open(fname,"r") as f:
        raw = f.read()

    raw = lex.remove_comments(raw)

    kernel_names = lex.find_kernel_names(raw)
    function_names = lex.find_function_names(raw)

    lexer = lex.get_lexer(token_file,kernel_names=kernel_names,function_names=function_names)

    tokens = lexer.lex(raw)

    parser = parse.get_parser(token_file)

    state = parse.ParserState(target = TARGET)

    parser.parse(tokens,state)

    return state

TMP_FILE_COUNT = -1

def get_tmp_file(extension):
    global TMP_FILE_COUNT
    TMP_FILE_COUNT += 1
    return "__fpctemp__" + str(TMP_FILE_COUNT) + "." + extension

def compile_metal_lib(fnames,header_out,keep_temps = True,metal_lib_file = None):
    transpiled = []
    bindings = []
    kernel_names = []
    for fname in fnames:
        state = transpile(fname,"Metal")
        transpiled.append(str(state))
        bindings.append(state.generate_metal_bindings())
        kernel_names += state.get_metal_names()
    tmp_air_files = []
    for out in transpiled:
        tmp_metal_file = get_tmp_file("metal")
        tmp_air_file = get_tmp_file("air")
        with open(tmp_metal_file,"w") as f:
            f.write(out)
        os.system("xcrun -sdk macosx metal -Wno-unused-variable -c " + tmp_metal_file + " -o " + tmp_air_file)

        if not keep_temps:
            os.remove(tmp_metal_file)

        tmp_air_files.append(tmp_air_file)
    if type(metal_lib_file) == type(None):
        tmp_lib_file = get_tmp_file("metallib")
    else:
        tmp_lib_file = metal_lib_file
    os.system("xcrun -sdk macosx metallib " + " ".join(tmp_air_files) + " -o " + tmp_lib_file)
    if not keep_temps:
        for tmp in tmp_air_files:
            os.remove(tmp)
    metal_lib = os.path.abspath(tmp_lib_file)
    header_file = os.path.abspath(os.path.join(os.path.dirname( __file__ ), '..', '..', 'include','fpc.hpp'))
    init = '''
#define FPC_TARGET_METAL
#include "''' + header_file + '''"
#include <stdlib.h>
#include <stdio.h>

void FPC_init(){
FPC::lib.load_library("''' + metal_lib + '''");\n'''
    for name in kernel_names:
        init += 'FPC::lib.load_kernel("' + name + '");\n'
    init += "}"
    out = init + "\n" + "\n".join(bindings)
    with open(header_out,"w") as f:
        f.write(out)
    
def compile_lib(fnames,target,header_out,keep_temps=True,**kwargs):
    if target == "Metal":
        return compile_metal_lib(fnames,header_out,keep_temps,**kwargs)
    

def extract_kernels(fname):
    with open(fname,"r") as f:
        raw = f.read()
    kernel_headers = re.findall(r"\bdevice\b.*\{",raw)
    kernels = []
    for kernel in kernel_headers:
        brace_amount = 1
        tmp = raw.split(kernel)[1]
        out = ""
        for i in tmp:
            if i == "{":
                brace_amount += 1
            if i == "}":
                brace_amount -= 1
            out += i
            if brace_amount == 0:
                break
        kernels.append(kernel + out)
    for kernel in kernels:
        raw = raw.replace(kernel,"\n"*kernel.count("\n"))
    kernels_file = "\n".join(kernels)
    return raw, kernels_file
            
def preprocess(fname):
    tmp_c_file_2 = get_tmp_file("cpp")
    with open(fname,"r") as f:
        raw = f.read()
    #raw =  re.sub(r".*fpc_headers\.hpp.*\n","\n",raw)
    #raw =  re.sub(r".*\.hpp.*\n","\n",raw)
    headers = [i for i in re.findall(r"\s*\#include.*\n",raw) if not "fpc_headers.hpp" in i]
    raw =  re.sub(r"\s*\#include.*\n","\n",raw)
    tmp = []
    keep = []
    for i in headers:
        if ".fpc" in i:
            keep.append(i)
        else:
            tmp.append(i)
    headers = tmp
    raw = "#define FPC_PREPROCESS\n" "\n".join(keep) + "\n" + raw
    with open(tmp_c_file_2,"w") as f:
        f.write(raw)
    tmp_c_file = get_tmp_file("cpp")
    os.system("cpp " + tmp_c_file_2 + " > " + tmp_c_file)
    os.remove(tmp_c_file_2)
    tmp_final_c_file = get_tmp_file("cpp")
    tmp_fpc_file = get_tmp_file("fpc")
    raw,kernels = extract_kernels(tmp_c_file)
    os.remove(tmp_c_file)
    header = get_tmp_file("hpp")

    put_back = "\n".join(headers) + "\n"
    raw = put_back + '#include "' + header + '"\n' + raw
    with open(tmp_final_c_file,"w") as f:
        f.write(raw)
    with open(tmp_fpc_file,"w") as f:
        f.write(kernels)
    return tmp_final_c_file,tmp_fpc_file,header
    #print(raw)
    
