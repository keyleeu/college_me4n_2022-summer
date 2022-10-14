#include <stdio.h>

typedef struct {
	int row;
	int col;
	int value;
}matrix;

void transposeSM(matrix a[], matrix b[]) {
	int m, n, v, i, j, p;
	m = a[0].row;	// 희소 행렬 a의 행 수
	n = a[0].col;	// 희소 행렬 a의 열 수
	v = a[0].value; // 희소 행렬 a에서 0이 아닌 원소 수
	b[0].row = n;	// 전치 행렬 b의 행 수
	b[0].col = m;	// 전치 행렬 b의 열 수
	b[0].value = v;	// 전치 행렬 b의 원소 수
	if (v > 0) {	// 0이 아닌 원소가 있는 경우에만 전치 연산 수행
		p = 1;
		for (i = 0; i < n; i++)			// 희소 행렬 a의 열별로 전치 반복 수행
			for (j = 1; j <= v; j++)	// 0이 아닌 원소 수에 대해서만 반복 수행
				if (a[j].col == i) {	// 현재의 열에 속하는 원소가 있으면 b[]에 삽입
					b[p].row = a[j].col;
					b[p].col = a[j].row;
					b[p].value = a[j].value;
					p++;
				}
	}
}

int main() {
	int i, j;
	matrix a[11] = {	{8,7,10}, 
						{0,2,2},
						{0,6,12},
						{1,4,7},
						{2,0,23},
						{3,3,31},
						{4,1,14},
						{4,5,25},
						{5,6,6},
						{6,0,52},
						{7,4,11}
	};
	matrix b[11] = {0, };
	transposeSM(a, b);
	
	printf("Matrix a\n");
	for(i=0; i<11; i++)
		printf("%d: %d %d %d\n", i, a[i].row, a[i].col, a[i].value);
	printf("Transpose Matrix b\n");
	for(i=0; i<11; i++)
		printf("%d: %d %d %d\n", i, b[i].row, b[i].col, b[i].value);
	return 0;
}
