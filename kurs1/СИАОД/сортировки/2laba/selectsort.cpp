#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void FillRand(int *p, int a)
{
	int i;
	for (i=0; i<a;i++)
	{
		p[i]=rand()%100+1;
	}
}
void PrintMas(int *p, int a){
	int i;
	for (i=0; i<a;i++)
		printf("%d  ",p[i]);
} 
int CheckSum(int *p, int a){
	int i,s=0;
	for (i=0;i<a;i++)
	s+=p[i];
	return s;
}
int RunNumber(int *p, int a)
{
	int i,k=1;
	for (i=0;i<a-1;i++){
		if (p[i]>p[i+1]){
			k++;	
		}		
	}
	return k;
}
int main()
{
  srand(time(NULL));
  int Massiv[100], n, c, d, position, swap, b, perestanovka=0, sravnenie=0;
 
  printf("Vvedite kolvo elementov\n");
  scanf("%d", &n);
 
  for (c = 0; c < n; c++)
    FillRand(Massiv,n);
    printf("Massiv: ");
	PrintMas(Massiv,n);
  for (c = 0; c < (n - 1); c++)
  {
    position = c;
   
    for (d = c + 1; d < n; d++)
    {
      if (Massiv[position] > Massiv[d])
        position = d;
        sravnenie++;
	}
    if (position != c)
    {
      swap = Massiv[c];
      Massiv[c] = Massiv[position];
      Massiv[position] = swap;
      perestanovka++;
	}
  }
  printf("\nSorted list in ascending order:\n");
 
  for (c = 0; c < n; c++)
    printf("%d\n", Massiv[c]);
 
    b=RunNumber(Massiv,n);
	printf("\nRunNumber %d\n",b);
	b=CheckSum(Massiv,n);
	printf("\nCheckSum %d\n\n",b);
    printf("perestanovka = %d; \nsravnenie = %d",perestanovka, sravnenie); 
    perestanovka = 3*(n-1);
	sravnenie = (n*n-n)/2;  
    printf("\nperestanovka = %d; \nsravnenie = %d",perestanovka, sravnenie); 
  return 0;
}
