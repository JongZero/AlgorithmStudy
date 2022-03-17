#include <stdio.h>
#define ROWS 5
#define COLS 5
// 행렬 전치 함수
void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS])
{
	for (int r = 0; r<ROWS; r++)
		for (int c = 0; c<COLS; c++)
			B[c][r] = A[r][c];
}
void matrix_print(int A[ROWS][COLS])
{
	printf("====================\n");
	for (int r = 0; r<ROWS; r++) {
		for (int c = 0; c<COLS; c++)
			printf("%d ", A[r][c]);
		printf("\n");
	}
	printf("====================\n");
}

int main(void)
{
	int array1[ROWS][COLS] = { { 2,3,0,6,7 },
							{ 8,9,1,5,6 },
							{ 7,0,5,2,8 },
							{ 5,4,5,2,4 },
							{ 1,6,8,3,1 } };
	int array2[ROWS][COLS];

	matrix_transpose(array1, array2);
	matrix_print(array1);
	matrix_print(array2);
	return 0;
}