#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int const N = 300,R = 11;
int main ( )
{ 
	char TEXT[N], SRAVNENIE[R], SLOVO[10][40]{0}; //��������� ������������ ������� 
	int i = 0, j = 0, k = 0, dlina = 0,dlina_text = 0,sravn = 0; // ����������
	
	printf("Input s chem sravnivat`(10 symvolov max): "); 
	gets(SRAVNENIE); //������� ��������
	dlina = strlen(SRAVNENIE); // �������� ����� ���������	
	printf("Input text(300 symvolov max): ");
	gets(TEXT); //��������� �����
	dlina_text = strlen(TEXT); // ��������� ����� ������ (��� ����� ������ �����������, ����� �� �� ���� ������ ��������, �� ����, ��� ���� ������ �������� �������)
	printf("sravnenie tolko 10 slov\n"); 
	
	for(i = 0; i < dlina_text;i++) //���� ������� �� ������ �����, ������ ����� = ��������� ������ � �������
	{
		if (TEXT[i] != ' ' and TEXT[i] != ',')  // ������� ��� ������ ��� ������� 
		{
			SLOVO[k][j] = TEXT[i]; //��������� � ������
			j++; //�������� � ���������� ������� � ������
		}
		else //�����
		{
			k++; //���������� ��������� � ��������� ������
			j = 0; //�������� ������ � ������
		}
	}
	
	puts("Slova podhodyat: "); //������� ����� ���������� ��� ���������

	for (i = 0; i < 10; i++) //����� ���� ����
	{
		sravn = strncmp(SLOVO[i],SRAVNENIE,dlina); //������������ ��������� � �����
		if(sravn == 0) // ���������
		{
			puts(SLOVO[i]); //����� ����� �����
		}
	}
	
	system("PAUSE");
	return 0; 
}
