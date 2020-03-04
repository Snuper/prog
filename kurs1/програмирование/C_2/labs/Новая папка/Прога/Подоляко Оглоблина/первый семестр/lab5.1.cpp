#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
int n;
scanf("%d", &n);
int i = 0;
double pi = 0;
while ( i < n)
{
pi += ((pow(-1, i)) / (2 * i + 1));
i++;
}
pi *= 4;
printf("\n pi=%1.5f", pi);
system("PAUSE");
return 0;
}
