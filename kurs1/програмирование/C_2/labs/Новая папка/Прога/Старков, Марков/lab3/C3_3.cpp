#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{   int m,x;
    printf("\n vvedite god :");  scanf("%d",&m);
    
    x=((m-(m/12)*12));
    
    
    
    switch(x)
    {
    case 0 :printf("\n obez`yana :"); break;
    case 1 :printf("\n petuh :"); break;
    case 2 :printf("\n sobaka :");  break;   
    case 3 :printf("\n svin`ya :");  break; 
    case 4 :printf("\n krisa :");  break; 
    case 5 :printf("\n korova :"); break;
    case 6 :printf("\n tigr :"); break;
    case 7 :printf("\n zayac :");  break;
    case 8 : printf("\n drakon :");  break;   
    case 9 :printf("\n zmeya :");  break; 
    case 10 :printf("\n loshad` :");   break; 
    case 11 :printf("\n ovca :");  break;
    
}
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
