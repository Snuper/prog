#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
int random (int N) { return rand()%N; }
main()
{ 
int *p,*m,*k;
int i,n,o=0,f=0,j=0,q=0,a=-50,b=50;
printf("Vvedite n  ");
scanf ("%d",&n);
p=(int *) malloc(n*sizeof(int));
if (p==NULL)
{ printf("Cannot allocate memory");
return 1;
}
	srand(time(NULL));
for (i=0;i<n;i++)
{
*(p+i)=random(b-a+1)+a;
}
for (i=0;i<n;i++)
{ if (p[i]>0) f++;
else o++;
	printf("  p[%d]=%d  ",i,p[i]);
}
m=(int *) malloc(f*sizeof(int));
k=(int *) malloc(o*sizeof(int));
if (m==NULL)
{ printf("Cannot allocate memory m");
return 1;
}if (k==NULL)
{ printf("Cannot allocate memory k");
return 1;
} 
{for (i=0;i<n;i++)
 {if (p[i]>0) 
 {m[j]=p[i];j++;}
 if (p[i]<0){k[q]=p[i];q++;
 }
 }}
printf("\n");
 for (j=0;j<f;j++)
 printf("  m[%d]=%d  ",j,m[j]);
 printf("\n");
 for (q=0;q<o;q++)
 printf("  k[%d]=%d  ",q,k[q]);
printf("\n");
free(p);
p=NULL;
free(m);
m=NULL;
free(k);
k=NULL;
getch();
return 0;
}
