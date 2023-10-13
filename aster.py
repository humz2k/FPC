from rply import Token
from llvmlite import ir

class State:
    def __init__(self,lexer,module_name):
        self.lexer = lexer
        self.module : ir.Module = ir.Module(module_name)

class Base:
    def __init__(self,p = []):
        #print(self.__class__.__name__)
        self.p = p
    
    def push_back(self,t):
        self.p.append(t)
        return self
    
    def push_front(self,t):
        self.p = [t] + self.p
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

    def eval(self,state : State):
        print("eval not implemented in " + self.__class__.__name__)

class TranslationUnit(Base):
    def eval(self,state : State):
        for i in self.p:
            i.eval(state)

class FunctionDefinition(Base):
    def eval(self,state : State):
        typ,definition,statement = self.p
        print(typ.eval(state))

class DeclarationSpecifiers(Base):
    def eval(self,state : State):
        tmp = ""
        for i in self.p:
            if isinstance(i,TypeSpecifier):
                tmp += i.get() + " "
        tmp = tmp.strip()
        unsigned = False
        out = None
        if "unsigned" in tmp:
            unsigned = True
        if tmp in ["int","unsigned int","signed int"]:
            out = ir.IntType(32)
        elif tmp in ["char","unsigned char","signed char"]:
            out = ir.IntType(8)
        elif tmp in ["short","unsigned short"]:
            out = ir.IntType(16)
        elif tmp in ["long","unsigned long","unsigned long long"]:
            out = ir.IntType(64)
        elif tmp == "float":
            out = ir.FloatType()
        elif tmp == "half":
            out = ir.HalfType()
        elif tmp == "double":
            out = ir.DoubleType()
        else:
            raise Exception("Invalid Type!")
        out.unsigned = unsigned
        return out

class TypeSpecifier(Base):
    def get(self):
        if isinstance(self.p[0],Token):
            return self.p[0].value

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