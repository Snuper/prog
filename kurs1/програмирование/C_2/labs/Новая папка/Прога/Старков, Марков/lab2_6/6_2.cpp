#include <stdio.h>
#include <conio.h>
#include <math.h>
void swap(int &m,int &n, float &pd, float &pm){
    int nfact=1,i,mfact=1,nrm,nrmfact=1;
    float cnm,p=0.45,q=0.65,pp,qq;
    for(i=0;i<n;i++)
    nfact*=i+1;
    for(i=0;i<m;i++)
    mfact*=i+1;
    nrm=n-m;
    for(i=0;i<nrm;i++)
    nrmfact*=i+1;
    printf(" %d",nrmfact);
    cnm=nfact/(mfact*nrmfact);
    //printf(" %f",cnm);
    pp=pow(p,m);
    qq=pow(q,(n-m));
    //printf(" %f",pp);printf(" %f",qq);
    pd=cnm*pp*qq;
    pp=pow(p,(n-m));
    qq=pow(q,m);
    //printf(" %f",pp);printf(" %f",qq);
    pm=cnm*pp*qq;
    }

int main()
{
int n,m;  
float pd,pm;
printf("vvedite n");
scanf("%d",&n); 
printf("vvedite m");
scanf("%d",&m);
 
      swap(m,n,pd,pm);
      printf("pd=%f\n",pd);
      printf("pm=%f",pm);
      
      
      
      
      
      
      getch();
     
      }
