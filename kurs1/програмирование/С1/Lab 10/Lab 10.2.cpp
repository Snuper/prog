#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int const N = 300, K = 40;
int main ()
{ 
	char TEXT[N], SLOVO[K][K]{0}, sravn[K][K]{}, UNIK[K][K]{0}; //������� ��� ������
	int i = 0, j = 0, k = 0, dlina_text = 0, kol = 0, ch[K]{}; //���������� ��� �������
		
	printf("Input text(300 symvolov max): "); 
	gets(TEXT); //�������� �����
	dlina_text = strlen(TEXT); //����� ����� ��� ����������� �����
	printf("sravnenie tolko 40 slov\n"); //������ ��������������
	
	for(i = 0; i < dlina_text;i++) //����� ����� �� ������
	{
		if (TEXT[i] != ' ' and TEXT[i] != ',') //���� �� ������ � �� ���
		{
			SLOVO[k][j] = TEXT[i]; //�� ��� �� ��� ����
			j++; //������� �� ���� ������� ���������
		}
		else  //�����
		{
			k++; //������� � ���� ������
			j = 0; //������� � ������� �������
		}
	}
	
	puts("Vse unikalnie slova: "); //������
	
	for (i = 0; i < K; i++)  //���� ������ ������������
	{
		for (j = 0; j < K; j++)	//��� �������� ���� ���������
		{
			if (strcmp(SLOVO[i],SLOVO[j]) == 0) //���� ����� ���������
			{
				ch[i]++; //���������� ������� ��� �����������
			}
		}
	}
		
	for (i = 0; i < K; i++) //���� ������ ����
	{
		kol = 0; //�������� ���������� ������
		for (j = 0; j < i; j++) //��� �������� ���� ���������
		{
			if (strcmp(SLOVO[i],SLOVO[j]) == 0) //���� ������
			{
				kol++; //����������� �����
			}
		}
		if(kol == 0 and (strcmp(SLOVO[i],sravn[i]) != 0)) //���� �� �����
		{
			printf("%s povtoryaetsa: %d\n",SLOVO[i], ch[i]);	//������� ����� � ������� ��� �����������
		}
	}
	
	system("PAUSE");
	return 0; 
}
