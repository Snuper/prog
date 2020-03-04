#include <iostream>

using namespace std;

int main()
{
	int i=10, A[i];
	setlocale(LC_ALL, "RUS");
	cout<<"Стек: ";
	for (i=0;i<10;i++)
	{
		A[i]=i;
		printf("%d ",A[i]);
	}
	cout<<endl;
	cout<< "\nудаление эллемента\n";
	cout<<"_ ";
	for (i=0;i<9;i++)
	{
		A[i]=i+1;
		printf("%d ",A[i]);
	}
	cout<<endl;
	cout<< "\nэллемент 0 был удален\n";
	for (i=0;i<9;i++)
	{
		A[i]=i+1;
		printf("%d ",A[i]);
	}
	cout<<endl;
	cout<< "\nдобавление эллемента\n";
	cout<<"_ ";
	for (i=0;i<10;i++)
	{
		A[i]=i;
		printf("%d ",A[i]);
	}
	cout<<endl;
	cout<< "\nэллемент 33 был добавлен\n";
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
	cout<<"Очередь:"<<endl;
	for (i=0;i<10;i++)
	{
		A[i]=i;
		printf("%d ",A[i]);
	}
	cout<<endl;
	cout<< "\nудаление эллемента\n";
	cout<<"_ ";
	for (i=0;i<9;i++)
	{
		A[i]=i+1;
		printf("%d ",A[i]);
	}
	cout<<endl;
	cout<< "\nэллемент 0 был удален\n";
	for (i=0;i<9;i++)
	{
		A[i]=i+1;
		printf("%d ",A[i]);
	}
	cout<<endl;
	cout<< "\nдобавление эллемента\n";
	for (i=0;i<10;i++)
	{
		A[i]=i;
		printf("%d ",A[i]);
	}
	cout<<"_ ";
	cout<< "\nэллемент 33 был добавлен\n";
	cout<<endl;
	for (i=0;i<10;i++)
	{
		A[i]=i;
		printf("%d ",A[i]);
	}
	cout<<"33 ";
}
