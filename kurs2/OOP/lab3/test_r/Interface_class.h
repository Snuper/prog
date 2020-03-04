#include "Silent_class.cpp"

using namespace std;

class tPoint
{
	private:
		int day, month, years;
	public:
		void Message();
		void setDate(int date_day, int date_month, int date_years);
		void getDate ();
};
