#include <stdlib.h>
#include <stdio.h>
#include <math.h>
float factorial(float a){
float f=1,k=1;
while(k<=a){
f*=k;
k++;
}
return f;
}
float cbg(float n,float m){
float c;
c=factorial(n)/(factorial(m)*factorial(n-m));
return c;
}
void veroyatnost(const float &p, const float &q, float s, float m, float d){
float pm,pd;
pm=cbg(s,m)*pow(q,m)*pow(p,s-m);
pd=cbg(s,d)*pow(p,d)*pow(q,s-d);
printf("\n pm=%4.2f pd=%4.2f\n",pm,pd);
}
main(){
float p=0.45,q=0.55,s,m,d;
printf("Deti=");
scanf("%f",&s);
printf("\nMalchiki=");
scanf("%f",&m);
printf("\nDevochki= ");
scanf("%f",&d);
if((s<m) || (s<d)) printf("Error\n");
else veroyatnost(p,q,s,m,d);
system("PAUSE");
}
