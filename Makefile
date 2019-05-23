SRC=./src/

all: Rubics

#warnings and cppcheck
WARN=-Wpedantic -Wall -Wextra
OPT=-O3

Release: main.o OutputManager.o side.o OutputColor.o cube.o CubeTree.o Solver.o ForceSolver.o
	g++ -fno-rtti main.o OutputManager.o side.o OutputColor.o cube.o CubeTree.o Solver.o ForceSolver.o -o ./bin/Rubics

Debug: main_d.o OutputManager_d.o side_d.o OutputColor_d.o cube_d.o CubeTree_d.o Solver_d.o ForceSolver_d.o
	g++ -fno-rtti main.o OutputManager.o side.o OutputColor.o cube.o CubeTree.o Solver.o ForceSolver.o -o ./bin/Rubics


main.o: $(SRC)main.cpp
	g++ ${WARN} ${OPT} -c $(SRC)main.cpp

OutputManager.o:$(SRC)OutputManager.cpp
	g++ ${WARN} ${OPT} -c $(SRC)OutputManager.cpp

OutputColor.o:$(SRC)OutputColor.cpp
	g++ ${WARN} ${OPT} -c $(SRC)OutputColor.cpp

side.o:$(SRC)side.cpp
	g++ ${WARN} ${OPT} -c $(SRC)side.cpp

cube.o:$(SRC)cube.cpp
	g++ ${WARN} ${OPT} -c $(SRC)cube.cpp

CubeTree.o:$(SRC)CubeTree.cpp
	g++ ${WARN} ${OPT} -c $(SRC)CubeTree.cpp

Solver.o:$(SRC)Solver.cpp
	g++ ${WARN} ${OPT} -c $(SRC)Solver.cpp

ForceSolver.o:$(SRC)ForceSolver.cpp
	g++ ${WARN} ${OPT} -c $(SRC)ForceSolver.cpp

#############################################
#                  DEBUG
#############################################

main_d.o: $(SRC)main.cpp
	g++ ${WARN} -c $(SRC)main.cpp

OutputManager_d.o:$(SRC)OutputManager.cpp
	g++ ${WARN} -c $(SRC)OutputManager.cpp

OutputColor_d.o:$(SRC)OutputColor.cpp
	g++ ${WARN} -c $(SRC)OutputColor.cpp

side_d.o:$(SRC)side.cpp
	g++ ${WARN} -c $(SRC)side.cpp

cube_d.o:$(SRC)cube.cpp
	g++ ${WARN} -c $(SRC)cube.cpp

CubeTree_d.o:$(SRC)CubeTree.cpp
	g++ ${WARN} -c $(SRC)CubeTree.cpp

Solver_d.o:$(SRC)Solver.cpp
	g++ ${WARN} -c $(SRC)Solver.cpp

ForceSolver_d.o:$(SRC)ForceSolver.cpp
	g++ ${WARN} -c $(SRC)ForceSolver.cpp

clean:
	rm *.o ./bin/Rubics


