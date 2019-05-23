#ifndef INCLUDE_FORCESOLVER_H_
#define INCLUDE_FORCESOLVER_H_

//	pure abstract solver class
//	owns a pointer to the initial cube and to the target
//
//
//
//

#include"solver.h"

class CubeTree;
class Cube;

class ForceSolver : public Solver
{
public:
	ForceSolver(Cube* cube, Cube* target);
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
