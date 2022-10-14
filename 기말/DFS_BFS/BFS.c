#include <stdlib.h>
#include <stdio.h>
#include "LinkedQueue.h"
#include "adjList.h"
#include "BFS.h"

// 그래프 g에서 정점 v에 대한 너비 우선 탐색 연산 : [알고리즘 8-2] 구현
void BFS_adjList(graphType* g, int v) {
	graphNode* w;

	// 큐 생성
	Queue* Q;						
	Q = createQueue();	
	g->visited[v] = TRUE;
	printf(" %c", v + 65);			// 정점 v를 알파벳으로 바꾸어 출력
	enqueue(Q, v);					// 현재 정점 v를 큐에 enQueue

	// 큐가 공백인 아닌 동안 너비 우선 탐색 수행
	while (!isQueueEmpty(Q)) {
		v = dequeue(Q);
		// 현재 정점 w를 방문하지 않은 경우 
		for (w = g->adjList_H[v]; w; w = w->link)	// 인접 정점이 있는 동안 수행
			if (!g->visited[w->vertex]) {			// 정점 w가 방문하지 않은 정점인 경우
				enqueue(Q, w->vertex);
				g->visited[w->vertex] = TRUE;
				printf(" %c", w->vertex + 65);		// 정점 0~6을 A~G로 바꾸어 출력
			}
	} // 큐가 공백이면 너비 우선 탐색 종료	
}