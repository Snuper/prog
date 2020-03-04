#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main(int argc, char *argv[])
{ int A;
printf("vvedite mesyac: \n"); scanf("%d",&A);
switch(A)
{
case 1: int B,N;
printf("vvedite den: \n");
scanf("%d",&B); if (B>31) printf("Error\n");
else {
N=B;
printf("nomer dnya=%3.0d \n",N);} break;
case 2: printf("vvedite den: \n");
scanf("%d",&B); if (B>28) printf("Error\n");
else {
N=31+B;
printf("nomer dnya=%3.0d \n",N);} break;
case 3: printf("vvedite den: \n");
scanf("%d",&B); if (B>31) printf("Error\n");
else {
N=31+28+B;
printf("nomer dnya=%3.0d \n",N);} break;
case 4: printf("vvedite den: \n");
scanf("%d",&B); if (B>30) printf("Error\n");
else {
N=62+28+B;
printf("nomer dnya=%3.0d \n",N);} break;
case 5: printf("vvedite den: \n");
scanf("%d",&B); if (B>31) printf("Error\n");
else {
N=62+30+28+B;
printf("nomer dnya=%3.0d \n",N);} break;
case 6: printf("vvedite den: \n");
scanf("%d",&B); if (B>30) printf("Error\n");
else {
N=93+30+28+B;
printf("nomer dnya=%3.0d \n",N);} break;
case 7: printf("vvedite den: \n");
scanf("%d",&B); if (B>31) printf("Error\n");
else {
N=93+60+28+B;
printf("nomer dnya=%3.0d \n",N);} break;
case 8: printf("vvedite den: \n");
scanf("%d",&B); if (B>31) printf("Error\n");
else {
N=124+60+28+B;
printf("nomer dnya=%3.0d \n",N);} break;
case 9: printf("vvedite den: \n");
scanf("%d",&B); if (B>30) printf("Error\n");
else {
N=155+60+28+B;
printf("nomer dnya=%3.0d \n",N);} break;
case 10: printf("vvedite den: \n");
scanf("%d",&B); if (B>31) printf("Error\n");
else {
N=155+90+28+B;
printf("nomer dnya=%3.0d \n",N);} break;
case 11: printf("vvedite den: \n");
scanf("%d",&B); if (B>30) printf("Error\n");
else {
N=155+120+28+B;
printf("nomer dnya=%3.0d \n",N);} break;
case 12: printf("vvedite den: \n");
scanf("%d",&B); if (B>31) printf("Error\n");
else {
N=186+120+28+B;
printf("nomer dnya=%3.0d \n",N);}break;
default: printf("\n Error \n");
}
system("PAUSE");
return EXIT_SUCCESS;
}

