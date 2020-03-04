#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

float power (float x, int n)
{
      float rez = 1;
      if (n == 0)return 1;
      if (n > 0)
         for (int i = 0; i <n; i++)
             rez *= x;
      if (n < 0)
         for (int i = 0; i>n; n++)
             rez *= (1/x);
      return rez;
      }

int main()
{
    float x;
    int n;

    printf("Vvedite chislo: ");
    scanf("%d",x);
    printf("Vvedite stepen: ");
    scanf("%f",n);
    
    system ("PAUSE");
    return 0;
}
