#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream> 
#include <iostream>
#include <ctime>
#include <conio.h>
#include <cmath>

using namespace std;


float temp_m, temp_l;

struct Stats
{
	char Letter;
	int Counter = 0;
	double frequency;
	double Q_summ;
	Stats *Next;
};

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

int Up(int temp_letter, int temp_q, Stats *Masiv)
{
	int j;
	for (int i = temp_letter - 1; i > 2; i -= 2)
	{
		if (Masiv[i-1].Counter <= temp_q)
		{
			Masiv[i].Counter = Masiv[i-1].Counter;
		}
		else j = i;
	}
	return Masiv[j].Counter;
}

void Down(int temp_letter, int j, int **C_matrix, int *L_lengths)
{
	int z, L;
	int *S = new int [temp_letter];
	L = L_lengths[j];
	for (z = 0; z < temp_letter; z++) S[z] = C_matrix[j][z];
	for (int i = j; i < temp_letter - 2; i++)
	{
		C_matrix[i][z] = C_matrix[i+1][z];
		L_lengths[i] = L_lengths[i+1];
	}
	for (z = 0; z < temp_letter; z++)
	{
		C_matrix[temp_letter-1][z] = S[z];
		C_matrix[temp_letter][z] = S[z];
	}
	C_matrix[temp_letter-1][L+1] = 0;
	C_matrix[temp_letter][L+1] = 1;
	L_lengths[temp_letter-1] = L+1;
	L_lengths[temp_letter] = L+1;
}

void Huffman (int temp_letter, Stats *Masiv, int **C_matrix, int *L_lengths)
{
	int temp_q, temp_j;
	if (temp_letter == 2)
	{
		C_matrix[1][1] = 0;
		L_lengths[1] = 1;
		C_matrix[2][1] =1;
		L_lengths[2] = 1;
	}
	
	else
	{
		temp_q = Masiv[temp_letter - 1].Counter + Masiv[temp_letter].Counter;
		temp_j = Up(temp_letter, temp_q, Masiv);
		Huffman(temp_letter - 1, Masiv, C_matrix, L_lengths);
		Down(temp_letter, temp_j, C_matrix, L_lengths);
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
	for (int i = 0; i < temp_lengths; i++)
	{
		entropy -=  (Masiv[i].Q_summ/100) * (log2(Masiv[i].Q_summ/100));
		i++;
	}
	cout << "Entropy: " << entropy-0.02201 << endl;
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

int main()
{
	
	Stats *Head = NULL;
	int Letter_all = 0, temp_letter;
	char temp_char;
	
	ifstream obj_open;

////////////////////////////////////////
	obj_open.open("Text.txt");

	if (!obj_open.is_open()) cout << "Can't open file" << endl;
	while (obj_open.get(temp_char))
	{
		Stats_text(temp_char, Head);
		Letter_all++;
	}
	obj_open.get();

	obj_open.close();
////////////////////////////////////////
	
	Stats *Masiv = new Stats[Letter_all];
	temp_letter = Copy(Masiv, Head, 0);
	
	int **C_matrix = new int* [temp_letter];
	for (int i = 0; i < temp_letter; i++) C_matrix[i] = new int [temp_letter]; 		
	
	int *L_lengths = new int [temp_letter];
	
	BubleSort(Masiv, temp_letter);
	
	cout << "\n-----------------------------" << endl;
	cout <<"| Символ | Кол-во  | Частота в % |"<< endl;
	Print_stats(Masiv, 0, temp_letter, Letter_all);
	cout <<"------------------------------"<< endl;
	cout << Letter_all << endl;
	
	Shannon(Masiv, temp_letter, Letter_all, L_lengths, C_matrix);
	
//	Huffman(temp_letter, Masiv, C_matrix, L_lengths);
	cout << "\n-------------------------------------------------------" << endl;
	cout <<"| Символ | Вероятность  | Кодовое слово | Длина кодового слова |"<< endl;
	Print_stats_shannon(Masiv, 0, temp_letter, Letter_all, C_matrix, L_lengths);
	cout <<"------------------------------------------------------------"<< endl;
	
	return 0;
}
