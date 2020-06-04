#       Knapsack
#       Author: Przybysz Filip
#

print('..Building App')

binFolder = '#bin/'

pathToFiles = [
    'src'
]

import sys
import os

if sys.platform.startswith('linux'):
    env = Environment(
        CC = 'g++',
        CCFLAGS = '-O2 -Wall -g',
        SCONS_CXX_STANDARD='c++11',
        CPPPATH = pathToFiles
    )
    env.PrependENVPath('PATH', os.environ['PATH'])

elif sys.platform.startswith('win'):
    env = Environment(
        CC = 'CL.exe',
        CCFLAGS = '-O2 -EHsc -MD',
        SCONS_CXX_STANDARD='c++11',
        CPPPATH = pathToFiles
    )
    env.PrependENVPath('PATH', os.environ['PATH'])

else:
    print( 'Unsupported OS. Exiting.')
    Exit(1)

SConscript('src/SConscript', exports = 'env', variant_dir = binFolder, duplicate = 0)

env.Append(
    LIBS = [
        'knapsack'
    ],

    LIBPATH = binFolder

)

env.Program(target = 'Knapsack', source = 'src/Knapsack.cpp')
