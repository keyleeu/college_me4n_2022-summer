#include <stdio.h>
#include "adjList.h"
#include "LinkedStack.h"
#include "DFS.h"

// 그래프 g에서 정점 v에 대한 깊이 우선 탐색 연산 : [알고리즘 8-1] 구현
void DFS_adjList(graphType* g, int v) {
	graphNode* w;
	
	// 스택 생성
	Stack* S;
	S = createStack();
	S->top = NULL;				// 스택의 top 설정
	push(S, v);					// 깊이 우선 탐색을 시작하는 정점 v를 스택에 push
	g->visited[v] = TRUE;
	printf(" %c", v + 65);			// 정점 v를 알파벳으로 바꾸어 출력
	push(S, v);					// 깊이 우선 탐색을 시작하는 정점 v를 스택에 push

	// 스택이 공백이 아닌 동안 깊이 우선 탐색 반복
	while (!isStackEmpty(S)) {
		v = pop(S);
		w = g->adjList_H[v];
		// 인접 정점이 있는 동안 수행
		while (w) {
			// 현재 정점 w를 방문하지 않은 경우 
			if (!g->visited[w->vertex]) {
				push(S, w->vertex);					// 현재 정점 W를 스택에 push
				g->visited[w->vertex] = TRUE;	// 정점 w에 대한 배열 값을 TRUE로 설정
				printf(" %c", w->vertex + 65);	// 정점 0~6을 A~G로 바꾸어서 출력
				v = w->vertex;
				w = g->adjList_H[v];
			}
			// 현재 정점 w가 이미 방문된 경우
			else 
				w = w->link;
		}
	} // 스택이 공백이면 깊이 우선 탐색 종료
}