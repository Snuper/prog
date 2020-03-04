#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
main()
{ char ch, sl[50];
  int i,n=0;
  char text[]="one two three four";
  FILE *pn, *pg;                      // Указатели на файлы
  pn=fopen("N.txt","r");
  pg=fopen("new.txt","w");
  ch=getc(pn); 
  while (!feof(pn))                  // Пока не конец файла
  { 
	ch=getc(pn);
	n++;
  }
  
  rewind(pn); 
  fgets(sl,50,pn);  
  for(i=n-1;i>=0;i--){
  	ch=sl[i];
  	putc(ch,pg);
  }
  rewind(pn);                          // Возврат указателя на начало файла pf
  printf("%s\n",sl);
  fclose(pn);                  // Вывод строки sl 
  fclose(pg);                          // Закрытие файлов
  getch();
}

