#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;



 void masA(int *arr,int D , int *N)  // zapolnenie mass
{
	for(int i=0 ; i<  *N ; i++)
	 {
		arr[i]=rand()%99;
	    cout<<arr[i]<<" ";
     }
   cout<<endl;
   *N=1000;
}
  
  
	
void qsort (int *arr,int D)   // sort mass
{
	for(int i = 0 ; i <D - 1; i++) 
     { 
       for(int j = 0 ; j < D - i - 1 ; j++)
          {  
           if(arr[j] < arr[j+1]) 
             {            
               int tmp = arr[j];
               arr[j] = arr[j+1] ;
               arr[j+1] = tmp;
             }
          }
     } 
     
       for(int i=0 ; i < D ; i++)
     	{
	      cout<<arr[i]<<" ";
        }
       cout<<endl;
       

     
}



void Bust(int *arr, int D , int k)  // poisk element pereborom
{
	int c=0;
	int i;
	for( i=0 ; i<D ; i++)
	{
		if (k==arr[i]) 
		{
		cout<<"metod perebor => arr["<<i<<"] = "<<arr[i];
		cout<<endl;
		c++;
		}
		if (k > arr[i]) break ;

	}
	if (c==0)
	{
		cout<<"metod perebor => no coincidence";
	}
	cout<<"kol-vo srav pereborom : "<<i<<endl;
	cout<<endl;
}



int Search_Binary(int *arr, int l ,int r ,int k) // poisk elementa binarom
{
 int srav=0;
  while (l<=r) {
    int m = (l + r) / 2;
    if (arr[m] < k) {r = m - 1 ; srav++ ; }
    if (arr[m] > k) {l = m + 1 ; srav++ ; }
    if (arr[m] == k) 
	{
		while(arr[m] == k)
		{
	    	m-- ;
	    }
		
		m++ ;
		
		while(arr[m] == k)
	    	{
		      cout<<"Binary search => "<<"arr["<<m<<"] = "<<k ;
		      cout<<endl;
	          m++ ;
	          
	        }	 
	        
	        cout<<"kol-vo srav binar : "<<srav<<endl;
	        
      return m;
	}
  }
  cout<<"kol-vo srav binar : "<<srav<<endl;
  cout<<"Binary search => no coincidence"<<endl;
return 1;
}



 int main()
  {
  	int D;
	int *arr;
	int N=100;
	int k;
	arr=new int [N];
	D=N;
	int f=0;
    
    cout<<"mass A1 (N=100) : ";
	masA(arr, D , &N);
	cout<<endl;
    cout<<"Sort mass A : ";
	qsort(arr,D);
	cout<<endl;
	cout<<"desired number : ";
	cin>>k;
	cout<<endl;
	Search_Binary(arr, 0 , D , k);
	cout<<endl;
	Bust(arr, D , k);
	 cout<<endl;

    delete [] arr ;
    
    arr=new int [N]; 
    D=N;
    cout<<"mass A (N=100) : ";
	masA(arr, D , &N);
	cout<<endl;
    cout<<"Sort mass A : ";
	qsort(arr,D);
	cout<<endl;
	cout<<"desired number : ";
	cin>>k;
	cout<<endl;
	Search_Binary(arr, 0 , D , k);
	cout<<endl;
	Bust(arr, D , k);
	
    delete [] arr ;
	
	
	
	cin.ignore();
    cin.get();
	return 0;
  }
