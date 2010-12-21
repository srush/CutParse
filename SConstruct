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

sources = ["EisnerToHypergraph.cpp", "hypergraph.pb.cc", "features.pb.cc"]
sources2 = ["Viterbi.cpp", "hypergraph.pb.cc", "features.pb.cc"]
libs = ["pthread", "protobuf", "hypergraph"]
  
#SConscript(dirs=['hypergraph', 'lattice'], exports=['env'])
                                
env.Program('convert', sources, LIBS = libs, LIBPATH= ['.', '/home/srush/Projects/relax_decode/hypergraph'], CPPPATH = ['.'])
env.Program('viterbi', sources2, LIBS = libs, LIBPATH= ['.', '/home/srush/Projects/relax_decode/hypergraph'], CPPPATH = ['.', '/home/srush/Projects/transforest/svector/',  '/home/srush/Projects/hypergraph/gen_cpp/', '/home/srush/Projects/relax_decode/hypergraph'])

