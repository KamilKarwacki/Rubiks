#ifndef INCLUDE_FORCESOLVER_H_
#define INCLUDE_FORCESOLVER_H_

//	Implementation of Solver Interface,
//	In addition to start and Target it owns a CubeTree
//	
//	Two solution methods are implemented
//	brute force solve method which is too memory consuming
//	and can only solve up to a layer of 6
//  and a depth first search

#include"solver.h"

class CubeTree;
class Cube;

class ForceSolver : public Solver
{
public:
	ForceSolver(Cube cube, Cube target);
	~ForceSolver();

// main interface point 
	void solve() override;

	void DFS(int maxDepth);
// private member functs
private:
	void InitTree(int maxDepth);
	void SearchTree(int maxDepth);
// private member variables
private:
	CubeTree* root;
	
};

#endif // INCLUDE_SOLVER_H_
