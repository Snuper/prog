#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
int N = 5;
main()
{
    int i = 0, len;
    char sl[50];
    char text[]="create and open new file";
    FILE *old, *neww;
    old = fopen("old.txt", "w");
    system("CLS");
    for (int i = 0; i < N; i++)
    {fputs("create and open new file", old);
	fputs("\n", old);
    }
    fclose(old);
    old = fopen("old.txt", "r");
    neww = fopen("new.txt", "w");
    while (!feof(old))
    {fgets(sl, 50, old);
	len = strlen(sl);
    if ((!feof(old))){
    for (i = len; i >= 0; i--){
    fputc(sl[i], neww);}}
    }
    fclose(old);
    fclose(neww);
}
