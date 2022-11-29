#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

//1.인접리스트의 노드구조를 구조체로 정의: 데이터필드,링크필드
typedef struct graphNode {
    int data;
    struct graphNode* link;
}graphNode;

//그래프를 구조체로 정의: 정점의 개수, 헤드 포인터
typedef struct GraphType {
    int n; //정점의 개수
    graphNode* adjH[30];
}graphType;

int size;   //n*n행렬에서 n

//그래프 초기화: 정점=0,헤드포인터=null
void initGraph(graphType* g) {
    g->n = 0;
    for (int v = 0; v < 30; v++) {
        g->adjH[v] = NULL;
    }
}

//그래프 g에 간선 (u,v)삽입
void insertEdge(graphType* g,int u, int v) { //그래프 g에 간선 (u,v) 삽입
    graphNode* node;

    node = (graphNode*)malloc(sizeof(graphNode));
    node->data = v;                     //노드의 data =v
    node->link = g->adjH[u];            //노드의 링크=이전에 가장 앞에 있던 노드
    g->adjH[u] = node;                  //adj에 가장 앞의 노드 저장
}

//연결리스트 프린트
void printGraph(graphType* g) {
     
    for (int i = 0; i < size; i++) {
        printf("정점%c:", i + 65);  
        graphNode* p = g->adjH[i];    //p에 그래프의 adj배열의 맨앞노드 저장
        while (p) {
            printf("->%c", p->data + 65); //노드의 데이터 프린트
            p = p->link;                  //뒤의 노드로 이동
        }
        printf("\n");
    }
}


int main(){
    //1.행렬 A,B의 행의 개수,열의 개수를 입력받는다
    printf("n*n 행렬의 행 또는 열의 개수:");
    scanf("%d", &size);

    //행렬arr를 2차원배열로 선언한다
    int** arr; //행렬arr
 
    //행렬을 배열을 통해 동적할당
    arr = (int**)malloc(sizeof(int) * size);  //배열의 세로 동적할당
    for (int i = 0; i < size; i++) {              //배열의 가로 동적할당;
        arr[i] = (int*)malloc(sizeof(int) * size);
    }

    //행렬의 원소 입력받기
    for (int a = 0; a < size; a++) {
        for (int b = 0; b < size; b++) {
            printf("arr[%d][%d]입력:", a, b);
            scanf("%d", &arr[a][b]);
        }
    }

    graphType* g;
    g = (graphType*)malloc(sizeof(graphType));
    
    initGraph(g);              //그래프 초기화

    for (int i=0; i < size; i++) {
        for (int j=0; j < size; j++) {
            if (arr[i][j] == 1) {    //행렬의 원소의 값이 1이면,           
                insertEdge(g, i, j);  //그래프에 간선(i.j)삽입
            }
        }
    }

    printGraph(g);
    
    //동적 할당 해제
    for (int g = 0; g < size; g++) {
        free(arr[g]);
    }
    free(arr);
    
    return 0;

}