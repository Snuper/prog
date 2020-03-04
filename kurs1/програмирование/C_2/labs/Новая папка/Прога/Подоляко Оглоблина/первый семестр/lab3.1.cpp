#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main(int argc, char *argv[])
{   int m;
    printf("\n vvedite mesyac :");  scanf("%d",&m);
    printf("\n %d mesyac vhodit v : ",m);
    switch(m)
    {
      case 1:case 2:case 3:
                  printf("1 kvartal, 1 polugodie\n"); break;
      case 4:case 5:case 6: printf ("2 kvartal 1 polugodie \n"); break;
      case 7: case 8: case 9: printf("3 kvartal 2 polugodie \n");  break;
      case 10: case 11: case 12: printf("4 kvartal 2 polugodie \n");  break;
      default: printf("\n Error \n");
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

