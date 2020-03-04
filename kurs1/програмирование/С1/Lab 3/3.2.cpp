#include <stdlib.h>
#include <stdio.h>

int main()
{   int c,y;
	y=0;
	if (-9<=c<=9)
	while(y==0){
		y=0;
	printf("\n Vvedite chislo :");  scanf("%d",&c);
	switch(c)
    {
      case -9: printf ("Minus devyat \n"); y=1; break;
      case -8: printf ("Minus vosem \n"); y=1;break;
      case -7: printf ("Minus sem \n"); y=1;break;
      case -6: printf ("Minus shest \n");y=1; break;
      case -5: printf ("Minus pyat \n"); y=1;break;
      case -4: printf ("Minus chetire \n"); y=1;break;
      case -3: printf ("Minus tri \n"); y=1;break;
      case -2: printf ("Minus dva \n"); y=1;break;
      case -1: printf ("Minus odin \n"); y=1;break;
      case 0: printf ("nol \n"); y=1;break;
      case 1: printf ("odin \n"); y=1;break;
      case 2: printf ("dva \n"); y=1;break;
      case 3: printf ("tri \n"); y=1;break;
      case 4: printf ("chetire \n"); y=1;break;
      case 5: printf ("pyat \n"); y=1;break;
      case 6: printf ("shest \n"); y=1;break;
      case 7: printf ("sem \n"); y=1;break;
      case 8: printf ("vosem \n"); y=1;break;
      case 9: printf ("devyat \n"); y=1;break;
	  default: printf("\n Dannoe chislo ne vhodit v promejutok \n");y=0;
    }
}
    system("PAUSE");
    return EXIT_SUCCESS;
}

