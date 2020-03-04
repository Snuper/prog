#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
main()
{int i,k;

struct spis {
char fam[20];
int ocen[4];
spis *next;};
spis *head, *p,*t1,*t2;
head=NULL;
printf ("Vvedite familii and 4 ocenki\n");

do {
p=new spis;
scanf("%s",p->fam);
for(i=0;i<4;i++)
scanf("%d",&p->ocen[i]);
p->next=head;
head=p;
}
while(strcmp(p->fam,"."));
do
{
k=0;
for (p=head; p->next->next; p=p->next)
{
t1=p->next;
t2=t1->next;
if (strcmp(t1->fam,t2->fam)>0) {
p->next=t2;
t1->next=t2->next;
t2->next=t1;
k=1;
}
}

}while(k);

printf("\nSpisok: \n");
for(p=head->next; p; p=p->next)
printf("%s %d %d %d %d\n",p->fam, p->ocen[0], p->ocen[1], p->ocen[2], p->ocen[3]);
delete p;

system("PAUSE");
}
