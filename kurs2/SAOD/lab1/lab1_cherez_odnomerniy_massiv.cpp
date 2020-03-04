/*
*/
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

int m;

void show(Vertex *&Tree)              //функция обхода с лево на право
{
	if (Tree != NULL)               //Пока не встретит пустую вершину
	{
//		cout<<"42"<<endl;
		show(Tree->Left);
		cout<<" "<<Tree->Data;
		show(Tree->Right);
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

void add_vertex(int Data, Vertex *&MyTree)
{
	if (NULL == MyTree)
	{
		MyTree = new Vertex;
		MyTree->Data = Data;
		MyTree->Left = MyTree->Right = NULL;
	}
	if (Data < MyTree->Data)
	{
		if (MyTree->Left != NULL)
			add_vertex(Data, MyTree->Left);
		else
		{
			MyTree->Left = new Vertex;
			MyTree->Left->Left = MyTree->Left->Right = NULL;
			MyTree->Left->Data = Data;
		}
	}
	if (Data > MyTree->Data)
	{
		if (MyTree->Right != NULL)
			add_vertex(Data, MyTree->Right);
		else
		{
			MyTree->Right = new Vertex;
			MyTree->Right->Left = MyTree->Right->Right = NULL;
			MyTree->Right->Data = Data;
		}
	}
}

int vichilsyaem_i(int L,int R,int i)
{	
	if (L>R)
	{
		return NULL;
	}
	else
	{
		m=(L+R)/2;
		return m;
	}	
}

int Razmer (Vertex *&MyTree)
{
	if (MyTree == NULL)
	return 0;
	else
	return (1+Razmer(MyTree->Left)+Razmer(MyTree->Left));
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

int Summ_root(Vertex *&MyTree, int h)
{
	if ( MyTree == NULL )
	return 0;
	else
	return (h + Summ_root(MyTree->Left, h+1)+Summ_root(MyTree->Right, h+1));
}

int Height_average(Vertex *&MyTree)
{
	return (Summ_root(MyTree, 1)/Razmer(MyTree));
}

int main()
{
	setlocale(LC_CTYPE,"rus");
	int x = 0, M, *A, i, R, L = 0, number;
	srand (time(0));
	Vertex *Tree = NULL;
	cout << "Введите кол-во вершин ИСДП: ";
	cin >> M;
	cout << endl;
	//__________________________________{создание динамического массива *}
	A = new int [M]; 		
	for ( i=0; i<M; i++)
	{
		A[i] = i;
//		A[i] = rand() % 100 + 1; //Рандом в диапозоне от 1 до 9
	}
//__________________________________{окончание создания *}
	for (int i = M, R = M, number = 0; number < M; number++)
	{
		m = vichilsyaem_i(L, R, i);
		add_vertex(A[m], Tree);
//		cout <<i+1<<" "<<x<<endl;
		printf("%d = %d\n",m+1 ,A[m]);
	}
	cout << endl << "Обход слева на право:";
	show(Tree);
	cout<<endl<<"Размер дерева = "<<Razmer(Tree)-1<<endl;
	cout<<"Сумма дерева = "<<Summ(Tree)<<endl;
	cout<<"Высота дерева = "<<Height(Tree)<<endl;
	cout<<"Средняя высота дерева = "<<Height_average(Tree)<<endl;
	del(Tree);
	return 0;
}
