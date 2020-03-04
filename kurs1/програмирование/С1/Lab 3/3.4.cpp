#include <stdlib.h>
#include <stdio.h>

int main()
{   int m,d,t,p,c,y,q;
	q=0;
	y=0;
	printf("\n Vvedite god "); scanf("%d",&t);
	printf("\n Vvedite mesyac "); scanf("%d",&m);
	if (t%4==0) c=1;
	else c=0;
 while (q==0)
 {
 if (m>12 or m<1)
 {
 printf ("\n Takogo mesyca ne sucshestvuet");
 printf("\n Vvedite drugoi mesyac: ");
 scanf("%d",&m);
 }
 else if (m<12 or m>1)
 q=1;
 }
 printf("\n Vvedite chislo "); scanf("%d",&d);
 while (y==0)
	{
   if ((m == 1 or 3 or 5 or 7 or 8 or 10 or 12) and d>31) 
	{printf ("\n Dannogo chisla v vedennom vami mesyace ne sucshestvuet");
	 printf ("\n Vvedite drugoe chislo: ");
	 scanf ("%d",&d);
	}
	if(m == 2 and d>28 and c == 0)
	{printf("\n Dannogo chisla v vedennom vami mesyace ne sucshestvuet");
	printf ("\n Vvedite drugoe chislo: ");
	 scanf ("%d",&d); 
	}
	if(m == 2 and d>29 and c == 1)
	{printf("\n Dannogo chisla v vedennom vami mesyace ne sucshestvuet");
	printf ("\n Vvedite drugoe chislo: ");
	 scanf ("%d",&d); 
	}
	if((m == 4 or 6 or 9 or 11) and d>30)
	{printf("\n Dannogo chisla v vedennom vami mesyace ne sucshestvuet");
	printf ("\n Vvedite drugoe chislo: ");
	 scanf ("%d",&d); 
	}
    else y=1;
}
	switch(m)
    {case 1: p=d;printf ("Poryadkoviw nomer %d \n", p); break;
    case 2: p=31+d; printf ("Poryadkoviw nomer %d \n", p); break;
    case 3: p=59+c+d; printf ("Poryadkoviw nomer %d \n", p); break;
    case 4: p=90+c+d; printf ("Poryadkoviw nomer %d \n", p); break;
    case 5: p=120+c+d; printf ("Poryadkoviw nomer %d \n", p); break;
    case 6: p=151+c+d; printf ("Poryadkoviw nomer %d \n", p); break;
    case 7: p=181+c+c; printf ("Poryadkoviw nomer %d \n", p); break;
    case 8: p=212+c+d; printf ("Poryadkoviw nomer %d \n", p); break;
    case 9: p=242+c+d; printf ("Poryadkoviw nomer %d \n", p); break;
    case 10: p=273+c+d; printf ("Poryadkoviw nomer %d \n", p); break;
    case 11: p=303+c+d; printf ("Poryadkoviw nomer %d \n", p); break;
    case 12: p=334+c+d; printf ("Poryadkoviw nomer %d \n", p); break;
	default: printf ("\n Net takogo mecyaca \n");
	}
    system("PAUSE");
    return EXIT_SUCCESS;
}
