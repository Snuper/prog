#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

struct INFO
{
	char F[30];
	char I[20];
	char O[30];
	int places;
	float mass;
} info;

void create(FILE *file)
{
	system("CLS");
	char ch;
	file = fopen("AirInfo.dat", "wb");
	printf("Enter information.\n");
	do
	{
		printf("\nFam: "); scanf("%s",&info.F);
		printf("Name: "); scanf("%s", &info.I);
		printf("Patro: "); scanf("%s", &info.O);
		printf("Number of place: "); scanf("%d", &info.places);
		printf("Mass: "); scanf("%f", &info.mass);
		fwrite(&info, sizeof(info), 1, file);
		printf("\n Finish? y/n ");
		ch = _getch();
	} while( ch != 'y');
	fclose(file);
}

void print(FILE *file)
{
	int i = 1;
	file = fopen("AirInfo.dat", "rb");
	if(fread(&info, sizeof(info), 1, file))
	while(!feof(file))
	{
		printf("\n%d. %s %.1s.%.1s.\nPlace: %d, Mass: %.2f\n", i, info.F, info.I, info.O, info.places, info.mass);
		fread(&info, sizeof(info), 1, file);
		i++;
	}
	else
		printf("List clear");
	_getch();
	fclose(file);
}

void Add(FILE *file)
{
	char ch;
	file = fopen("AirInfo.dat", "ab");
	system("CLS");
	do
	{
		printf("\nFam: "); scanf("%s",&info.F);
		printf("Name: "); scanf("%s", &info.I);
		printf("Patro: "); scanf("%s", &info.O);
		printf("Number of place: "); scanf("%d", &info.places);
		printf("Mass: "); scanf("%f", &info.mass);
		fwrite(&info, sizeof(info), 1, file);
		printf("\n Finish? y/n ");
		ch = _getch();
	} while( ch != 'y');
	fclose(file);
}
 // COMMIT
void Copy(FILE *file, FILE *temp)
{
	file = fopen("AirInfo.dat", "rb+");
	temp = fopen("temp.dat", "wb");
	system("CLS");
	fread(&info, sizeof(info), 1, file); // Dobavlenie stroki!
	while(!feof(file))
	{	
		if(info.mass >= 10)
		{
			fwrite(&info, sizeof(info), 1, temp);
		}
		fread(&info, sizeof(info), 1, file); //izmenenie mestopolozheniya
	}
	fclose(file);
	fclose(temp);
	if(remove("AirInfo.dat"))
	{
		printf("Error delete original file.");
		_getch();
	}
	file = NULL;
	temp = NULL;
}
//END COMMIT
void Delet(FILE *file, FILE *temp)
{
	temp = fopen("temp.dat", "rb+");
	file = fopen("AirInfo.dat", "wb+");
	system("CLS");
	
	fread(&info, sizeof(info), 1, temp);
	while(!feof(temp))
	{
		fwrite(&info, sizeof(info), 1, file);
		fread(&info, sizeof(info), 1, temp);	
	}
	fclose(file);
	fclose(temp);
	if(remove("temp.dat"))
	{
		printf("Error delete temp file.");
		_getch();
	}
	file = NULL;
	temp = NULL;
}

int main()
{
	char choose;
	FILE *file;
	FILE *temp;
	while(1)
	{
		system("CLS");
		puts("1 - new file.");
		puts("2 - check file.");
		puts("3 - add new passanger.");
		puts("4 - delete low mass");
		puts("0 - exit.");
		
		choose = _getch();
		switch(choose)
		{
			case '1':
				create(file);
				break;
			case '2':
				print(file);
				break;
			case '3':
				Add(file);
				break;
			case '4':
				Copy(file, temp);
				Delet(file, temp);
				break;
			case '0':
				return 0;
			default:
				puts("Not valid choose");
				_getch();
		}
	}
}
