#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct st         
    { char ch;
      struct s *ne;   
    } stack;
  main()
  {   stack *p,*q;
      char a;
      p=NULL;
      system ("CLS");     
//  заполнение стека 
      do           
      { a=getchar();
        q=(stack *)malloc(sizeof(stack));
         q->ne=p; 
         p=q;
         q->ch=a;
      }  while(a!='.');
//  печать стека c освобождением памяти
      do        
      { p=q->ne;
        free(q);
        q=p;
        printf("%c",p->ch);
      } while(p->ne!=NULL);
      getch();
      return 0;
  }
