from rply import ParserGenerator
from generate_grammar_strings import generate
import aster

def get_func(func,pg,j):
    @pg.production(j)
    def tmp(state,p):
        return func(state,p)
    return tmp

def get_parser(filename="tokens.txt"):
    with open(filename,"r") as f:
        tokens = [i.split()[0] for i in f.read().splitlines() if (not i.startswith("//")) and (not len(i) == 0)]
    if "IGNORE" in tokens:
        tokens.remove("IGNORE")
    tokens.append("TYPEDEF_NAME")
    tokens.append("ENUMERATION_CONSTANT")
    pg = ParserGenerator(tokens, precedence=[
        
    ])

    grammar = generate("grammar.txt")
    keys = list(grammar.keys())
    keys.remove("translation_unit")
    keys = ["translation_unit"] + keys
    for i in keys:
        func = getattr(aster,i)
        for j in grammar[i]:
            get_func(func,pg,j)
            #@pg.production(j)
            #def tmp(state,p):
            #    return func(state,p)

    @pg.error
    def error_handler(state,token):
        print("ERROR AT",token,token.source_pos)
        exit()

    out = pg.build()
    print(out.lr_table.sr_conflicts)
    return out