#include <stdlib.h>
#include <stdio.h>

int main()
{   int c,y;
	printf("\n Vvedite god: "); scanf("%d",&c);
	y = c % 12;	
	switch(y)
    {case 4: printf ("God krisi \n"); break;
    case 5: printf ("God korovi \n"); break;
    case 6: printf ("God tigra \n"); break;
    case 7: printf ("God zayca \n"); break;
    case 8: printf ("God drakona \n"); break;
    case 9: printf ("God zmei \n"); break;
    case 10: printf ("God loshadi \n"); break;
    case 11: printf ("God ovci \n"); break;
    case 12: printf ("God obesiani \n"); break;
    case 1: printf ("God petuha \n"); break;
    case 2: printf ("God sobaki \n"); break;
    case 3: printf ("God svinyi \n"); break;
      
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

