#ifndef INCLUDE_OUTPUTMANAGER_H_
#define INCLUDE_OUTPUTMANAGER_H_

//	class which can display cube or side
//	graphically
//		
//
//
//

#include"OutputColor.h"
#include"side.h"
#include"cube.h"


//class Cube;
//	class Side;

class OutputManager{
public:

	OutputManager();
	~OutputManager();

	void setWidth(int width){ this->width = width; }

	void print(Side& side);
	void print(Cube& cube);

private:
	// width=1 means that a color will be 1 space wide
	int width;
};



#endif 