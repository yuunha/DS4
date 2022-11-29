#include <stdio.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 6 
#define INF 10000
#define START 0

//인접행렬로 받아오기
int weight[MAX_VERTICES][MAX_VERTICES] = {
	{0,INF,25,15,35, INF},
	{15,0,INF,INF,10, INF},
	{10,50,0,INF,65, INF},
	{0,20,INF,0,35, INF},
	{INF,INF,30,0,INF,INF},
	{INF, INF,INF,3,INF,0}
};

int distance[MAX_VERTICES];
int S[MAX_VERTICES];

//남은 정점 중 최단경로 찾기
int nextVertex() {
	int i, min, minPos;   
	min = INT_MAX;
	minPos = -1;
	for (int i = 0; i < MAX_VERTICES; i++) {
		if (distance[i] < min && !S[i]) {//현재min보다 작고, 남은 정점인 경우
			min = distance[i];           //min과 minPos 업데이트
			minPos = i;
		}
	}
	return minPos;// 최단경로 가진 정점 리턴
}

//가장 짧은 경로를 찾아 print
void shortestPath() {
	int i, u, w = 0;
	//distance를 직선거리로 초기화하고, 
	//집합s는 false로 초기화(아무것도 들어있지 않음)
	for (int i = 0; i < MAX_VERTICES; i++) {
		distance[i] = weight[START][i];
		S[i] = FALSE;
	}

	S[START] = TRUE;//집합s에 시작정점 추가
	distance[START] = 0;  

	for (int i = 0; i < 5; i++) {
		u = nextVertex();
		S[u] = TRUE;
		 for(int w = 0; w < MAX_VERTICES; w++) {
			if(!S[w]) {  //남은 정점 중에서,
    	//정점u를 경유할때 현재저장된 경로보다 짧으면, 경로길이 업데이트
				if (distance[u] + weight[u][w] < distance[w])
					distance[w] = distance[u] + weight[u][w];
			} 
		}
	}
	//최단거리 출력
	printf("v0에서의 최단경로 표 \nv0 v1  v2  v3  v4  v5 \n");
	for (int i = 0; i < MAX_VERTICES; i++) {
		printf("%d  ", distance[i]);
	};
}

int main() {
	shortestPath();

	return 0;
}