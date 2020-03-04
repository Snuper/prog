/*
number - переменная для подсчета шагов, для построения конкретного дерева
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
void add_vertex(int Data, Vertex *&MyTree ,int number)
{
	if (number == 1)
	{
		MyTree = new Vertex;
		MyTree->Data = Data;
		MyTree->Left = MyTree->Right = NULL;
//		cout<<number<<endl;
	}
	if (number == 2)
	{
		MyTree->Left = new Vertex;
		MyTree->Left->Data = Data;
		MyTree->Left->Left = MyTree->Left->Right = NULL;	
//		cout<<number<<endl;
	}
	if (number == 3)
	{
		MyTree->Right = new Vertex;
		MyTree->Right->Data = Data;
		MyTree->Right->Right = MyTree->Right->Left = NULL;
//		cout<<number<<endl;
	}
	if (number == 4)
	{
		MyTree->Left->Left= new Vertex;;
		MyTree->Left->Left->Data = Data;
		MyTree->Left->Left->Left = MyTree->Left->Left->Right = NULL;
//		cout<<number<<endl;
	}
	if (number == 5)
	{
		MyTree->Left->Right = new Vertex;;
		MyTree->Left->Right->Data = Data;
		MyTree->Left->Right->Left = MyTree->Left->Right->Right = NULL;
//		cout<<number<<endl;
	}
	if (number == 6)
	{
		MyTree->Right->Right = new Vertex;;
		MyTree->Right->Right->Data = Data;
		MyTree->Right->Right->Left = MyTree->Right->Right->Right = NULL;
//		cout<<number<<endl;
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
	int x = 0;
	srand (time(0));
	Vertex *Tree = NULL;
	for (int i = 1; i < 7; i++)
	{
		x = rand() % 9 + 1; //Рандом в диапозоне от 1 до 9
		add_vertex(x, Tree, i);
		cout <<i<<" "<<x<<endl;
	}
	show(Tree);
	cout<<endl<<"Размер дерева = "<<Razmer(Tree)-1<<endl;
	cout<<"Сумма дерева = "<<Summ(Tree)<<endl;
	cout<<"Высота дерева = "<<Height(Tree)<<endl;
	cout<<"Средняя высота дерева = "<<Height_average(Tree)<<endl;
	del(Tree);
	return 0;
}
