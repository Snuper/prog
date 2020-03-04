#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{   int m;
    printf("\n Nomer:");  scanf("%d",&m);
    printf("\n Polugodie i kvartal: ",m);
    switch(m)
    {

    	case 1:case 2:case 3: printf("1 1\n"); break;
    	case 4:case 5:case 6: printf("1 2\n"); break;
	  	case 7:case 8:case 9: printf("2 3 \n"); break;
    	case 10:case 11:case 12: printf("2 4 \n"); break;		  
      default: printf("\n Error \n");
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

