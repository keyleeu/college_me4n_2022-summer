#include <stdlib.h>
#include <stdio.h>
#pragma once
// 그래프 G11의 가중치 인접행렬
int weight[MAX_VERTICES][MAX_VERTICES] = {	
	{ 0, 10, 4, 11, 2 },
	{ INF, 0, INF, 2, INF },
	{ INF, 1, 0, 6, INF },
	{ INF, INF, INF, 0, INF },
	{ INF, INF, 1, INF, 0 },
};