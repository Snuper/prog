#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

const int size = 3;

float A[size][size + 1] = 
{
	{-3, 1, 2, 1},
    {2, 1, -3, -4},
    {-4, 2, 1, -2}
};

float B[size];

void printMatrix()
{
	cout << endl << "------Matrix - A------" << endl;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size + 1; j++)
		{
			cout << " " << round(A[i][j]*100)/100 << " ";
		}
		cout << endl;
	}
	cout << "------Matrix - A------" << endl;
}

int main(void)
{
	float mnozhitel, max, temp_swap;
	int i, j, dioganal, temp, swap;
	
	printMatrix();
	for(dioganal = 0; dioganal < size-1; dioganal++)
	{
		for(temp = dioganal; temp < size; temp++)
		{
			if(A[temp][dioganal] < 0) B[temp] = A[temp][dioganal] * -1;
			else B[temp] = A[temp][dioganal];
		}
		
		max = B[dioganal];
		
		for(temp = dioganal; temp < size; temp++)
		{
			if(B[temp] > max)
			{
				max = B[temp];
				swap = temp;
			}
			else swap = -1;
		}
		
		if(swap == -1) cout << endl << "No swap" << endl; 
		else
		{
			cout << endl << "Swap " << dioganal + 1 << " and " << swap + 1 << endl;
			for (temp = 0, temp_swap; temp < size + 1; temp++)
			{
				temp_swap = A[dioganal][temp];
				A[dioganal][temp] = A[swap][temp];
				A[swap][temp] = temp_swap;
			}
		}
//		cout << endl << " dioganal = " << dioganal << endl;
		for(i = 1 + dioganal; i < size; i++)
		{
			j = 0;
			mnozhitel = A[i][dioganal] / A[dioganal][dioganal];
//			cout << "  mnozhitel= " << mnozhitel << "   A[dioganal][dioganal] = " << A[dioganal][dioganal] << "   A[i][dioganal]=" << A[i][dioganal] << endl;
//			cout << "dioganal - 1 = " << dioganal - 1 << " i = " << i << endl;
			for(j = 0; j < size + 1; j++)
			{
				A[i][j] -= mnozhitel * A[dioganal][j];
//				cout << "  A[i][j]= " << A[i][j] << "   mnozhitel = " << mnozhitel << "   A[dioganal][j] = " << A[dioganal][j] << endl;
			}
		}
		printMatrix();
	}
	
	for (temp = 1, i = 0; i < size; ++i) temp *= A[i][i];
	
	if(temp)
	for(dioganal = 1, mnozhitel = 1; dioganal < size + 1; dioganal++)
	{
		for(temp = dioganal - 1; temp > 0; temp--) A[size - dioganal][size] -= A[size - dioganal][size - temp];
		mnozhitel = A[size - dioganal][size] / A[size - dioganal][size - dioganal];
		for(temp = size - 1; temp >= 0; temp--) A[temp][size - dioganal] *= mnozhitel;
		cout << "x" << size - dioganal + 1 << " = " << mnozhitel << endl;
//		printMatrix();
	}
	else cout << "Erorr" << endl;
	
	return 0;
}
