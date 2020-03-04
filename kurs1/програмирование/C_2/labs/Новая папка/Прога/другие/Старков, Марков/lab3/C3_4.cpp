#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{   int m,x;
    printf("\n vvedite mesac :");  scanf("%d",&m);
    printf("\n vvedite den` :");  scanf("%d",&x);
    
    
    
    
    switch(m)
    {
    
    case 1 :x=x; break;
    case 2 :x=31+x;  break;   
    case 3 :x=31+28+x;  break; 
    case 4 :x=31+28+31+x;  break; 
    case 5 :x=31+28+31+30+x; break;
    case 6 :x=31+28+31+30+31+x; break;
    case 7 :x=31+28+31+30+31+30+x;  break;
    case 8 :x=31+28+31+30+31+30+31+x;   break;   
    case 9 :x=31+28+31+30+31+30+31+31+x;  break; 
    case 10 :x=31+28+31+30+31+30+31+31+30+x ;  break; 
    case 11 : x=31+28+31+30+31+30+31+31+30+31+x;  break;
    case 12 :x=31+28+31+30+31+30+31+31+30+31+30+x;  break;
     default: printf("\n Error \n");
}
printf(" %d",x  );
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
