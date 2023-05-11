from rply import ParserGenerator
from . import aster

class Line:
    def __init__(self):
        self.return_type = None

    def set_return_type(self,typ):
        self.return_type = typ

class SimpleLine(Line):
    def __init__(self,expr : aster.Expression):
        super().__init__()
        self.expr = expr
    
    def __str__(self):
        return str(self.expr) + ";"
    
class ReturnLine(Line):
    def __init__(self,expr = None):
        super().__init__()
        self.expr = expr
    
    def __str__(self):
        if type(self.return_type) != type(None):
            if type(self.expr) == type(None):
                if self.return_type != aster.VoidType():
                    raise Exception("Non-void function doesn't return value")
            if self.expr.type != self.return_type:
                raise Exception("Function returns wrong type")
        if type(self.expr) == type(None):
            return "return;"
        return "return " + str(self.expr) + ";"
    
class IfStatement(Line):
    def __init__(self,expr : aster.Expression, target : str,state):
        super().__init__()
        self.expr = expr
        self.add_to = True
        self.if_true = []
        self.if_false = []
        self.target = target
        self.state = state

    def set_return_type(self, typ):
        super().set_return_type(typ)
        for line in self.if_true:
            line.set_return_type(typ)
        for line in self.if_false:
            line.set_return_type(typ)
    
    def switch(self):
        self.state.local_variables.pop(-1)
        self.state.local_variables.append(self.state.local_variables[-1].copy())
        self.add_to = False
    
    def add_line(self,line : Line):
        if self.add_to:
            self.if_true.append(line)
        else:
            self.if_false.append(line)
        
    def __str__(self):
        out = "if (" + str(self.expr) + ")\n{\n"
        for line in self.if_true:
            out += str(line) + "\n"
        if len(self.if_false) != 0:
            out += "}\nelse\n{\n"
            for line in self.if_false:
                out += str(line) + "\n"
        out += "}"
        return out
    
class ForLoop(Line):
    def __init__(self,target):
        super().__init__()
        self.target = target
        self.lines = []

    def set_return_type(self, typ):
        super().set_return_type(typ)
        for line in self.lines:
            line.set_return_type(typ)

    def add(self,init : aster.Expression, cond : aster.Expression,incr : aster.Expression):
        self.init = init
        self.cond = cond
        if self.cond.type != aster.IntType(32):
            raise Exception("Invalid cond in ForLoop")
        self.incr = incr
    
    def add_line(self,line : Line):
        self.lines.append(line)
    
    def __str__(self):
        out = "for (" + str(self.init) + "; " + str(self.cond) + "; " + str(self.incr) + ")\n{\n"
        for line in self.lines:
            out += str(line) + "\n"
        out += "}"
        return out
    
class WhileLoop(Line):
    def __init__(self,expr : aster.Expression,target):
        super().__init__()
        self.target = target
        self.expr = expr
        self.lines = []

    def set_return_type(self, typ):
        super().set_return_type(typ)
        for line in self.lines:
            line.set_return_type(typ)
    
    def add_line(self,line : Line):
        self.lines.append(line)
    
    def __str__(self):
        out = "while (" + str(self.expr) + ")\n{\n"
        for line in self.lines:
            out += str(line) + "\n"
        out += "}"
        return out

class Kernel:
    def __init__(self,name : str,inputs : list,target : str):
        self.name = name
        self.inputs = inputs
        self.lines = []
        self.target = target

    def add_line(self,line : Line):
        self.lines.append(line)

    def __str__(self):
        indexers = aster.THREAD_INDEXERS
        if self.target == "Metal":
            out = "kernel void " + self.name + "("
            input_strings = []
            for typ,name in self.inputs:
                if isinstance(typ,aster.PointerType):
                    input_strings.append("device " + str(typ) + " " + str(name))
                else:
                    input_strings.append("device " + str(typ) + " &" + str(name))
            out += ", ".join(input_strings)
            tmp = ""
            if len(indexers) > 1:
                tmp = str(len(indexers))
            out += ", uint" + tmp + " mtl_thread [[thread_position_in_grid]]"
            out += ")\n{\n"
            for line in self.lines:
                out += str(line) + "\n"
            out += "\n}\n"
            return out

