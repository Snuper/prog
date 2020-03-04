#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{   int m;
    printf("\n vvedite chislo :");  scanf("%d",&m);
    
    
    switch(m)
    {
    case -9: printf("minus devyat \n"); break;
    case -8: printf("minus vosem \n"); break;
    case -7: printf("minus sem` \n"); break;
     case -6: printf("minus shest \n"); break;
     case -5: printf("minus pyat \n"); break;
     case -4: printf("minus chetir`e \n"); break;
     case -3: printf("minus tri\n"); break;
     case -2: printf("minus dva \n"); break;
     case -1: printf("minus odin \n"); break;
     case 0: printf("minus nol` \n"); break;
     case 1: printf("odin \n"); break;
     case 2: printf("dva \n"); break;
     case 3: printf("tri \n"); break;
     case 4: printf("chetire \n"); break;
     case 5: printf("pyat \n"); break;
     case 6: printf("shest \n"); break;
     case 7: printf("sem` \n"); break;
     case 8: printf("vosem` \n"); break;
     case 9: printf("devyat` \n"); break;
      
      default: {
               printf("\n Error \n");
               
               }
    }
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
