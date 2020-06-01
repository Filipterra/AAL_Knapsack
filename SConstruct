print('..Building App')

pathToFiles = [
    'src'
]


env = Environment(
    CC = 'g++',
    CCFLAGS = '-Wall -g',
    SCONS_CXX_STANDARD='c++11',
    CPPPATH = pathToFiles  
)

env.Program(target = 'Knapsack', source = 'src/Knapsack.cpp')
