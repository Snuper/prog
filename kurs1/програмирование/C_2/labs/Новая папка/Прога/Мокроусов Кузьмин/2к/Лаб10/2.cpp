#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
main()
{ char ch, sl[50];
  int i,n=0;
  char text[]="one two three four";
  FILE *pn, *pg;                      // ��������� �� �����
  pn=fopen("N.txt","r");
  pg=fopen("new.txt","w");
  ch=getc(pn); 
  while (!feof(pn))                  // ���� �� ����� �����
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
  rewind(pn);                          // ������� ��������� �� ������ ����� pf
  printf("%s\n",sl);
  fclose(pn);                  // ����� ������ sl 
  fclose(pg);                          // �������� ������
  getch();
}

