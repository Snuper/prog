#include <stdlib.h>
#include <stdio.h>

int main() 
{
	int K, M, N, max = 0, mid = 0, min = 0;
	printf("Input K,M,N numbers: ");
	scanf("%d %d %d", &K, &M, &N);
	//max
	max = K;
	if(M > max) max = M;
	if(N > max) max = N;
	//min
	min = K;
	if(M < min) min = M;
	if(N < min) min = N;
	//mid
	mid = K;
	if(min < M and M < max) mid = M;
	if(min < N and N < max) mid = N;
	//urav
	printf("DO ryad: %d %d %d \n", K, M, N);
	printf("POSLE ryad: %d %d %d \n", min, mid, max);
	system("PAUSE");
	return 0;
}
