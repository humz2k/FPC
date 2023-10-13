from lex import FPCLexer
from parse import get_parser

with open("test.c", "r") as f:
    raw = f.read()

lexer = FPCLexer(raw,"tokens.txt")


class State:
    def __init__(self,lexer):
        self.lexer = lexer

state = State(lexer)
#for i in lexer:
#    print(i)

parser = get_parser()
out = parser.parse(state.lexer,state)
out.recurse()
out.eval(state)