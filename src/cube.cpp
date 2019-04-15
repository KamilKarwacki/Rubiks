#include"../include/cube.h"

#include<algorithm>

//--------------------------------
// constructor and destructor 
//--------------------------------
Cube::Cube(){}

Cube::~Cube(){}

//--------------------------------
// operator ==
//--------------------------------
// is used by the solver to check if cube is solved
// starting from each side and checks if all colors are the same
bool Cube::operator==(const Cube& other) const 
{
	if(!(other.left == this->left))
		return false;
	if(!(other.right == this->right))
		return false;
	if(!(other.up == this->up))
		return false;
	if(!(other.down == this->down))
		return false;
	if(!(other.front == this->front))
		return false;
	if(!(other.back == this->back))
		return false;
	return true;
}

//--------------------------------
// Rotations
//--------------------------------

void Cube::L()
{
	// use permutation functionality defined in Side class
	left.TurnClock();

	// up side is used as a buffer
	std::swap(up.at(0), front.at(0));
	std::swap(up.at(3), front.at(3));
	std::swap(up.at(6), front.at(6));
	
	std::swap(up.at(0), down.at(0));
	std::swap(up.at(3), down.at(3));
	std::swap(up.at(6), down.at(6));
	
	std::swap(up.at(0), back.at(0));
	std::swap(up.at(3), back.at(3));
	std::swap(up.at(6), back.at(6));	
}

void Cube::Lprime()
{
	left.TurnAntiClock();

	// up side is used as a buffer
	std::swap(up.at(0), back.at(0));
	std::swap(up.at(3), back.at(3));
	std::swap(up.at(6), back.at(6));
	
	std::swap(up.at(0), down.at(0));
	std::swap(up.at(3), down.at(3));
	std::swap(up.at(6), down.at(6));
	
	std::swap(up.at(0), front.at(0));
	std::swap(up.at(3), front.at(3));
	std::swap(up.at(6), front.at(6));
}	

void Cube::R()
{
	// use permutation functionality defined in Side class
	right.TurnClock();

	// up side is used as a buffer
	std::swap(up.at(2), back.at(2));
	std::swap(up.at(5), back.at(5));
	std::swap(up.at(8), back.at(8));
	
	std::swap(up.at(2), down.at(2));
	std::swap(up.at(5), down.at(5));
	std::swap(up.at(8), down.at(8));
	
	std::swap(up.at(2), front.at(2));
	std::swap(up.at(5), front.at(5));
	std::swap(up.at(8), front.at(8));	
}

void Cube::Rprime()
{
	right.TurnAntiClock();

	// up side is used as a buffer
	std::swap(up.at(2), front.at(2));
	std::swap(up.at(5), front.at(5));
	std::swap(up.at(8), front.at(8));
	
	std::swap(up.at(2), down.at(2));
	std::swap(up.at(5), down.at(5));
	std::swap(up.at(8), down.at(8));
	
	std::swap(up.at(2), back.at(2));
	std::swap(up.at(5), back.at(5));
	std::swap(up.at(8), back.at(8));
}

void Cube::U()
{
	// use permutation functionality defined in Side class
	up.TurnClock();

	// front side is used as a buffer
	std::swap(front.at(0), left.at(0));
	std::swap(front.at(1), left.at(1));
	std::swap(front.at(2), left.at(2));
	
	std::swap(front.at(0), back.at(8));
	std::swap(front.at(1), back.at(7));
	std::swap(front.at(2), back.at(6));
	
	std::swap(front.at(0), right.at(0));
	std::swap(front.at(1), right.at(1));
	std::swap(front.at(2), right.at(2));	
}

void Cube::Uprime()
{
	// use permutation functionality defined in Side class
	up.TurnAntiClock();

	// front side is used as a buffer
	std::swap(front.at(0), right.at(0));
	std::swap(front.at(1), right.at(1));
	std::swap(front.at(2), right.at(2));
	
	std::swap(front.at(0), back.at(8));
	std::swap(front.at(1), back.at(7));
	std::swap(front.at(2), back.at(6));
	
	std::swap(front.at(0), left.at(0));
	std::swap(front.at(1), left.at(1));
	std::swap(front.at(2), left.at(2));	
}

void Cube::D()
{
	// use permutation functionality defined in Side class
	down.TurnAntiClock();

	// front side is used as a buffer
	std::swap(front.at(6), right.at(6));
	std::swap(front.at(7), right.at(7));
	std::swap(front.at(8), right.at(8));
	
	std::swap(front.at(6), back.at(2));
	std::swap(front.at(7), back.at(1));
	std::swap(front.at(8), back.at(0));
	
	std::swap(front.at(6), left.at(6));
	std::swap(front.at(7), left.at(7));
	std::swap(front.at(8), left.at(8));	
}

void Cube::Dprime()
{
	// use permutation functionality defined in Side class
	down.TurnClock();

	// front side is used as a buffer
	std::swap(front.at(6), left.at(6));
	std::swap(front.at(7), left.at(7));
	std::swap(front.at(8), left.at(8));
	
	std::swap(front.at(6), back.at(2));
	std::swap(front.at(7), back.at(1));
	std::swap(front.at(8), back.at(0));
	
	std::swap(front.at(6), right.at(6));
	std::swap(front.at(7), right.at(7));
	std::swap(front.at(8), right.at(8));	
}

void Cube::F()
{
	// use permutation functionality defined in Side class
	front.TurnClock();

	// up side is used as a buffer
	std::swap(up.at(6), right.at(0));
	std::swap(up.at(7), right.at(3));
	std::swap(up.at(8), right.at(6));
	
	std::swap(up.at(6), down.at(2));
	std::swap(up.at(7), down.at(1));
	std::swap(up.at(8), down.at(0));
	
	std::swap(up.at(6), left.at(8));
	std::swap(up.at(7), left.at(5));
	std::swap(up.at(8), left.at(2));
}

void Cube::Fprime()
{
	// use permutation functionality defined in Side class
	front.TurnAntiClock();

	// up side is used as a buffer
	std::swap(up.at(6), left.at(8));
	std::swap(up.at(7), left.at(5));
	std::swap(up.at(8), left.at(2));
	
	std::swap(up.at(6), down.at(2));
	std::swap(up.at(7), down.at(1));
	std::swap(up.at(8), down.at(0));
	
	std::swap(up.at(6), right.at(0));
	std::swap(up.at(7), right.at(3));
	std::swap(up.at(8), right.at(6));
}

void Cube::B()
{
	// use permutation functionality defined in Side class
	back.TurnClock();

	// up side is used as a buffer
	std::swap(up.at(0), left.at(6));
	std::swap(up.at(1), left.at(3));
	std::swap(up.at(2), left.at(0));
	
	std::swap(up.at(0), down.at(8));
	std::swap(up.at(1), down.at(7));
	std::swap(up.at(2), down.at(6));
	
	std::swap(up.at(0), right.at(2));
	std::swap(up.at(1), right.at(5));
	std::swap(up.at(2), right.at(8));	
}

void Cube::Bprime()
{
	// use permutation functionality defined in Side class
	back.TurnAntiClock();

	// up side is used as a buffer
	std::swap(up.at(0), right.at(2));
	std::swap(up.at(1), right.at(5));
	std::swap(up.at(2), right.at(8));
	
	std::swap(up.at(0), down.at(8));
	std::swap(up.at(1), down.at(7));
	std::swap(up.at(2), down.at(6));
	
	std::swap(up.at(0), left.at(6));
	std::swap(up.at(1), left.at(3));
	std::swap(up.at(2), left.at(0));	
}

