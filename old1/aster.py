from nodes import *

def translation_unit(state,p):
    pass

def primary_expression(state,p):
    if (p[0].name == "IDENTIFIER"):
        return PrimaryExpression([Identifier(p)],state)
    if (len(p) == 1):
        return PrimaryExpression(p,state)
    return PrimaryExpression(p[1:-1],state)

def constant(state,p):
    return Constant(p,state)

def enumeration_constant(state,p):
    return EnumerationConstant(p,state)

def string(state,p):
    if (p[0].name == "STRING_LITERAL"):
        return String(p,state)
    raise Exception("WTF")

def generic_selection(state,p):
    raise Exception("WTF")

def generic_assoc_list(state,p):
    raise Exception("WTF")

def generic_association(state,p):
    raise Exception("WTF")

def postfix_expression(state,p):
    if len(p) == 1:
        return p[0]
    if (p[1].name == "["):
        return ArraySubscript(p,state)
    if (p[1].name == "("):
        return FunctionCall(p,state)
    if (p[1].name == "."):
        return StructAccessor(p,state)
    if (p[1].name == "PTR_OP"):
        return StructPtrAccessor(p,state)
    if (p[1].name == "INC_OP"):
        return PostIncDec(p,state)
    if (p[1].name == "DEC_OP"):
        return PostIncDec(p,state)
    raise Exception("WTF")

def argument_expression_list(state,p):
    if len(p) == 1:
        return ArgumentExpressionList(p,state)
    return p[0].add(p[2])

def unary_expression(state,p):
    if len(p) == 1:
        return p[0]
    if p[0].name in ["INC_OP","DEC_OP"]:
        return PreIncDec(p,state)
    if p[0].name == "SIZEOF":
        if (p[1].name == "("):
            return SizeofType(p,state)
        return SizeofExpr(p,state)
    if p[0].name == "ALIGNOF":
        return Alignof(p,state)
    return UnaryOp(p,state)

def unary_operator(state,p):
    return p[0]

def cast_expression(state,p):
    if len(p) == 1:
        return p[0]
    return Cast(p,state)

def multiplicative_expression(state,p):
    if len(p) == 1:
        return p[0]
    return BinOp(p,state)

def additive_expression(state,p):
    if len(p) == 1:
        return p[0]
    return BinOp(p,state)

def shift_expression(state,p):
    if len(p) == 1:
        return p[0]
    return BinOp(p,state)

def relational_expression(state,p):
    if len(p) == 1:
        return p[0]
    return BinOp(p,state)

def equality_expression(state,p):
    if len(p) == 1:
        return p[0]
    return BinOp(p,state)

def and_expression(state,p):
    if len(p) == 1:
        return p[0]
    return BinOp(p,state)

def exclusive_or_expression(state,p):
    if len(p) == 1:
        return p[0]
    return BinOp(p,state)

def inclusive_or_expression(state,p):
    if len(p) == 1:
        return p[0]
    return BinOp(p,state)

def logical_and_expression(state,p):
    if len(p) == 1:
        return p[0]
    return BinOp(p,state)

def logical_or_expression(state,p):
    if len(p) == 1:
        return p[0]
    return BinOp(p,state)

def conditional_expression(state,p):
    if len(p) == 1:
        return p[0]
    return Ternary(p,state)

def assignment_expression(state,p):
    if len(p) == 1:
        return p[0]
    return Assign(p,state)

def assignment_operator(state,p):
    return p[0]

def expression(state,p):
    if len(p) == 1:
        return Expression(p,state)
    return p[0].add(p[2])

def constant_expression(state,p):
    return ConstantExpression(p,state)

def declaration(state,p):
    return Declaration(p,state)

def declaration_specifiers(state,p):
    if len(p) == 1:
        return DeclarationSpecifiers(p,state)
    return p[1].add_before(p[0])

def init_declarator_list(state,p):
    if len(p) == 1:
        return InitDeclaratorList(p,state)
    return p[0].add(p[2])

def init_declarator(state,p):
    if len(p) == 1:
        return p[0]
    return p[0].add(p[2])
    #return InitDeclarator(p,state)

def storage_class_specifier(state,p):
    return p[0]

def type_specifier(state,p):
    return TypeSpecifier(p,state)

