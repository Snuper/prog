#include <iostream>

using namespace std;

int main()
{
	int i=10, A[i];
	setlocale(LC_ALL, "RUS");
	cout<<"����: ";
	for (i=0;i<10;i++)
	{
		A[i]=i;
		printf("%d ",A[i]);
	}
	cout<<endl;
	cout<< "\n�������� ���������\n";
	cout<<"_ ";
	for (i=0;i<9;i++)
	{
		A[i]=i+1;
		printf("%d ",A[i]);
	}
	cout<<endl;
	cout<< "\n�������� 0 ��� ������\n";
	for (i=0;i<9;i++)
	{
		A[i]=i+1;
		printf("%d ",A[i]);
	}
	cout<<endl;
	cout<< "\n���������� ���������\n";
	cout<<"_ ";
	for (i=0;i<10;i++)
	{
		A[i]=i;
		printf("%d ",A[i]);
	}
	cout<<endl;
	cout<< "\n�������� 33 ��� ��������\n";
	cout<<"33 ";
	for (i=0;i<10;i++)
	{
		A[i]=i;
		printf("%d ",A[i]);
	}
	cout<<endl;
	cout<<endl;
	cout<<"_________________________________";
	cout<<endl;
	cout<<"�������:"<<endl;
	for (i=0;i<10;i++)
	{
		A[i]=i;
		printf("%d ",A[i]);
	}
	cout<<endl;
	cout<< "\n�������� ���������\n";
	cout<<"_ ";
	for (i=0;i<9;i++)
	{
		A[i]=i+1;
		printf("%d ",A[i]);
	}
	cout<<endl;
	cout<< "\n�������� 0 ��� ������\n";
	for (i=0;i<9;i++)
	{
		A[i]=i+1;
		printf("%d ",A[i]);
	}
	cout<<endl;
	cout<< "\n���������� ���������\n";
	for (i=0;i<10;i++)
	{
		A[i]=i;
		printf("%d ",A[i]);
	}
	cout<<"_ ";
	cout<< "\n�������� 33 ��� ��������\n";
	cout<<endl;
	for (i=0;i<10;i++)
	{
		A[i]=i;
		printf("%d ",A[i]);
	}
	cout<<"33 ";
}
