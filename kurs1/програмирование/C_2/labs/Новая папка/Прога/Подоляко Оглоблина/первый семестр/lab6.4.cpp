#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const int n=16;    
 main() 
{  system("CLS");
   int   i, s,c, a[n]; 
   s=0;c=0;
     printf( "\n Vvedite nomer karti ");     
   for (i=0; i<n; i++) 
		scanf ("%d", &a[i]);
   for (i=1; i<n; i=i+2)
     {s=s+a[i];}
      printf("\n s=%d",s); 
    for (i=0; i<n; i=i+2)
      {c=a[i]*2; 
      if (c>9) c=c-9;
      s=s+c;}
       printf("\n s=%d",s); 
    if (s%10==0) 
         printf("\n true\n");
    else printf("\n error\n");
   system("PAUSE");
   return 0;
}
