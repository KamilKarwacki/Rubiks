#include<iostream>

#include"OutputColor.h"




std::ostream& operator<<(std::ostream& os, DisplayColor& dc)
{
	return os << "\033[" << static_cast<int>(dc) << "m";
}



// Display color has to have a specific number,
// but the sides and the cube are filled with integer from 0 to 5
// to keep the enum private for the side,
// this function converts from enum class color to enum class DisplayColor

DisplayColor converter(Color color){
	switch (color){
		case Color::red:
		return DisplayColor::BG_RED;
		case Color::green:
		return DisplayColor::BG_GREEN;
		case Color::yellow:
		return DisplayColor::BG_YELLOW;
		case Color::blue:
		return DisplayColor::BG_BLUE;
		case Color::orange:
		return DisplayColor::BG_ORANGE;
		case Color::white:
		return DisplayColor::BG_WHITE;	
	}
}
