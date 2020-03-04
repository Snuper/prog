#include <stdio.h>
#include <conio.h>
int dvoichnoe(int argc),mass[500],i=0,n=1;

int main()
{int a,z;
printf("vvedite chislo ");
 scanf("%d", &a);
  for (i = 0; i < 500; i++)
 mass[i] = 0;
 i=0;
 z=dvoichnoe(a);
 printf("%d_",z);
 getch();
}
int dvoichnoe(int argc)
{
 int a,k=1;
 if (argc == 0) {

 for (i=n-2;i>=0;i--)
 printf("%d",mass[i]);
 scanf("%d",&k);
 return k;}
 
 if (argc % 2 == 0)
 {
 mass[i] = 0;
 i++;
 n++;
 
 return dvoichnoe(argc = argc / 2);
 }
 if (argc % 2 == 1)
 {
 mass[i] = 1;
 i++;
 n++;
 return dvoichnoe(argc = argc / 2);
 }
 
}
