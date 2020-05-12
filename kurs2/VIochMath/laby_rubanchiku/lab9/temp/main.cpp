#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>

using namespace std;
#define pi 3.1415926
int n;
double* a,*b;
double Function(double);

double A(int j)
{
double S=0;
int ii;
for (int i=-n;i<n+1;i++)
	{
	
	S=S+Function(2*pi*double(i)/(2*n+1))*cos(2*pi*double(j)*double(i)/(2*n+1));
	}
if (j==0) return 1/double(2*n+1)*S;

return 2/double(2*n+1)*S;
}

double B(int j)
{
int ii;
double S=0;
for (int i=-n;i<n+1;i++)
	{
	ii=-n+i;
	S=S+Function(2*pi*double(i)/double(2*n+1))*sin(2*pi*double(j*i)/double(2*n+1));
	}
return 2/double(2*n+1)*S;
}

double Function(double x)
{
	if (x<-1.5) return double(1);
	if (x>=-1.5 && x<1.6) return 0.5;
	return -0.333;
}

double Interpolate(double x)
{
double S=a[0];
for (int i=1;i<n;i++)
	{
	S=S+a[i]*cos(double(i)*x)+b[i]*sin(double(i)*x);
	}
return S;
}

int main()
{
double size;
cout << rand();
cout <<" Amount of interpolation units? ";
cin>>n;
cout<<" Size of result vector? ";
cin >>size;

//double* xj=new double[N];
cout <<n<<endl;
a=new double[n];
b=new double[n];

ofstream oo;
oo.open("result.txt");
oo<< size<<" "<<endl;
cout<<size<<endl;

oo<<" Коэффициенты a :"<<endl;
for (int j=0; j<n;j++)
{
a[j]=A(j);
oo<<a[j]<<endl;
}

oo<<" Коэффициенты b :"<<endl;
for (int j=1; j<n;j++)
{
b[j]=B(j);
oo<<b[j]<<endl;
}
double x;
oo<< "Координаты узлов  и значения в них"<<endl;
for (int j=0;j<size;j++)
	{
		x=-pi+2*pi/size*j;
		oo<<x<<"\t"<<Function(x)<<endl;
	}
oo<<" STOP "<<endl;
for (int j=0;j<size;j++)
	{
		x=-pi+2*pi/size*j;
		oo<<x<<"\t"<<Interpolate(x)<<endl;
	}
oo<< endl<<" Error "<<endl;
for (int j=0;j<400;j++)
	{
		x=-pi+2*pi/size*j;
		oo<<x<<"\t"<<Interpolate(x)-Function(x)<<endl;
	}

oo.close();
return 0;
}