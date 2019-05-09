#include"../include/ForceSolver.h"
#include"../include/cube.h"
#include"../include/CubeTree.h"
#include"../include/solver.h"

#include<iostream>

//--------------------------------
// constructor and destructor 
//--------------------------------
ForceSolver::ForceSolver(Cube* cube, Cube* target)
	: Solver(cube, target)
{ 
	this->root   = new CubeTree(0, *cube);
}

ForceSolver::~ForceSolver()
{
	delete root;
}

//--------------------------------
// solve 
//--------------------------------
// This brute force solver aims to solve the cube by
// creating a Tree of all Possible states of the cube 
// starting with the initial cube
// he checks each tree node to see 
// if the state matches the target
void ForceSolver::solve() 
{
	const int maxDepth = 6;

	// create tree up to a give deapth
	std::cout << "Initializing tree up to depth: " << maxDepth << std::endl;
	InitTree(maxDepth);

	// search for solution in this tree
	std::cout << "searching for a solution" << std::endl;
	SearchTree(maxDepth);

	// give the path
}

//--------------------------------
//  InitTree
//--------------------------------
//
//
void ForceSolver::InitTree(int maxDepth)
{
	// call recursive Function which will initialize children
	this->root->InitChildren(maxDepth);
}

//--------------------------------
// SearchTree 
//--------------------------------
//
//
void ForceSolver::SearchTree(int maxDepth)
{
	this->root->SearchChildren(maxDepth, *(target));
}