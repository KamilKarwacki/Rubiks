#include"../include/OutputColor.h"
#include"../include/OutputManager.h"
#include"../include/side.h"
#include"../include/cube.h"

#include<iostream>


int main(){

	Side left(Color::red), right(Color::orange),
	 	 up(Color::yellow), down(Color::white),
	 	 front(Color::green), back(Color::blue); 
	OutputManager outputManager;

	Cube cube;

	cube.setLeft(left);
	cube.setRight(right);
	cube.setUp(up);
	cube.setDown(down);
	cube.setFront(front);
	cube.setBack(back);

	outputManager.print(cube);
	cube.B();
	outputManager.print(cube);
		

	return 0;
}



