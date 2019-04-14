#ifndef INCLUDE_OUTPUTCOLOR_H_
#define INCLUDE_OUTPUTCOLOR_H_

//	overloading output stream operator
//	
//		
//
//
//

#include<iosfwd>


enum class Color{ red, green, yellow, blue, orange, white };
enum class DisplayColor{
	BG_RED    = 41,
	BG_GREEN  = 42,
	BG_YELLOW = 43,
	BG_BLUE   = 44,
	BG_ORANGE = 104,
	BG_WHITE  = 107,
	RESET     = 0,
};


std::ostream& operator<<(std::ostream& os, DisplayColor& dc);
DisplayColor converter(Color color);

#endif 