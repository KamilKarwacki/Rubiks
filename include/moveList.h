#ifndef INCLUDE_MOVELIST_H_
#define INCLUDE_MOVELIST_H_

//	wrapper around vector class 
//	used to store moves
//
//
//
//

#include<vector>

class moveList{

private:
	//left left' right right' ....
	enum class Move{L,Lp,R,Rp,U,Up,D,Dp,F,Fp,B,Bp};

public:
	moveList();
	~moveList();
	
	void append(Move move);
	void display();

private:
	std::vector<Move> list;
}

#endif // INCLUDE_MOVELIST_H_