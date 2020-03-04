#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

main()
{ char ch, sl[100];
char text[]="one two three four \n";
int n=4,i,j;
FILE *pf, *pr, *pn, *pc; // Указатели на файлы
//pf=fopen("new.txt","w");
//for(i=0;i<n;i++) {
//fputs(text,pf);
//} // Запись в файл строки text
//fclose(pf); // Закрытие файла pf
pf=fopen("new.txt","r"); 
pr=fopen("glas.txt","w"); 
pc= fopen("sogl.txt", "w");
ch=getc(pf);
while (!feof(pf)){
 if(ch== 'a' || ch==  'e' || ch==  'y' || ch==  'u' || ch==  'i' || ch==  'o'){ 
		while(ch!= ' '){
                    putc(ch,pr); 
                    ch=getc(pf);
                    }
		putc(ch,pf);
        }
		else {
		while (ch!= ' ') { 
              putc(ch,pc);
              ch= getc(pf);}
		putc(ch,pc);
	}
	ch=getc(pf);
}
fclose(pr);
fclose(pc);
fclose(pf);
rewind(pf);
pn=fopen("reverse.txt", "w+");
pf=fopen("new.txt", "r+");
while(!feof(pf)){
	fgets(sl, 100, pf);
	j=strlen(sl);
	for(i=j; i>=0; i--)
	 fprintf(pn, "%c", sl[i]);
}
fclose(pf); // Закрытие файлов
fclose(pr);
fclose(pn);
fclose(pc);
getch();
}

