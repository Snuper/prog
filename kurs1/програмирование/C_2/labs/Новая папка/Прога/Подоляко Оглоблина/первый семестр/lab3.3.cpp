#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{   int A;
    printf("\n vvedite god :");  scanf("%d",&A);
    printf("\n %d=",A);
     A=A%12;
    switch(A)
   
    {
      case 4: printf("krisa\n"); break;
      case 5: printf ("korova\n"); break;
      case 6: printf("tigr\n");  break;
      case 7: printf("zayac\n");  break;
      case 8: printf("drakon\n"); break;
      case 9: printf("zmeya\n"); break;
      case 10: printf("loshad\n"); break;
      case 11: printf("ovca\n"); break;
      case 0: printf("obezyana\n"); break;
      case 1: printf("petuh\n"); break;
      case 2: printf("sobaka\n"); break;
      case 3: printf("svinya\n"); break;
      default: printf("\n Error \n");
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}


