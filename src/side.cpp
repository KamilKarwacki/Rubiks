#include"side.h"


//--------------------------------
// constructor and destructor 
//--------------------------------
side::side(){}

side::~side(){}


//--------------------------------
// init 
//--------------------------------
void side::init(const std::array<side::color ,9> colors)
{
	for(int i = 0; i < 9; i++){
		this->colors[i] = colors[i];
	}
}


//--------------------------------
// TurnClock and TurnAntiClock
//--------------------------------
// permutes the elements clockwise
void TurnClock()
{
	color temp;

	// first temp will store the corners
	temp = colors.at(2);
	colors.at(2) = colors.at(0);

	colors.at(8) = temp;
	temp = colors.at(8);

	colors.at(6) = temp;
	temp = colors.at(6);

	colors.at(0) = temp;

	
	// now permute edges
	temp = colors.at(5);
	colors.at(5) = colors.at(1);

	temp = colors.at(7);
	colors.at(7) = temp;

	temp = colors.at(3);
	colors.at(3) = 
	
}