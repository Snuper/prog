#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
int N = 6;
main()
{
    char b[20];
    int ch;
    FILE *texst, *glas, *soglas;
    texst = fopen("texst.txt", "w");
    system("CLS");
    char string[] = ""; 
    char in_string[10];
    gets(in_string);fputs(in_string,texst); 
    fclose(texst);
    texst = fopen("texst.txt", "r");
    glas = fopen("glas.txt", "w");
    soglas = fopen("soglas.txt", "w");
    while (!feof(texst))
    {fscanf(texst, "%s", b);
    if ((!feof(texst)))
    {if (b[0] == 'a' || b[0] == 'y' || b[0] == 'u' || b[0] == 'i' || b[0] == 'o' || b[0] == 'e'){
    fputs(b, glas);
    fputs("\n", glas);}
    else {
	fputs(b, soglas);
    fputs("\n", soglas);}}
    }
    fclose(texst);
    fclose(glas);
    fclose(soglas);
    system("pause");
}
