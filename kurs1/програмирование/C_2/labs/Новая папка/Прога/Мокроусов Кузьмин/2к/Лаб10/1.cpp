#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
main()
{ char ch, sl[50];
  char text[]="one two three four";
  FILE *pn, *pg, *ps;                      // Указатели на файлы
  pn=fopen("N.txt","r");
  pg=fopen("new1.txt","w");
  ps=fopen("new2.txt","w");
  ch=getc(pn); 
  while (!feof(pn))                  // Пока не конец файла
  {                      // Чтение символа ch из файла pf
    	if (ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'a' or ch == 'y'){
     		while(ch != ' ') {
				putc(ch,pg);                    
				ch=getc(pn); 
			}
			putc(ch,pg); 
		}
		else{
			while(ch != ' ') {
				putc(ch,ps);                    
				ch=getc(pn); 
			}
			putc(ch,ps); 
		}
	ch=getc(pn);
  }

  rewind(pn);                          // Возврат указателя на начало файла pf
  fgets(sl,50,pn);                     // Чтение из файла pf строки в переменную sl
  printf("%s\n",sl);
  fclose(pn);                  // Вывод строки sl 
  fclose(pg);                          // Закрытие файлов
  fclose(ps);
  getch();
}

