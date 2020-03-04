#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{   int m,n,m1;
    printf("\n Chislo: ");  scanf("%d",&m);
    printf("\n Slovami: ",m,m1);
    n=0;
    if (m>0) n = 1;
    if (m<0) n = 2;
    m1=abs(m);
    switch(m)
    {
    	case 0: printf("Nol"); break;
		case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9: printf("Plus "); break;
    	case -1:case -2:case -3:case -4:case -5:case -6:case -7:case -8:case -9: printf("Minus "); break;
		default: printf("\n Error \n");
    }
    switch(m1)
    {
    	case 0: printf("\n"); break;
    	case 1: printf("odin \n"); break;
    	case 2: printf("dva \n"); break;
    	case 3: printf("tri \n"); break;
    	case 4: printf("chetire \n"); break;
    	case 5: printf("piat \n"); break;
    	case 6: printf("shest \n"); break;
    	case 7: printf("sem \n"); break;
    	case 8: printf("vosem \n"); break;
    	case 9: printf("deviat \n"); 
    	default: printf("errfxrfxrfx");
	}
    system("PAUSE");
    return EXIT_SUCCESS;
}

