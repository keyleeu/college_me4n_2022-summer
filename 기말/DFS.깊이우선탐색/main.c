#include <stdio.h>
#include "adjList.h"
#include "BFS.h"
#include "DFS.h"

int main(void) {
	int i;
	graphType* G1 = (graphType*)malloc(sizeof(graphType));

	//G1 ���� : ���� u�� ���� ���� (u,v)�� ���Լ����� v�� ū �ͺ���.
	createGraph(G1);
	for (i = 0; i < 7; i++)
		insertVertex(G1, i);
	insertEdge(G1, 0, 2);
	insertEdge(G1, 0, 1);
	insertEdge(G1, 1, 4);
	insertEdge(G1, 1, 3);
	insertEdge(G1, 1, 0);
	insertEdge(G1, 2, 4);
	insertEdge(G1, 2, 0);
	insertEdge(G1, 3, 6);
	insertEdge(G1, 3, 1);
	insertEdge(G1, 4, 6);
	insertEdge(G1, 4, 2);
	insertEdge(G1, 4, 1);
	insertEdge(G1, 5, 6);
	insertEdge(G1, 6, 5);
	insertEdge(G1, 6, 4);
	insertEdge(G1, 6, 3);

	print_adjList(G1);
	printf("\n\n");
	printf("BFS : ");
	BFS_adjList(G1, 0);
	printf("\n");

	for(int v = 0; v <MAX_VERTEX;v++)
		G1->visited[v] = FALSE;
	printf("DFS : ");
	DFS_adjList(G1, 0);

	getchar();  return 0;
}

