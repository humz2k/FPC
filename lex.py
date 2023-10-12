from rply import Token
from rply import LexerGenerator

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

class FPCLexer(object):
    def __init__(self,string,filename="tokens.txt"):
        self.tokens = get_lexer(filename).lex(string)
    
    def __iter__(self):
        return self

    def next(self):
        out = next(self.tokens)
        return out
    
    def __next__(self):
        return self.next()