#include <iostream>
#include "Interface_class.h"

using namespace std;

void tPoint::Message()
	{
		cout<<"\nHelo world\n";
	}
	
void tPoint::setDate(int date_day, int date_month, int date_years)
	{
		day = date_day;
		month = date_month;
		years = date_years;
	}
	
void tPoint::getDate ()
	{
		printf("\nДата: %d.%d.%d", day, month, years);
	}
