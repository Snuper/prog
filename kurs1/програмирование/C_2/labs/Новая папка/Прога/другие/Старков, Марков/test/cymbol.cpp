#include <stdio.h>
#include <stdlib.h>
int main(){
    int i,j;
    scanf("%d%d",&i,&j);
    while(i <= j){
            printf("%d - %c\t",i,i);
            i++;
    }
    system("PAUSE");
}
