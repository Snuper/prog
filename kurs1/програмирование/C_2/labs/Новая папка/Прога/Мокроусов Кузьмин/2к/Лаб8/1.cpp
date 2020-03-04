#include <stdio.h>
#include <conio.h>
#include <string.h>
#define n 3
main()
{
   int i,j,k; float sum; 
  struct tov {int sh; int vi; int pos;} t;  
  struct tov shk[n];  
  printf("\n Vvedite shkoli \n");
  for (i=0;i<n;i++)
  {   printf("\n  Shkola, Vipusk, VUZ :  ");
     scanf("%d%d%d",&t.sh,&t.vi,&t.pos);
      shk[i]=t; 
  }

  for (i=0;i<n;i++){
    for (j=0;j<n-1-i;j++){
      if (shk[j].pos>shk[j+1].pos){
      	t=shk[j];  
		shk[j]=shk[j+1];
		shk[j+1]=t;
      } 
    }
  }

	for (i=0;i<n;i++)
  {   
       printf("Shokla %d == %d == %d \n",shk[i].sh,shk[i].vi,shk[i].pos);

  }

  getch();
}

