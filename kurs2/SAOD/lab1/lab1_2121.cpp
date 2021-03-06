/*
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

struct Vertex    //������� ������
{
   int Data;     //�� ��� ������� � ������
   Vertex *Left;    //��������� �� ����� �������
   Vertex *Right;
};

int show(Vertex *&Tree)              //������� ������ � ���� �� �����
{
	if (Tree != NULL)               //���� �� �������� ������ �������
	{
//		cout<<"42"<<endl;
		show(Tree->Left);
		cout<<" "<<Tree->Data;
		show(Tree->Right);
		return Tree->Data;
	}
}

void del(Vertex *&Tree)	//������� ������
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
//������� ����� ������� ��������

void Search_element (Vertex *&Tree,int element)
{
	int checkout = 0;
		if (Tree != NULL)
	{
		if ( checkout != 1 )
		{
			Search_element(Tree->Left, element);
			if (Tree->Data == element)
			{
				cout << endl << element << " = " <<&Tree;
				checkout = 1;
			}
			Search_element(Tree->Right, element);
		}
	}
}

int Razmer (Vertex *&MyTree)
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
	int x = 0, M, *A, m = 0, element;
	srand (time(0));
	cout << "������� ���-�� ������ ����: ";
	cin >> M;
	cout << endl;
	A = new int [M]; 		
	for (int i=0; i<M; i++)
	{
		A[i] = i;
	}
	Vertex *Tree = ISDP(0, M-1, A, m);
	cout << endl << "����� ����� �� �����:";
	show(Tree);
	cout<<endl<<"������ ������ = "<<Razmer(Tree)<<endl;
	cout<<"����� ������ = "<<Summ(Tree)<<endl;
	cout<<"������ ������ = "<<Height(Tree)<<endl;
	cout<<"������� ������ ������ = "<<Height_average(Tree)<<endl;
	cout << "\n������� ������� �������: ";
	cin >> element;
	Search_element(Tree, element);
	del(Tree);
	return 0;
}
