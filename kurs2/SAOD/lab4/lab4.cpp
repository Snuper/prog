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


bool Rost = false;

struct Vertex    //Вершина дерева
{
   int Data;     //То что запишим в дерево
   Vertex *Left;    //указатели на новые вершины
   Vertex *Right;
   int Balance;
};

int show(Vertex *&Tree)              //функция обхода с лево на право
{
	if (Tree != NULL)               //Пока не встретит пустую вершину
	{
//		cout<<"42"<<endl;
		show(Tree->Left);
		cout<<Tree->Data<<" ";
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

void SDP ( int x, Vertex *&Tree) //Двойная косвенность - добавление вершины
{
	if (!Tree)
	{
		Tree = new Vertex;
		Tree->Data = x;
		Tree->Left = Tree->Right = NULL;
	}
	else
	{
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
		else if (x >= Tree->Data)
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

float Summ_root(Vertex *&MyTree, float h)
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

void ABL_LL(Vertex *&Tree)
{
	Vertex *q = NULL;
	q = Tree->Left;
	q->Balance = 0;
	Tree->Balance = 0;
	Tree->Left = q->Right;
	q->Right = Tree;
	Tree = q;
}

void ABL_LR(Vertex *&Tree)
{
	Vertex *q = NULL;
	Vertex *r = NULL;
	q = Tree->Left; 
	r = q->Right;
	if (r->Balance < 0){
		Tree->Balance = 1;
	}else{
		Tree->Balance = 0;
	}
	if (r->Balance > 0){
		q->Balance = -1;
	}else{
		q->Balance = 0;
	}
	r->Balance = 0;
	q->Right = r->Left;
	Tree->Left = r->Right;
	r->Right = Tree;
	r->Left = q;
	Tree = r;
}

void ABL_RR(Vertex *&Tree)
{
	Vertex *q = NULL;
	q = Tree->Right;
	q->Balance = 0;
	Tree->Balance = 0;
	Tree->Right = q->Left;
	q->Left = Tree;
	Tree = q;
}

void ABL_RL(Vertex *&Tree)
{
	Vertex *r = NULL;
	Vertex *q = NULL;
	q = Tree->Right;
	r = q->Left;
	if (r->Balance > 0){
		Tree->Balance = -1;
	}else{
		Tree->Balance = 0;
	}
	if (r->Balance < 0){
		q->Balance = 1;
	}else{
		q->Balance = 0;
	}
	r->Balance = 0;
	q->Left = r->Right;
	Tree->Right = r->Left;
	r->Right = q;
	r->Left = Tree;
	Tree = r;
}

void ABL_create(int Data ,Vertex *&Tree)
{
	if (!Tree)
	{
		Tree = new Vertex;
		Tree->Data = Data;
		Tree->Left = Tree->Right = NULL;
		Tree->Balance = 0;
		Rost = true;
	}
	else if (Tree->Data > Data)
	{
		ABL_create(Data, Tree->Left);
		if (Rost)
		{
			if (Tree->Balance > 0)
			{
				Tree->Balance = 0;
				Rost = false;
			}
			else if (Tree->Balance == 0)
			{
				Tree->Balance = -1;
				Rost = true;
			}
			else if (Tree->Left->Balance < 0)
			{
				ABL_LL(Tree);
				Rost = false;
			}
			else
			{
				ABL_LR(Tree);
				Rost = false;
			}
		}
	}
	else if (Tree->Data < Data)
	{
		ABL_create(Data, Tree->Right);
		if (Rost)
		{
			if (Tree->Balance < 0)
			{
				Tree->Balance = 0;
				Rost = false;
			}
			else if (Tree->Balance == 0)
			{
				Tree->Balance = 1;
				Rost = true;
			}
			else if (Tree->Right->Balance > 0)
			{
				ABL_RR(Tree);
				Rost = false;
			}
			else
			{
				ABL_RL(Tree);
				Rost = false;
			}
		}
	}
}

int main()
{
	setlocale(LC_CTYPE,"rus");
	int *A, M, element_search, *B, element_delet, *F, r, s, h, ha;
	srand (time(0));
	Vertex *Tree = NULL;
	cout << "Введите кол-во вершин для СДП и АВЛ: ";
	cin >> M;
	cout << "\nСДП\n";
	B = new int [M];
	for (int i=0; i<M; i++) 
	{
		B[i] = rand();
	}
	for (int i=0; i<M; i++) SDP(B[i], Tree);
	cout << endl << "Обход слева на право: ";
	show(Tree);
	r = Razmer(Tree);
	s = Summ(Tree);
	h = Height(Tree);
	ha = Height_average(Tree);
	del(Tree);
	Tree = NULL;
	/*A = new int [M];
	for (int i=0; i<M; i++) 
	{
		A[i] = rand();
	}*/
	for (int i=0; i<M; i++) ABL_create(B[i], Tree);
	cout << endl << "АВЛ" << endl << "Обход слева на право: ";
	show(Tree);
	Razmer(Tree);
	Summ(Tree);
	Height(Tree);
	Height_average(Tree);
	cout << "\n------------------------------------------------------" << endl;
	cout <<"|"<<M<<"  | Размер "<<"| Контр.сумма "<<"| Высота "<<"| Средн.высота |"<< endl;
	cout <<"|"<<"СДП |"<< r <<"     |"<< s <<"       |"<< h <<"       |"<< ha <<"             |"<< endl;
	cout <<"|"<<"АВЛ  |"<< Razmer(Tree) <<"     |"<< Summ(Tree) <<"      |"<< Height(Tree) <<"      |"<< Height_average(Tree) <<"             |"<< endl;
	cout <<"------------------------------------------------------"<< endl;
	del(Tree);
	return 0;
}
