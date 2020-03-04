#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

struct record
{
	char author[12];
	char title[32];
	char publisher[16];
	short int year;
	short int num_of_page;
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
			cout<< "\nDo You want to complete reading? Press N for exit, or press another button for continue\n"<<endl;
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
	char* x=tt[(l+r)/2].author;
	int  i=l, j=r;
	record Swap;
	while (i<=j)
	{
			while (strcmp(tt[i].author,x)<0) i++;
			while (strcmp(tt[j].author,x)>0) j--;
		{	
			if (i<=j)
			{
				Swap=tt[i];
				tt[i]=tt[j];
				tt[j]=Swap;

				i++;
				j--;
			}
		}
	}
	if (l<j) QuickSortAuthor(tt, l, j);
	if (i<r) QuickSortAuthor(tt, i, r);	
}

void QuickSortYears(record* tt, int l, int r)
{
	unsigned short int x=tt[(l+r)/2].year;
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

void SortAuthor (record* tt, int n)
{
	record Swap;
	int i,j,t;
	for (i = 0; i < n-1; i++) 
	{ 
		for (j=n-1; j>i; j--) 
		{  
			if ((strcmp(tt[j].author, tt[j-1].author) < 0) and (tt[j].year == tt[j-1].year)) 
			{
				Swap=tt[j];
				tt[j]=tt[j-1];
				tt[j-1]=Swap;
			}
		}
	}
}

int main()
{
	FILE *fp;
	record *tt = new record[4000];  
	int hit, l = 0, k = 0, temp, r = 0;
	fp=fopen("testBase1.dat", "rb");
	Record_all(fp,tt);
	while(true)
	{
		cout<<"1 - ALL\n2 - 20\n3 - YEARS"<<endl;
		hit = getch();	
		if(hit==49)
		{
			Reader_All(fp, tt);
			break;
		}
		else if (hit==50)
		{
			Reader_20(fp, tt);
			break;
		}
		else if (hit==51)
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
				cout<< r << endl;
			}
		}		
	 else cout<<"\nEROR!\n"<<endl;
	}
	fclose(fp);
	delete []tt;   
	return 0;
}
