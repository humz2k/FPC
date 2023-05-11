import os
import sys
sys.path.append(os.path.abspath("src"))
import fpcc

fpcc.compile_lib(["test.fpc"],"Metal","test_fpc.hpp",keep_temps=False)
