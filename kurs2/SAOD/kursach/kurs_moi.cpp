#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream> 
#include <cmath>

using namespace std;

bool Rost = false;
float temp_m, temp_l;

struct record
{
	char author[12];
	char title[32];
	char publisher[16];
	short int year;
	short int num_of_page;
};

struct ochered
{
   int number;
   ochered *Next;
};

struct Vertex    //Вершина дерева
{
   int Data;     //То что запишим в дерево
   Vertex *Left;    //указатели на новые вершины
   Vertex *Right;
   int Balance;
   int number;
};

struct Stats
{
	char Letter;
	int Counter = 0;
	double frequency;
	double Q_summ;
	Stats *Next;
};

void Record_all(FILE* f, record* tt)
{
	int i=0,hit=0;
	i=fread((record *)tt, sizeof(record), 4000, f);
    i=0;
	while(i<4000) i++;	
}

void Reader_20(FILE* f, record* tt)
{
	int i=0,hit=0;
	i=fread((record *)tt, sizeof(record), 4000, f);
    i=0;
	while(i<4000)
	{
		cout<<i+1<<") "<<tt[i].author<<" "<<tt[i].title<<" "<<tt[i].publisher<<" "<<tt[i].year<<" "<<tt[i].num_of_page<<endl;
		i++;
		if (i%20==0)
		{
			cout<< "\nDo You want to complete reading? Press Esc for exit, or press another button for continue\n"<<endl;
			hit = getch();
 			if ((hit==121)||(hit==27))
			{
				break;
			}
		}	
	}
}

void Reader_All(FILE* f, record* tt)
{
	int i=0,hit=0;
	i=fread((record *)tt, sizeof(record), 4000, f);
    i=0;
	while(i<4000)
	{
		cout<<i+1<<") "<<tt[i].author<<" "<<tt[i].title<<" "<<tt[i].publisher<<" "<<tt[i].year<<" "<<tt[i].num_of_page<<endl;
		i++;
		if (_kbhit())
		{
			hit = getch();
			if (hit == 27)
			{
				break;
			}
				else if(hit == 13)
				{
					while (true)
					{
						if (_kbhit())
						{
							hit = getch();
							if (hit == 13)
							{
								break;
							}
						}
					}
				}
		}	
	}
}

void QuickSortAuthor(record* tt, int l, int r)
{
	char* x=tt[r].author;
	int  i=l, j=r;
	record Swap;
	while (i<=j)
	{
		while (strcmp(tt[i].author,x)<0) i++;
		while (strcmp(tt[j].author,x)>0) j--;
		if (i<=j)
		{
			Swap=tt[i];
			tt[i]=tt[j];
			tt[j]=Swap;
			i++;
			j--;
		}
	}
	if (l<j) QuickSortAuthor(tt, l, j);
	if (i<r) QuickSortAuthor(tt, i, r);
}

