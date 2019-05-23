#include"../include/CubeTree.h"
#include"../include/cube.h"

#include<iostream>

//--------------------------------
// constructor and destructor 
//--------------------------------
CubeTree::CubeTree(int depth, Cube parentVal) 
	: value(parentVal), depth(depth){
}


CubeTree::~CubeTree()
{

}

//--------------------------------
// InitChildren 
//--------------------------------
//used for Force Solver gives RAM overflow
void CubeTree::InitChildren(int maxDepth)
{
	// this is recursive and has to return when
	// reached max depth
	if(depth == maxDepth) return;

	// create Children with the state of the parent
	L      = std::make_unique<CubeTree>(depth + 1, value);
	Lprime = std::make_unique<CubeTree>(depth + 1, value);
	R      = std::make_unique<CubeTree>(depth + 1, value);
	Rprime = std::make_unique<CubeTree>(depth + 1, value);
	F      = std::make_unique<CubeTree>(depth + 1, value);
	Fprime = std::make_unique<CubeTree>(depth + 1, value);
	U      = std::make_unique<CubeTree>(depth + 1, value);
	Uprime = std::make_unique<CubeTree>(depth + 1, value);
	D      = std::make_unique<CubeTree>(depth + 1, value);
	Dprime = std::make_unique<CubeTree>(depth + 1, value);
	B      = std::make_unique<CubeTree>(depth + 1, value);
	Bprime = std::make_unique<CubeTree>(depth + 1, value);

	// and then permute accordingly
	L->value.L();
	R->value.R();
	F->value.F();
	D->value.D();
	B->value.B();
	U->value.U();

	Lprime->value.Lprime();
	Rprime->value.Rprime();
	Fprime->value.Fprime();
	Dprime->value.Dprime();
	Bprime->value.Bprime();
	Uprime->value.Uprime();
	
	// perform recursive call,
	// now all children are intialized with the correct values
	L->InitChildren(maxDepth);
	R->InitChildren(maxDepth);
	U->InitChildren(maxDepth);
	B->InitChildren(maxDepth);
	D->InitChildren(maxDepth);
	F->InitChildren(maxDepth);

	Lprime->InitChildren(maxDepth);
	Rprime->InitChildren(maxDepth);
	Uprime->InitChildren(maxDepth);
	Bprime->InitChildren(maxDepth);
	Dprime->InitChildren(maxDepth);
	Fprime->InitChildren(maxDepth);
}

//--------------------------------
// SearchChildren 
//--------------------------------
//used for ForceSolver
void CubeTree::SearchChildren(int maxDepth, const Cube& target)
{
	if(depth == maxDepth) return;
	if(value == target){
		std::cout << "foud solution at depth "
			<< depth <<std::endl;
		return;
	}

	L->SearchChildren(maxDepth, target);
	R->SearchChildren(maxDepth, target);
	U->SearchChildren(maxDepth, target);
	D->SearchChildren(maxDepth, target);
	B->SearchChildren(maxDepth, target);
	F->SearchChildren(maxDepth, target);

	Lprime->SearchChildren(maxDepth, target);
	Rprime->SearchChildren(maxDepth, target);
	Uprime->SearchChildren(maxDepth, target);
	Dprime->SearchChildren(maxDepth, target);
	Bprime->SearchChildren(maxDepth, target);
	Fprime->SearchChildren(maxDepth, target);
}
 

//--------------------------------
// DFS
//--------------------------------
//
void CubeTree::DFS(int maxDepth, const Cube& target)
{

	if(depth == maxDepth){
		if(value  == target)
			std::cout << "solution found at depth "
						<< depth << std::endl;
		return;	
	}
	
	if(value == target){
		std::cout<< "solution found at depth " 
			<< depth << std::endl;
		return;
	}

	L = std::make_unique<CubeTree>(depth + 1, value);
	L->value.L();
	L->DFS(maxDepth, target);
	L.reset();

	R = std::make_unique<CubeTree>(depth + 1, value);
	R->value.R();
	R->DFS(maxDepth, target);
	R.reset();

	U = std::make_unique<CubeTree>(depth + 1, value);
	U->value.U();
	U->DFS(maxDepth, target);
	U.reset();

	D = std::make_unique<CubeTree>(depth + 1, value);
	D->value.D();
	D->DFS(maxDepth, target);
	D.reset();

	F = std::make_unique<CubeTree>(depth + 1, value);
	F->value.F();
	F->DFS(maxDepth, target);
	F.reset();

	B = std::make_unique<CubeTree>(depth + 1, value);
	B->value.B();
	B->DFS(maxDepth, target);
	B.reset();
}
