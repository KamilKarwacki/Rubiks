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
#include<memory>

class Cube;


class CubeTree{
public:
	CubeTree(int depth, Cube parentVal);
	~CubeTree();

	void InitChildren(int maxDepth);
	void SearchChildren(int maxDepth, const Cube& target);

	void DFS(int maxDepth,const Cube& target);
	

public:
	Cube value;
	int depth;
	char name;

//------------
// Children
	std::unique_ptr<CubeTree> L;
	std::unique_ptr<CubeTree> Lprime;
	std::unique_ptr<CubeTree> R;
	std::unique_ptr<CubeTree> Rprime;
	std::unique_ptr<CubeTree> U;
	std::unique_ptr<CubeTree> Uprime;
	std::unique_ptr<CubeTree> D;
	std::unique_ptr<CubeTree> Dprime;
	std::unique_ptr<CubeTree> B;
	std::unique_ptr<CubeTree> Bprime;
	std::unique_ptr<CubeTree> F;
	std::unique_ptr<CubeTree> Fprime;
};





#endif // INCLUDE_CUBETREE_H_