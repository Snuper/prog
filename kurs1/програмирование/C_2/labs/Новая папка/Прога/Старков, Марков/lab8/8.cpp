#include <stdlib.h>
#include <stdio.h>
#include <math.h>
main(){
int i,N ;
printf("\nprint N\n"); scanf("%d",&N);
float A[N+1],h,y,x , a=1 , b=10,sum=0,sum2=0; 
h=(b-a)/N;
for(i=0; i<N+1; i++){
   y=((2*a)+log(a))/(1+log(a));                             
     a+=h;
      A[i]=y; 
     
        
         }
   for(i=1; i<N-1; i++){
                          //printf("\n%f",A[i]);
   sum+= A[i]; }  
   sum+= (A[0]/2+A[N]/2);
   printf("\I1=");
   printf("%f\n",(sum*h));
   sum=0;
for(i=0; i<N; i++)
 if((i+1)%2==0)
 {sum+=A[i];} //нечет
 else if((i+1)%2!=0)
 {sum2+=A[i];}//Чёт
 printf("\nI2=%f",(h/3)*((sum*4)+(sum2*2)+A[0]+A[N]));
   
   
     
         
    


system("PAUSE"); 
return 0;
}
