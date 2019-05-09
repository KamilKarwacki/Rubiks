#include"../include/OutputManager.h"
#include"../include/OutputColor.h"
#include<iostream>
#include<string>
#include<array>


//--------------------------------
// constructor and destructor 
//--------------------------------
OutputManager::OutputManager(){width = 1;}
OutputManager::~OutputManager(){}

//--------------------------------
// printSide
//--------------------------------
// reset object needed to reset the colors to normal
// after printing the side

void OutputManager::print(Side& side) 
{
	DisplayColor reset = DisplayColor::RESET; 
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			DisplayColor mode = converter(side.at(i*3 + j));
			std::cout << mode << " ";
		}
	std::cout << reset << std::endl;
	}

	//reset the colors
	std::cout << reset << std::endl;
}

//--------------------------------
// printCube
//--------------------------------
// uses the function printSide to print every side of
// a rubics cube, also displays information about the 
// side which is printed

void OutputManager::print(Cube& cube) 
{
	std::array<std::string,6> names = {std::string("up"),
							 std::string("front"),
							 std::string("left"),
							 std::string("right"),
							 std::string("back"),
							 std::string("bottom") };

	Side sides[6] = {cube.up, cube.front,
					  cube.left, cube.right,
					  cube.back, cube.down};


	for(int i = 0; i < 6; i++){
		std::cout << names[i] << std::endl;
		print(sides[i]);
		std::cout << std::endl;
	}

}