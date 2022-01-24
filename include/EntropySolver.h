#ifndef INCLUDE_ENTROPYSOLVER_H_
#define INCLUDE_ENTROPYSOLVER_H_

// Implementation of Solver Interface
//
//
//
//

#include"solver.h"
class Cube;

class EntropySolver : public Solver
{
public:
	EntropySolver(Cube start, Cube target);
	~EntropySolver();




};














#endif // INCLUDE_ENTROPYSOLVER_H_
