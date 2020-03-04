#include <stdio.h>
#include <conio.h>
int nums[100], A[50],i, j,k=0,n=1;

int f( int j);

int f(int j){
if(nums[j]<0){
printf("%d ", nums[j]);
f(j+1);
}
else if(nums[j]>0){
A[k]=nums[j];
k++;
n++;
f(j+1);
}
else { for (k=0;k<n-1;k++)
printf("%d ",A[k]);
return 0;
}
}
int main(){
while(scanf("%d", &nums[i])&&nums[i++]);
f(0);
getch();
}
