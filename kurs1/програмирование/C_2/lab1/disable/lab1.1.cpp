#include <stdlib.h>
#include <stdio.h>

int FillInc(int q, int i, int e)
{
for (q=0;q<N-1;q++)
  {
  for (i=0;i<N;i++)
  {
  if (A[i] < A[i+1])	
  ;
  else
  {
  e=A[i];
  A[i]=A[i+1];
  A[i+1]=e;
  }
  }
  }
  printf("\nPo vozrastaniu");
  for (i=0;i<N;i++)
  printf("\nA[%d]=%d",i,A[i]);
  system("PAUSE");
  return 0;
}
int FillDec(int q, int i, int e)
{
  for (q=0;q<N-1;q++)
  {
  for (i=0;i<N;i++)
  {
  if (A[i] > A[i+1])	
  ;
  else
  {
  e=A[i];
  A[i]=A[i+1];
  A[i+1]=e;
  }
  }
  }
  printf("\nPo vozrastaniu");
  for (i=0;i<N;i++)
  printf("\nA[%d]=%d",i,A[i]);
  system("PAUSE");
  return 0;
}
int FillRand ()
{
const int N = 20;
int random (int N) { return rand()%N; }
main()
{ 
  int sum=0, i, A[N], a = -100, b = 100;//a и b область значений
  printf("Elementi massiva\n");
  for ( i = 0; i < N; i ++)
{     
	 printf("A[%d]",i);
	 A[i] = random(b-a+1) + a; 
	 printf("=%d;\n",A[i]);   
}
  system("PAUSE");
  return 0;
}
}
int CheckSum (int i, int sum)
{
for(i=0; i<N; i++)
	sum = sum+A[i];
    printf("summa=%d",sum);
  system("PAUSE");
  return 0;
}
int RunNumber ()
{
	for(q=0,i=0; i<N-1; i++) 
{ 
if(A[i] < A[i+1]) 
; 
else 
q++; 
}
printf("q=%d",q); 
system("PAUSE"); 
return 0;
}
int PrintMas ()
{
	for (i=0 ; i < N ; i++)
	{
		printf ("\nA[%d]=%d",i,A[i]);
	}
}
