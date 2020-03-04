#include <stdlib.h>
#include <stdio.h>

void SelectSort(float *a, int n)
{
int i, j, k;
float p;
for (i = 0; i < n-1; i++)
{
k = i;
for (j = i + 1; j < n; j++)
{
if (a[j] < a[k])
{			
k = j;
}                 
}
if (k != i)
{
p = a[i];
a[i] = a[k];
a[k] = p;              
}   
}   
}
main()
{ 
int i,n,s;
float *p,*a,d=100,c=1;
printf (" Input: "); 
scanf ("%d", &n); 
p = new float [n]; 
if ( p == NULL ) 
{  
printf("\n ERROR ");
return 1; 
} 
a = new float [n]; 
if ( a == NULL )
{  
printf("\n ERROR ");
return 1; 
}
for (i = 0; i < n; i ++ ) 
{ 
*(p+i)=(rand()*(d-c))/RAND_MAX+c;
}
for (i = 0; i < n; i ++ ) 
{ 
a[i]=*(p+i);
} 
puts("\n");
SelectSort(a,n);
for (i = 0; i < n; i ++ ) 
printf ("\n p[%d] = %f", i,*(p+i));
puts("\n");
for (i = 0; i < n; i ++ ) 
printf ("\n a[%d] = %f", i,*(a+i));
delete p; 
p=NULL;
delete a; 
a=NULL;
system("PAUSE");
return 0;
}
