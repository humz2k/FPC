from rply import ParserGenerator
from . import aster

class ParserState(object):
    def __init__(self):
        pass
        self.logs = []

    def log(self,string):
        print(string)
        self.logs.append(string)

def get_parser(filename="tokens.txt"):
    with open(filename,"r") as f:
        tokens = [i.split()[0] for i in f.read().splitlines() if (not i.startswith("//")) and (not len(i) == 0)]
    if "IGNORE" in tokens:
        tokens.remove("IGNORE")
    pg = ParserGenerator(tokens, precedence=[
        
    ])

    @pg.production('primary_expression : IDENTIFIER')
    @pg.production('primary_expression : CONSTANT')
    @pg.production('primary_expression : STRING_LITERAL')
    @pg.production('primary_expression : ( expression )')
    def primary_expression(state,p):
        state.log('primary_expression')

    @pg.production('postfix_expression : primary_expression')
    @pg.production('postfix_expression : postfix_expression [ expression ]')
    @pg.production('postfix_expression : postfix_expression ( )')
    @pg.production('postfix_expression : postfix_expression ( argument_expression_list )')
    @pg.production('postfix_expression : postfix_expression . IDENTIFIER')
    @pg.production('postfix_expression : postfix_expression PTR_OP IDENTIFIER')
    @pg.production('postfix_expression : postfix_expression INC_OP')
    @pg.production('postfix_expression : postfix_expression DEC_OP')
    def postfix_expression(state,p):
        state.log('postfix_expression')

    @pg.production('argument_expression_list : assignment_expression')
    @pg.production('argument_expression_list : argument_expression_list , assignment_expression')
    def argument_expression_list(state,p):
        state.log('argument_expression_list')

    @pg.production('unary_expression : postfix_expression')
    @pg.production('unary_expression : INC_OP unary_expression')
    @pg.production('unary_expression : DEC_OP unary_expression')
    @pg.production('unary_expression : unary_operator cast_expression')
    @pg.production('unary_expression : SIZEOF unary_expression')
    @pg.production('unary_expression : SIZEOF ( type_name )')
    def unary_expression(state,p):
        state.log('unary_expression')

    @pg.production('unary_operator : &')
    @pg.production('unary_operator : *')
    @pg.production('unary_operator : +')
    @pg.production('unary_operator : -')
    @pg.production('unary_operator : ~')
    @pg.production('unary_operator : !')
    def unary_operator(state,p):
        state.log('unary_operator')

    @pg.production('cast_expression : unary_expression')
    @pg.production('cast_expression : ( type_name ) cast_expression')
    def cast_expression(state,p):
        state.log('cast_expression')

    @pg.production('multiplicative_expression : cast_expression')
    @pg.production('multiplicative_expression : multiplicative_expression * cast_expression')
    @pg.production('multiplicative_expression : multiplicative_expression / cast_expression')
    @pg.production('multiplicative_expression : multiplicative_expression MOD cast_expression')
    def multiplicative_expression(state,p):
        state.log('multiplicative_expression')

    @pg.production('additive_exprresion : multiplicative_expression')
    @pg.production('additive_exprresion : additive_exprresion + multiplicative_expression')
    @pg.production('additive_exprresion : additive_exprresion - multiplicative_expression')
    def additive_expression(state,p):
        state.log('additive_expression')

    @pg.production('shift_expression : additive_exprresion')
    @pg.production('shift_expression : shift_expression LEFT_OP additive_exprresion')
    @pg.production('shift_expression : shift_expression RIGHT_OP additive_exprresion')
    def shift_expression(state,p):
        state.log('shift_expression')

    @pg.production('relational_expression : shift_expression')
    @pg.production('relational_expression : relational_expression < shift_expression')
    @pg.production('relational_expression : relational_expression > shift_expression')
    @pg.production('relational_expression : relational_expression LE_OP shift_expression')
    @pg.production('relational_expression : relational_expression GE_OP shift_expression')
    def relational_expression(state,p):
        state.log('relational_expression')

    @pg.production('equality_expression : relational_expression')
    @pg.production('equality_expression : equality_expression EQ_OP relational_expression')
    @pg.production('equality_expression : equality_expression NE_OP relational_expression')
    def equality_expression(state,p):
        state.log('equality_expression')

    @pg.production('and_expression : equality_expression')
    @pg.production('and_expression : and_expression & equality_expression')
    def and_expression(state,p):
        state.log('and_expression')

    @pg.production('exclusive_or_expression : and_expression')
    @pg.production('exclusive_or_expression : exclusive_or_expression ^ and_expression')
    def exclusive_or_expression(state,p):
        state.log('exclusive_or_expression')

    @pg.production('inclusive_or_expression : exclusive_or_expression')
    @pg.production('inclusive_or_expression : inclusive_or_expression | exclusive_or_expression')
    def inclusive_or_expression(state,p):
        state.log('inclusive_or_expression')

    @pg.production('logical_and_expression : inclusive_or_expression')
    @pg.production('logical_and_expression : logical_and_expression AND_OP inclusive_or_expression')
    def logical_and_expression(state,p):
        state.log('logical_and_expression')

    @pg.production('logical_or_expression : logical_and_expression')
    @pg.production('logical_or_expression : logical_or_expression OP_OP logical_and_expression')
    def logical_or_expression(state,p):
        state.log('logical_or_expression')

    @pg.production('conditional_expression : logical_or_expression')
    @pg.production('conditional_expression : logical_or_expression ? expression : conditional_expression')
    def conditional_expression(state,p):
        state.log('conditional_expression')

    @pg.production('assignment_expression : conditional_expression')
    @pg.production('assignment_expression : unary_expression assignment_operator assignment_expression')
    def assignment_expression(state,p):
        state.log('assignment_expression')

    @pg.production('assignment_operator : =')
    @pg.production('assignment_operator : MUL_ASSIGN')
    @pg.production('assignment_operator : DIV_ASSIGN')
    @pg.production('assignment_operator : MOD_ASSIGN')
    @pg.production('assignment_operator : ADD_ASSIGN')
    @pg.production('assignment_operator : SUB_ASSIGN')
    @pg.production('assignment_operator : LEFT_ASSIGN')
    @pg.production('assignment_operator : RIGHT_ASSIGN')
    @pg.production('assignment_operator : AND_ASSIGN')
    @pg.production('assignment_operator : XOR_ASSIGN')
    @pg.production('assignment_operator : OR_ASSIGN')
    def assignment_operator(state,p):
        state.log('assignment_operator')
    
    @pg.production('expression : assignment_expression')
    @pg.production('expression : expression , assignment_expression')
    def expression(state,p):
        state.log('expression')
    
    @pg.production('constant_expression : conditional_expression')
    def constant_expression(state,p):
        state.log('constant_expression')
    
    @pg.production('declaration : declaration_specifiers ;')
    @pg.production('declaration : declaration_specifiers init_declarator_list ;')
    def declaration(state,p):
        state.log('declaration')
    
    @pg.production('declaration_specifiers : storage_class_specifier')
    @pg.production('declaration_specifiers : storage_class_specifier declaration_specifiers')
    @pg.production('declaration_specifiers : type_specifier')
    @pg.production('declaration_specifiers : type_specifier declaration_specifiers')
    @pg.production('declaration_specifiers : type_qualifier')
    @pg.production('declaration_specifiers : type_qualifier declaration_specifiers')
    def declaration_specifiers(state,p):
        state.log('declaration_specifiers')
    
    @pg.production('init_declarator_list : init_declarator')
    @pg.production('init_declarator_list : init_declarator_list , init_declarator')
    def init_declarator_list(state,p):
        state.log('init_declarator_list')

    @pg.production('init_declarator : declarator')
    @pg.production('init_declarator : declarator = initializer')
    def init_declarator(state,p):
        state.log('init_declarator')

    @pg.production('storage_class_specifier : TYPEDEF')
    @pg.production('storage_class_specifier : EXTERN')
    @pg.production('storage_class_specifier : STATIC')
    @pg.production('storage_class_specifier : AUTO')
    @pg.production('storage_class_specifier : REGISTER')
    def storage_class_specifier(state,p):
        state.log('storage_class_specifier')
    
    @pg.production('type_specifier : VOID')
    @pg.production('type_specifier : CHAR')
    @pg.production('type_specifier : SHORT')
    @pg.production('type_specifier : INT')
    @pg.production('type_specifier : LONG')
    @pg.production('type_specifier : FLOAT')
    @pg.production('type_specifier : DOUBLE')
    @pg.production('type_specifier : SIGNED')
    @pg.production('type_specifier : UNSIGNED')
    @pg.production('type_specifier : struct_or_union_specifier')
    @pg.production('type_specifier : enum_specifier')
    @pg.production('type_specifier : TYPE_NAME')
    def type_specifier(state,p):
        state.log('type_specifier')

    @pg.production('struct_or_union_specifier : struct_or_union IDENTIFIER { struct_declaration_list }')
    @pg.production('struct_or_union_specifier : struct_or_union { struct_declaration_list }')
    @pg.production('struct_or_union_specifier : struct_or_union IDENTIFIER')
    def struct_or_union_specifier(state,p):
        state.log('struct_or_union_specifier')

    @pg.production('struct_or_union : STRUCT')
    @pg.production('struct_or_union : UNION')
    def struct_or_union(state,p):
        state.log("struct_or_union")

    @pg.production('struct_declaration_list : struct_declaration')
    @pg.production('struct_declaration_list : struct_declaration_list struct_declaration')
    def struct_declaration_list(state,p):
        state.log('struct_declaration_list')

    @pg.production('struct_declarator : declarator')
    @pg.production('struct_declarator : : constant_expression')
    @pg.production('struct_declarator : declarator : constant_expression')
    def struct_declarator(state,p):
        state.log('struct_declarator')

    @pg.production('enum_specifier : ENUM { enumerator_list }')
    @pg.production('enum_specifier : ENUM IDENTIFIER { enumerator_list }')
    @pg.production('enum_specifier : ENUM IDENTIFIER')
    def enum_specifier(state,p):
        state.log('enum_specifier')

    @pg.production('enumerator_list : enumerator')
    @pg.production('enumerator_list : enumerator_list , enumerator')
    def enumerator_list(state,p):
        state.log('enumerator_list')

    @pg.production('enumerator : IDENTIFIER')
    @pg.production('enumerator : IDENTIFIER = constant_expression')
    def enumerator(state,p):
        state.log('enumerator')

    @pg.production('type_qualifier : CONST')
    @pg.production('type_qualifier : VOLATILE')
    def type_qualifier(state,p):
        state.log('type_qualifier')
    
    @pg.production('declarator : pointer direct_declarator')
    @pg.production('declarator : direct_declarator')
    def declarator(state,p):
        state.log('declarator')
    


    @pg.error
    def error_handler(state,token):
        print("ERROR AT",token,token.source_pos)
        exit()

    out = pg.build()
    #print(out.lr_table.sr_conflicts)
    return out