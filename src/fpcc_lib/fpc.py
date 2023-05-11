from . import lex
from . import parse
import os

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
    
