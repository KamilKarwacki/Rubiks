#include"OutputColor.h"
#include"OutputManager.h"
#include"side.h"
#include"cube.h"
#include"ForceSolver.h"

#include<iostream>


int main(){

	Side left(Color::red), right(Color::orange),
	 	 up(Color::yellow), down(Color::white),
	 	 front(Color::green), back(Color::blue); 
	OutputManager manager;

	Cube target;
	
	
	target.setLeft(left);
	target.setRight(right);
	target.setUp(up);
	target.setDown(down);
	target.setFront(front);
	target.setBack(back);

	
	Cube start(target);

	
	start.Uprime();
	start.Dprime();
	start.Lprime();
	start.Rprime();
	start.Dprime();

		
	manager.print(target);
	manager.print(start);

	// solving part
	ForceSolver Fsolver(start, target);
	Fsolver.DFS(8);
		
	return 0;
}



