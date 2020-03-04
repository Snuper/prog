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
if (NULL == Tree)
	{
		Tree = new Vertex;
		Tree->Weight = x;
		Tree->Data = p;
//		cout << "ROOT = " << Tree->Data << " " << Tree->Weight << endl;
		Tree->Left = Tree->Right = NULL;
	}
	if (x <= Tree->Weight)
	{
		if (Tree->Left != NULL) SDP(x, Tree->Left, p);
			else
			{
				Tree->Left = new Vertex;
				Tree->Left->Left = Tree->Left->Right = NULL;
				Tree->Left->Weight = x;
				Tree->Left->Data = p;
//				cout << "LEFT = " << Tree->Left->Data << " " << Tree->Left->Weight << endl;
			}
	}
	if (x > Tree->Weight)
	{
		if (Tree->Right != NULL) SDP(x, Tree->Right, p);
			else
			{
				Tree->Right = new Vertex;
				Tree->Right->Left = Tree->Right->Right = NULL;
				Tree->Right->Weight = x;
				Tree->Right->Data = p;
//				cout << "RIGHT = " << Tree->Right->Data << " " << Tree->Right->Weight << endl;
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
	/*for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			cout << "P" << " " << i << " " << j << " " << P[i][j] << endl;
//			cout << "R" << " " << i << " " << j << " " << R[i][j] << endl;
			cout << "W" << " " << i << " " << j << " " << W[i][j] << endl;
		}
	}*/
	for (; h < M; h++)
	{
		for (i = 0; i < M - h; i++)
		{
			j = i + h;
//			cout << R[i][j-1] << endl;
			m = R[i][j-1];
//			cout << "m = " << m << endl;
//			cout << "M = " << M-2 << endl;
				min = P[i][m-1] + P[m][j];
			
//			cout << "P = " << i << " " << m - 1 << " " << P[i][m-1] << endl;
//			cout << "P = " << m << " " << j << " "  << P[m][j] << endl;
			
//			cout << "min = " << min << endl;
//			cout << "R = " << R[i+1][j] << endl;
			for (k = m+1; k < R[i+1][j]; k++)
			{ 
				x = P[i][k-1] + P[k][j];
//				cout << "x = " << x << endl;
				if (x < min)
				{
//					cout << "ECKJDB= " << x << endl;
					m = k;
					min = x;
				}
			}
//			cout << "W = " << W[i][j] << endl;
//			cout << "MIN = " << min << endl;
			P[i][j] = min + W[i][j];
//			cout << "p = " << P[i][j] << endl;
			R[i][j] = m;
//			cout << "R = " << R[i+1][j] << endl;
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

void A1_create (Vertex *&MyTree, Vertex *V, int M)
{
	Vertex Swap;
	int i,j,t;
	for (i = 0; i < M-1; i++) 
	{ 
		for (j = M-1; j > i; j--) 
		{  
			if (V[j].Weight <= V[j-1].Weight) 
			{
				Swap=V[j];
				V[j]=V[j-1];
				V[j-1]=Swap;
			}
		}
	}
	for (i = 0; i < M-1; i++) SDP(V[i].Weight, MyTree, V[i].Data);	
}
 
void Create_A2 (Vertex *V, Vertex *&Mytree, int L, int R, int q, int M)
{
	q++;
	int wes = 0, summa = 0, i;
	if (L <= R and q < M-1)
	{
		for(i = L; L < R; L++) wes = wes + V[i].Weight;
			for(i = L; L < R-1; L++)
			{
				if ((summa < wes/2) and (summa + V[i].Weight) >= (wes/2))
				{
					summa = summa + V[i].Weight;
				}
			}
		SDP(V[i].Weight, Mytree, V[i].Data);
		Create_A2 (V, Mytree, L, i-1, q, M);
		Create_A2 (V, Mytree, i+1, R, q, M);
	}
}

int main()
{
	setlocale(LC_CTYPE,"rus");
	int M, i, j, z = 0, DOP_S, A_S, DOP_R, A_R;
	float DOP_SW, A_SW;
	srand (time(0));
	Vertex *Tree = NULL;
	cout << "Введите кол-во вершин для DOP|A1|A2: ";
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
	DOP_R = Razmer(Tree);
	DOP_S = Summ(Tree);
	DOP_SW = Summ_weight_average(Tree, 0)/z;
	del(Tree);
	
	A1_create(Tree, V, M);
	A_R = Razmer(Tree);
	A_S = Summ(Tree);
	A_SW = Summ_weight_average(Tree, 0)/z;
	
	Create_A2 (V, Tree, 0, M-1, 0, M);
	
	cout << "\n------------------------------------------------------" << endl;
	cout <<"|"<<M<<"  | Размер "<<"| Контр.сумма "<<"| Средн.Взв.высота |"<< endl;
	cout <<"|"<<"DOP  |"<< DOP_R <<"     |"<< DOP_S <<"         |"<< DOP_SW <<"           |"<< endl;
	cout <<"|"<<"A1  |"<< A_R <<"     |"<< DOP_S <<"         |"<< Summ_weight_average(Tree, 0)/z <<"           |"<< endl;
	cout <<"|"<<"A2  |"<< Razmer(Tree)-1 <<"     |"<< DOP_S <<"         |"<< A_SW <<"           |"<< endl;
	cout <<"------------------------------------------------------"<< endl;
	del(Tree);
	return 0;
}
