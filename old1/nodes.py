from rply import Token
from llvmlite import ir

class Node:
    def __init__(self,p,state):
        #print(self._type())
        self.name = self._type()
        self.state = state
        if (type(p) != list):
            raise Exception("p should be list")
        self.p = p

    def eval(self,*args,**kwargs):
        raise Exception("eval in " + str(self.name) + " no implemented")

    def info(self,indent):
        pass

    def recurse(self,indent=""):
        print(indent,self.name)
        self.info(indent + "   ")
        for i in self.p:
            #print(indent,i)
            if isinstance(i,Token):
                print(indent + "   ",i)
            else:
                i.recurse(indent + "   ")

    def add(self,p):
        self.p.append(p)
        return self
    
    def add_before(self,p):
        #print(self.p)
        self.p = [p] + self.p
        #print(self.p)
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
    def __init__(self,p,state):
        super().__init__(p,state)
        if len(p) == 3:
            for i in p[0].p:
                if isinstance(i,Token):
                    if i.name == "TYPEDEF":
                        state.typedefs += [i.identifier for i in p[1].p]

class DeclarationSpecifiers(Node):
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
    def __init__(self,p,state):
        super().__init__(p,state)
        if (len(p) == 1):
            self.identifier = p[0].value
        elif p[0].name == "(":
            self.identifier = p[1].identifier
        else:
            self.identifier = p[0].identifier

    def info(self,indent):
        print(indent,"Identifier =",self.identifier)

class Pointer(Node):
    def make_ptr(self,typ):
        out = Type(ir.PointerType(typ.base),typ.signed)
        for i in self.p:
            if isinstance(i,Pointer):
                out = i.make_ptr(out)
        return out

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
    def eval(self,*args,**kwargs):
        self.state.module = ir.Module(name = kwargs["module_name"])
        for i in self.p:
            i.eval()

class FunctionDefinition(Node):
    def __init__(self,p,state):
        super().__init__(p,state)
        self.declaration_list = None
        if len(p) == 4:
            self.declaration_specifiers,self.declarator,self.declaration_list,self.compound_statement = p
        else:
            self.declaration_specifiers,self.declarator,self.compound_statement = p

    def eval(self,*args,**kwargs):
        func_return_type = None
        for i in self.declaration_specifiers.p:
            if isinstance(i,Token):
                continue
            if not (isinstance(i,TypeSpecifier)):
                raise Exception("something weird happened!")
            func_return_type = i.get_type()
        if isinstance(self.declarator.p[0],Pointer):
            func_return_type = self.declarator.p[0].make_ptr(func_return_type)
        print(self.declaration_list)

class DeclarationList(Node):
    pass

class Type:
    def __init__(self,base,signed=None):
        self.base = base
        self.signed = signed

    def __str__(self):
        out = str(self.base)
        if (self.signed == False):
            out = "u" + out
        return out

class TypeSpecifier(Node):
    def __init__(self,p,state):
        super().__init__(p,state)

    def get_type(self):
        all_tokens = True
        for i in self.p:
            if not isinstance(i,Token):
                all_tokens = False
                break
        if not all_tokens:
            raise Exception("Not implemented in TypeSpecifier")
        else:
            string = tuple([i.name for i in self.p])
            print(string)
            if string == ("VOID",):
                return Type(ir.VoidType())
            if string == ("SIGNED","CHAR"):
                return Type(ir.IntType(8),True)
            if string == ("UNSIGNED","CHAR"):
                return Type(ir.IntType(8),False)
            if string in [("SHORT",),("SHORT","INT"),("SIGNED","SHORT"),("SIGNED","SHORT","INT")]:
                return Type(ir.IntType(16),True)
            if string in [("UNSIGNED","SHORT"),("UNSIGNED","SHORT","INT")]:
                return Type(ir.IntType(16),False)
            if string in [("INT",),("SIGNED"),("SIGNED","INT")]:
                return Type(ir.IntType(32),True)
            if string in [("UNSIGNED",),("UNSIGNED","INT")]:
                return Type(ir.IntType(32),False)
            if string in [("LONG",),("LONG","INT"),("SIGNED","LONG"),("SIGNED","LONG","INT")]:
                return Type(ir.IntType(64),True)
            if string in [("UNSIGNED","LONG"),("UNSIGNED","LONG","INT")]:
                return Type(ir.IntType(64),False)
            if string in [("LONG","LONG"),("LONG","LONG","INT"),("SIGNED","LONG","LONG"),("SIGNED","LONG","LONG","INT")]:
                return Type(ir.IntType(128),True)
            if string in [("UNSIGNED","LONG","LONG"),("UNSIGNED","LONG","LONG","INT")]:
                return Type(ir.IntType(128),True)
            if string in [("FLOAT",)]:
                return Type(ir.FloatType())
            if string in [("DOUBLE",)]:
                return Type(ir.DoubleType())
            if string in [("HALF",)]:
                return Type(ir.HalfType())
            raise Exception("Not implemented")

class StorageClassSpecifier(Node):
    pass

class EnumerationConstant(Node):
    pass