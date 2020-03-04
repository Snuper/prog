#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//int random (int N) { return rand() % N; }

main()
{
int i,n,j;
float *a,c,*b;
printf ("Vvedite razmer massiva -> ");
scanf ("%d", &n);
a = new float [n]; 
if ( a == NULL ) 
{
printf("Ne videlena pamyat' \n");
return 1; 
}
for (i = 0; i < n; i ++ )
{
a[i]= (float)rand()/RAND_MAX;
b[i]=*(a+i);
}
puts("\n");
for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n-i; j++)
		{
			if(b[j] > b[j+1])
			{
			c=b[j];
			b[j]=b[j+1];
			b[j+1]=c;
			}
		}
	}
printf("Nachalnyi massiv= ");
for(i = 0; i < n; ++i) printf("%f ", a[i]);
puts("\n");
printf("Otsortirovanniy massiv= ");
for(i = 0; i < n; ++i) printf("%f ", b[i]);
delete a;
delete b;
a=NULL;
b=NULL;
puts("\n");
//getche();
system("Pause"); 
return 0;
}
