#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <conio.h>

int random (int N) { return rand()%N; }
int mp=0, cp=0, rec=0;
using namespace std;
void FillIncStack (struct stack **head, int n);
void FillDecStack (struct stack **head, int n);
void FillRandStack (struct stack **head, int n);
void DeleteStack (struct stack **head);
void CheckSumStack (struct stack *head);
void RunNumberStack (struct stack *head);
void PrintStack (struct stack *head);
void StackToQueue (struct stack **head, struct stack **tail);
void MergeS (stack **head_a, stack **head_b, stack **tail, int q, int r);
void Split (stack **head, stack **head_a, stack **head_b);
void Swap (int &x, int &y);
void ResultOld (int n);
void ResultTabl (int n);
void MergeSort (stack **head, stack **tail, int n);
void WorkDec (int n, int i);
void WorkInc (int n, int i);
void WorkRand (int n, int i);
void WorkRand1 (int A[], int n, int i);

int *a1,*a2,*a3;
struct stack {
	struct stack *next;
	int data;
};

struct New {
	stack *head;
	stack *tail;
};

void FillRand (int A[], int n) {
	int i;
	for ( i = 0; i < n; i ++ ) A[i] = rand()%10;
}

main() {
    srand(time(NULL));
    	int a_1 [10];
	int a_2 [10];
	int a_3 [10];
	for (int n = 100, j = 0; n <1001, j < 10; n += 100, j ++) {
		
    	a1 = new int [n+1]; // rand
    	a2 = new int [n+1]; //inc
    	a3 = new int [n+1]; // rand
    	FillRand(a1, n);
    	FillRand(a2, n);
    	WorkRand1 (a3, n, 0);
    	a_1[j]=a1[n];
    	a_2[j]=a2[n];
    	a_3[j]=a3[n];
    	delete a1;
    	delete a2;
    	delete a3;
    }
	stack *head, *tail;
	head=NULL;
	tail=(stack*)&head;
	int n;
	printf ("Input C: ");
	scanf("%d", &n);
	int A[n];
	FillRandStack (&head, n);
	PrintStack (head);
	CheckSumStack (head);
	RunNumberStack (head);
	printf ("\n");
	MergeSort (&head, &tail, n);
	PrintStack (head);
	CheckSumStack (head);
	RunNumberStack (head);
	ResultOld (n);
	printf ("\n");
	ResultTabl (100);
	printf ("\n\n\n");
	system("PAUSE");
	return 0;
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

void FillRandStack (struct stack **head, int n) {
	int i, a=0, b=2*n;
	struct stack *p;
	for (i=n; i>0; i--) {
		p=(stack *)malloc(sizeof(struct stack));
		p->data=rand()%10;
		p->next=*head;
		*head=p;
	}
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

void CheckSum (int A[], int n) {
	int i, s;
	for (s=0, i=0; i< n; i++) s+=A[i];
	printf ("\n%d", s);
}

void CheckSumStack (struct stack *head) {
	int s=0;
	struct stack *p=head;
	while (p!=NULL) {
		s+=p->data;
		p=p->next;
	}
	printf ("\n%d", s);
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
		printf ("\n%d\n", c);
	}
	else printf ("\n%d\n", 0);
}


void PrintStack (struct stack *head) {
	struct stack *p=head;
	while (p!=NULL) {
		printf ("%3d ", p->data);
		p=p->next;
	}
}


void StackToQueue (struct stack **head, struct stack **tail) {
	(*tail)->next=*head;
	*tail=*head;
	*head=(*head)->next;
	(*tail)->next=NULL;
}



void Split (stack **head, stack **head_a, stack **head_b) {
	stack *k, *p;
	*head_a=*head;
	*head_b=(*head)->next;
	k=*head_a;
	p=*head_b;
	mp+=4;
	while (p!=NULL) {
		k->next=p->next;
		k=p;
		p=p->next;
		mp+=2;
	}
}
 
void Swap (int &x, int &y) {
	int t=x; x=y; y=t;
}

void ResultOld (int n) {
	//printf ("\nC(t)=%f, M(t)=%f, T(t)=%f", n*log2(n), n*log2(n), 2*n*log2(n));
	//printf ("\nC(p)=%d, M(p)=%d, T(p)=%d", cp, mp, cp+mp);
}


void ResultTabl (int n) {
	int i;
	cout<<  " _________________________________"<<endl;
	cout<<  "|  n   |   MergeSort (m(f)+c(f))  |"<<endl;
	cout<<  "|      |--------------------------|"<<endl;
	cout<<"|      |   Inc  |   Dec  |  Rand  |"<<endl;
	cout<<"|------|--------|--------|--------|";
	for (; n<=500; n+=100) {
		printf ("\n| %4d |", n);
		WorkInc (n, 0);
		printf (" %6.d |", cp+mp);
		WorkDec (n, 0);
		printf (" %6.d |", cp+mp);
		WorkRand (n, 0);
		printf (" %6.d |", cp+mp);
		cout<<endl;
		cout<<"|------|--------|--------|--------|";
	}
}

void MergeSort (stack **head, stack **tail, int n) {
	int i, m, q, p=1, r;
	stack *a=NULL, *b=NULL;
	New c[2];
	Split (head, &a, &b);
	while (p<n) {
		c[0].tail=(stack*)&c[0].head;
		c[1].tail=(stack*)&c[1].head;
		i=0;
		m=n;
		while (m>0) {
			if (m>=p) q=p;
			else q=m;
			m-=q;
			if (m>=p) r=p;
			else r=m;
			m-=r;
			MergeS (&a, &b, &c[i].tail, q, r);
			i=1-i;
		}
		a=c[0].head;
		b=c[1].head;
		p*=2;
	}
	c[0].tail->next=NULL;
	*head=c[0].head;
}

void MergeS (stack **head_a, stack **head_b, stack **tail, int q, int r) {
	while (q!=0 && r!=0) {
		cp++;
		if ((*head_a)->data<=(*head_b)->data) {
			StackToQueue (head_a, tail);
			mp++;
			q--;
		}
		else {
			StackToQueue (head_b, tail);
			mp++;
			r--;
		}
	}
	while (q>0) {
		StackToQueue (head_a, tail);
		mp++;
		q--;
	}
	while (r>0) {
		StackToQueue (head_b, tail);
		mp++;
		r--;
	}
}

void WorkDec (int n, int i) {
	mp=0; cp=0;
	int A[n];
	switch (i) {
		case 0: 
			stack *head, *tail;
			head=NULL;
			tail=(stack*)&head;
			FillDecStack (&head, n);
			MergeSort (&head, &tail, n);
			break;
	}
}

void WorkInc (int n, int i) {
	mp=0; cp=0;
	int A[n];
	switch (i) {
		case 0: 
			stack *head, *tail;
			head=NULL;
			tail=(stack*)&head;
			FillIncStack (&head, n);
			MergeSort (&head, &tail, n);
			break;
	}
}

void WorkRand (int n, int i) {
	mp=0; cp=0;
	int A[n];
	switch (i) {
		case 0: 
			stack *head, *tail;
			head=NULL;
			tail=(stack*)&head;
			FillRandStack (&head, n);
			MergeSort (&head, &tail, n);
			break;
	}
}
void WorkRand1 (int A[], int n, int i) {
	switch (i) {
		case 0: 
			stack *head, *tail;
			head=NULL;
			tail=(stack*)&head;
			FillRandStack (&head, n);
			MergeSort (&head, &tail, n);
			break;
	}
	A[n]=mp+cp;
}

