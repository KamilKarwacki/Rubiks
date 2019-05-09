#include"../include/CubeTree.h"
#include"../include/cube.h"

#include<iostream>

//--------------------------------
// constructor and destructor 
//--------------------------------


CubeTree::CubeTree(int depth, Cube parentVal) 
	:value(parentVal), depth(depth), visited(false){
	L = nullptr; Lprime = nullptr;
	R = nullptr; Rprime = nullptr;
	U = nullptr; Uprime = nullptr;
	D = nullptr; Dprime = nullptr;
	B = nullptr; Bprime = nullptr;
	F = nullptr; Fprime = nullptr;
}

CubeTree::~CubeTree()
{
	if(L != nullptr) delete L;
	if(R != nullptr) delete R;
	if(U != nullptr) delete U;
	if(B != nullptr) delete B;
	if(D != nullptr) delete D;
	if(F != nullptr) delete F;
	
	if(Lprime != nullptr) delete Lprime;
	if(Rprime != nullptr) delete Rprime;
	if(Uprime != nullptr) delete Uprime;
	if(Bprime != nullptr) delete Bprime;
	if(Dprime != nullptr) delete Dprime;
	if(Fprime != nullptr) delete Fprime;
}

//--------------------------------
// InitChildren 
//--------------------------------
//
void CubeTree::InitChildren(int maxDepth)
{
	// this is recursive and has to return when
	// reached max depth
	if(depth == maxDepth) return;

	// create Children with the state of the parent
	L      = new CubeTree(depth + 1, value);
	Lprime = new CubeTree(depth + 1, value);
	R      = new CubeTree(depth + 1, value);
	Rprime = new CubeTree(depth + 1, value);
	F      = new CubeTree(depth + 1, value);
	Fprime = new CubeTree(depth + 1, value);
	U      = new CubeTree(depth + 1, value);
	Uprime = new CubeTree(depth + 1, value);
	D      = new CubeTree(depth + 1, value);
	Dprime = new CubeTree(depth + 1, value);
	B      = new CubeTree(depth + 1, value);
	Bprime = new CubeTree(depth + 1, value);

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
//
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
 