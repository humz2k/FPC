import copy

TARGET = ""
THREAD_INDEXERS = ""

class AstObj:
    pass

class Type(AstObj):
    def __init__(self):
        self.const = False
        self.repr = ""

    def __str__(self):
        if self.const:
            return "const " + self.repr
        return self.repr
    
    def __eq__(self,other):
        if other.repr == self.repr:
            return True
        return False

class PointerType(Type):
    def __init__(self,pointee : Type):
        super().__init__()
        self.pointee = pointee
        self.repr = str(self.pointee) + "*"

class HalfType(Type):
    def __init__(self):
        super().__init__()
        self.repr = "half"

class FloatType(Type):
    def __init__(self):
        super().__init__()
        self.repr = "float"

class DoubleType(Type):
    def __init__(self):
        super().__init__()
        self.repr = "double"
    
class IntType(Type):
    def __init__(self,bits):
        super().__init__()
        if bits == 8:
            self.repr = "char"
        if bits == 16:
            self.repr = "short"
        if bits == 32:
            self.repr = "int"
        if bits == 64:
            self.repr = "long"

class VoidType(Type):
    def __init__(self):
        super().__init__()
        self.repr = "void"

class Expression(AstObj):
    def __init__(self):
        self.type : Type = None

class Cast(Expression):
    def __init__(self,typ,val):
        self.type = copy.deepcopy(typ)
        self.val = val
    
    def __str__(self):
        return "((" + str(self.type) + ")" + str(self.val) + ")"

class Variable(Expression):
    def __init__(self,typ,name,declare = False,kernel_arg = False):
        self.type = copy.deepcopy(typ)
        self.name = name
        self.declare = declare
        self.kernel_arg = kernel_arg
        if kernel_arg:
            if not isinstance(self.type,PointerType):
                self.name = "&" + self.name
    
    def __str__(self):
        if self.declare:
            self.declare = False
            return str(self.type) + " " + self.name
        return self.name

class Constant(Expression):
    def __init__(self,typ,val):
        self.type = copy.deepcopy(typ)
        self.type.const = True
        self.val = val
    
    def __str__(self):
        if self.type == IntType(8):
            return self.val
        if self.type == IntType(16):
            if "." in self.val:
                raise Exception("Invalid Int Literal")
            return "((short)" + self.val + ")"
        if self.type == IntType(32):
            if "." in self.val:
                raise Exception("Invalid Int Literal")
            return self.val
        if self.type == IntType(64):
            if "." in self.val:
                raise Exception("Invalid Long Literal")
            return self.val + "l"
        if self.type == FloatType():
            if "." in self.val:
                return self.val + "0f"
            else:
                return self.val + ".0f"
        if self.type == DoubleType():
            if "." in self.val:
                return self.val + "0"
            else:
                return self.val + ".0"

class Index(Expression):
    def __init__(self,var,indexer):
        self.var : Expression = var
        if not isinstance(self.var.type,PointerType):
            raise Exception("Indexing Non-pointer type")
        self.type : Type = copy.deepcopy(self.var.type.pointee)
        if self.var.type.const:
            self.type.const = True
        self.indexer : Expression = indexer
        if self.indexer.type != IntType(32):
            raise Exception("Cannot index with type " + str(self.indexer.type))
    
    def __str__(self):
        return str(self.var) + "[" + str(self.indexer) + "]"

class ThreadIdx(Expression):
    def __init__(self,attr : str):
        global THREAD_INDEXERS
        self.type = IntType(32)
        self.attr = attr
        self.indexers = THREAD_INDEXERS
        if not self.attr in self.indexers:
            raise Exception("Invalid ThreadIdx")
        
    def __str__(self):
        global TARGET
        if TARGET == "Metal":
            if len(self.indexers) == 1:
                return "(int)mtl_thread"
            return "(int)mtl_thread." + ["x","y","z"][self.indexers.index(self.attr)]
        
class BlockIdx(Expression):
    def __init__(self,attr : str):
        global THREAD_INDEXERS
        self.type = IntType(32)
        self.attr = attr
        self.indexers = THREAD_INDEXERS
        if not self.attr in self.indexers:
            raise Exception("Invalid BlockIdx")
        
    def __str__(self):
        global TARGET
        if TARGET == "Metal":
            return "__FPC_blockidx" + str(self.indexers.index(self.attr))
        
class IncrPost(Expression):
    def __init__(self,var : Expression, op : str):
        self.var = var
        self.type = copy.deepcopy(var.type)
        if var.type.const:
            raise Exception("Cannot increment constant")
        self.op = op

    def __str__(self):
        return str(self.var) + self.op

class IncrPre(Expression):
    def __init__(self,var : Expression, op : str):
        self.var = var
        self.type = copy.deepcopy(var.type)
        if var.type.const:
            raise Exception("Cannot increment constant")
        self.op = op
    
    def __str__(self):
        return self.op + str(self.var)
        
class BinOp(Expression):
    def __init__(self,op : str,left : Expression,right : Expression,typ : Type):
        self.type = copy.deepcopy(typ)
        self.type.const = True
        self.op = op
        self.left = left
        self.right = right

    def __str__(self):
        return "(" + str(self.left) + " " + self.op + " " + str(self.right) + ")"
    
class SinOp(Expression):
    def __init__(self,op : str,val : Expression,typ : Type):
        self.type = copy.deepcopy(typ)
        self.type.const = True
        self.op = op
        self.val = val

    def __str__(self):
        return "(" + self.op + " " + str(self.val) + ")"

class Assign(Expression):
    def __init__(self,left,right):
        global TARGET
        self.type = VoidType()
        if not left.type == right.type:
            raise Exception("Invalid Assign")
        if left.type == VoidType():
            raise Exception("Assigning Void Type")
        if left.type.const:
            raise Exception("Assigning to const")
        self.left = left
        self.right = right
    
    def __str__(self):
        return str(self.left) + " = " + str(self.right)
    
class FunctionCall(Expression):
    def __init__(self,name : str,inputs : list,typ : Type):
        self.name = name
        self.inputs = inputs
        self.type = typ
    
    def __str__(self):
        return self.name + "(" + ",".join([str(i) for i in self.inputs]) + ")"
    
class LibCall(Expression):
    def __init__(self,name : str,inputs : list,typ : Type):
        self.name = name
        self.inputs = inputs
        self.type = copy.deepcopy(typ)
    
    def __str__(self):
        return self.name + "(" + ",".join([str(i) for i in self.inputs]) + ")"