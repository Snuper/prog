#include <stdlib.h> 
#include <math.h> 
#include <conio.h>
#include <stdio.h>

int random (int N) { return rand() % N; }
const int K=30;
int x[K], flag=0;

void  sort( int n)

  { 
  if ((n<0)&&(flag==0)) {flag=1; n=30;}
   if (n<0) return;
  switch(flag)
  {case (0): if (x[n]<0) printf(" %d",x[n]); break;
  case (1): if (x[n]>0) printf(" %d",x[n]); break;}
  sort(n-1);
 }


int main()
{

int i;
for (i = 0; i < K; i++) {

        x[i] = random(4+ 9+1) -9;
        while(x[i]==0)
        x[i] = random(4+ 9+1) -9;
    }
    for (i = 0; i < K; i++)
    printf(" %d",x[i]);
    printf("\n");
    
    sort(K-1);
    printf("\nconec`");
    system ("PAUSE");
        }
