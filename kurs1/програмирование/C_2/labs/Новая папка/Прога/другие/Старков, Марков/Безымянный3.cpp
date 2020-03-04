#include <stdio.h>
#include <iostream>
#include <math.h>


int n=100;
float m[100];
int q=2;

float y(float x)
{ float f=0;
f=(2.5*x*x-0.1)/(tan(x)+sin (x));
return f;
};

float i1(float r1, float r2, float r3)
{ float n1=0;
n1=(y(r1)+y(r2))/2;
for(int i=1; i<n; i++) {
n1=n1+y((r1+(i*r3)));
m[i]=y((r1+(i*r3)));
}
n1=n1*r3;
return n1;
};

float i2(float t1, float t2, float t3)
{ float u=0,c=0,g=0;
u=y(t1)+y(t2);
m[0]=y(t1);
m[100]=y(t2);
q=q+2;
c=0;
g=0;
for(int i=1; i<n;i=i+2) {
c=c+y((t1+i*t3));
m[i]=y((t1+i*t3));
q=q+1;
}
for(int i=2; i<n-1;i=i+2){
g=g+y((t1+i*t3));
m[i]=y((t1+i*t3));
q=q+1;
}
g=g*2;
c=c*4;
u=(u+c+g)*t3/3;
return u;
}

int main() {
float a=6;
float b=4;
float h=0;
float Iq1=0,Iq2=0;
h=(b-a)/n;
Iq1=i1(a,b,h);
Iq2=i2(a,b,h);
printf("trapezhiya \n");
printf("%f \n", Iq1);
printf("simpson \n");
printf("%f \n", Iq2);
system("pause");
return 0;
}