class Function:
    def __init__(self,name : str, return_type : aster.Type, inputs : list, target : str):
        self.name = name
        self.inputs = inputs
        self.lines = []
        self.target = target
        self.return_type = return_type
    
    def add_line(self,line : Line):
        self.lines.append(line)
    
    def __str__(self):
        for line in self.lines:
            line.set_return_type(self.return_type)
        out = str(self.return_type) + " " + self.name + "("
        out += ",".join([str(typ) + " " + str(name) for typ,name in self.inputs])
        out += ")\n{\n"
        for line in self.lines:
            out += str(line) + "\n"
        out += "\n}\n"
        return out

class ParserState(object):
    def __init__(self,target = "Metal"):
        aster.TARGET = target
        self.target = target
        self.local_variables = []
        self.elements = []
        self.kernels = {}
        self.functions = {}
        self.indexers = ""

    def get_metal_names(self):
        return list(self.kernels.keys())
    
    def generate_metal_cpp(self,name,inputs,i):
        out = "void " + name + "(const int (&num_blocks)[" + str(i) + "], const int (&block_size)[" + str(i) + "], "
        arg_strings = []
        for typ,arg_name in inputs:
            typ_str = typ.repr
            if isinstance(typ,aster.PointerType):
                typ_str = "FPC::Buffer"
            arg_strings.append(typ_str + " " + arg_name)
        out += ", ".join(arg_strings) + ")\n{\n"
        if i == 1:
            out += "MTL::Size m_grid_size = MTL::Size(block_size[0] * num_blocks[0], 1, 1);\nMTL::Size m_thread_group_size = MTL::Size(block_size[0], 1, 1);\n"
        if i == 2:
            out += "MTL::Size m_grid_size = MTL::Size(block_size[0] * num_blocks[0], block_size[1] * num_blocks[1], 1);\nMTL::Size m_thread_group_size = MTL::Size(block_size[0], block_size[1], 1);\n"
        if i == 3:
            out += "MTL::Size m_grid_size = MTL::Size(block_size[0] * num_blocks[0], block_size[1] * num_blocks[1], block_size[2] * num_blocks[2]);\nMTL::Size m_thread_group_size = MTL::Size(block_size[0], block_size[1], block_size[2]);\n"
        out += "FPC::lib.dispatch_function(" + '"' + name + '"' + ",m_grid_size,m_thread_group_size," + ",".join([i[1] for i in inputs]) + ");\n}\n"
        return out
    
    def generate_metal_bindings(self):
        out = ""
        for key,value in zip(self.kernels.keys(),self.kernels.values()):
            out += self.generate_metal_cpp(key,value.inputs,1) + "\n"
            out += self.generate_metal_cpp(key,value.inputs,2) + "\n"
            out += self.generate_metal_cpp(key,value.inputs,3) + "\n"
        return out + "\n"

    def add_kernel(self,name : str,inputs : list):
        out : Kernel = Kernel(name,inputs,self.target)
        if name in self.kernels:
            self.throw("KernelExists")
        self.kernels[name] = out
        self.elements.append(out)
        self.local_variables = [{}]
        for typ,name in inputs:
            if name in self.local_variables[-1]:
                self.throw("VarExists")
            self.local_variables[-1][name] = aster.Variable(typ,name,declare=False)
        return out
    
    def mangle(self,name : str, inputs : list):
        i_strings = "_".join([str(i) for i in inputs])
        i_strings = i_strings.replace("const","")
        i_strings = i_strings.replace(" ","")
        i_strings.replace("*","ptr")
        return name + "_" + i_strings
    
    def get_func_call(self,name : str,inputs : list):
        input_types = [i.type for i in inputs]
        new_name = self.mangle(name,input_types)
        if new_name in self.functions:
            return aster.FunctionCall(new_name,inputs,self.functions[new_name].return_type)
        self.throw("FuncNotExist")

    def add_function(self,name : str, return_type : aster.Type, inputs : list):
        new_name = self.mangle(name,[i[0] for i in inputs])
        out : Function = Function(new_name,return_type=return_type,inputs=inputs,target=self.target)
        if new_name in self.functions:
            self.throw("FuncExists")
        self.functions[new_name] = out
        self.elements.append(out)
        self.local_variables = [{}]
        for typ,name in inputs:
            if name in self.local_variables[-1]:
                self.throw("VarExists")
            self.local_variables[-1][name] = aster.Variable(typ,name,declare=False)
        return out
    
    def declare_variable(self,typ : aster.Type, name : str):
        if name in self.local_variables[-1]:
            self.throw("VarExists")
        out : aster.Variable = aster.Variable(typ,name,declare = True)
        self.local_variables[-1][name] = out
        return out
    
    def get_if(self,expr : aster.Expression):
        out : IfStatement = IfStatement(expr,self.target,self)
        self.local_variables.append(self.local_variables[-1].copy())
        if expr.type != aster.IntType(32):
            self.throw("CondTypeErr")
        return out
    
    def get_for(self):
        out : ForLoop = ForLoop(self.target)
        self.local_variables.append(self.local_variables[-1].copy())
        return out
    
    def get_while(self,expr : aster.Expression):
        out : WhileLoop = WhileLoop(expr,self.target)
        if expr.type != aster.IntType(32):
            self.throw("CondTypeErr")
        self.local_variables.append(self.local_variables[-1].copy())
        return out

    def set_thread_indexers(self,indexers):
        self.indexers = indexers
        aster.THREAD_INDEXERS = self.indexers
        if len(indexers) > 3:
            self.throw("TooManyIndexers")

    def find_variable(self,var_name : str):
        if var_name in self.local_variables[-1]:
            return self.local_variables[-1][var_name]
        self.throw("VarNotFound")

    def get_binop(self,op : str, left : aster.Expression, right : aster.Expression):
        if isinstance(left.type,aster.PointerType):
            if isinstance(right.type,aster.PointerType):
                if left.type == right.type:
                    if op == "-":
                        return aster.BinOp(op,left,right,left.type)
                self.throw("InvalidPointerMath")
            if not right.type == aster.IntType(32):
                self.throw("InvalidPointerMath")
            if not op in ["+","-"]:
                self.throw("InvalidPointerMath")
            return aster.BinOp(op,left,right,left.type)
        if left.type != right.type:
            self.throw("InvalidBinopTypes")
        out_t = left.type
        if op in ["==","!=",">","<",">=","<=","&&","||"]:
            out_t = aster.IntType(32)
        if op in ["&","|","^"]:
            if not isinstance(left.type,aster.IntType):
                self.throw("InvalidBinopTypes")
        return aster.BinOp(op,left,right,out_t)
    
    def get_sinop(self,op : str, val : aster.Expression):
        if isinstance(val.type,aster.PointerType):
            self.throw("InvalidPointerMath")
        out_t = val.type
        if op in ["!","~"]:
            if not isinstance(val.type,aster.IntType):
                self.throw("InvalidSinopTypes")
        if op in ["!"]:
            if val.type != aster.IntType(32):
                self.throw("InvalidSinopTypes")
        return aster.SinOp(op,val,out_t)
    
    def __str__(self):
        out = ""
        if self.target == "Metal":
            out += "#include <metal_stdlib>\nusing namespace metal;\n"
        out += "\n".join([str(i) for i in self.elements])
        return out

    def throw(self,err_t : str):
        print(err_t)
        exit()

    def log(self,msg):
        #print(msg)
        pass

