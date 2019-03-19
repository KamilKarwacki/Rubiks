#ifndef SRC_CUBE_H_
#define SRC_CUBE_H_

//	cube class containing 6 sides
//	
//	utilities:
//		can be initialized with sides
//
//

#include "side.h"

class cube{

public:
	cube();
	~cube();


private:
	side left;
	side right;
	side up;
	side bottom;
	side front;
	side back;
}


#endif // SRC_CUBE_H_