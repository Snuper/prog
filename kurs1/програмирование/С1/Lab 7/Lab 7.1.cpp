#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  
  float a = 2.14, b = -4.21, c = 3.25, x1 = -4.5, x2 = -33.5, h = -0.5, x, p;
  int n, i, j;
  n = (x2 + x1 )/ h;
  float A[n];
  for (i = 0; x >= x2; x += h, i++)
  {
  	A[i] = a*pow(x,2)*sin(x)+b*x+c;
  }
  for (i = 0; i < n-1; i++)
  {
  	for(j = n - 2;j >= i; j--)
  	{
  		if(A[j] < A[j+1])
  		{
  			p = A[j];
  			A[j] = A[j+1];
  			A[j+1] = p;
		}
	}
	printf("sort mas %f\n", A[i]);
  }
  system("PAUSE");
  return 0;
}

