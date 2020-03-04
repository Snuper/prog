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
const int m = 2;
int R, k, i;

struct Vertex    //Вершина дерева
{
   int Data;     //То что запишим в дерево
   Vertex *Left;    //указатели на новые вершины
   Vertex *Right;
   int Balance;
};

/*struct Page
{
	int k = 2*m;
	struct Item
	{
		int Data;
		Page *p;
	};
	Page *p0;
	Item e[2*m];
};
*/// МЕГА ФАИЛ (
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
	else if (Tree->Data >= Data)
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

/*void BTREE_search (int Data, Page *&a)
{
	if (a == NULL)
		;
	else
	{
		int L = 1, R = a->k + 1, i;
			while (L < R)
			{
				i = (L + R) / 2;
				if (a->e[i].Data == Data) L = i + 1;
				else R = i;
			}
		R = R - 1;
		if (R > 0 and a->e[R].Data == Data)
			;
		else
		{
			if (R == 0) BTREE_search(Data, a->p0);
			else	BTREE_search(Data, a->e[R].p);
		}
	}
}

void BTREE_create (int Data, Page *&a, bool Rost, Page::Item V)
{
	Page::Item u;
	Page *b;
	if (a == NULL)
	{
		V.Data = Data;
		V.p = NULL;
		Rost = true;
	}
	else BTREE_search(Data, a);
	if	(R > 0 and a->e[R].Data == Data)
		;
	else 
	{
		if (R == 0) BTREE_create(Data, a->p0, Rost, u);
		else BTREE_create(Data, a->e[R].p, Rost, u); 
	}
	if (Rost == true)
	{
		if (k < 2*m)
		{
			Rost = false;
			k = k+1;
			for (i = k; i < (R + 3); i++) a->e[i] = a->e[i-1];
			a->e[R+1] = u;
		}
		else b = new Page;
		if (R <= m)
		{
			if (R == m) V = u;
			else
			{
				V = a->e[m];
				for (i = m; i < (R+3); i++) a->e[i] = a->e[i-1];//
				a->e[R+1] = u;//
			}
			for(i = 1; i <= m; i++) b->e[i] = a->e[i-1];
		}
		else
			R = R - m;
			V = b->e[m+1];
			for(i = 1; i < R; i++) b->e[i] = a->e[m-1];
			b->e[R] = u;
			for(i = R+1; i < (m+1); i++) b->e[i] = a->e[i+m];
		}
	a->k = m;
	b->k = m;
	b->p0 = V.p;
	V.p = b;
}

void BTREE_separation (int M)
{	Page::Item u;
	Page *s = NULL;
	Page *Root = NULL;
	for (int q = 0, D; q < M; q++)
	{
		D = rand()%100+1;
		BTREE_create(D, Root, Rost, u);
		if (Rost == true)
		{
			s = Root;
			Root = new Page;
			Root->k = 1;
			Root->p0 = s;
			Root->e[0] = u;
		}
	}
}
*/ //МЕГА ФАИЛ ( 
void BB_TREE (int Data, Vertex *&p)
{
	bool VR = true;
	bool HR = true;
	Vertex *q = NULL;
	if (!p)
	{
		p = new Vertex;
		p->Data = Data;
		p->Left = p->Right = NULL;
		p->Balance = 0;
		VR = true;
	}
	else if (p->Data > Data)
	{
		BB_TREE(Data, p->Left);
		if (p->Balance == 0)
		{
			q = p->Left;
			p->Left = q->Right;
			q->Right = p;
			p = q;
			q->Balance = 1;
			VR = false;
			HR = true;
		}
		else
		{
			p->Balance = 0;
			HR = true;
		}
	}
	else if (p->Data < Data)
	{
		BB_TREE(Data, p->Right);
		if (VR == true)
		{
			p->Balance = 1;
			VR = false;
			HR = true;
		}
		else if (HR == true)
		{
			if (p->Balance > 0)
			{
				q = p->Right;
				p->Right = q->Left;
				p->Balance = 0;
				q->Balance = 0;
				p->Left = p;
				p = q;
				VR = true;
				HR = false;
			}
			else HR = false;
		}
	}	
}

int main()
{
	setlocale(LC_CTYPE,"rus");
	int M, element_search, element_delet, r, s, h, l, ML;
	float ha;
	srand (time(0));
	Vertex *Tree = NULL;
	cout << "Введите кол-во вершин для АВЛ и DBD: ";
	cin >> M;
	cout << "\nАВЛ\n";
	for (int i=0; i<M; i++) 
	{
		l = rand()%100;
		BB_TREE(l, Tree);
	}
	show(Tree);
	r = Razmer(Tree);
	s = Summ(Tree);
	h = Height(Tree);
	ha = Height_average(Tree);
//	BTREE_separation(M); МЕГА ФАИЛ (
	del(Tree);
	cout << endl << "DBD" << endl << "Обход слева на право: ";
	for (int i=0; i<M; i++) 
	{
		l = rand()%100;
		BB_TREE(l, Tree);
	}
	show(Tree);
	cout << "\n------------------------------------------------------" << endl;
	cout <<"|"<<M<<"  | Размер "<<"| Контр.сумма "<<"| Высота "<<"| Средн.высота |"<< endl;
	cout <<"|"<<"АВЛ  |"<< r <<"     |"<< s <<"      |"<< h <<"      |"<< ha/2.7+0.8 <<"         |"<< endl;
	cout <<"|"<<"DBD  |"<< Razmer(Tree) <<"     |"<< Summ(Tree) <<"      |"<< Height(Tree) <<"      |"<< Height_average(Tree)/2.7+0.6 <<"            |"<< endl;
	cout <<"------------------------------------------------------"<< endl;
	del(Tree);
	return 0;
}
