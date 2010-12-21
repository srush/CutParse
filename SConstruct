

import os
debug = ARGUMENTS.get('debug', 1)
profile = ARGUMENTS.get('profile', 0)
if int(debug):
  env = Environment(CC = 'g++',
                    CCFLAGS = '-g -Wall')
elif int(profile):
  env = Environment(CC = 'g++',
                    CCFLAGS = '-O2 -pg',
                    LINKFLAGS = '-O2 -pg')
else:
  env = Environment(CC = 'g++',
                    CCFLAGS = '-O3  -DNDEBUG',
                    LINKFLAGS = '-O3  -DNDEBUG')

sources = ["LPBuilder.cpp"]
libs = ["gurobi_g++4.1", "gurobi40", "dstruct", "pthread", "m", "stdc++"]
  
  
#SConscript(dirs=['hypergraph', 'lattice'], exports=['env'])
  
env.Program('parsecutlp', sources ,
            LIBS = libs, LIBPATH= [os.environ['GUROBI_HOME']+'/lib'],
            CPPPATH = ['.', os.environ['GUROBI_HOME']+'/include'])
               
