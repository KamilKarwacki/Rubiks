#ifndef INCLUDE_CUBE_H_
#define INCLUDE_CUBE_H_

//	cube class containing 6 sides
//	
//	utilities:
//		can be initialized with sides
//
//

#include "side.h"


class Cube{
public:
	Cube();
	Cube(const Cube& cube);
	~Cube();

	//needed for a solver to check if cube is equal to target
	bool operator==(const Cube& other) const;
	

	inline void setLeft(const Side& left_)  {left = left_;}
	inline void setRight(const Side& right_){right = right_;}
	inline void setUp(const Side& up_)      {up = up_;}
	inline void setDown(const Side& down_)  {down = down_;}
	inline void setFront(const Side& front_){front = front_;}
	inline void setBack(const Side& back_)  {back = back_;}

	void L();
	void Lprime();
	void R();
	void Rprime();
	void U();
	void Uprime();
	void F();
	void Fprime();
	void B();
	void Bprime();
	void D();
	void Dprime();

private:
	Side left;
	Side right;
	Side up;
	Side down;
	Side front;
	Side back;

	//Output manager does not modify only reads
	friend class OutputManager;
};


#endif // SRC_CUBE_H_