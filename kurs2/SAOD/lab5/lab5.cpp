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
bool boolean = false;

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

void SDP (int x, Vertex *&Tree)
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

float Razmer (Vertex *&MyTree)
{
	if (MyTree == NULL)
	return 0;
	else
	return (1+Razmer(MyTree->Left)+Razmer(MyTree->Right));
}

float Summ (Vertex *&MyTree)
{
	if (MyTree == NULL)
	return 0;
	else
	return (MyTree->Data+Summ(MyTree->Left)+Summ(MyTree->Right));
}

float Height(Vertex *&MyTree)
{
	if(MyTree == NULL)
	return 0;
	else
	return (1+max(Height(MyTree->Left),Height(MyTree->Right)));
}

float max(int a, int b)
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

void LL1(Vertex *&Tree)
{
	Vertex *q = NULL;
	q = Tree->Left;
		if (q->Balance == 0)
		{
			q->Balance = 1;
			Tree->Balance = -1;
			boolean = false;
		}
		else
		{
			Tree->Balance = 0;
			q->Balance = 0;
		}
			Tree->Left = q->Right;
			q->Right = Tree;
			Tree = q; 
}

void RR1 (Vertex *&Tree)
{
	Vertex *q = NULL;
	q = Tree->Right;
	if (q->Balance == 0)
	{
		Tree->Balance = 1;
		q->Balance = -1;
		boolean = false;
	}
	else
	{
		Tree->Balance = 0;
		q->Balance = 0;
	}
		Tree->Right = q->Left;
		q->Left = Tree;
		Tree = q;
}

void BL(Vertex *&Tree)
{
	if (Tree->Balance == -1)
	{
	Tree->Balance = 0;
	}
		else if (Tree->Balance == 0) 
		{
		Tree->Balance = 1;
		boolean = false;
		}
		else if (Tree->Balance == 1)
		{
			if (Tree->Left->Balance == 0) RR1(Tree);
			else 
			{
			ABL_RL(Tree);
			}
		}
}
void BR(Vertex *&Tree)
{
	if (Tree->Balance == 1)
	{
	Tree->Balance = 0;
	}
		else if (Tree->Balance == 0) 
		{
		Tree->Balance = -1;
		boolean = false;
		}
		else if (Tree->Balance == -1)
		{
			if (Tree->Left->Balance <= 0) LL1(Tree);
			else 
			{
			ABL_LR(Tree);
			}
		}
}

void dela(Vertex *&Tree)
{
	Vertex *q = NULL;
	q = Tree;
	if(Tree->Right != NULL)
	{
		dela(Tree->Right);
		if (boolean == true) BR(Tree);
	}
	else
	{
		q->Data = Tree->Data;
		q = Tree;
		Tree = Tree->Left;
		boolean = true;
	}
}


void Delete_ABL(int x, Vertex *&Tree)
{
	Vertex *q = NULL;
	if(!Tree)
	{
		Tree = new Vertex;
		Tree->Data = x;
		Tree->Left = Tree->Right = NULL;
		Tree->Balance = 0;
		boolean = true;
	}
	else if (Tree->Data > x)
	{
		Delete_ABL(x, Tree->Left);
		if (boolean == true) BL(Tree);
	}
	else if (Tree->Data < x)
	{
		Delete_ABL(x, Tree->Right);
		if (boolean == true) BR (Tree);
	}
	else
	{
		q = Tree;
	 if (q->Left == 0)
	{
	 	Tree = q->Right;
	 	boolean = true;
	}
	 else if (q->Right == 0)
	{
	 	Tree = q->Left;
	 	boolean = true;
	}
	 else 
	{
		dela (Tree->Left);
		if (boolean == 1) BL(Tree);
	}
	}
}

int main()
{
	setlocale(LC_CTYPE,"rus");
	int *A, M, element_search, *B, element_delet, r, s, h, ha, j;
	srand (time(0));
	Vertex *Tree = NULL;
	cout << "Введите кол-во вершин для АВЛ: ";
	cin >> M;
	Tree = NULL;
	for (int i = 0; i < M; i++) ABL_create(i, Tree);
	cout << endl << "АВЛ" << endl << "Обход слева на право: ";
	show(Tree);
	cout << "\nВведите переменную, который желаете удалить: ";
	cin>>element_delet;
	Delete_ABL(element_delet, Tree);
	show(Tree);
	cout << "\nВведите 10 переменных, которые желаете удалить: ";
	for ( int o = 0; o<12; o++)
	{
		cin >> j;
		Delete_ABL(j, Tree);
	}
	cout << endl << "Обход слева на право: ";
	show(Tree);
	cout<<endl<<"Размер дерева = "<<Razmer(Tree)<<endl;
	cout<<"Сумма дерева = "<<Summ(Tree)<<endl;
	cout<<"Высота дерева = "<<Height(Tree)<<endl;
	cout<<"Средняя высота дерева = "<<Height_average(Tree)<<endl;
	del(Tree);
	return 0;
}
