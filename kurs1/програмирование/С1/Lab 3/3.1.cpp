#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{   int m;
    printf("\n Nomer mesyaca :");  scanf("%d",&m);
    switch(m)
    {
      case 1: case 2: case 3: 
                  printf("Perviy kvartal, pervoe polugodie \n"); break;
      case 4: case 5: case 6: printf ("Vtoroy kvartal, pervoe polugodie \n"); break;
      case 7: case 8: case 9: printf("Tretiy kvartal, vtoroe polugodie \n");  break;
      case 10: case 11: case 12: printf ("Chetvrtiy kvartal, vtoroe polugodie \n"); break;
      default: printf("\n Error \n");
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

