#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <queue>
#include <iostream>
int random (int N) { return rand()%N; }
int mp=0, cp=0, rec=0;
using namespace std;
struct stack {
	struct stack *next;
	int data;
};
struct Queue {
	stack *head;
	stack *tail;
	int data;
};
void FillIncStack (struct stack **head, int n);
void FillDecStack (struct stack **head, int n);
void FillRandStack (struct stack **head, int n);
void DeleteStack (struct stack **head);
void CheckSumStack (struct stack *head);
void RunNumberStack (struct stack *head);
void PrintStack (struct stack *head);
void FillIncQueue (struct stack **head, struct stack **tail, int n);
void FillDecQueue (struct stack **head, struct stack **tail, int n);
void FillRandQueue (struct stack **head, struct stack **tail, int n);
void DeleteQueue (struct stack **head, struct stack **tail);
void PrintQueue (struct stack *head);
main() {
	stack *head, *tail;
	head=NULL;
	tail=(stack*)&head;
	int n;
	int i;
	printf ("Input C: ");
	scanf("%d", &n);
	printf ("Stack: ");
	cout << endl;
	FillRandStack (&head, n);
	PrintStack (head);
	CheckSumStack (head);
	RunNumberStack (head);
	DeleteStack (&head);
	cout << endl;
		FillIncStack (&head, n);
	PrintStack (head);
	CheckSumStack (head);
	RunNumberStack (head);
	DeleteStack (&head);
	cout << endl;
		FillDecStack (&head, n);
	PrintStack (head);
	CheckSumStack (head);
	RunNumberStack (head);
	DeleteStack (&head);
	cout << endl;
    printf("Ochered:");
    cout<<endl;
    FillRandQueue (&head, &tail,n);
    PrintQueue  (head);
    DeleteQueue(&head, &tail);
    cout<<endl;
        FillIncQueue (&head, &tail,n);
    PrintQueue  (head);
    DeleteQueue(&head, &tail);
    cout<<endl;
        FillDecQueue (&head, &tail,n);
    PrintQueue  (head);
    DeleteQueue(&head, &tail);
    cout<<endl;
    
	system("PAUSE");
	return 0;
}

void FillInc (int A[], int n) {
	int i;
	for ( i = 0; i < n; i ++ ) A[i] = i+1;
}

void FillIncStack (struct stack **head, int n) {
	int i;
	struct stack *p;
	for (i=n; i>0; i--) {
		p=(stack *)malloc(sizeof(struct stack));
		p->data=i;
		p->next=*head;
		*head=p;
	}
}
void FillIncQueue (struct stack **head, struct stack **tail, int n) {
	int i;
	struct stack *p;
	for (i=1; i<=n; i++) {
		p=(stack *)malloc(sizeof(struct stack));
		p->data=i;
		(*tail)->next=p;
		*tail=p;
	}
	(*tail)->next=NULL;
}
void FillDecStack (struct stack **head, int n) {
	int i;
	struct stack *p;
	for (i=1; i<=n; i++) {
		p=(stack *)malloc(sizeof(struct stack));
		p->data=i;
		p->next=*head;
		*head=p;
	}
}
void FillDecQueue (struct stack **head, struct stack **tail, int n) {
	int i;
	struct stack *p;
	for (i=n; i>0; i--) {
		p=(stack *)malloc(sizeof(struct stack));
		p->data=i;
		(*tail)->next=p;
		*tail=p;
	}
	(*tail)->next=NULL;
}
void FillRandStack (struct stack **head, int n) {
	int i, a=0, b=2*n;
	srand(time(NULL));
	struct stack *p;
	for (i=n; i>0; i--) {
		p=(stack *)malloc(sizeof(struct stack));
		p->data=random(b-a+1)+a;
		p->next=*head;
		*head=p;
	}
}
void FillRandQueue (struct stack **head, struct stack **tail, int n) 
{
	int i, a=0, b=2*n;
	srand(time(NULL));
	struct stack *p;
	for (i=n; i>0; i--) 
    {
		p=(stack *)malloc(sizeof(struct stack));
		p->data=random(b-a+1)+a;;
		(*tail)->next=p;
		*tail=p;
	}
	(*tail)->next=NULL;
}
void DeleteStack (struct stack **head) {
	int i;
	struct stack *p=*head;
	while (p!=NULL) {
		*head=p->next;
		free (p);
		p=*head;
	}
}
void DeleteQueue (struct stack **head, struct stack **tail) 
{
	DeleteStack (head);
	*tail=NULL;
	*tail=(stack*)&(*head);
}

void CheckSumStack (struct stack *head) {
	int s=0;
	struct stack *p=head;
	while (p!=NULL) {
		s+=p->data;
		p=p->next;
	}
	printf ("\nCheckSum = %d", s);
}


void RunNumberStack (struct stack *head) {
	int c=1;
	if (head!=NULL) {
		struct stack *p=head, *q=p->next;	
		while (q!=NULL) {
			if (p->data>q->data) c++;
			p=p->next;
			q=p->next;
		}
		printf ("\nRunNumber = %d\n", c);
	}
	else printf ("\nRunNumber = %d\n", 0);
}


void PrintStack (struct stack *head) {
	struct stack *p=head;
	while (p!=NULL) {
		printf ("%3d ", p->data);
		p=p->next;
	}
}
void PrintQueue (struct stack *head) 
{
	struct stack *p=head;
	while (p!=NULL) {
		printf ("%3d ", p->data);
		p=p->next;
	}
}

void Swap (int &x, int &y) {
	int t=x; x=y; y=t;
}

