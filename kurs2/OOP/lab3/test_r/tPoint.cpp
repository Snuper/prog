#include "Interface_class.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int day, month, years;
	cout<<"������� ������� ����, ����� � ���: "<<endl;
	cout<<endl<<"����: ";
	cin>>day;
	cout<<endl<<"�����: ";
	cin>>month;
	cout<<endl<<"���: ";
	cin>>years;
	tPoint objMessage;
	objMessage.Message();
	objMessage.setDate(day, month, years);
	objMessage.getDate();
	return 0;
}
