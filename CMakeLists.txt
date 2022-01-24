cmake_minimum_required(VERSION 3.1)

project(Rubiks VERSION 1.0
			   DESCRIPTION "algoritgms too solve 3x3 rubics cube"
			   LANGUAGES CXX)

add_library(rubiklib STATIC src/cube.cpp include/cube.h 
			   				src/CubeTree.cpp include/CubeTree.h
							src/side.cpp include/side.h
							src/EntropySolver.cpp include/EntropySolver.h
							src/ForceSolver.cpp include/ForceSolver.h
							src/OutputColor.cpp include/OutputColor.h
							
							src/Solver.cpp include/solver.h
							src/OutputManager.cpp include/OutputManager.h)

target_include_directories(rubiklib PUBLIC include)

add_executable(rubik src/main.cpp)
target_link_libraries(rubik PUBLIC rubiklib)


