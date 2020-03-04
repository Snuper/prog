#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

typedef unsigned char Byte;
	
struct spis
{
   spis *next;
   Byte data;
};

void printSpis(spis *Node){
    spis *p = NULL;
    cout << "Список: ";
    for(p = Node; p != NULL; p = p->next){
        cout << (int)p->data << " ";
    }
    cout << endl << endl;

}

void addSpis(Byte element,spis **Node,spis **tail)
{
	spis *p=NULL;
    if(*tail)
    {
        p = new spis;
        p->data = element;
        (*tail)->next = p;
        (*tail) = (*tail)->next;
        (*tail)->next = NULL;
    }else{
        p = new spis;
        p->data = element;
        (*Node) = (*tail) = p;
        (*tail)->next = NULL;
    }

}

int sizeSpis(spis* Node)
{
    int count = 0;
    spis *p = Node;
    while(p != NULL){
        p = p->next;
        ++count;
    }
    return count;
}

void BigDelete(spis *start){

int i,j;
spis *pos,*head;
Byte info;
pos = start;
while(pos->next!=NULL){
info=pos->data;
head=pos;
while(head->next!=NULL){
if (head->next->data==info) head->next=head->next->next;
head=head->next;
}
pos=pos->next;


}

}

/*void DFQ(spis *Node, int n)
{
	int A[n], i = 0;
	spis *p = NULL, *q = NULL;
	p = Node;
	cout << endl << "Тест на запись" << endl;
	while ( i < n )
	{
		A[i] = p->data;
		p = p->next;
		i++;
		cout << endl << A[i];
	}
	cout << endl << "Тест на запись-end" << endl;
	for(p = Node, i = 0; p != NULL; p = Node)
	{
		cout << endl << "Тест на запись-nachalo" << endl;
		p = Node;
		while( i < n )
		{
			if ( A[i] == p->data)
			{
				q = p->next;
				p->next = p->next->next;
        		delete q;
			}
			else i++;
		}
    cout << endl << "Тест на запись-konec" << endl;
	}
}
*/
void delSpis(spis **Node)
{
    {
        spis* p=NULL;
        p=(*Node);
        (*Node) = (*Node)->next;
        delete p;
    }
}

void addElementOnPozition(spis **Node,int position, int element)
{
    if(position <0 || position > (sizeSpis(*Node)))
    {
        cout << "Неверная позиция элемента:" << endl;
        return;
    }
    if(position != 0)
    {
        spis *p = NULL, *q = NULL;
        int i;
        for(i = 1, p = (*Node); i < position; i++ , p = p->next){}
        q = new spis;
        q->data = element;
        q->next = p->next;
        p->next = q;
        return;
    }

    if(position == 0)
    {
        spis *q = NULL;
        q = new spis;
        q->data = element;
        q->next = (*Node);
        (*Node) = q;
        cout << q->data << endl;
    }

    if(position == sizeSpis(*Node))
    {
        spis *p = NULL, *q = NULL;
        int i;
        for(i = 1, p = (*Node); i < position; i++, p = p->next){}
        q = new spis;
        q->data = element;
        q->next = NULL;
        p->next = q;
    }
}

void delElem(spis **Node,int pozition)
{
    if(pozition > sizeSpis(*Node)+1 || pozition <= 0)
    {
        cout<<"Неверная позиция элемента"<<endl;
        return;
    }
    int i;
    spis *p = NULL, *q = NULL;
    if(pozition!=1)
    {
        for(i = 1, p = (*Node); i < pozition - 1; i++, p = p->next)	{}
        q = p->next;
        p->next = p->next->next;
        delete q;
    }
    else{

        spis* p = NULL;
        p = (*Node);
        (*Node) = (*Node)->next;
        delete p;
    }
}

void moveElement(spis **Node, int n, int k)
{
    Byte elem_move;
    spis *p = NULL;
    p = (*Node);

    for(int i = 1; i < n; i++, p = p->next){}
    elem_move = p->data;
    addElementOnPozition(&(*Node), k, elem_move);
        if(n <= sizeSpis(*Node) && n > 0)
        {
            delElem(&(*Node), n);
        }else cout<< "Неверная позиция" <<endl;
}

int main()
{
    srand(time(0));
	spis *MySpis, *tail;
    MySpis = NULL;
    tail = NULL;
    setlocale(LC_ALL, "RUS");
    int n, poz, k, fullsquare;
    int elem;
    cout << "Введите кол-во элементов: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
    	fullsquare = rand()%10+1;
    	fullsquare = fullsquare * fullsquare;
        addSpis(fullsquare, &MySpis, &tail);
    }
    printSpis(MySpis);
    cout << "Размер списка: " << sizeSpis(MySpis) << endl;
	cout << "Удаление повторяющихся элементов списка..." << endl;
	BigDelete(MySpis);
	printSpis(MySpis);
    cout << endl << "Размер списка: " << sizeSpis(MySpis) << endl;
    cout << "Введите элемент, который хотите добавить и позицию : ";
    cin >> elem >> poz;
    addElementOnPozition(&MySpis, poz, elem);
    printSpis(MySpis);
    cout << "Введите позицию удаляемого элемента: ";
    cin >> poz;
    delElem(&MySpis, poz);
    printSpis(MySpis);

    cout << "Введите позицию элемента, который хотите переместить и позицию...: ";
    cin >> n >> k;
    moveElement(&MySpis, n, k);
    printSpis(MySpis);
}
