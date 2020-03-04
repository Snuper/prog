#include "libra.h"
#include "unit.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;



list *push(list* head, unit vall) {

	if(head == NULL) {

		list *newelem = new list;
		newelem->note = vall;
		head = newelem;
		head->next = NULL;

	} else {
		list *newelem = new list;
		newelem->note = vall;
		newelem->next = head;
		head = newelem;

	}
	return head;
} 


void lie(unit* A, unit* B) {

	for (int i = 0; i < const_size; i++)
		A[i] = B[i];

}

void QuickSortNum(unit* A, int l, int r)
{

	unsigned short int x = A[(l + r) / 2].debt;
	int  i = l, j = r;
	unit Swap;
	while (i <= j) {
		while (A[i].debt < x) i++;
		while (A[j].debt > x) j--;
		if (i <= j) {
			Swap = A[i];
			A[i] = A[j];
			A[j] = Swap;
			i++;
			j--;
		}
	}
	if (l < j) QuickSortNum(A, l, j);
	if (i < r) QuickSortNum(A, i, r);
}

void QuickSortName(unit* A, int l, int r)
{

	char* x = A[r].lawyer;
	int  i = l, j = r;
	unit Swap;
	while (i <= j)
	{
		while (strcmp(A[i].lawyer, x) < 0) i++;
		while (strcmp(A[j].lawyer, x) > 0) j--;
		if (i <= j)
		{
			Swap = A[i];
			A[i] = A[j];
			A[j] = Swap;
			i++;
			j--;
		}
	}
	if (l < j) QuickSortName(A, l, j);
	if (i < r) QuickSortName(A, i, r);

}



void Reader_20(FILE* f, unit* mas)
{

	int i = 0, hit = 0;

	i = 0;
	while (i < const_size)
	{
		
		cout << i + 1 << ") " << mas[i].name << " " << mas[i].debt << "  " << mas[i].date << "  " << mas[i].lawyer << "  " << endl;
		i++;
		if (i % 20 == 0) {
			cout << "\nDo You want to finish reading? Press Y for exit, or press another button for continue\n" << endl;
			hit = _getch();
			//			cout<<" %d "<<hit<<endl;   // check pressed button

			if ((hit == 121) || (hit == 27)) {
				break;
			}
		}

	}

}



void Reader_All(FILE* f, unit* mas)
{

	int i = 0, hit = 0;

	i = 0;
	while (i < const_size)
	{
		
		cout << i + 1 << ") " << mas[i].name << " " << mas[i].debt << "  " << mas[i].date << "  " << mas[i].lawyer << "  " << endl;
		i++;
		if (_kbhit()) {
			hit = _getch();
			if (hit == 27) {
				break;
			}
			else if (hit == 13) {
				while (true) {
					if (_kbhit()) {
						hit = _getch();
						if (hit == 13) {
							break;
						}
					}

				}
			}
		}

	}

}

int BinSearch(unsigned short int key, unit* Z) {

	int m, L, R;
	int i;
	L = 0;
	R = const_size;
	while (L < R) {
		m = (L + R) / 2;
		

		if (Z[m].debt < key) L = m + 1;
		else R = m;
	}
	

	if (Z[m].debt == key) 
		return R;

	else return -1;

}

void MakeList(unit* A, int b, list *&head, unsigned short int key) {
	
	int i, c = b;
	head = NULL;
	
	while (true)
	{

		

		if (A[c].debt!= key) break;
		c++;
		cout<<"29";

	}

	for (i = b; i < c ; i++) {
		
		head = push (head, A[i]);
		cout << endl << head->note.name << " " << head->note.debt << "  " << head->note.date << "  " << head->note.lawyer;
			

	}
	_getch();

}




void PrintList(list* head) {

	int i = 1;
	list* temp = head;

	while (temp != NULL) {

		
		cout << i << ") " << temp->note.name << " " << temp->note.debt << "  " << temp->note.date << "  " << temp->note.lawyer << "  " << endl;
		i++;
		temp = temp->next;

	}

}

void UI(FILE* fp, unit* mas)
{

	unsigned short int key;
	int hit, i, k = 0, l = 0, temp, s;
	unit* pseudo_unit;
	bool search = false, sort = false;
	list* head = NULL;
	list* header;

	pseudo_unit = new unit[const_size];
	head = new list;

	while (true) {
		system("cls");
		cout << "1- Read all\n2- Read by 20\n3- Sort" << endl;

		if (sort)
		{

			cout << "4- Search" << endl;

		}

		if (search)
		{

			cout << "5- Print List" << endl;

		}

		hit = _getch();

		if (hit == 49) {
			Reader_All(fp, mas);
		}
		else if (hit == 50) {
			Reader_20(fp, mas);
		}
		else if (hit == 51) {

			QuickSortNum(mas, 0, const_size - 1);
			while (l < const_size) {

				temp = mas[l].debt;
				
				while (temp == mas[l].debt) {

					l++;

				}

				QuickSortName(mas, k, l - 1);
				k = l;

			}

			sort = true;

		}
		else if ((hit == 52)&&(sort)) {

			cout<<"What do you want to find?"<<endl;
			cin>> key;

			lie(pseudo_unit, mas);

			s = BinSearch(key, pseudo_unit);
			
			if (s != -1) {

				header = head;
				MakeList(pseudo_unit, s, head, key);
				search = true;
				

			}
		}
		else if ((hit = 53) && (search)) {

			PrintList(head);
			_getch();


		}
		

		else if (hit == 27) {
			break;
		}
		else
			cout << "\nError! Try again!\n" << endl;

	}

}
