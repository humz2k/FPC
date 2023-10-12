class Base:
    def __init__(self,p):
        print(self.__class__.__name__)
        self.p = p
    
    def push_back(self,t):
        self.p.append(t)
        return self
    
    def push_front(self,t):
        self.p = [t] + p
        return self

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