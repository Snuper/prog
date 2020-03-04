#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

int func (int mas[], int i)
{
	if(i > 9){
		return 0;
	}
	if (mas[i] < 0)
	{ 
    cout<<mas[i]<<" ";
	func (mas, i + 1);
    }
    else if(mas[i] > 0)
    {
    	func(mas, i + 1);
		cout<<mas[i]<<" ";
	}
}


int main ()
{
    srand(time(NULL));
	int mas[10];
	for ( int i = 0; i < 10; i ++)
    {
          mas[i]= -50 + rand() % 100;
          if ( mas [i] == 0 )
             mas [i] = 1;
    }   
    for ( int i = 0; i < 10; i ++)
          cout<<mas[i]<<" ";
    cout<<endl;
	func(mas, 0);
	cout<<endl;
	
	system("PAUSE");
	return 0;
}
