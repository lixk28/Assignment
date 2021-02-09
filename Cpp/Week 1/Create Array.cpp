#include <stdio.h>

int* Array(int len)
{
	int *p = new int[len];
	return p;
}		

int** Reshape(int* vec, int row, int col)
{
	int **p;
	p = new int *[row];
	for(int i = 0; i < row; i++)
		p[i] = new int[col];

	int k = 0;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			p[i][j] = vec[k++];
	
	return p;
}	

void FreeArray(int* vec)
{
	delete []vec;
}

void FreeMatrix(int** mat, int row)
{
	for(int i = 0; i < row; i++)
		delete []mat[i];
	delete []mat;
}

int main() {
	int* vec = NULL;
	int len, row, col;
	scanf("%d", &len);	
	vec = Array(len);
	for (int i = 0; i < len; ++i) {
		scanf("%d", vec + i);	
	}
	int** mat = NULL;
	scanf("%d%d", &row, &col);
	mat = Reshape(vec, row, col);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("%d%c", mat[i][j], j == col - 1 ? '\n' : ' ');
		}
	}
	FreeArray(vec);
	FreeMatrix(mat, row);
	return 0;
}