#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void Treugolnik(float *a, float *b, float *c){
float p,s;
if ((*a+*b<=*c)||(*a+*c<=*b)||(*b+*c<=*a))
printf("Triangle does not exist\n");
else{
p=*a+*b+*c;
s=sqrt(p/2*(p/2-*a)*(p/2-*b)*(p/2-*c));
printf("p=%4.2f s=%4.2f \n",p,s);
}
}
main(){
float a,b,c;
printf("Vvedite a,b,c:");
scanf ("%f%f%f",&a,&b,&c);
Treugolnik(&a,&b,&c);
system("PAUSE");
}
