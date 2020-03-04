#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	int bes;
	int N, variant;
	printf("input N: "); // massiv i tochnost`
	scanf("%d",&N);
	float a , b , h, M[N], x, form1 = 0, form2 = 0, f1_form2 = 0, f2_form2 = 0, f3_form2 = 0;
	int i;
			a = -2;
			b = 5;
			x = a;
			h = (b - a) / N; // hod raven
			for(i = 0; i < N ; i++)
			{
				M[i] = pow(x,2)/(10+pow(x,3));
				printf("M[%d] = %f\n", i, M[i]);
				x += h;	
			}
    for(i = 0;i < N; i++) //formula 1 trap
	{
		if (i == 0 or i == N - 1)
		{
			form1 += M[i]/2;
		}
		else
		{
			form1 += M[i];
		}
	}
	form1 *= h;
	for(i = 0;i < N; i++) //formula 2 Simpson
	{
		if ( i == 0 or i == N - 1)
		{
			f1_form2 += M[i];
		}
		else if ( i % 2 != 0 )
		{
			f2_form2 += M[i];
		}
		else if (i % 2 == 0)
		{
			f3_form2 += M[i];
		}
	}
	form2 = (h / 3) * (f1_form2 + 4 * f2_form2 + 2 * f3_form2);
	printf("Formula trapeciy = %f \nFormula Simpsona = %f\n", form1, form2);
	system("PAUSE");
	return 0;
}
