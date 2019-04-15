#include"../include/side.h"

// for std::swap(a,b)
#include<algorithm> 


//--------------------------------
// constructor and destructor 
//--------------------------------
Side::Side(){}

// homogeneous fill
Side::Side(Color color)
{
	for(int i = 0; i < 9; i++){
		this->colors[i] = color;
	}	
}

Side::~Side(){}

//--------------------------------
// init 
//--------------------------------
void Side::init(std::array<Color ,9> &colors)
{
	for(int i = 0; i < 9; i++){
		this->colors[i] = colors[i];
	}
}

//--------------------------------
// operator==
//--------------------------------
//checks if side is filled homogeneously
bool Side::operator==(const Color color) const
{
	for(int i = 0; i < 9; i++)
		if(this->colors.at(i) != color)
			return false;
	return true;
}

bool Side::operator==(const Side& other) const
{
	for(int i = 0; i < 9; i++)
		if(this->colors.at(i) != other.colors.at(i))
			return false;
	return true;
}

//--------------------------------
// TurnClock and TurnAntiClock
//--------------------------------
void Side::TurnClock()
{
	// 0 location acts like a buffer
	std::swap(colors.at(0), colors.at(2));
	std::swap(colors.at(0), colors.at(8));
	std::swap(colors.at(0), colors.at(6));
	
	// now permute edges
	std::swap(colors.at(1), colors.at(5));
	std::swap(colors.at(1), colors.at(7));
	std::swap(colors.at(1), colors.at(3));	
}

void Side::TurnAntiClock()
{
	std::swap(colors.at(0), colors.at(6));
	std::swap(colors.at(0), colors.at(8));
	std::swap(colors.at(0), colors.at(2));
	
	// now permute edges
	std::swap(colors.at(1), colors.at(3));
	std::swap(colors.at(1), colors.at(7));
	std::swap(colors.at(1), colors.at(5));
}