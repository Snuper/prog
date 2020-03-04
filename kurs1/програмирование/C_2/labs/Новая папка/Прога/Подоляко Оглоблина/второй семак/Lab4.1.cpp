#include<stdio.h>
#include<stdlib.h>
#include <time.h>
const int n=5;
typedef  int rown[n];
int random (int N) { return rand()%N; }
main()
{ int i,j,m,imax,jmax,max=0,y,k=0, g=20;
rown *a;
rown *b;
printf("Vvedite m= ");
scanf("%d",&m);
a=new rown[m];
if (a==NULL)
{ printf("Cannot allocate memory");
return 1;
}
b=new rown[m-1];
if (b==NULL)
{ printf("Cannot allocate memory");
return 1;
}
srand(time(NULL));
for(i=0;i<m;i++)
{for(j=0;j<n;j++)
{ a[i][j]=random(g-k+1)+k;
if (a[i][j]>max) {max=a[i][j];imax=i;jmax=j;}
printf("%4d",a[i][j]);
}
puts("\n");
}
for(i=0;i<m;i++)
a[i][jmax]=-1;
for(j=0;j<n;j++)
a[imax][j]=-1;

 for(i=0;i<imax;i++)
{for(j=0;j<jmax;j++)
{ b[i][j]=a[i][j];
}
}

for(i=imax; i<m-1; i++){
for(j=0;j<n-1;j++)
b[i][j]=a[i+1][j];}
for(j=jmax;j<n-1;j++)
{for (i=0;i<=imax;i++)
b[i][j]=a[i][j+1];
}
for(i=imax; i<m-1; i++){
for(j=jmax;j<n-1;j++)
b[i][j]=a[i+1][j+1];}

printf("\n Massiv C\n");
for(i=0;i<m-1;i++)
{
for(j=0;j<n-1;j++)
{printf("%4d",b[i][j]);}
puts("\n");}
delete a;
delete b;
a=NULL;
	b=NULL;
puts("\n");
system("PAUSE");
return 0;

}
