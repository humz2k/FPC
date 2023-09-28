from rply import LexerGenerator
from rply import ParserGenerator
import re

def get_lexer():
    lexer = LexerGenerator()
    lexer.ignore(r"\s+")
    lexer.add('STRING',r"'(\.|[^\'])+'")
    lexer.add(':',r"\:")
    lexer.add('OR',r"\|")
    lexer.add(';',r"\;")
    lexer.add("IDENTIFIER","[a-zA-Z]([a-zA-Z_0-9]+)?")
    return lexer.build()

def get_parser():
    tokens = ["STRING",":","OR",";","IDENTIFIER"]
    pg = ParserGenerator(tokens, precedence=[
        
    ])

    @pg.production('productions : production')
    @pg.production('productions : productions production')
    def productions(p):
        if (len(p) == 1):
            return p[0]
        p[0].update(p[1])
        return p[0]
        #print("PRODUCTIONS",p)

    @pg.production('production : identifier : rule_list')
    def production(p):
        out = []
        for i in p[2]:
            out.append(p[0] + " : " + i)
        return {p[0]:out}
        #print("PRODUCTION",p)

    @pg.production('string : STRING')
    def pass_string(p):
        if (p[0].value == "'|'"):
            return "OR"
        if (p[0].value == "'%'"):
            return "MOD"
        else:
            return p[0].value[1:-1]
        
    @pg.production('identifier : IDENTIFIER')
    def pass_identifier(p):
        return p[0].value

    @pg.production('rule : string')
    @pg.production('rule : identifier')
    @pg.production('rule : rule identifier')
    @pg.production('rule : rule string')
    def rule(p):
        if (len(p) == 1):
            return p[0]
        return p[0] + " " + p[1]
        #print("RULE",p)

    @pg.production('rule_list_open : rule')
    @pg.production('rule_list_open : rule_list_open OR rule')
    def rule_list(p):
        if len(p) == 1:
            return [p[0]]
        return p[0] + [p[2]]
        #print("RULE_LIST_OPEN",p)

    @pg.production('rule_list : rule_list_open ;')
    def rule_list(p):
        return p[0]
        #print("RULE_LIST",p)

    @pg.error
    def error_handler(token):
        print("ERROR AT",token,token.source_pos)
        exit()

    out = pg.build()
    print(out.lr_table.sr_conflicts)
    return out

def generate(filename = "grammar.txt"):
    with open(filename,"r") as f:
        raw = f.read().splitlines()
    raw = [i for i in raw if not i.startswith("#")]
    raw = "\n".join(raw)
    lexer = get_lexer()
    tokens = lexer.lex(raw)
    parser = get_parser()
    out = parser.parse(tokens)
    return out

generate()