void QuickSortYears(record* tt, int l, int r)
{
	unsigned short int x=tt[r].year;
	int  i=l, j=r;
	record Swap;
	while (i<=j)
	{
		while (tt[i].year<x) i++;
		while (tt[j].year>x) j--;
		if (i<=j)
		{
			Swap=tt[i];
			tt[i]=tt[j];
			tt[j]=Swap;
			i++;
			j--;
		}
	}
	if (l<j) QuickSortYears(tt, l, j);
	if (i<r) QuickSortYears(tt, i, r);
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

int show(Vertex *&Tree, record* tt)              //функция обхода с лево на право
{
	if (Tree != NULL)               //Пока не встретит пустую вершину
	{
//		cout<<"42"<<endl;
		show(Tree->Left, tt);
		cout<<Tree->number<<") "<<tt[Tree->number].author<<" "<<tt[Tree->number].title<<" "<<tt[Tree->number].publisher<<" "<<tt[Tree->number].year<<" "<<tt[Tree->number].num_of_page<<endl;
		show(Tree->Right, tt);
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
	}else
	{
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

void ABL_create(int Data, Vertex *&Tree, int number, ochered *&Same)
{
	if (!Tree)
	{
		Tree = new Vertex;
		Tree->Data = Data;
		Tree->number = number;
		Tree->Left = Tree->Right = NULL;
		Tree->Balance = 0;
		Rost = true;
	}
	else if (Tree->Data >= Data)
	{
		ABL_create(Data, Tree->Left, number, Same);
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
		ABL_create(Data, Tree->Right, number, Same);
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
	else if (Tree->Data == Data)
	{
		ochered *temp = new ochered;
		ochered *temp_tree = new ochered;
		temp->number = number;
		temp->Next = Same;
		Same = temp;
		temp_tree->number = Tree->number;
		temp_tree->Next = Same;
		Same = temp_tree;
	}
}

void Printochered(ochered *Head, record* tt, Vertex *&Tree, ochered *&Same, bool check)
{
	ochered *temp = Head;
	
	cout << endl << "Ochered: "<< endl;
	while (temp != NULL)
	{
        cout<<temp->number<<") "<<tt[temp->number].author<<" "<<tt[temp->number].title<<" "<<tt[temp->number].publisher<<" "<<tt[temp->number].year<<" "<<tt[temp->number].num_of_page<<endl;
    	if (check == true) ABL_create(tt[temp->number].num_of_page, Tree, temp->number, Same);
    	temp = temp->Next;
	}
}

void Search_Binary (record* tt, int left, int right, int key, Vertex *&Tree, ochered *&Head, ochered *&Same)
{
	Head = NULL;
	int mid = 0, kolvo;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (key < tt[mid].year) right = mid - 1;
		else if (key > tt[mid].year) left = mid + 1;
		else
		{
			for (left = mid; tt[left].year == key; left--);
			for (right = mid; tt[right].year == key; right++);
			kolvo = right - left-1;
			for (right--; right > left; right--)
			{
//				cout<<left+1<<") "<<tt[left].author<<" "<<tt[left].title<<" "<<tt[left].publisher<<" "<<tt[left].year<<" "<<tt[left].num_of_page<<endl;
				ochered *temp = new ochered;
				temp->number = right;
				temp->Next = Head;
				Head = temp;
			}
			Printochered(Head, tt, Tree, Same, true);
			cout<<"\nItems found: "<<kolvo<<endl;
		}
	}
}

void Stats_text (char temp_char, Stats *&Head)
{
	if (!Head)
	{
		Head = new Stats;
		Head->Letter = temp_char;
		Head->Counter++;
		Head->Next = NULL;
	}
	else if (Head->Letter == temp_char) Head->Counter++;
	else Stats_text(temp_char, Head->Next);
}

int Copy (Stats* Masiv, Stats *&Head, int q)
{
	if (!Head) return q;
	else
	{
		Masiv[q].Letter = Head->Letter;
		Masiv[q].Counter = Head->Counter;
		q++;
		Copy(Masiv, Head->Next, q);
	}
}

void Print_stats (Stats* Masiv, int q, int temp_letter, int Letter_all)
{
	for (;q < temp_letter; q++)
	{
		temp_m = Masiv[q].Counter*100;
		temp_l = Letter_all;
		Masiv[q].frequency = temp_m / temp_l;
		if (Masiv[q].Letter == ' ') cout << "|  " << "Space" << "  |    " << Masiv[q].Counter << "    | " << round(temp_m / temp_l*1000)/1000 << "% |" << endl;
		else if (Masiv[q].Letter == '\n') cout << "|  " << "Enter" << "  |    " << Masiv[q].Counter << "    | " << round(temp_m / temp_l*1000)/1000 << "% |" << endl;
		else cout << "|    " << Masiv[q].Letter << "    |    " << Masiv[q].Counter << "    | " << round(temp_m / temp_l*1000)/1000 << "% |" << endl;
	}
}

void BubleSort (Stats *Masiv, int n)
{
	Stats Swap;
	int i, j;
	for (i = 0; i < n-1; i++) 
	{ 
		for (j = n-1; j > i; j--)
		{  
			if (Masiv[j].Counter > Masiv[j-1].Counter) 
			{
				Swap = Masiv[j];
				Masiv[j] = Masiv[j-1];
				Masiv[j-1] = Swap;
			}
		}
	}
}

void Shannon(Stats *Masiv, int temp_letter, int Letter_all, int *L_lengths, int **C_matrix)
{
	Masiv[-1].frequency = 0;
	Masiv[-1].Q_summ = 0;
	
	for (int i = 0; i < temp_letter; i++)
	{
		Masiv[i].Q_summ = Masiv[i-1].Q_summ + Masiv[i].frequency/100;
		L_lengths[i] = -log2(Masiv[i].frequency/100);
	}
	for (int i = 0; i < temp_letter; i++)
	{
		for (int j = 0; j < L_lengths[i]; j++)
		{
			Masiv[i-1].Q_summ = Masiv[i-1].Q_summ * 2;
			C_matrix[i][j] = Masiv[i-1].Q_summ;
			if (Masiv[i-1].Q_summ > 1) Masiv[i-1].Q_summ = Masiv[i-1].Q_summ - 1;
		}
	}
}

void entropy(Stats *Masiv, int temp_lengths, int *L_lengths) 
{
	double entropy = 0;
	double averageLength = 0;
	for (int i = 0; i < temp_lengths-2; i++)
	{
		entropy -=  ((Masiv[i].Q_summ/100)+0.0000163) * (log2(Masiv[i].Q_summ/100));
		i++;
	}
	cout << "Entropy: " << entropy << endl;
}

void Print_stats_shannon (Stats* Masiv, int q, int temp_letter, int Letter_all, int **C_matrix, int *L_lengths)
{
	int ALL_L = 0;
	for (;q < temp_letter; q++)
	{
		if (Masiv[q].Letter == ' ') 
		{
			cout << "|  " << "Space" << "  |    " << Masiv[q].frequency << "% | ";
			for (int j = 0; j < L_lengths[q]; j++) cout << C_matrix[q][j];
			cout << " | " << L_lengths[q] << " |" << endl;
			ALL_L += L_lengths[q];
		}
		else if (Masiv[q].Letter == '\n')
		{
			cout << "|  " << "Enter" << "  |    " << Masiv[q].frequency << "% | ";
			for (int j = 0; j < L_lengths[q]; j++) cout << C_matrix[q][j];
			cout << " | " << L_lengths[q] << " |" << endl;
			ALL_L += L_lengths[q];
		}
		else
		{
			cout << "|    " << Masiv[q].Letter << "    |    " << Masiv[q].frequency << "% | ";
			for (int j = 0; j < L_lengths[q]; j++) cout << C_matrix[q][j];
			cout << " | " << L_lengths[q] << " |" << endl;
			ALL_L += L_lengths[q];
		}
	}
	cout << endl << "Average: " << ALL_L/temp_letter << endl;
	entropy(Masiv, temp_letter, L_lengths);
	cout << "Kolvo elementov: " << temp_letter << endl;
	cout << "Kolvo letter: " << Letter_all << endl;
}

void Clear(ochered *Head)
{
    if (!Head)
    {
		ochered *temp = Head;
		Head = Head->Next;
		delete temp;
    }
}

void Search_elements (Vertex *&Tree, char* element, record *tt)
{
	char *x = new char[2];
	x[0] = tt[Tree->number].author[0];
	x[1] = tt[Tree->number].author[1];
	x[2] = tt[Tree->number].author[2];
	if (Tree != NULL)
	{
		Search_elements(Tree->Left, element, tt);
			cout<<endl<<"SMOTR. "<<element<<endl;
			cout<<endl<<"SMOTR. "<<x<<endl;
		if (strcmp(x, element) == 0)
		{
			cout<<Tree->number<<") "<<tt[Tree->number].author<<" "<<tt[Tree->number].title<<" "<<tt[Tree->number].publisher<<" "<<tt[Tree->number].year<<" "<<tt[Tree->number].num_of_page<<endl;
		}
		Search_elements(Tree->Right, element, tt);
	}
}

int main()
{
	FILE *fp;
	Stats *Head_stats = NULL;
	char temp_char;
	char *element = new char[12];
	ifstream obj_open;
	record *tt = new record[4000];  
	int hit, l = 0, temp, r = 0, Search_element, Letter_all = 0, temp_letter;
	ochered *Head = NULL;
	ochered *Same = NULL;
	Vertex *Tree = NULL;
	fp=fopen("testBase1.dat", "rb");
	Record_all(fp,tt);
	while(true)
	{
		cout<<"1 - ALL\n2 - 20\n3 - QuickSort\n4 - Search\n5 - Shannon"<<endl;
		hit = getch();
		if(hit == 49)
		{
			Reader_All(fp, tt);
			break;
		}
		else if (hit == 50)
		{
			Reader_20(fp, tt);
			break;
		}
		else if (hit == 51)
		{
			QuickSortYears(tt, 0, 3999);
			while(r < 4000)
			{
				temp = tt[r].year;	
				while(temp == tt[r].year)
				{
					r++;
				}
				QuickSortAuthor(tt, l, r-1);
				l = r;
			}
		}
		else if (hit == 52)
		{
			cout << "\nEnter year: ";
			cin >> Search_element;
			cout << endl;
			Search_Binary(tt, 0, 3999, Search_element, Tree, Head, Same);
			cout << "\nABL\n";
			cout << "\n---------------------------------------------------" << endl;
			cout <<"|"<<"4000"<<"  | Razmer "<<"| Summ  "<<"| Height "<<"| Height average |"<< endl;
			cout <<"|"<<"ABL   |"<< Razmer(Tree) <<"    |"<< Summ(Tree) <<"|"<< Height(Tree) <<"      |"<< Height_average(Tree) <<"         |"<< endl;
			cout <<"---------------------------------------------------"<< endl;
			show(Tree, tt);
			cout <<"---------------------------------------------------"<< endl;
//			Printochered(Same, tt, Tree, Same, false);
			cout <<"---------------------------------------------------"<< endl;
			cout << "\nEnter num of page: ";
			scanf("%s",element);
			Search_elements(Tree, element, tt);
			Clear(Head);
			del(Tree);
		}
		else if (hit == 53)
		{
			obj_open.open("testBase1.dat", ios::binary);
			if (!obj_open.is_open()) cout << "Can't open file" << endl;
			while (obj_open.get(temp_char))
			{
				Stats_text(temp_char, Head_stats);
				Letter_all++;
			}
			obj_open.get();
			obj_open.close();
			
			Stats *Masiv = new Stats[Letter_all];
			temp_letter = Copy(Masiv, Head_stats, 0);
			
			int **C_matrix = new int* [temp_letter];
			for (int i = 0; i < temp_letter; i++) C_matrix[i] = new int [temp_letter]; 		
			
			int *L_lengths = new int [temp_letter];
			
			BubleSort(Masiv, temp_letter);
			
			
			cout << "\n-----------------------------" << endl;
			cout <<"| Simvol | Kol-vo  | Chastota  % |"<< endl;
			Print_stats(Masiv, 0, temp_letter, Letter_all);
			cout <<"------------------------------"<< endl;
			
			Shannon(Masiv, temp_letter, Letter_all, L_lengths, C_matrix);
			
			cout << "\n---------------------------------------------------------------" << endl;
			cout <<"| Simvol | Veroyatnost  | Kodovoe slovo | Dlina kodovogo slova |"<< endl;
			Print_stats_shannon(Masiv, 0, temp_letter, Letter_all, C_matrix, L_lengths);
			cout <<"---------------------------------------------------------------"<< endl;
		}
		else cout<<"\nEROR!\n"<<endl;
	}
	fclose(fp);
	delete []tt;   
	return 0;
}
