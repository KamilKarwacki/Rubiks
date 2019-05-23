#ifndef INCLUDE_CUBETREE_H_
#define INCLUDE_CUBETREE_H_

//	cube tree created by ForceSolver
//	has 8 children showcasing every move possible
//	when doing the cube
//
//
//

#include"cube.h"
#include<string>
class Cube;


class CubeTree{
public:
	CubeTree(int depth, Cube parentVal);
	~CubeTree();

	void InitChildren();
	void InitChildren(int maxDepth);
	void SearchChildren(int maxDepth, const Cube& target);

	void DFS(int maxDepth,const Cube& target);
	

public:
	Cube value;
	int depth;
	char name;

//------------
// Children
	CubeTree* L;
	CubeTree* Lprime;
	CubeTree* R;
	CubeTree* Rprime;
	CubeTree* U;
	CubeTree* Uprime;
	CubeTree* D;
	CubeTree* Dprime;
	CubeTree* B;
	CubeTree* Bprime;
	CubeTree* F;
	CubeTree* Fprime;
};





#endif // INCLUDE_CUBETREE_H_