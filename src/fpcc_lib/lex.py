from rply import LexerGenerator
import re

def get_lexer(filename = "tokens.txt", kernel_names = [], function_names = []):
    
    lexer = LexerGenerator()
    with open(filename,"r") as f:
        raw = [i.split() for i in f.read().splitlines() if (not i.startswith("//")) and (not len(i) == 0)]

    for i in kernel_names:
        lexer.add("KERNEL_NAME",i)
    for i in function_names:
        lexer.add("FUNCTION_NAME",i)

    for i in raw:
        if i[0] == "IGNORE":
            lexer.ignore(i[1])
        else:
            lexer.add(i[0],i[1])
    
    return lexer.build()

def find_kernel_names(raw):
    return [i.strip() for i in re.findall(r"kernel\s*([a-zA-Z_0-9]*)",raw)]

def find_function_names(raw):
    return [i[-1].strip() for i in re.findall(r"((void)|(int)|(char)|(short)|(long)|(float)|(double))[\*]*\s*([a-zA-Z_0-9]*)\s*\(",raw)]

def remove_comments(raw):
    out = ""
    lines = raw.splitlines()
    for line in lines:
        if line.startswith(r"//"):
            out += "\n"
        else:
            out += line.split(r"//")[0] + "\n"
    return out