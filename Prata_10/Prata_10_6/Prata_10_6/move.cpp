#include <iostream>
#include "move.h"

Move::Move(double a = 0, double b = 0)
{
	x = a;
	y = b;
}

void Move::ShowMove() const
{
	if (this->x == 0 && this->y == 0)
	{
		std::cout << "You are at the begining of coordinate." << std::endl;
	}
	else
	{
		std::cout << "Look at this locate:" << std::endl;
		std::cout << "x: " << x << std::endl;
		std::cout << "y: " << y << std::endl;
	}
}

Move Move::add(const Move& m) const
{
	return Move(x + m.x, y + m.y);
}

void Move::Reset(double a = 0, double b = 0)
{
	x = a;
	y = b;
}