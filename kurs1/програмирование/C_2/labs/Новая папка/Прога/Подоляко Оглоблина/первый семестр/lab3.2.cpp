#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{   int C;
    printf("\n vvedite chislo :");  scanf("%d",&C);
    printf("\n %d=",C);
    switch(C)
    {
      case -9: printf("-devyat\n"); break;
      case -8: printf ("-vosem\n"); break;
      case -7: printf("-sem\n");  break;
      case -6: printf("-shest\n");  break;
      case -5: printf("-pyat\n"); break;
      case -4: printf("-chetire\n"); break;
      case -3: printf("-tri\n"); break;
      case -2: printf("-dva\n"); break;
      case -1: printf("-odin\n"); break;
      case 0: printf("nol\n"); break;
      case 1: printf("odin\n"); break;
      case 2: printf("dva\n"); break;
      case 3: printf("tri\n"); break;
      case 4: printf("chetire\n"); break;
      case 5: printf("pyat\n"); break;
      case 6: printf("shest\n"); break;
      case 7: printf("sem\n"); break;
      case 8: printf("vosem\n"); break;
      case 9: printf("devyat\n"); break;
      default: printf("\n Error \n"); break;
      
    }
     system("PAUSE");
}
