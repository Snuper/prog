#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{ 	int m,d,c;
    printf("\n Mesac i den: ");  scanf("%i%i",&m,&d);
	c=0;
	switch(m)
    {
    	case 1: c=0+d; break;
    	case 2: c=31+d; break;
    	case 3: c=59+d; break;
    	case 4: c=90+d; break;
    	case 5: c=120+d; break;
    	case 6: c=151+d; break;
    	case 7: c=181+d; break;
    	case 8: c=212+d; break;
    	case 9: c=242+d; break;
    	case 10: c=273+d; break;
    	case 11: c=303+d; break;
    	case 12: c=334+d; break;
	}
	printf("\n Den %8i \n", c);
    system("PAUSE");
    return EXIT_SUCCESS;
}
