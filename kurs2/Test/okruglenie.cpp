#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale.h>

using namespace std;

double f(double x, double y, double yProiz)
{
	return (exp(x) + y + yProiz) / 3;
}

int main()
{
	
	setlocale(LC_ALL,"RUS");
	
		
	double y[10000];
	double x1[10000];
	double x2[10000];
	
	double yProiz[10000];
	
	
	double y051[10000];
	double y052[10000];

	y[0]=1;
	yProiz[0]=1;
	x1[0]=0;
	x2[0]=0;

	
		int k=0;
	double t=50;
	double raz;
	double h1=0.1;
//	long double h1=0.2;
	double h2=0.05;
	double yOtv1[10000];
	double yOtv2[10000];
	double xOtv1[10000];
	double yProizOtv1[10000];
	double yProizOtv2[10000];
	
	double d1,d2;
		d1=1/h1;

cout<<"\t"<<"Äëÿ h = "<<h1<<endl;
cout<<endl;
cout<<setw(15)<<" y "<<setw(15)<<" y'"<<setw(15)<<" x "<<endl;
cout<<endl;
	
	while(k<d1)
	{
		k++;
		x1[k-1]=x2[k-1];

		y051[k]=y[k-1]+h1/2*yProiz[k-1];		
		y052[k]=yProiz[k-1]+h1/2*f(x2[k-1],y[k-1],yProiz[k-1]);

		
		x1[k]=x1[k-1]+h1/2;
		
		x2[k]=x2[k-1]+h1; 
		
		y[k]=y[k-1]+h1*y052[k];
		
		yProiz[k]=yProiz[k-1]+h1*f(x1[k],y051[k],y052[k]);
	//	cout<<setw(15)<<k<<setw(15)<<h1<<setw(15)<<y[k]<<setw(15)<<yProiz[k]<<setw(15)<<x2[k]<<setw(10)<<e<<endl;
		cout<<setw(15)<<y[k]<<setw(15)<<yProiz[k]<<setw(15)<<x2[k]<<endl;
		cout<<endl;
		yOtv1[k-1]=y[k];
		yProizOtv1[k-1]=yProiz[k];
		
		
	}

	cout<<endl;
	
	k=0;
	t=50;
	y[0]=1;
	yProiz[0]=1;
	x1[0]=0;
	x2[0]=0;

cout<<endl;
cout<<"\t"<<"Äëÿ h = "<<h2<<endl;
cout<<endl;

cout<<setw(15)<<" y "<<setw(15)<<" y'"<<setw(15)<<" x "<<endl;

d2=1/h2;

	double hB1;
	double hB2;

int i=0;
	//
	while(k<d2)
	{
		k++;
		x1[k-1]=x2[k-1];

		y051[k]=y[k-1]+h2/2*yProiz[k-1];
		y052[k]=yProiz[k-1]+h2/2*f(x2[k-1],y[k-1],yProiz[k-1]);
		
		x1[k]=x1[k-1]+h2/2;
		x2[k]=x2[k-1]+h2; 
		
		y[k]=y[k-1]+h2*y052[k];
		yProiz[k]=yProiz[k-1]+h2*f(x1[k],y051[k],y052[k]);
	//	cout<<setw(15)<<k<<setw(15)<<h2<<setw(15)<<y[k]<<setw(15)<<yProiz[k]<<setw(15)<<x2[k]<<setw(10)<<e<<endl;
	cout<<setw(15)<<y[k]<<setw(15)<<yProiz[k]<<setw(15)<<x2[k]<<setw(10)<<endl;
		cout<<endl;

	}
	
	
	//
	double e = 0.000001;	
	//
	double t1 = 1;
	double t2 = 1;
	
	double Otv1[2];
	double Otv2[2];
	
	h1=0.1;
	h2=0.05;
	cout<<setw(15)<<"h"<<setw(15)<<"x"<<setw(15)<<"y"<<setw(15)<<"y'"<<endl;
	cout<<endl;
	while (t1 >= e && t2 >= e)
	{
		
	double d;
	d=1/h1;
	double d1;
	d1=1/h2;
	//
	double x = 0;
	double x1 = 0;
	//
	double y[2];
	double y1[2];
	double yProiz[2];
	double yProiz1[2];
	double y051[2];
	double y0511[2];
	
	//
	double y0 = 1;
	double y01 = 1;
	double yProiz0 = 1;
	double yProiz01 = 1;
	//
	yProiz[0] = y0;
	yProiz[1] = yProiz0;

	for (int i = 0; i < d; i++)
	{

		
		y051[0] = yProiz[0] + (h1 / 2) * yProiz[1];
		y051[1] = yProiz[1] + (h1 / 2) * f(x, yProiz[0], yProiz[1]);
		y[0] = yProiz[0] + h1 * y051[1];
		y[1] = yProiz[1] + h1 * f(x + h1 / 2, y051[0], y051[1]);
		
		x = x + h1;
		yProiz[0] = y[0];
		yProiz[1] = y[1];
		hB1=h1;
		
	}
		cout<<setw(15)<<h1<<setw(15)<<x<<setw(15)<< y[0] << setw(15)<<y[1]<<endl;
		Otv1[0]=y[0];
		Otv1[1]=y[1];
			
	yProiz1[0] = y0;
	yProiz1[1] = yProiz0;
		for (int i = 0; i < d1; i++)
	{

	
		y0511[0] = yProiz1[0] + (h2 / 2) * yProiz1[1];
		y0511[1] = yProiz1[1] + (h2 / 2) * f(x1, yProiz1[0], yProiz1[1]);
		y1[0] = yProiz1[0] + h2 * y0511[1];
		y1[1] = yProiz1[1] + h2 * f(x1 + h2 / 2, y0511[0], y0511[1]);
		
		x1 = x1 + h2;
		yProiz1[0] = y1[0];
		yProiz1[1] = y1[1];
		hB2=h2;
	//	cout<<setw(15)<<h2<<setw(15)<<x<<setw(15)<< y[0] << setw(15)<<y[1]<<endl<<endl;
	}
		cout<<setw(15)<<h2<<setw(15)<<x<<setw(15)<< y1[0] << setw(15)<<y1[1]<<endl;
		Otv2[0]=y1[0];
		Otv2[1]=y1[1];
			
		t1 = abs(Otv1[0] - Otv2[0]);
		t2 = abs(Otv1[1] - Otv2[1]);
		h2 /= 2;
		h1 /= 2;
		cout<<endl;

	}
	
	
	return 0;
}
