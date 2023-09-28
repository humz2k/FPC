from lex import *
from parse import *

lexer = get_lexer()

s = None
with open("test.fpc","r") as f:
    s = f.read()

tokens = lexer.lex(s)

parser = get_parser()