def struct_or_union_specifier(state,p):
    if p[0].name == "STRUCT":
        return StructSpecifier(p,state)
    return UnionSpecifier(p,state)

def struct_or_union(state,p):
    return p[0]

def struct_declaration_list(state,p):
    if len(p) == 1:
        return StructDeclarationList(p,state)
    return p[0].add(p[1])

def struct_declaration(state,p):
    return StructDeclaration(p,state)

def specifier_qualifier_list(state,p):
    if len(p) == 1:
        return SpecifierQualifierList(p,state)
    return p[1].add_before(p[0])

def struct_declarator_list(state,p):
    if len(p) == 1:
        return StructDeclaratorList(p,state)
    return p[0].add(p[2])

def struct_declarator(state,p):
    return StructDeclarator(p,state)

def enum_specifier(state,p):
    return EnumSpecifier(p,state)

def enumerator_list(state,p):
    if len(p) == 1:
        return EnumeratorList(p,state)
    return p[0].add(p[2])

def enumerator(state,p):
    return Enumerator(p,state)

def atomic_type_specifier(state,p):
    return AtomicTypeSpecifier(p,state)

def type_qualifier(state,p):
    return p[0]

def function_specifier(state,p):
    return p[0]

def alignment_specifier(state,p):
    return AlignmentSpecifier(p,state)

def declarator(state,p):
    if len(p) == 1:
        return p[0]
    return p[1].add_before(p[0])

def direct_declarator(state,p):
    return DirectDeclarator(p,state)

def pointer(state,p):
    return Pointer(p,state)

def type_qualifier_list(state,p):
    if len(p) == 1:
        return TypeQualifierList(p,state)
    return p[0].add(p[1])

def parameter_type_list(state,p):
    return ParameterTypeList(p,state)

def parameter_list(state,p):
    if len(p) == 1:
        return ParameterList(p,state)
    return p[0].add(p[2])

def parameter_declaration(state,p):
    return ParameterDeclaration(p,state)

def identifier_list(state,p):
    if len(p) == 1:
        return IdentifierList(p,state)
    return p[0].add(p[2])

def type_name(state,p):
    return TypeName(p,state)

def abstract_declarator(state,p):
    return AbstractDeclarator(p,state)

def direct_abstract_declarator(state,p):
    return DirectAbstractDeclarator(p,state)

def initializer(state,p):
    return Initializer(p,state)

def initializer_list(state,p):
    if len(p) in [1,2]:
        return InitializerList(p,state)
    return p[0].add(p[2:])

def designation(state,p):
    return Designation(p,state)

def designator_list(state,p):
    if len(p) == 1:
        return DesignatorList(p,state)
    return p[0].add(p[1])

def designator(state,p):
    return Designator(p,state)

def static_assert_declaration(state,p):
    return StaticAssertDeclaration(p,state)

def statement(state,p):
    return p[0]

def labeled_statement(state,p):
    if p[0].name == "IDENTIFIER":
        return JumpLabel(p,state)
    return SwitchCase(p,state)

def compound_statement(state,p):
    return CompoundStatement(p,state)

def block_item_list(state,p):
    if len(p) == 1:
        return BlockItemList(p,state)
    return p[0].add(p[1])

def block_item(state,p):
    return p[0]

def expression_statement(state,p):
    return ExpressionStatement(p,state)

def selection_statement(state,p):
    if p[0].name == "IF":
        return IfStatement(p,state)
    return SwitchStatement(p,state)

def iteration_statement(state,p):
    if p[0].name == "WHILE":
        return WhileLoop(p,state)
    if p[0].name == "DO":
        return DoWhileLoop(p,state)
    return ForLoop(p,state)

def jump_statement(state,p):
    if p[0].name == "GOTO":
        return Goto(p,state)
    if p[0].name == "CONTINUE":
        return Continue(p,state)
    if p[0].name == "BREAK":
        return Break(p,state)
    return Return(p,state)

def translation_unit(state,p):
    if len(p) == 1:
        return TranslationUnit(p,state)
    return p[0].add(p[1])

def external_declaration(state,p):
    return p[0]

def function_definition(state,p):
    return FunctionDefinition(p,state)

def declaration_list(state,p):
    if len(p) == 1:
        return DeclarationList(p,state)
    return p[0].add(p[1])
