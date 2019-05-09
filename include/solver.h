#ifndef INCLUDE_SOLVER_H_
#define INCLUDE_SOLVER_H_

//	pure abstract solver class
//	owns a pointer to the initial cube and to the target
//
//
//
//

class Cube; 
class MoveList;

class Solver{
public:
	Solver(Cube* cube, Cube* target);
	virtual ~Solver(){};

	virtual void solve() = 0;
protected:
	Cube* cube;
	Cube* target;
	MoveList* list;
};

#endif // INCLUDE_SOLVER_H_