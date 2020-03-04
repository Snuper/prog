#include "Interface_class.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int day, month, years;
	cout<<"¬ведите текущий день, мес€ц и год: "<<endl;
	cout<<endl<<"ƒень: ";
	cin>>day;
	cout<<endl<<"ћес€ц: ";
	cin>>month;
	cout<<endl<<"√од: ";
	cin>>years;
	tPoint objMessage;
	objMessage.Message();
	objMessage.setDate(day, month, years);
	objMessage.getDate();
	return 0;
}
