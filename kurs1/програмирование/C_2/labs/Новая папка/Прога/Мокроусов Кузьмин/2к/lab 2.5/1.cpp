#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

main()
{ int m,k,j,i,c=0;
float **B; float *A; // ��������� matr � ��������� �� ������ ����������
system("CLS");
printf("Vvedite razmer stroki m: "); scanf("%d",&m);
A=new float[m];
if (A==NULL)
{ puts("Massiv ne sozdan!");
return 1;
}
for (i=0; i<m; i++){  // ���������� ����������� �������
A[i]=rand()%100;
printf("%f ",A[i]);
}
printf("\n Vvedite k, k<m: "); scanf("%d",&k);
B=new float *[m]; // �������� ������ ��� ������ ����������
if (B==NULL)
{ puts("Massiv ne sozdan!");
return 1;
}
int jjo=0;
if (m%k==0) jjo=m/k;
else jjo=m/k+1;
for (i=0; i<jjo; i++)
{ B[i]=new float[k]; // �������� ������ ��� i-� ������
if (B[i]==NULL)
{ puts("Massiv ne sozdan!");
return 1;
}
for (j=0; j<k; j++){
B[i][j]=A[c];// ��������� ������
c++;
if (c>m) B[i][j]=0;}
}
for (i=0; i<jjo; i++)
{ for (j=0; j<k; j++)
printf("\t%6.2f",B[i][j]);
printf("\n");
}
for (i=0;i<m;i++){
delete B[i]; //����������� ������ i-� ������
B[i]=NULL;
}
delete B; // ����������� ������ ������� ����������
B=NULL;
delete A; // ����������� ������ ������� ����
A=NULL;
getch();
}
