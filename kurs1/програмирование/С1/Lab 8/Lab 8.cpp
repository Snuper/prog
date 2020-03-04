#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	int bes;
	
	do //beskonech
	{
	int N, variant;
	
	do //variant
	{
	printf("choose variant: ");
	scanf("%d",&variant);
	}	while(variant < 1 or variant > 12 );
	
	printf("input N: "); // massiv i tochnost`
	scanf("%d",&N);
	
	float a , b , h, M[N], x, form1 = 0, form2 = 0, f1_form2 = 0, f2_form2 = 0, f3_form2 = 0;
	int i;
	
	
	
	switch(variant)
	{
		case 1:
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
			break;
		case 2:
			a = 4;
			b = 6;
			x = a;
			h = (b - a) / N; // hod raven
			for(i = 0; i < N ; i++)
			{
				M[i] = (2.5 * pow(x,2) - 0.1) / (tan(x) + sin(x));
				printf("M[%d] = %f\n", i, M[i]);
				x += h;
			}
			break;
		case 3:
		{
			a = 2;
			b = 10;
			x = a;
			h = (b - a) / N; // hod raven
			for(i = 0; i < N; i++)
			{

				M[i] = pow((x + 1),2) * sqrt(log10(x));
				printf("M[%d] = %f\n", i, M[i]);
				x += h;
			}
			break;
		}
		case 4:
		{
			a = 1;
			b = 20;
			x = a;
			h = (b - a) / N; // hod raven
			for(i = 0; i < N; i++)
			{

				M[i] = (pow(x,2) * log(x)) / pow((1+x),2);
				printf("M[%d] = %f\n", i, M[i]);
				x += h;
			}
			break;
		}
		case 5:
		{
			a = 0.1;
			b = 2.1;
			x = a;
			h = (b - a) / N; // hod raven
			for(i = 0; i < N; i++)
			{
				M[i] = 1 / (0.5 + 0.1 * pow(x,3) * sqrt(x));
				printf("M[%d] = %f\n", i, M[i]);
				x += h;
			}
			break;
		}
		case 6:
		{
			a = 0.5;
			b = 2.5;
			x = a;
			h = (b - a) / N; // hod raven
			for(i = 0; i < N; i++)
			{
				M[i] = pow(x,2) * sqrt(pow((2 + 3 * x),3));
				printf("M[%d] = %f\n", i, M[i]);
				x += h;
			}
			break;
		}
		case 7:
		{
			a = 1;
			b = 30;
			x = a;
			h = (b - a) / N; // hod raven
			for(i = 0; i < N; i++)
			{
				M[i] = 1 / sqrt(0.02 + 0.01 * x);
				printf("M[%d] = %f\n", i, M[i]);
				x += h;
			}
			break;
		}
		case 8:
		{
			a = -2;
			b = 2;
			x = a;
			h = (b - a) / N; // hod raven
			for(i = 0; i < N; i++)
			{
				M[i] = (1 + 2 * x + pow(x,2)) / (5 + 2 * pow(x,2));
				printf("M[%d] = %f\n", i, M[i]);
				x += h;
			}
			break;
		}
		case 9:
		{
			a = 1;
			b = 10;
			x = a;
			h = (b - a) / N; // hod raven
			for(i = 0; i < N ; i++)
			{
				M[i] = (2 * x + log10(x)) / (1 + log10(x));
				printf("M[%d] = %f\n", i, M[i]);
				x += h;
			}
			break;
		}
		case 10:
		{
			a = 0.2;
			b = 10;
			x = a;
			h = (b - a) / N; // hod raven
			for(i = 0; i < N; i++)
			{
				M[i] = sqrt(pow((2 + x),3)) / pow(x,2);
				//printf("M[%d] = %f\n", i, M[i]);
				x += h;
			}
			break;
		}
		case 11:
		{
			a = 0.5;
			b = 5;
			x = a;
			h = (b - a) / N; // hod raven
			for(i = 0; i < N; i++)
			{
				M[i] = (1 + pow(x,2)) / (pow(x,3) + sqrt(1 + x));
				printf("M[%d] = %f\n", i, M[i]);
				x += h;
			}
			break;
		}
		case 12:
		{
			a = 2;
			b = 7;
			x = a;
			h = (b - a) / N; // hod raven
			for(i = 0; i < N ; i++)
			{
				M[i] = (1 - x) * log10(x) / sqrt(1 -log10(x));
				printf("M[%d] = %f\n", i, M[i]);
				x += h;
			}
			break;
		}
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
	printf("Dlya zapuska drugogo varianta input number (not 0), for exit input 0: ");
	scanf("%d",&bes);
	}	while(bes != 0);
	system("PAUSE");
	return 0;
}
