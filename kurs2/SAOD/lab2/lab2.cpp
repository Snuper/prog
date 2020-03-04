/*
*/
//#include "functions_tree.h"  попитка - фаил
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;


struct Vertex    //Вершина дерева
{
   int Data;     //То что запишим в дерево
   Vertex *Left;    //указатели на новые вершины
   Vertex *Right;
};

int show(Vertex *&Tree)              //функция обхода с лево на право
{
	if (Tree != NULL)               //Пока не встретит пустую вершину
	{
//		cout<<"42"<<endl;
		show(Tree->Left);
		cout<<" "<<Tree->Data;
		show(Tree->Right);
		return Tree->Data;
	}
}

void del(Vertex *&Tree)	//Очистка памяти
{
   if (Tree != NULL)
	{
//	   cout<<"42"<<endl;
	   del(Tree->Left);
	   del(Tree->Right);
	   delete Tree;
	   Tree = NULL;
	}
 
}

Vertex* ISDP(int L, int R, int *a, int m) 
{	
	if (L > R)
	return NULL;
	else
	m=(L+R)/2;
	Vertex *p = new Vertex;
	p->Data = a[m];
	p->Left = ISDP(L, m - 1, a, m);
	p->Right = ISDP(m + 1, R, a, m);
	return p;
}

void SDP(int x,Vertex *&Tree)
{
	if (NULL == Tree)
	{
		Tree = new Vertex;
		Tree->Data = x;
		Tree->Left = Tree->Right = NULL;
	}
	if (x < Tree->Data)
	{
		if (Tree->Left != NULL) SDP(x, Tree->Left);
			else
			{
				Tree->Left = new Vertex;
				Tree->Left->Left = Tree->Left->Right = NULL;
				Tree->Left->Data = x;
			}
	}
	if (x > Tree->Data)
	{
		if (Tree->Right != NULL) SDP(x, Tree->Right);
			else
			{
				Tree->Right = new Vertex;
				Tree->Right->Left = Tree->Right->Right = NULL;
				Tree->Right->Data = x;
			}
	}
}

void SDP_plusvertex (int Data, Vertex *&Tree) //Двойная косвенность - добавление вершины
{
Vertex **p;
p = &Tree;
while (*p != NULL)
	{
		if (Data < (*p)->Data) p = &((*p)->Left);
		else if (Data > (*p)->Data) p = &((*p)->Right);
	}
	if (*p == NULL)
	{
		*p = new Vertex;
		(*p)->Left = (*p)->Right = NULL;
		(*p)->Data = Data;
	}
}

float Razmer (Vertex *&MyTree)
{
	if (MyTree == NULL)
	return 0;
	else
	return (1+Razmer(MyTree->Left)+Razmer(MyTree->Right));
}

int Summ (Vertex *&MyTree)
{
	if (MyTree == NULL)
	return 0;
	else
	return (MyTree->Data+Summ(MyTree->Left)+Summ(MyTree->Right));
}

int Height(Vertex *&MyTree)
{
	if(MyTree == NULL)
	return 0;
	else
	return (1+max(Height(MyTree->Left),Height(MyTree->Right)));
}

int max(int a, int b)
{
	if (a<b)
	return a;
	else
	return b;
}

float Summ_root(Vertex *&MyTree, int h)
{
	if ( MyTree == NULL )
	return 0;
	else
	return (h + Summ_root(MyTree->Left, h+1)+Summ_root(MyTree->Right, h+1));
}

float Height_average(Vertex *&MyTree)
{
	return (Summ_root(MyTree, 1)/Razmer(MyTree));
}

int main()
{
	setlocale(LC_CTYPE,"rus");
	int x = 0, M, *A, m = 0, element, *B, a, b, n, s, *C, n1, a2, b3;
	float c, c4;
	srand (time(0));
	cout << "Введите кол-во вершин для ИСДП и СДП: ";
	cin >> M;
	cout << endl;
	A = new int [M]; 		
	for (int i=0; i<M; i++) A[i] = i*i;
	Vertex *Tree = ISDP(0, M-1, A, m);
	cout << "\nИСДП\n";
	cout << endl << "Обход слева на право:";
	show(Tree);
	n = Razmer(Tree);
	a = Summ(Tree);
	b = Height(Tree);
	c = Height_average(Tree);
	del(Tree);
	cout << "\nСДП\n";
	B = new int [M];
	for (int i=0; i<M; i++) 
	{
		B[i] = rand();
	}
	for (int i=0; i<M; i++) SDP(B[i], Tree);
	n1 = Razmer(Tree);
	a2 = Summ(Tree);
	b3 = Height(Tree);
	c4 = Height_average(Tree);
	cout << endl << "Обход слева на право:";
	show(Tree);
	cout << "\nСДП - Двойная косвенность"<<endl;
	del(Tree);
	C = new int [M];
	for (int i=0; i<M; i++) 
	{
		C[i] = rand();
	}
	for (int i=0; i<M; i++) SDP_plusvertex(C[i], Tree);
	show(Tree);
	cout << "\n------------------------------------------------------" << endl;
	cout <<"|"<<M<<"  | Размер "<<"| Контр.сумма "<<"| Высота "<<"| Средн.высота |"<< endl;
	cout <<"|"<<"ИСДП |"<< n <<"     |"<< a <<"       |"<< b <<"       |"<< c <<"             |"<< endl;
	cout <<"|"<<"СДП  |"<< n1 <<"     |"<< a2 <<"      |"<< b3 <<"      |"<< c4 <<"             |"<< endl;
	cout <<"|"<<"DVO  |"<< Razmer(Tree) <<"     |"<< Summ(Tree) <<"      |"<< Height(Tree) <<"      |"<< Height_average(Tree) <<"             |"<< endl;
	cout <<"------------------------------------------------------"<< endl;
	del(Tree);
	return 0;
}
