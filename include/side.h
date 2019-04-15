#ifndef INCLUDE_SIDE_H_
#define INCLUDE_SIDE_H_ 

//	class of a 3x3 matrix
//	the side of a rubics cube
//	
//	utilities:
//		can be rotated clockwise or anti-clockwise
//		can be initialized with colors

#include <array>
#include"OutputColor.h"

//class Cube;

class Side{
public:
	Side();
	Side(Color color);
	~Side();

	void init(std::array<Color, 9> &colors);

	bool operator==(const Color color) const;
	bool operator==(const Side& other) const;
	
	inline Color& at(int i) {return colors.at(i);}
	
private: // only used by cube
	void TurnClock();
	void TurnAntiClock();

private:
	std::array<Color, 9> colors; 
	friend class Cube;
};

#endif // SRC_SIDE_H_
