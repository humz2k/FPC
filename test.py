from lex import FPCLexer
from parse import get_parser
from aster import State

with open("test.c", "r") as f:
    raw = f.read()

lexer = FPCLexer(raw,"tokens.txt")


state = State(lexer,"test.c")
#for i in lexer:
#    print(i)

parser = get_parser()
out = parser.parse(state.lexer,state)
out.recurse()
out.eval(state)
print(state.module)