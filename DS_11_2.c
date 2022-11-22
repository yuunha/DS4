#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int heap[200]; // 힙
int count = 0; // heap의 원소의 갯수, heap의 끝

void swap(int* a, int* b) {
	int tmp = *a; *a = *b; *b = tmp;
}

void push(int data) {
	// 힙의 가장 끝에 데이터 추가
	heap[++count] = data;
	//child를 parent와 비교->child가 크면 두개를 바꿈
	int child = count;
	int parent = child / 2;
	while (child > 1 && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}
}
//삭제 함수
int pop() {
	// 힙의 가장 첫번째 원소 반환
	int result = heap[1];
	//첫번째 원소와 가장 끝의 원소를 바꾼다-> 첫번째 원소(가장 큰 원소) 삭제됨
	swap(&heap[1], &heap[count]);
	count--;
	//나머지 남은 원소들 배열
	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= count) {
		child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}
	//child가 parent보다 크면 위치 교환
	while (child <= count && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);

		parent = child;
		child = child * 2;
		if (child + 1 <= count) {
			child = (heap[child] > heap[child + 1]) ? child : child + 1;
		}
	}
	return result;
}

int main() {

	// 랜덤함수를 위한 srand와 seed
	srand(time(NULL));


	// 배열 초기화
	int arr[6] = { 3,5,6,9,1,2 };
	// 삽입
	for (int i = 0; i < 6; i++) {
		push(arr[i]);
	}
    //값들이 내림차순으로 정렬됨 
	for (int i = 0; i < 6; i++) {
		printf("%d ", pop());
	}
	printf("\n");


	int arr1[8] = { 3,11,14,5,6,9,1,2 };
	for (int i = 0; i < 8; i++) {
		push(arr1[i]);
	}
	// 값들이 내림차순으로 정렬됨 
	for (int i = 0; i < 8; i++) {
		printf("%d ", pop());
	}
	printf("\n");


	return 0;
}
