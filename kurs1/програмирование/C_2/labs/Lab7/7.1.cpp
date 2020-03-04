#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
void SelectSort(int *a, int n)

{

    int i, j, p, k;

    printf("\n");

    for (i = 0; i < n-1; i++)
    {

        k = i;

        for (j = i + 1; j < n; j++)

        {


            if (a[j] < a[k]){
			

                k = j;
                } 
                
        }

        if (k != i)

        {

            p = a[i];

            a[i] = a[k];

            a[k] = p;
            
           
        }

    
    }
   
}
void FillRand(int *a, int n)

{

    int i;

    for (i = 0; i < n; i++)

    {

        a[i] = rand() % 10000;

        printf("%7d ", a[i]);
    }
}
void PrintMas(int *a, int n){
	int i;
	for (i=0; i<n;i++)
		printf("%7d ",a[i]);
}
int Binary(int *a, int n, int k, int &f){
	int l=0,r=n-1,m;
	f=0;
	while (l<=r)
	{ m=(l+r)/2;
	if (a[m]>k){r=m-1; f++;
	}else if (a[m]<k){l=m+1; f++;
	}else{ return m;
	}
	}
	printf("\nERROR\n");
	return -1;
}
int Search(int *a, int n, int k, int &f){
	int i;
	f=0;
	for (i=0;i<n;i++){
		if (a[i]==k) {
		return i;} else{f++;
		}
	}}
int main(){

 int i,n,s,j,f,l;
  int *p;
  srand(time(NULL));
  printf (" Input: "); 
  scanf ("%d", &n); 
  p = new int [n]; 
  if ( p == NULL ) 
  {  
     printf("\n ERROR ");
    return 1; 
  } 

FillRand(p,n);
SelectSort(p,n);
puts("\n");
PrintMas(p,n);
puts("\n");
scanf("%d",&i);
s=Binary(p,n,i,f);
j=Search(p,n,i,l);
printf("\nBinary: %d    %d\nSearch: %d    %d",s,f,j,l);
getch();
delete p;
puts("\n");
printf (" Input: "); 
  scanf ("%d", &n); 
  p = new int [n]; 
  if ( p == NULL ) 
  {  
     printf("\n ERROR ");
    return 1; 
  } 

FillRand(p,n);
SelectSort(p,n);
puts("\n");
PrintMas(p,n);
puts("\n");
scanf("%d",&i);
s=Binary(p,n,i,f);
j=Search(p,n,i,l);
printf("\nBinary: %d    %d\nSearch: %d    %d",s,f,j,l);
getch();
delete p; 
p=NULL;
return 0;
}
