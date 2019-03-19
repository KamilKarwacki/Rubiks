#ifndef SRC_SIDE_H_
#define SRC_SIDE_H_ 

//	class of a 3x3 matrix
//	the side of a rubics cube
//	
//	utilities:
//		can be rotated clockwise or anti-clockwise
//		can be initialized with colors

#include<array>

class side{

private:
	enum colors{ white, yellow, green, blue, brown, orange };

public:
	side();
	~side();

	init(const std::array<int, 9> colors);

	TurnClock();
	TurnAntiClock();

private:
	std::array<int, 9> colors; 
}

#endif // SRC_SIDE_H_