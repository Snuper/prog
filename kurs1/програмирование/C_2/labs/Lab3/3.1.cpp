#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
main()
{ int *p,*a,*b;  
  int i,n,m,k; 
  srand(time(NULL));
  printf("\n Input: ");
  scanf("%d",&n);
  p=(int *) malloc(n*sizeof(int));
  if ( p == NULL ) 
 {  
     printf("ERROR");
    return 1; 
 }
  for (i=0;i<n;i++)
  p[i]=rand()%101-50;
  for (i=0;i<n;i++)  
     printf("\np[%d]=%d",i,p[i]);
  for (i=0;i<n;i++)
  if(p[i]<0)
  {
  m++;
  }
  else
  {
  k++;
  }
  a=(int *) malloc(m*sizeof(int));
  b=(int *) malloc(k*sizeof(int));
  for (i=0,m=0,k=0;i<n;i++)
  if(p[i]<0)
  {
  a[m]=p[i]; 
  m++;
  }
  else
  {
  b[k]=p[i]; k++;
  }
  printf("\n-");
  for(i=0;i<m;i++)
  printf("\n%d ",a[i]);
  printf("\n+");
  for(i=0;i<k;i++)
  printf("\n%d ",b[i]);
  free(p);
  p=NULL;
  free(a);
  a=NULL;
  free(b);
  b=NULL;
  getch();
  return 0;
}
