#include <stdio.h>
#include <conio.h>
int nums[100], i, j;
int print(int j);
int print(int j){
if(nums[j]>0){
printf("%d ", nums[j]);
print(j+1);
}
else if(nums[j]<0){
print(j+1);
}
else {
return 0;
}
}

int main(){
while(scanf("%d", &nums[i])&&nums[i++]);
print(0);
getch();

}
