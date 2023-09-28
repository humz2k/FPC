from rply import LexerGenerator
import re

def get_lexer(filename = "tokens.txt"):
    
    lexer = LexerGenerator()
    with open(filename,"r") as f:
        raw = [i.split() for i in f.read().splitlines() if (not i.startswith("//")) and (not len(i) == 0)]

    for i in raw:
        if i[0] == "IGNORE":
            lexer.ignore(i[1])
        else:
            lexer.add(i[0],i[1])
    
    return lexer.build()

lexer = get_lexer()

s = None
with open("test.fpc","r") as f:
    s = f.read()

tokens = lexer.lex(s)

for i in tokens:
    print(i)