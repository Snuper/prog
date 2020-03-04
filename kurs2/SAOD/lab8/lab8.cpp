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
//		cout << "ROOT = " << Tree->Data << " " << Tree->Weight << endl;
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
//					cout << "LEFT = " << Tree->Left->Data << " " << Tree->Left->Weight << endl;
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
//					cout << "RIGHT = " << Tree->Right->Data << " " << Tree->Right->Weight << endl;
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

void BB_sort_A1(Vertex *V, int M)
{
	Vertex Swap;
	int j;
	for (i = 0; i < M-1; i++) 
	{ 
		for (j = M-1; j > i; j--) 
		{  
			if (V[j].Weight >= V[j-1].Weight) 
			{
				Swap=V[j];
				V[j]=V[j-1];
				V[j-1]=Swap;
			}
		}
	}
}

void BB_sort_A2(Vertex *V, int M)
{
	Vertex Swap;
	int j;
	for (i = 0; i < M-1; i++) 
	{ 
		for (j = M-1; j > i; j--) 
		{  
			if (V[j].Data >= V[j-1].Data) 
			{
				Swap=V[j];
				V[j]=V[j-1];
				V[j-1]=Swap;
			}
		}
	}
}

void A1_create (Vertex *&MyTree, Vertex *V, int M)
{
	BB_sort_A1(V, M);
	for (i = 0; i < M; i++) SDP(V[i].Weight, MyTree, V[i].Data);	
}
 
void Create_A2 (Vertex *V, Vertex *&Mytree, int L, int R)
{
	int wes = 0, sum = 0;
	if (L <= R)
	{
		for (i = L; i < R; i++) wes = wes + V[i].Weight;
		for (i = L; L < R - 1; L++)
		{
			if (sum < wes/2 and (sum + V[i].Weight) >= wes/2)
			{
				sum = sum + V[i].Weight;
			}
		}
		SDP(V[i].Weight, Mytree, V[i].Data);
		Create_A2 (V, Mytree, L, i-1);
		Create_A2 (V, Mytree, i+1, R);
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
	int q, SUMM = 0;
	
	int **R = new int* [M+1];
	for ( i=0; i<M+1; i++) R[i] = new int [M+1];
	
	int **P = new int* [M+1];
	for ( i=0; i<M+1; i++) P[i] = new int [M+1];
	
	Vertex *V = new Vertex [M];
	for (i = 0; i < M; i++)
	{
		V[i].Weight = rand()%28;
		V[i].Data = rand()%28;
		z += V[i].Weight;
	}
	
	int **W = new int* [M+1];		
	for (i=0; i<M+1; i++) W[i] = new int [M+1];
	
	for (i = 0, j = 0; i < M+1; i++, j++)
	{
		W[i][j] = 0;
		P[i][j] = 0;
		R[i][j] = 0;
	}
	for (i = 0, j = 1, q = 0; i < M; i++, j++, q++) 
	{
		SUMM = SUMM + V[q].Weight;
		W[i][j] = V[q].Weight;
		P[i][j] = V[q].Weight;
		R[i][j] = i+1;
//		cout << i << " " << j << " " << P[i][j] << endl;
	}
	
	Matrix_W(W, M+1, SUMM);
	Matrix_P_R(P, R, M+1, W);
	if (M < 31)
	{
	cout << "W" << endl;
	for (i = 0; i < M+1; i++)
	{
		for (j = 0; j < M+1; j++)
		{
			if (j < i) cout << 0 << " "; 
			else cout << W[i][j] << " ";
		}
		cout << endl;
	}
	cout << "W" << endl;
	}
	if (M < 31)
	{
	cout << "P" << endl;
	for (i = 0; i < M+1; i++)
	{
		for (j = 0; j < M+1; j++)
		{
			if (j < i) cout << 0 << " ";
			else cout << P[i][j] << " ";
		}
		cout << endl;
	}
	cout << "P" << endl;
	}
	if (M < 31)
	{
	cout << "R" << endl;
	for (i = 0; i < M+1; i++)
	{
		for (j = 0; j < M+1; j++)
		{
			if (j < i) cout << 0 << " ";
			else cout << R[i][j] << " ";
		}
		cout << endl;
	}
	cout << "R" << endl;
	}
	
	Create_DOP(0, M-1, Tree, V, R);
//	cout << M << " " << M << " " << R[M][M] << endl;
	float prob, aw, ap;
	ap = P[0][M];
	aw = W[0][M];
	prob = ap/aw;
	cout << ap << "  " << aw;
	printf("   %f", prob);
	k = R[M][M];
	SDP(V[k].Weight, Tree, V[k].Data);
	DOP_R = Razmer(Tree);
	DOP_S = Summ(Tree);
	DOP_SW = Summ_weight_average(Tree, 0)/z;
	del(Tree);
	
	A1_create(Tree, V, M);
	A_R = Razmer(Tree);
	A_S = Summ(Tree);
	A_SW = Summ_weight_average(Tree, 0)/z;
	del(Tree);
	
	BB_sort_A2(V, M);
	Create_A2 (V, Tree, 0, M-1);
	
	cout << "\n------------------------------------------------------" << endl;
	cout <<"|"<<M<<"  | Размер "<<"| Контр.сумма "<<"| Средн.Взв.высота |"<< endl;
	cout <<"|"<<"DOP  |"<< DOP_R <<"     |"<< DOP_S <<"         |"<< DOP_SW <<"           |"<< endl;
	cout <<"|"<<"A1  |"<< A_R <<"     |"<< A_S <<"         |"<< A_SW <<"           |"<< endl;
	cout <<"|"<<"A2  |"<< Razmer(Tree) <<"     |"<< Summ(Tree) <<"         |"<< Summ_weight_average(Tree, 0)/z <<"           |"<< endl;
	cout <<"------------------------------------------------------"<< endl;
	del(Tree);
	return 0;
}
