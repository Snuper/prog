#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
void probability(const float &p, const float &q, float k, float b, float g);
float fac(float a){
	float b=1;
	for(int i=1;i<=a;i++){
		b*=i;
	}
	return b;
}
float ciznpok(float n,float m){
	float c;
	c=fac(n)/(fac(m)*fac(n-m));
	return c;
}
int probability(float &p, float &q, float k, float b, float g){
		float pb,pg;
		if(k<b || k<g){
            return 0;    
        }else{pb=ciznpok(k,b)*pow(q,b)*pow(p,k-b);
		pg=ciznpok(k,g)*pow(p,g)*pow(q,k-g);
		printf("\n pb=%f pg=%f",pb,pg);
        }
}
main(){
	float p=0.45,q=1-p,k,b,g;
	printf("kids boys girls \n");
	scanf("%f%f%f",&k,&b,&g);
	probability(p,q,k,b,g);
	system("Pause");
}
