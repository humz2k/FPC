from rply import ParserGenerator
from aster import *
from rply import Token

def get_parser(filename="tokens.txt"):
    with open(filename,"r") as f:
        tokens = [i.split()[0] for i in f.read().splitlines() if (not len(i) == 0)]
    if "IGNORE" in tokens:
        tokens.remove("IGNORE")
    tokens.append("TYPEDEF_NAME")
    tokens.append("ENUMERATION-CONSTANT")
    pg = ParserGenerator(tokens, precedence=[
        ('left',[',']),
        ('right',['?','=','+=','-=','*=','/=','%=','<<=','>>=','&=','^=','|=']),
        ('left',['&','^','|','&&','||']),
        ('left',['==','!=']),
        ('left',['<','<=','>','>=']),
        ('left',['<<','>>']),
        ('left',['+','-']),
        ('left',['*','/','%']),
        ('right',['++','--','!','~','SIZEOF']),
        ('left',['.','->']),
    ])

    @pg.production('translation-unit : external-declaration')
    @pg.production('translation-unit : translation-unit external-declaration')
    def translation_unit(state,p):
        if len(p) == 1:
            return TranslationUnit(p)
        return p[0].push_back(p[1])

    @pg.production('external-declaration : function-definition')
    @pg.production('external-declaration : declaration')
    def external_declaration(state,p):
        return p[0]

    @pg.production('function-definition : declaration-specifiers declarator declaration-list compound-statement')
    @pg.production('function-definition : declaration-specifiers declarator compound-statement')
    def function_definition(state,p):
        return FunctionDefinition(p)

    @pg.production('declaration-specifiers : storage-class-specifier declaration-specifiers')
    @pg.production('declaration-specifiers : storage-class-specifier')
    @pg.production('declaration-specifiers : type-specifier declaration-specifiers')
    @pg.production('declaration-specifiers : type-specifier')
    @pg.production('declaration-specifiers : type-qualifier declaration-specifiers')
    @pg.production('declaration-specifiers : type-qualifier')
    @pg.production('declaration-specifiers : function-specifier declaration-specifiers')
    def declaration_specifiers(state,p):
        if len(p) == 1:
            return DeclarationSpecifiers(p)
        return p[1].push_front(p[0])

    @pg.production('storage-class-specifier : TYPEDEF')
    @pg.production('storage-class-specifier : EXTERN')
    @pg.production('storage-class-specifier : STATIC')
    @pg.production('storage-class-specifier : AUTO')
    @pg.production('storage-class-specifier : REGISTER')
    def storage_class_specifier(state,p):
        return p[0]

    @pg.production('type-specifier : VOID')
    @pg.production('type-specifier : CHAR')
    @pg.production('type-specifier : SHORT')
    @pg.production('type-specifier : INT')
    @pg.production('type-specifier : LONG')
    @pg.production('type-specifier : FLOAT')
    @pg.production('type-specifier : DOUBLE')
    @pg.production('type-specifier : SIGNED')
    @pg.production('type-specifier : UNSIGNED')
    @pg.production('type-specifier : BOOL')
    @pg.production('type-specifier : COMPLEX')
    @pg.production('type-specifier : struct-or-union-specifier')
    @pg.production('type-specifier : enum-specifier')
    @pg.production('type-specifier : TYPEDEF_NAME')
    def type_specifier(state,p):
        return TypeSpecifier(p)

    @pg.production('struct-or-union-specifier : struct-or-union { struct-declaration-list }')
    @pg.production('struct-or-union-specifier : struct-or-union identifier { struct-declaration-list }')
    @pg.production('struct-or-union-specifier : struct-or-union identifier')
    def struct_or_union_specifier(state,p):
        if p[0].name == "STRUCT":
            return StructSpecifier(p[1:])
        return UnionSpecifier(p[1:])

    @pg.production('struct-or-union : STRUCT')
    @pg.production('struct-or-union : UNION')
    def struct_or_union(state,p):
        return p[0]

    @pg.production('struct-declaration-list : struct-declaration')
    @pg.production('struct-declaration-list : struct-declaration-list struct-declaration')
    def struct_declaration_list(state,p):
        if len(p) == 1:
            return StructDeclarationList(p)
        return p[0].push_back(p[1])

    @pg.production('struct-declaration : specifier-qualifier-list struct-declarator-list ;')
    def struct_declaration(state,p):
        return StructDeclaration(p)

    @pg.production('specifier-qualifier-list : type-specifier specifier-qualifier-list')
    @pg.production('specifier-qualifier-list : type-specifier')
    @pg.production('specifier-qualifier-list : type-qualifier specifier-qualifier-list')
    @pg.production('specifier-qualifier-list : type-qualifier')
    def specifier_qualifier_list(state,p):
        return SpecifierQualifierList(p)

    @pg.production('type-qualifier : CONST')
    @pg.production('type-qualifier : RESTRICT')
    @pg.production('type-qualifier : VOLATILE')
    def type_qualifier(state,p):
        return p[0]

    @pg.production('struct-declarator-list : struct-declarator')
    @pg.production('struct-declarator-list : struct-declarator-list , struct-declarator')
    def struct_declarator_list(state,p):
        if len(p) == 1:
            return StructDeclaratorList(p)
        return p[0].push_back(p[1])

    @pg.production('struct-declarator : declarator')
    @pg.production('struct-declarator : declarator COLON constant-expression')
    @pg.production('struct-declarator : COLON constant-expression')
    def struct_declarator(state,p):
        return StructDeclarator(p)

    @pg.production('declarator : pointer direct-declarator')
    @pg.production('declarator : direct-declarator')
    def declarator(state,p):
        if len(p) == 1:
            return p[0]
        return p[1].push_front(p[0])

    @pg.production('pointer : * type-qualifier-list')
    @pg.production('pointer : *')
    def pointer_base(state,p):
        return Pointer(p)
    
    @pg.production('pointer : * type-qualifier-list pointer')
    @pg.production('pointer : * pointer')
    def pointer(state,p):
        if len(p) == 2:
            return p[1].push_front(p[0])
        p[2].push_front(p[1])
        return p[2].push_front(p[0])

    @pg.production('type-qualifier-list : type-qualifier')
    @pg.production('type-qualifier-list : type-qualifier-list type-qualifier')
    def type_qualifier_list(state,p):
        if len(p) == 1:
            return TypeQualifierList(p)
        return p[0].push_back(p[1])

    @pg.production('direct-declarator : identifier')
    @pg.production('direct-declarator : ( declarator )')
    def direct_declarator_base(state,p):
        if len(p) == 1:
            return DirectDeclarator([p[0]])
        return DirectDeclarator([p[1]])
    
    @pg.production('direct-declarator : direct-declarator [ type-qualifier-list assignment-expression ]')
    @pg.production('direct-declarator : direct-declarator [ type-qualifier-list ]')
    @pg.production('direct-declarator : direct-declarator [ assignment-expression ]')
    @pg.production('direct-declarator : direct-declarator [ ]')
    @pg.production('direct-declarator : direct-declarator [ STATIC type-qualifier-list assignment-expression ]')
    @pg.production('direct-declarator : direct-declarator [ STATIC assignment-expression ]')
    @pg.production('direct-declarator : direct-declarator [ type-qualifier-list STATIC assignment-expression ]')
    @pg.production('direct-declarator : direct-declarator [ type-qualifier-list * ]')
    @pg.production('direct-declarator : direct-declarator [ * ]')
    @pg.production('direct-declarator : direct-declarator ( parameter-type-list )')
    @pg.production('direct-declarator : direct-declarator ( )')
    @pg.production('direct-declarator : direct-declarator ( identifier-list )')
    def direct_declarator(state,p):
        return p[0].add_back(p[1:])
    
    @pg.production('conditional-expression : logical-OR-expression')
    @pg.production('assignment-expression : conditional-expression')
    @pg.production('logical-OR-expression : logical-AND-expression')
    @pg.production('logical-AND-expression : inclusive-OR-expression')
    @pg.production('inclusive-OR-expression : exclusive-OR-expression')
    @pg.production('exclusive-OR-expression : AND-expression')
    @pg.production('AND-expression : equality-expression')
    @pg.production('equality-expression : relational-expression')
    @pg.production('relational-expression : shift-expression')
    @pg.production('shift-expression : additive-expression')
    @pg.production('additive-expression : multiplicative-expression')
    @pg.production('multiplicative-expression : cast-expression')
    @pg.production('cast-expression : unary-expression')
    @pg.production('unary-expression : postfix-expression')
    @pg.production('postfix-expression : primary-expression')
    def pass_through(state,p):
        return p[0]

    
    @pg.production('assignment-expression : unary-expression = assignment-expression')
    @pg.production('assignment-expression : unary-expression *= assignment-expression')
    @pg.production('assignment-expression : unary-expression /= assignment-expression')
    @pg.production('assignment-expression : unary-expression %= assignment-expression')
    @pg.production('assignment-expression : unary-expression += assignment-expression')
    @pg.production('assignment-expression : unary-expression -= assignment-expression')
    @pg.production('assignment-expression : unary-expression <<= assignment-expression')
    @pg.production('assignment-expression : unary-expression >>= assignment-expression')
    @pg.production('assignment-expression : unary-expression &= assignment-expression')
    @pg.production('assignment-expression : unary-expression ^= assignment-expression')
    @pg.production('assignment-expression : unary-expression |= assignment-expression')
    def assignment_expression(state,p):
        return AssignmentExpression(p)

    @pg.production('conditional-expression : logical-OR-expression ? expression COLON conditional-expression')
    def conditional_expression(state,p):
        return ConditionalExpression(p)

    @pg.production('logical-OR-expression : logical-OR-expression LOR logical-AND-expression')
    @pg.production('logical-AND-expression : logical-AND-expression && inclusive-OR-expression')
    @pg.production('inclusive-OR-expression : inclusive-OR-expression OR exclusive-OR-expression')
    @pg.production('exclusive-OR-expression : exclusive-OR-expression ^ AND-expression')
    @pg.production('AND-expression : AND-expression & equality-expression')
    @pg.production('equality-expression : equality-expression == relational-expression')
    @pg.production('equality-expression : equality-expression != relational-expression')
    @pg.production('relational-expression : relational-expression < shift-expression')
    @pg.production('relational-expression : relational-expression > shift-expression')
    @pg.production('relational-expression : relational-expression <= shift-expression')
    @pg.production('relational-expression : relational-expression >= shift-expression')
    @pg.production('shift-expression : shift-expression << additive-expression')
    @pg.production('shift-expression : shift-expression >> additive-expression')
    @pg.production('additive-expression : additive-expression + multiplicative-expression')
    @pg.production('additive-expression : additive-expression - multiplicative-expression')
    @pg.production('multiplicative-expression : multiplicative-expression * cast-expression')
    @pg.production('multiplicative-expression : multiplicative-expression / cast-expression')
    @pg.production('multiplicative-expression : multiplicative-expression MOD cast-expression')
    def binop(state,p):
        return BinOpExpression(p)

    @pg.production('cast-expression : ( type-name ) cast-expression')
    def cast_expression(state,p):
        p1 = [p[1],p[3]]
        return CastExpression(p1)

    @pg.production('unary-expression : ++ unary-expression')
    @pg.production('unary-expression : -- unary-expression')
    @pg.production('unary-expression : & cast-expression')
    @pg.production('unary-expression : * cast-expression')
    @pg.production('unary-expression : + cast-expression')
    @pg.production('unary-expression : - cast-expression')
    @pg.production('unary-expression : ~ cast-expression')
    @pg.production('unary-expression : ! cast-expression')
    @pg.production('unary-expression : SIZEOF unary-expression')
    @pg.production('unary-expression : SIZEOF ( type-name )')
    def unary_expression(state,p):
        if len(p) == 4:
            return SizeofType([p[2]])
        return UnaryExpression(p)

    @pg.production('postfix-expression : postfix-expression [ expression ]')
    def pointer_index(state,p):
        return PointerIndex(p)

    @pg.production('postfix-expression : postfix-expression ( )')
    @pg.production('postfix-expression : postfix-expression ( argument-expression-list )')
    def function_call(state,p):
        if len(p) == 3:
            return FunctionCall([p[0]])
        return FunctionCall([p[0]] + p[2:-1])

    @pg.production('postfix-expression : postfix-expression ++')
    @pg.production('postfix-expression : postfix-expression --')
    def post_increment(state,p):
        return PostIncrement(p)

    @pg.production('postfix-expression : postfix-expression . identifier')
    def struct_reference(state,p):
        return StructReference([p[0],p[-1]])
    
    @pg.production('postfix-expression : postfix-expression -> identifier')
    def struct_ptr_reference(state,p):
        return StructPointerReference([p[0],p[-1]])

    
    @pg.production('postfix-expression : ( type-name ) { initializer-list }')
    @pg.production('postfix-expression : ( type-name ) { initializer-list , }')
    def postfix_expression(state,p):
        raise Exception("WTF IS THIS")

    @pg.production('primary-expression : identifier')
    @pg.production('primary-expression : constant')
    @pg.production('primary-expression : string-literal')
    @pg.production('primary-expression : ( expression )')
    def primary_expression(state,p):
        if len(p) == 1:
            return p[0]
        return p[1]

    @pg.production('expression : assignment-expression')
    @pg.production('expression : expression , assignment-expression')
    def expression(state,p):
        if len(p) == 1:
            return Expression(p)
        return p[0].push_back(p[2])

    @pg.production('argument-expression-list : assignment-expression')
    @pg.production('argument-expression-list : argument-expression-list , assignment-expression')
    def argument_expression_list(state,p):
        if len(p) == 1:
            return ArgumentExpressionList(p)
        return p[0].push_back(p[2])

    @pg.production('type-name : specifier-qualifier-list abstract-declarator')
    @pg.production('type-name : specifier-qualifier-list')
    def type_name(state,p):
        return TypeName(p)
    
    @pg.production('abstract-declarator : pointer')
    @pg.production('abstract-declarator : pointer direct-abstract-declarator')
    @pg.production('abstract-declarator : direct-abstract-declarator')
    def abstract_declarator(state,p):
        return AbstractDeclarator(p)

    @pg.production('direct-abstract-declarator : ( abstract-declarator )')
    @pg.production('direct-abstract-declarator : [ type-qualifier-list assignment-expression ]')
    @pg.production('direct-abstract-declarator : [ type-qualifier-list ]')
    @pg.production('direct-abstract-declarator : [ assignment-expression ]')
    @pg.production('direct-abstract-declarator : [ ]')
    @pg.production('direct-abstract-declarator : [ STATIC type-qualifier-list assignment-expression ]')
    @pg.production('direct-abstract-declarator : [ STATIC assignment-expression ]')
    @pg.production('direct-abstract-declarator : [ type-qualifier-list STATIC assignment-expression ]')
    @pg.production('direct-abstract-declarator : [ ]')
    @pg.production('direct-abstract-declarator : ( parameter-type-list )')
    @pg.production('direct-abstract-declarator : ( )')
    def direct_abstract_declarator_base(state,p):
        return DirectAbstractDeclarator(p)

    @pg.production('direct-abstract-declarator : direct-abstract-declarator [ type-qualifier-list assignment-expression ]')
    @pg.production('direct-abstract-declarator : direct-abstract-declarator [ type-qualifier-list ]')
    @pg.production('direct-abstract-declarator : direct-abstract-declarator [ assignment-expression ]')
    @pg.production('direct-abstract-declarator : direct-abstract-declarator [ ]')
    @pg.production('direct-abstract-declarator : direct-abstract-declarator [ STATIC type-qualifier-list assignment-expression ]')
    @pg.production('direct-abstract-declarator : direct-abstract-declarator [ STATIC assignment-expression ]')
    @pg.production('direct-abstract-declarator : direct-abstract-declarator [ type-qualifier-list STATIC assignment-expression ]')
    @pg.production('direct-abstract-declarator : direct-abstract-declarator [ * ]')
    @pg.production('direct-abstract-declarator : direct-abstract-declarator ( parameter-type-list )')
    @pg.production('direct-abstract-declarator : direct-abstract-declarator ( )')
    def direct_abstract_declarator(state,p):
        return p[0].add_back(p[1:])

    @pg.production('parameter-type-list : parameter-list')
    @pg.production('parameter-type-list : parameter-list , ...')
    def parameter_type_list(state,p):
        if len(p) == 1:
            return p[0]
        return p[0].push_back(p[-1])

    @pg.production('parameter-list : parameter-declaration')
    @pg.production('parameter-list : parameter-list , parameter-declaration')
    def parameter_list(state,p):
        if len(p) == 1:
            return ParameterList(p)
        return p[0].push_back(p[2])

    @pg.production('parameter-declaration : declaration-specifiers declarator')
    @pg.production('parameter-declaration : declaration-specifiers abstract-declarator')
    @pg.production('parameter-declaration : declaration-specifiers')
    def parameter_list(state,p):
        return ParameterDeclaration(p)

    @pg.production('initializer-list : designation initializer')
    @pg.production('initializer-list : initializer')
    @pg.production('initializer-list : initializer-list , designation initializer')
    @pg.production('initializer-list : initializer-list , initializer')
    def initializer_list(state,p):
        if len(p) <= 2:
            return InitializerList(p)
        return p[0].add_back(p[2:])

    @pg.production('designation : designator-list =')
    def designation(state,p):
        pass

    @pg.production('designator-list : designator')
    @pg.production('designator-list : designator-list designator')
    def designator_list(state,p):
        pass

    @pg.production('designator : [ constant-expression ]')
    @pg.production('designator : . identifier')
    def designator(state,p):
        pass

    @pg.production('constant-expression : conditional-expression')
    def constant_expression(state,p):
        return p[0]

    @pg.production('initializer : assignment-expression')
    @pg.production('initializer : { initializer-list }')
    @pg.production('initializer : { initializer-list , }')
    def initializer(state,p):
        if len(p) == 1:
            return p[0]
        return p[1]
    
    @pg.production('identifier-list : identifier')
    @pg.production('identifier-list : identifier-list , identifier')
    def identifier_list(state,p):
        if len(p) == 1:
            return IdentifierList(p)
        return p[0].push_back(p[2])

    @pg.production('enum-specifier : ENUM identifier { enumerator-list }')
    @pg.production('enum-specifier : ENUM { enumerator-list }')
    @pg.production('enum-specifier : ENUM identifier { enumerator-list , }')
    @pg.production('enum-specifier : ENUM { enumerator-list , }')
    @pg.production('enum-specifier : ENUM identifier')
    def enum_specifier(state,p):
        if len(p) == 2:
            return EnumSpecifier([p[1]])
        if isinstance(p[1],Token):
            return EnumSpecifier([p[2]])
        return EnumSpecifier([p[1],p[3]])

    @pg.production('enumerator-list : enumerator')
    @pg.production('enumerator-list : enumerator-list , enumerator')
    def enumerator_list(state,p):
        if len(p) == 1:
            return EnumList(p)
        return p[0].push_back(p[2])

    @pg.production('enumerator : ENUMERATION-CONSTANT')
    @pg.production('enumerator : ENUMERATION-CONSTANT = constant-expression')
    def enumerator(state,p):
        return Enumerator(p)

    @pg.production('function-specifier : INLINE')
    def function_specifier(state,p):
        return FunctionSpecifier(p)

    @pg.production('declaration-list : declaration')
    @pg.production('declaration-list : declaration-list declaration')
    def declaration_list(state,p):
        if len(p) == 1:
            return DeclarationList(p)
        return p[0].push_back(p[1])

    @pg.production('declaration : declaration-specifiers init-declarator-list ;')
    @pg.production('declaration : declaration-specifiers ;')
    def declaration(state,p):
        return Declaration(p[:-1])

    @pg.production('init-declarator-list : init-declarator')
    @pg.production('init-declarator-list : init-declarator-list , init-declarator')
    def init_declarator_list(state,p):
        if len(p) == 1:
            return InitDeclaratorList(p)
        return p[0].push_back(p[2])

    @pg.production('init-declarator : declarator')
    @pg.production('init-declarator : declarator = initializer')
    def init_declarator(state,p):
        if len(p) == 1:
            return InitDeclarator(p)
        return InitDeclarator([p[0],p[-1]])

    @pg.production('compound-statement : { block-item-list }')
    @pg.production('compound-statement : { }')
    def compound_statement(state,p):
        if len(p) == 2:
            return CompoundStatement([])
        return CompoundStatement(p[1])

    @pg.production('block-item-list : block-item')
    @pg.production('block-item-list : block-item-list block-item')
    def block_item_list(state,p):
        if len(p) == 1:
            return [p[0]]
        return p[0] + [p[1]]

    @pg.production('block-item : declaration')
    @pg.production('block-item : statement')
    def block_item(state,p):
        return p[0]

    @pg.production('statement : labeled-statement')
    @pg.production('statement : compound-statement')
    @pg.production('statement : expression-statement')
    @pg.production('statement : selection-statement')
    @pg.production('statement : iteration-statement')
    @pg.production('statement : jump-statement')
    def statement(state,p):
        return p[0]

    @pg.production('labeled-statement : identifier COLON statement')
    def label_base(state,p):
        return Label([p[0],p[2]])
    
    @pg.production('labeled-statement : CASE constant-expression COLON statement')
    @pg.production('labeled-statement : DEFAULT COLON statement')
    def labeled_statement(state,p):
        if len(p) == 3:
            return SwitchDefault([p[-1]])
        return SwitchLabel([p[1],p[-1]])
        

    @pg.production('expression-statement : expression ;')
    @pg.production('expression-statement : ;')
    def expression_statement(state,p):
        if len(p) == 1:
            return EmptyExpression()
        return p[0]

    @pg.production('selection-statement : IF ( expression ) statement')
    @pg.production('selection-statement : IF ( expression ) statement ELSE statement')
    def if_statement(state,p):
        if len(p) == 5:
            return IfStatement([p[2],p[4]])
        return IfStatement([p[2],p[4],p[6]])

    @pg.production('selection-statement : SWITCH ( expression ) statement')
    def selection_statement(state,p):
        return SwitchStatement([p[2],p[-1]])

    @pg.production('iteration-statement : WHILE ( expression ) statement')
    def while_loop(state,p):
        return WhileLoop([p[2],p[-1]])

    @pg.production('iteration-statement : DO statement WHILE ( expression ) ;')
    def do_while_loop(state,p):
        return DoWhileLoop([p[-3],p[1]])

    @pg.production('iteration-statement : FOR ( expression ; expression ; expression ) statement')
    def for_loop_1(state,p):
        return ForLoop([p[2],p[4],p[6],p[-1]])
    
    @pg.production('iteration-statement : FOR ( expression ; expression ; ) statement')
    def for_loop_2(state,p):
        return ForLoop([p[2],p[4],EmptyExpression(),p[-1]])

    @pg.production('iteration-statement : FOR ( expression ; ; expression ) statement')
    def for_loop_3(state,p):
        return ForLoop([p[2],EmptyExpression(),p[5],p[-1]])
    
    @pg.production('iteration-statement : FOR ( ; expression ; expression ) statement')
    def for_loop_4(state,p):
        return ForLoop([EmptyExpression(),p[3],p[5],p[-1]])

    @pg.production('iteration-statement : FOR ( expression ; ; ) statement')
    def for_loop_5(state,p):
        return ForLoop([p[2],EmptyExpression(),EmptyExpression(),p[-1]])

    @pg.production('iteration-statement : FOR ( ; expression ; ) statement')
    def for_loop_6(state,p):
        return ForLoop([EmptyExpression(),p[3],EmptyExpression(),p[-1]])

    @pg.production('iteration-statement : FOR ( ; ; expression ) statement')
    def for_loop_7(state,p):
        return ForLoop([EmptyExpression(),EmptyExpression(),p[-3],p[-1]])

    @pg.production('iteration-statement : FOR ( ; ; ) statement')
    def for_loop_8(state,p):
        return ForLoop([EmptyExpression(),EmptyExpression(),EmptyExpression(),p[-1]])
    
    @pg.production('iteration-statement : FOR ( declaration expression ; expression ) statement')
    def for_loop_9(state,p):
        return ForLoop([p[2],p[3],p[5],p[-1]])
    
    @pg.production('iteration-statement : FOR ( declaration expression ; ) statement')
    def for_loop_10(state,p):
        return ForLoop([p[2],p[3],EmptyExpression(),p[-1]])
    
    @pg.production('iteration-statement : FOR ( declaration ; expression ) statement')
    def for_loop_11(state,p):
        return ForLoop([p[2],EmptyExpression(),p[4],p[-1]])
    
    @pg.production('iteration-statement : FOR ( declaration ; ) statement')
    def for_loop_12(state,p):
        return ForLoop([p[2],EmptyExpression(),EmptyExpression(),p[-1]])

    @pg.production('jump-statement : GOTO identifier')
    @pg.production('jump-statement : CONTINUE ;')
    @pg.production('jump-statement : BREAK ;')
    @pg.production('jump-statement : RETURN ;')
    @pg.production('jump-statement : RETURN expression ;')
    def jump_statement(state,p):
        if p[0].name == "GOTO":
            return Goto([p[1]])
        if p[0].name == "CONTINUE":
            return Continue()
        if p[0].name == "BREAK":
            return Break()
        if len(p) == 2:
            return Return()
        return Return([p[1]])

    @pg.production('identifier : IDENTIFIER')
    def identifier(state,p):
        return Identifier([p[0]])
    
    @pg.production('string-literal : STRING_LITERAL')
    def string_literal(state,p):
        return StringLiteral([p[0]])

    @pg.production('constant : I_CONSTANT')
    @pg.production('constant : F_CONSTANT')
    def constant(state,p):
        return Constant([p[0]])

    @pg.error
    def error_handler(state,token):
        print("ERROR AT",token,token.source_pos)
        exit()

    out = pg.build()
    print(out.lr_table.sr_conflicts)
    #print(out.lr_table.rr_conflicts)
    return out