#ifndef INCLUDE_SOLVER_H_
#define INCLUDE_SOLVER_H_

//	abstract solver class
//
//
//
//
//

#include "cube.h"

class solver{

public:
	solver();
	virtual ~solver();

	void solve();
private:
	cube* p_cube;
}

#endif // INCLUDE_SOLVER_H_