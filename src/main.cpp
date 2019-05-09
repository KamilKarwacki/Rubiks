#include"../include/OutputColor.h"
#include"../include/OutputManager.h"
#include"../include/side.h"
#include"../include/cube.h"
#include"../include/ForceSolver.h"

#include<iostream>


int main(){

	Side left(Color::red), right(Color::orange),
	 	 up(Color::yellow), down(Color::white),
	 	 front(Color::green), back(Color::blue); 
	OutputManager manager;

	Cube* target = new Cube;
	

	
	target->setLeft(left);
	target->setRight(right);
	target->setUp(up);
	target->setDown(down);
	target->setFront(front);
	target->setBack(back);

	
	Cube* start = new Cube(*target);

	
	start->U();
	start->L();
	start->R();
	start->D();
	start->R();
	
	
		
	manager.print(*target);
	manager.print(*start);

	// solving part
	ForceSolver Fsolver(start, target);
	Fsolver.solve();

	return 0;
}



