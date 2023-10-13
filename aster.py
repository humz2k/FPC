from rply import Token

class Base:
    def __init__(self,p = []):
        #print(self.__class__.__name__)
        self.p = p
    
    def push_back(self,t):
        self.p.append(t)
        return self
    
    def push_front(self,t):
        self.p = [t] + p
        return self
    
    def add_back(self,p):
        self.p = self.p + p
        return self
    
    def add_front(self,p):
        self.p = p + self.p
        return self
    
    def recurse(self,indent = ""):
        print(indent + self.__class__.__name__)
        indent += "   "
        for i in self.p:
            if isinstance(i,Token):
                print(indent + i.name + " val = ('" + i.value + "')")
            else:
                i.recurse(indent)

class TranslationUnit(Base):
    pass

class FunctionDefinition(Base):
    pass

class DeclarationSpecifiers(Base):
    pass

class TypeSpecifier(Base):
    pass

class StructSpecifier(Base):
    pass

class UnionSpecifier(Base):
    pass

class StructDeclarationList(Base):
    pass

class StructDeclaration(Base):
    pass

class SpecifierQualifierList(Base):
    pass

class StructDeclaratorList(Base):
    pass

class StructDeclarator(Base):
    pass

class Declarator(Base):
    pass

class Pointer(Base):
    pass

class TypeQualifierList(Base):
    pass

class DirectDeclarator(Base):
    pass

class AssignmentExpression(Base):
    pass

class ConditionalExpression(Base):
    pass

class BinOpExpression(Base):
    pass

class CastExpression(Base):
    pass

class UnaryExpression(Base):
    pass

class SizeofType(Base):
    pass

class PointerIndex(Base):
    pass

class FunctionCall(Base):
    pass

class PostIncrement(Base):
    pass

class StructReference(Base):
    pass

class StructPointerReference(Base):
    pass

class Expression(Base):
    pass

class ArgumentExpressionList(Base):
    pass

class TypeName(Base):
    pass

class AbstractDeclarator(Base):
    pass

class DirectAbstractDeclarator(Base):
    pass

class ParameterList(Base):
    pass

class ParameterDeclaration(Base):
    pass

class InitializerList(Base):
    pass

class IdentifierList(Base):
    pass

class EnumSpecifier(Base):
    pass

class EnumList(Base):
    pass

class Enumerator(Base):
    pass

class FunctionSpecifier(Base):
    pass

class DeclarationList(Base):
    pass

class Declaration(Base):
    pass

class InitDeclaratorList(Base):
    pass

class InitDeclarator(Base):
    pass

class CompoundStatement(Base):
    pass

class Label(Base):
    pass

class SwitchLabel(Base):
    pass

class SwitchDefault(Base):
    pass

class EmptyExpression(Base):
    pass

class IfStatement(Base):
    pass

class SwitchStatement(Base):
    pass

class WhileLoop(Base):
    pass

class DoWhileLoop(Base):
    pass

class ForLoop(Base):
    pass

class Goto(Base):
    pass

class Continue(Base):
    pass

class Break(Base):
    pass

class Return(Base):
    pass

class Identifier(Base):
    pass

class StringLiteral(Base):
    pass

class Constant(Base):
    pass