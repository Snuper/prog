#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
main()
{ char ch, sl[50];
  char text[]="one two three four";
  FILE *pn, *pg, *ps;                      // ��������� �� �����
  pn=fopen("N.txt","r");
  pg=fopen("new1.txt","w");
  ps=fopen("new2.txt","w");
  ch=getc(pn); 
  while (!feof(pn))                  // ���� �� ����� �����
  {                      // ������ ������� ch �� ����� pf
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

  rewind(pn);                          // ������� ��������� �� ������ ����� pf
  fgets(sl,50,pn);                     // ������ �� ����� pf ������ � ���������� sl
  printf("%s\n",sl);
  fclose(pn);                  // ����� ������ sl 
  fclose(pg);                          // �������� ������
  fclose(ps);
  getch();
}

