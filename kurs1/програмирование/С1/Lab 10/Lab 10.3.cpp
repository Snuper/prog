#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int const N = 300, K = 40;
int main ()
{ 
	char TEXT[N], SLOVO[K][K] = {0}; //������ ������
	int i = 0, j = 0, k = 0, dlina_text = 0; //d��� ����������� ����� � ��� �������� �� ���������
	char c[K][K];	//��� ������ ������
	
	printf("Input text(300 symvolov max): "); //������
	gets(TEXT); //�������� �����
	dlina_text = strlen(TEXT); //���� �����
	printf("alphavit poryadok: \n"); //������
	//rebotaet ne lez!
	for(i = 0; i < dlina_text;i++) //����� �� ������ �����
	{
		if (TEXT[i] != ' ' and TEXT[i] != ',') //�� ����� � �� ���
		{
			SLOVO[k][j] = TEXT[i]; //��� ���
			j++; //���� ������
		}
		else  //�����
		{
			k++; //���� ������
			j = 0; //�������� ������
		}
	}
	for(i = 0; i < k; i++) //����������� ������ ��� ������ ����� �����
	{
		for (j = k - 1; j >= i; j--) //������ ����
		{
			if (strncmp(SLOVO[j],SLOVO[j+1],1) > 0) //����������
			{
				strcpy(c[i],SLOVO[j]); //�������� � �����
				strcpy(SLOVO[j],SLOVO[j+1]); //������ �������
				strcpy(SLOVO[j+1],c[i]); //�� ������
			}
		}
	}
	for (i = 0; i < k+1; i++) //���� ������
	{
		printf("%d. %s\n", i + 1, SLOVO[i]); //������ i+1 ��� �������
	}
	system("PAUSE");
	return 0; 
}
