#ifndef SQUARE_H
#define SQUARE_H

#include "Interface_point.h"
class Square : public Figure
{
	public:
		Square(float w_x, float h_x)
		{
			w = w_x;
			h = h_x;
		}
		Square()
		{
			w = 1;
			h = 3;
		}
		void Move_where(float ping);
		void Create_figure();
	protected:
};

#endif
