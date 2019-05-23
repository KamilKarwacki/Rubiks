#include"../include/solver.h"
#include"../include/cube.h"


Solver::Solver(Cube* cube, Cube* target)
{
	this->target = new Cube(*target);
	this->cube   = new Cube(*cube);
}

Solver::~Solver()
{
	delete this->target;
	delete this->cube;
}