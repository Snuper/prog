#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{   float m;
	int a;
    printf("\n God: ");  scanf("%i",&a);
	printf("\n Jivotnoe: ",a);
    m=a%12;
    a=m;
	switch(a)
    {
    	case 0: printf("Obeziana \n"); break;
    	case 1: printf("Petuh \n"); break;
    	case 2: printf("Sobaka \n"); break;
    	case 3: printf("Svin'ia \n"); break;
    	case 4: printf("Krisa \n"); break;
    	case 5: printf("Kororva \n"); break;
    	case 6: printf("Tigr \n"); break;
    	case 7: printf("Zayac \n"); break;
    	case 8: printf("Drakon \n"); break;
    	case 9: printf("Zmeia \n"); break;
    	case 10: printf("Loshad' \n"); break;
    	case 11: printf("Ovca \n"); break;
	}

    system("PAUSE");
    return EXIT_SUCCESS;
}
