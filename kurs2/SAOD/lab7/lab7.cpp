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
int R, k = 0, i;

struct Vertex    //Вершина дерева
{
   int Data;     //То что запишим в дерево
   Vertex *Left;    //указатели на новые вершины
   Vertex *Right;
   int Weight;
};

void SDP (int x, Vertex *&Tree, int p) //Двойная косвенность - добавление вершины
{
	if (!Tree)
	{
		Tree = new Vertex;
		Tree->Weight = x;
		Tree->Data = p;
		cout << "ROOT = " << Tree->Data << " " << Tree->Weight << endl;
		Tree->Left = Tree->Right = NULL;
	}
	else
	{
		if (x < Tree->Weight)
		{
			if (Tree->Left != NULL) SDP(x, Tree->Left, p);
				else
				{
					Tree->Left = new Vertex;
					Tree->Left->Left = Tree->Left->Right = NULL;
					Tree->Left->Weight = x;
					Tree->Left->Data = p;
					cout << "LEFT = " << Tree->Left->Data << " " << Tree->Left->Weight << endl;
				}
		}
		else if (x >= Tree->Weight)
		{
			if (Tree->Right != NULL) SDP(x, Tree->Right, p);
				else
				{
					Tree->Right = new Vertex;
					Tree->Right->Left = Tree->Right->Right = NULL;
					Tree->Right->Weight = x;
					Tree->Right->Data = p;
					cout << "RIGHT = " << Tree->Right->Data << " " << Tree->Right->Weight << endl;
				}
		}
	}
}

int show(Vertex *&Tree)              //функция обхода с лево на право
{
	if (Tree != NULL)               //Пока не встретит пустую вершину
	{
		show(Tree->Left);
		cout<<Tree->Data<<"(" <<Tree->Weight << ") ";
		show(Tree->Right);
		return Tree->Data;
	}
}

void del(Vertex *&Tree)	//Очистка памяти
{
   if (Tree != NULL)
	{
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

void Matrix_W (int **W, int M, int SUMM)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = i + 2; j < M; j++)
		{
			W[i][j] = W[i][j-1] + W[i+1][j];
//			cout << i << " " << j << " " << W[i][j] << endl;
		}
	}
	W[0][M - 1] = SUMM;
//	cout << 0 << " " << M - 1 << " " << W[0][M - 1] << endl;
}

void Matrix_P_R (int **P, int **R, int M, int **W)
{
	int m, x, k, min = 0, i = 0, h = 2, j = 0;
	for (; h < M; h++)
	{
		for (i = 0; i < M - h; i++)
		{
			j = i + h;
			m = R[i][j-1];
			min = P[i][m-1] + P[m][j];
			for (k = m+1; k < R[i+1][j]; k++)
			{
				x = P[i][k-1] + P[k][j];
				if (x <= min)
				{
					m = k;
					min = x;
				}
			}
			P[i][j] = min + W[i][j];
			R[i][j] = m;
		}
	}
}

void Create_DOP (int l, int r, Vertex *&Mytree, Vertex *V, int **R)
{
	if (l < r)
	{
//		cout << l << " " << r << " " << R[l][r] << endl;
		k = R[l][r];
		SDP(V[k].Weight, Mytree, V[k].Data);
		Create_DOP(l, k-1, Mytree, V, R);
		Create_DOP(k, r, Mytree, V, R);
	}
}

float Summ_weight_average (Vertex *&MyTree, int h)
{
	if (MyTree == NULL)
	return 0;
	else
	return (h*(MyTree->Weight)+Summ_weight_average(MyTree->Left, h+1)+Summ_weight_average(MyTree->Right, h+1));
}

int main()
{
	setlocale(LC_CTYPE,"rus");
	int M, i, j, z = 0;
	srand (time(0));
	Vertex *Tree = NULL;
	cout << "Введите кол-во вершин для DOP: ";
	cin >> M;
	int q = M, SUMM = 0;
	
	int **R = new int* [M];
	for ( i=0; i<M; i++) R[i] = new int [M];
	
	int **P = new int* [M];
	for ( i=0; i<M; i++) P[i] = new int [M];
	
	Vertex *V = new Vertex [M];
	for (i = 0; i < M; i++)
	{
		V[i].Weight = rand()&100 + 0;
		V[i].Data = rand()&100 + 0;
		z += V[i].Weight;
	}
	
	int **W = new int* [M];		
	for (i=0; i<M; i++) W[i] = new int [M];
	
	for (i = 0, j = 0; i < M; i++, j++)
	{
		W[i][j] = 0;
		P[i][j] = 0;
		R[i][j] = 0;
	}
	for (i = 0, j = 1, q = 0; i < M - 1; i++, j++, q++) 
	{
		SUMM = SUMM + V[q].Weight;
		W[i][j] = V[q].Weight;
		P[i][j] = V[q].Weight;
		R[i][j] = i + 1;
//		cout << i << " " << j << " " << P[i][j] << endl;
	}
	
	Matrix_W(W, M, SUMM);
	Matrix_P_R(P, R, M, W);
	cout << "W" << endl;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			cout << W[i][j] << " ";
		}
		cout << endl;
	}
	cout << "W" << endl;
	
	cout << "P" << endl;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			cout << P[i][j] << " ";
		}
		cout << endl;
	}
	cout << "P" << endl;
	
	cout << "R" << endl;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			cout << R[i][j] << " ";
		}
		cout << endl;
	}
	cout << "R" << endl;
	
	Create_DOP(0, M-1, Tree, V, R);
	
	cout << "\nDOP\n";
	Razmer(Tree);
	Summ(Tree);
	Height(Tree);
	Height_average(Tree);
	show(Tree);
	cout << "\n------------------------------------------------------" << endl;
	cout <<"|"<<M<<"  | Размер "<<"| Контр.сумма "<<"| Средн.Взв.высота |"<< endl;
	cout <<"|"<<"DOP  |"<< Razmer(Tree) <<"     |"<< Summ(Tree) <<"         |"<< Summ_weight_average(Tree, 0)/z<<"           |"<< endl;
	cout <<"------------------------------------------------------"<< endl;
	del(Tree);
	return 0;
}
