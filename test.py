from lex import *
from parse import *

lexer = get_lexer()

s = None
with open("test.c","r") as f:
    s = "\n".join([i for i in f.read().splitlines() if not i.startswith("#")])

class Tokenizer(object):
    def __init__(self,tokens,state):
        self.tokens = tokens
    
    def __iter__(self):
        return self

    def next(self):
        out = next(self.tokens)
        if out.name == "IDENTIFIER":
            if out.value in state.typedefs:
                out.name = "TYPEDEF_NAME"
        return out
    
    def __next__(self):
        return self.next()
    
class ParserState(object):
    def __init__(self):
        self.typedefs = []

state = ParserState()

tokens = Tokenizer(lexer.lex(s),state)

parser = get_parser()

out = parser.parse(tokens,state)

print(out.p)