def get_parser(filename="tokens.txt"):
    with open(filename,"r") as f:
        tokens = [i.split()[0] for i in f.read().splitlines() if (not i.startswith("//")) and (not len(i) == 0)] + ["KERNEL_NAME","FUNCTION_NAME"]
    if "IGNORE" in tokens:
        tokens.remove("IGNORE")
    pg = ParserGenerator(tokens, precedence=[
        ('left',["ASSIGN","PLUS_EQUAL","MINUS_EQUAL","STAR_EQUAL","SLASH_EQUAL","PERCENT_EQUAL"]),
        ('left', ['CONST']),
        ('left', ['AND', 'OR']),
        ('left', ['NOT']),
        ('left', ['EQUAL', 'NOT_EQUAL','GREATER','LESS','GREATER_OR_EQUAL','LESS_OR_EQUAL']),
        ('left', ['PLUS', 'MINUS']),
        ('left', ['STAR', 'SLASH']),
        ('left', ['PERCENT']),
        ('left', ['AMP', 'VERT','HAT','TILDE','LEFT_SHIFT','RIGHT_SHIFT']),
        ('left', ['PERIOD']),
        ('left',['PLUS_PLUS','MINUS_MINUS']),
        ('right',["OPEN_SQUARE"]),
        ('left',["CLOSE_PAREN"]),
    ])

    @pg.production('program : kernel')
    @pg.production('program : function')
    def program(state,p):
        state.log('program : kernel|function')

    @pg.production('program : program kernel')
    @pg.production('program : program function')
    def program(state,p):
        state.log('program : program kernel|function')

    @pg.production('function_open : type FUNCTION_NAME OPEN_PAREN CLOSE_PAREN OPEN_CURL')
    def function_open(state : ParserState,p):
        return state.add_function(p[1].value,p[0],[])

    @pg.production('function_open_header : type FUNCTION_NAME OPEN_PAREN type IDENTIFIER')
    def func_header_open(state : ParserState,p):
        return [p[0],p[1].value,(p[3],p[4].value)]
    
    @pg.production('function_open_header : function_open_header COMMA type IDENTIFIER')
    def func_header_cont(state: ParserState,p):
        state.log('function_open_header : function_open_header COMMA type IDENTIFIER')
        return p[0] + [(p[2],p[3].value)]
    
    @pg.production('function_open : function_open_header CLOSE_PAREN OPEN_CURL')
    def func_header_fin(state : ParserState, p):
        state.log('function_open : function_open_header CLOSE_PAREN OPEN_CURL')
        return_type = p[0][0]
        name = p[0][1]
        inputs = p[0][2:]
        return state.add_function(name,return_type,inputs)
    
    @pg.production('function_open : function_open line')
    def add_line(state : ParserState,p):
        p[0].add_line(p[1])
        return p[0]
    
    @pg.production('function : function_open CLOSE_CURL')
    def fin_func(state : ParserState,p):
        state.local_variables.pop(-1)
        return p[0]

    @pg.production('kernel : KERNEL KERNEL_NAME OPEN_SQUARE IDENTIFIER CLOSE_SQUARE OPEN_PAREN CLOSE_PAREN')
    def no_input_kernel(state,p):
        state.log('kernel : KERNEL KERNEL_NAME OPEN_PAREN CLOSE_PAREN')
        state.throw("EmptyKernel")

    @pg.production('kernel_open_header : KERNEL KERNEL_NAME OPEN_SQUARE IDENTIFIER CLOSE_SQUARE OPEN_PAREN type IDENTIFIER')
    def open_kernel_header(state,p):
        state.log('kernel_open_header : KERNEL KERNEL_NAME OPEN_SQUARE IDENTIFIER CLOSE_SQUARE OPEN_PAREN type IDENTIFIER')
        thread_indexers = list(p[3].value)
        state.set_thread_indexers(thread_indexers)
        return [p[1].value,(p[6],p[7].value)]
    
    @pg.production('kernel_open_header : kernel_open_header COMMA type IDENTIFIER')
    def cont_kernel_header(state,p):
        state.log('kernel_open_header : kernel_open_header COMMA type IDENTIFIER')
        return p[0] + [(p[2],p[3].value)]

    @pg.production('kernel_open : kernel_open_header CLOSE_PAREN OPEN_CURL')
    def open_kernel(state : ParserState,p):
        state.log('kernel_open : kernel_open_header CLOSE_PAREN OPEN_CURL')
        name = p[0][0]
        inputs = p[0][1:]
        return state.add_kernel(name,inputs)
    
    @pg.production('kernel_open : kernel_open line')
    def cont_kernel(state : ParserState,p):
        state.log('kernel_open : kernel_open line')
        kernel : Kernel = p[0]
        line = p[1]
        kernel.add_line(line)
        return kernel
    
    @pg.production('kernel : kernel_open CLOSE_CURL')
    def finish_kernel(state,p):
        state.log('kernel : kernel_open CLOSE_CURL')

    @pg.production('if : IF OPEN_PAREN expression CLOSE_PAREN OPEN_CURL')
    def get_if(state : ParserState,p):
        state.log('if : IF OPEN_PAREN expression CLOSE_PAREN OPEN_CURL')
        return state.get_if(p[2])
    
    @pg.production('if : if line')
    def pass_line_to_if(state : ParserState,p):
        state.log('if : if line')
        p[0].add_line(p[1])
        return p[0]
    
    @pg.production('if : if CLOSE_CURL ELSE OPEN_CURL')
    def pass_line_to_if(state : ParserState,p):
        state.log('if : if CLOSE_CURL ELSE OPEN_CURL')
        p[0].switch()
        return p[0]

    @pg.production('line : if CLOSE_CURL')
    def pass_if(state : ParserState,p):
        state.local_variables.pop(-1)
        return p[0]
    
    @pg.production('open_for : FOR')
    def open_for(state : ParserState,p):
        return state.get_for()
    
    @pg.production('for : open_for OPEN_PAREN expression SEMI_COLON expression SEMI_COLON expression CLOSE_PAREN OPEN_CURL')
    def for_loop(state : ParserState,p):
        p[0].add(p[2],p[4],p[6])
        return p[0]
    
    @pg.production('for : for line')
    def cont_for(state : ParserState,p):
        p[0].add_line(p[1])
        return p[0]
    
    @pg.production('line : for CLOSE_CURL')
    def end_for(state : ParserState,p):
        state.local_variables.pop(-1)
        return p[0]
    
    @pg.production('while : WHILE OPEN_PAREN expression CLOSE_PAREN OPEN_CURL')
    def open_while(state : ParserState,p):
        return state.get_while(p[2])
    
    @pg.production('while : while line')
    def cont_while(state : ParserState,p):
        p[0].add_line(p[1])
        return p[0]

    @pg.production('line : while CLOSE_CURL')
    def finish_while(state : ParserState,p):
        state.local_variables.pop(-1)
        return p[0]

    @pg.production('type : TYPE_NAME')
    def base_type(state,p):
        state.log('type : TYPE_NAME')
        type_name = p[0].value
        if type_name == "void":
            return aster.VoidType()
        if type_name == "float":
            return aster.FloatType()
        if type_name == "double":
            return aster.DoubleType()
        if type_name == "half":
            return aster.HalfType()
        if type_name == "char":
            return aster.IntType(8)
        if type_name == "short":
            return aster.IntType(16)
        if type_name == "int":
            return aster.IntType(32)
        if type_name == "long":
            return aster.IntType(64)
    
    @pg.production('type : type STAR')
    def pointer_type(state,p):
        state.log('type : type STAR')
        return aster.PointerType(p[0])

    @pg.production('type : CONST type')
    def const_type(state,p):
        state.log('type : CONST type')
        typ : aster.Type = p[1]
        typ.const = True
        return typ

    @pg.production('line : expression SEMI_COLON')
    def line(state,p):
        state.log('line : expression SEMI_COLON')
        return SimpleLine(p[0])
    
    @pg.production('line : RETURN expression SEMI_COLON')
    @pg.production('line : RETURN SEMI_COLON')
    def return_line(state : ParserState,p):
        if len(p) == 3:
            return ReturnLine(p[1])
        return ReturnLine()

    @pg.production('expression : OPEN_PAREN type CLOSE_PAREN expression')
    def cast(state : ParserState,p):
        state.log('expression : OPEN_PAREN type CLOSE_PAREN expression')
        return aster.Cast(p[1],p[3])

    @pg.production('expression : expression ASSIGN expression')
    def assign(state,p):
        state.log('expression : expression ASSIGN expression')
        return aster.Assign(p[0],p[2])

    @pg.production('expression : expression PLUS_EQUAL expression')
    @pg.production('expression : expression MINUS_EQUAL expression')
    @pg.production('expression : expression STAR_EQUAL expression')
    @pg.production('expression : expression SLASH_EQUAL expression')
    @pg.production('expression : expression PERCENT_EQUAL expression')
    def assign_incr(state : ParserState,p):
        ops = {"PLUS_EQUAL":"+","MINUS_EQUAL":"-","STAR_EQUAL":"*","SLASH_EQUAL":"/","PERCENT_EQUAL":"%"}
        op = ops[p[1].name]
        return aster.Assign(p[0],state.get_binop(op,p[0],p[2]))
    
    @pg.production('expression : OPEN_PAREN expression CLOSE_PAREN')
    def pass_expr(state,p):
        state.log('expression : OPEN_PAREN expression CLOSE_PAREN')
        return p[1]

    @pg.production('expression : NUMBER')
    def constant(state,p):
        state.log('expression : NUMBER')
        num_str = p[0].value
        if "." in num_str:
            return aster.Constant(aster.DoubleType(),num_str)
        return aster.Constant(aster.IntType(32),num_str)
    
    @pg.production('expression : CHAR')
    def constant(state,p):
        state.log('expression : CHAR')
        num_str = p[0].value
        return aster.Constant(aster.IntType(8),num_str)
    
    @pg.production('expression : FLOAT_LIT')
    @pg.production('expression : HALF_LIT')
    @pg.production('expression : LONG_LIT')
    @pg.production('expression : SHORT_LIT')
    def constant(state,p):
        state.log('expression : LIT')
        num_str = p[0].value[:-1]
        if p[0].name == "FLOAT_LIT":
            return aster.Constant(aster.FloatType(),num_str)
        if p[0].name == "HALF_LIT":
            return aster.Constant(aster.HalfType(),num_str)
        if p[0].name == "LONG_LIT":
            return aster.Constant(aster.IntType(64),num_str)
        if p[0].name == "SHORT_LIT":
            return aster.Constant(aster.IntType(16),num_str)
        
    @pg.production('expression : type IDENTIFIER')
    def declaration(state,p):
        return state.declare_variable(p[0],p[1].value)

    @pg.production('expression : IDENTIFIER')
    def variable(state,p):
        state.log('expression : IDENTIFIER')
        var_name = p[0].value
        return state.find_variable(var_name)
    
    @pg.production('expression : expression PLUS_PLUS')
    @pg.production('expression : expression MINUS_MINUS')
    def incr_decr_post(state : ParserState,p):
        state.log('expression : expression PLUS_PLUS|MINUS_MINUS')
        return aster.IncrPost(p[0],p[1].value)

    @pg.production('expression : PLUS_PLUS expression')
    @pg.production('expression : MINUS_MINUS expression')
    def incr_decr_pre(state : ParserState,p):
        state.log('expression : PLUS_PLUS|MINUS_MINUS expression')
        return aster.IncrPre(p[0],p[1].value)

    @pg.production('expression : expression OPEN_SQUARE expression CLOSE_SQUARE')
    def index(state,p):
        state.log('expression : expression OPEN_SQUARE expression CLOSE_SQUARE')
        return aster.Index(p[0],p[2])

    @pg.production('expression : THREAD PERIOD IDENTIFIER')
    def thread_idx(state,p):
        state.log('expression : THREAD PERIOD IDENTIFIER')
        return aster.ThreadIdx(p[2].value)

    @pg.production('expression : expression PLUS expression')
    @pg.production('expression : expression MINUS expression')
    @pg.production('expression : expression SLASH expression')
    @pg.production('expression : expression STAR expression')
    @pg.production('expression : expression PERCENT expression')
    @pg.production('expression : expression EQUAL expression')
    @pg.production('expression : expression NOT_EQUAL expression')
    @pg.production('expression : expression GREATER expression')
    @pg.production('expression : expression LESS expression')
    @pg.production('expression : expression GREATER_OR_EQUAL expression')
    @pg.production('expression : expression LESS_OR_EQUAL expression')
    @pg.production('expression : expression AND expression')
    @pg.production('expression : expression OR expression')
    @pg.production('expression : expression AMP expression')
    @pg.production('expression : expression VERT expression')
    @pg.production('expression : expression HAT expression')
    def binop(state,p):
        state.log('expression : expression OP expression')
        return state.get_binop(p[1].value,p[0],p[2])
    
    @pg.production('expression : NOT expression')
    @pg.production('expression : TILDE expression')
    def sinop(state : ParserState,p):
        state.log('expression : op expression')
        return state.get_sinop(p[0].value,p[1])
    
    @pg.production('expression : FUNCTION_NAME OPEN_PAREN CLOSE_PAREN')
    def empty_func_call(state,p):
        return state.get_func_call(p[0].value,[])

    @pg.production('func_call_open : FUNCTION_NAME OPEN_PAREN expression')
    def open_func_call(state : ParserState,p):
        return [p[0].value,p[2]]
    
    @pg.production('func_call_open : func_call_open COMMA expression')
    def cont_func_call(state : ParserState,p):
        return p[0] + [p[2]]
    
    @pg.production('expression : func_call_open CLOSE_PAREN')
    def func_call(state : ParserState,p):
        return state.get_func_call(p[0][0],p[0][1:])

    @pg.error
    def error_handler(state,token):
        print("ERROR AT",token,token.source_pos)
        exit()

    out = pg.build()
    #print(out.lr_table.sr_conflicts)
    return out