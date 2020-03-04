#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
int i;
float i2;
float chislo;
int factorial(int n)
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}
float cosin(float x)
{
float y=-1;
while(x>3.1415926535) x-=3.1415926535;
for(i=1,i2=1;i<10;i++,i2++)
y=y-((pow((-1),i)*pow(x,2*i2))/factorial(2*i));
return y;
}
main()
{
printf("Vvedite x\n");
scanf("%f", &chislo);
printf("Cosinus x raven %f\n", cosin(chislo));
printf("Cosinus x raven %f", cos(chislo));
}
