SRC=./src/

all: Rubics

Rubics: main.o OutputManager.o side.o OutputColor.o cube.o
	g++ main.o OutputManager.o side.o OutputColor.o cube.o -o ./bin/Rubics

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

clean:
	rm *.o ./bin/Rubics


