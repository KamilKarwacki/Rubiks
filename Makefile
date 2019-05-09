SRC=./src/

all: Rubics

Rubics: main.o OutputManager.o side.o OutputColor.o cube.o CubeTree.o Solver.o ForceSolver.o
	g++ -fno-rtti main.o OutputManager.o side.o OutputColor.o cube.o CubeTree.o Solver.o ForceSolver.o -o ./bin/Rubics

main.o: $(SRC)main.cpp
	g++ -c $(SRC)main.cpp

OutputManager.o:$(SRC)OutputManager.cpp
	g++ -c $(SRC)OutputManager.cpp

OutputColor.o:$(SRC)OutputColor.cpp
	g++ -c $(SRC)OutputColor.cpp

side.o:$(SRC)side.cpp
	g++ -c $(SRC)side.cpp

cube.o:$(SRC)cube.cpp
	g++ -c $(SRC)cube.cpp

CubeTree.o:$(SRC)CubeTree.cpp
	g++ -c $(SRC)CubeTree.cpp

Solver.o:$(SRC)Solver.cpp
	g++ -c $(SRC)Solver.cpp

ForceSolver.o:$(SRC)ForceSolver.cpp
	g++ -c $(SRC)ForceSolver.cpp

clean:
	rm *.o ./bin/Rubics


