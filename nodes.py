class Node:
    def __init__(self,p,state):
        #print(self._type())
        self.name = self._type()
        self.state = state
        if (type(p) != list):
            raise Exception("p should be list")
        self.p = p

    def add(self,p):
        self.p.append(p)
        return self
    
    def add_before(self,p):
        self.p = [p] + self.p
        return self
    
    def _type(self):
        return self.__class__.__name__

class Identifier(Node):
    pass

class Constant(Node):
    pass

class String(Node):
    pass

class PrimaryExpression(Node):
    pass

class ArraySubscript(Node):
    pass

class FunctionCall(Node):
    pass

class StructAccessor(Node):
    pass

class StructPtrAccessor(Node):
    pass

class PostIncDec(Node):
    pass

class PreIncDec(Node):
    pass

class ArgumentExpressionList(Node):
    pass

class SizeofType(Node):
    pass

class SizeofExpr(Node):
    pass

class Alignof(Node):
    pass

class UnaryOp(Node):
    pass

class Cast(Node):
    pass

class BinOp(Node):
    pass

class Ternary(Node):
    pass

class Assign(Node):
    pass

class Expression(Node):
    pass

class ConstantExpression(Node):
    pass

class Declaration(Node):
    pass

class InitDeclaratorList(Node):
    pass

class InitDeclarator(Node):
    pass

class StructSpecifier(Node):
    pass

class UnionSpecifier(Node):
    pass

class StructDeclarationList(Node):
    pass

class StructDeclaration(Node):
    pass

class SpecifierQualifierList(Node):
    pass

class StructDeclaratorList(Node):
    pass

class StructDeclarator(Node):
    pass

class EnumSpecifier(Node):
    pass

class EnumeratorList(Node):
    pass

class Enumerator(Node):
    pass

class AtomicTypeSpecifier(Node):
    pass

class AlignmentSpecifier(Node):
    pass

class Declarator(Node):
    pass

class DirectDeclarator(Node):
    pass

class Pointer(Node):
    pass

class TypeQualifierList(Node):
    pass

class ParameterTypeList(Node):
    pass

class ParameterList(Node):
    pass

class ParameterDeclaration(Node):
    pass

class IdentifierList(Node):
    pass

class TypeName(Node):
    pass

class AbstractDeclarator(Node):
    pass

class DirectAbstractDeclarator(Node):
    pass

class Initializer(Node):
    pass

class InitializerList(Node):
    pass

class Designation(Node):
    pass

class DesignatorList(Node):
    pass

class Designator(Node):
    pass

class StaticAssertDeclaration(Node):
    pass

class JumpLabel(Node):
    pass

class SwitchCase(Node):
    pass

class CompoundStatement(Node):
    pass

class BlockItemList(Node):
    pass

class ExpressionStatement(Node):
    pass

class IfStatement(Node):
    pass

class SwitchStatement(Node):
    pass

class WhileLoop(Node):
    pass

class DoWhileLoop(Node):
    pass

class ForLoop(Node):
    pass

class Goto(Node):
    pass

class Continue(Node):
    pass

class Break(Node):
    pass

class Return(Node):
    pass

class TranslationUnit(Node):
    pass

class FunctionDefinition(Node):
    pass

class DeclarationList(Node):
    pass

class TypeSpecifier(Node):
    pass

class StorageClassSpecifier(Node):
    pass