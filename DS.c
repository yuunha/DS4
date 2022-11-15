#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
//왼쪽 오른쪽 노드를 가리키는 포인터rlink,llink와 name,score을 가진 node 정의
struct NODE {
	struct NODE* rlink;
	struct NODE* llink;
	char name[20];
	int score;
};
struct NODE* head;
struct NODE* tail;

//head와 tail을 동적할당 후, head 뒤에 tail이 오도록 초기화
//head의 llink는 null,rlink는 tail
//tail의 llink는 head,rlink는 null을 가리키도록 초기화
void init() {
	head = (struct NODE*)malloc(sizeof(struct NODE));
	tail = (struct NODE*)malloc(sizeof(struct NODE));

	head->rlink = tail;
	head->llink = NULL;
	tail->rlink = NULL;
	tail->llink = head;
}

//노드 생성: 이름과 점수를 동적할당한 newnode의 name,score에 입력받는다
//결과:노드를 반환
struct NODE* createnode() {
	struct NODE* newnode = (struct NODE*)malloc(sizeof(struct NODE));
	char n[20] = { '\0' };
	int s = 0;

	printf("이름 : ");
	scanf("%s", n);
	printf("점수 : ");
	scanf("%d", &s);

	strcpy(newnode->name, n);
	newnode->score = s;
	
	return (newnode);
}
//노드 삽입:노드를 생성후, tail앞에 생성한 노드를 삽입
//노드 삽입 방법: tail의 앞에 있던 노드의 rlink와 tail의 llilnk를 newnode로 바꿔준다
//       :새로운 노드의 rlink와 llink는 tail과 tail앞에 있던 노드로 넣는다
void push_back() {
	struct NODE* newnode = createnode();
	struct NODE* p;
	p = tail;
	p->llink->rlink = newnode;
	newnode->llink = p->llink;
	p->llink = newnode;
	newnode->rlink = p;
}

//노드 삭제: 문자열n에 학생의 이름을 받아와서, p->name과 비교해서 같은 노드 찾기
//노드 삭제 방법: 찾은 노드의 오른쪽 노드의 llink와 찾은 노드의 왼쪽 노드의 rlink에
//             :                찾은노드의 왼쪽노드, 찾은노드의 오른쪽 노드 대입한 후 
//                                     찾은 노드의메모리 삭제
void remove_node() {
    char n[20];
	struct NODE* p;

	printf("삭제할 학생의 이름 : ");
	scanf("%s", &n);


	p = head->rlink;
	while (p->rlink != tail) {
		if (!strcmp(n, p->name)) {
			p->rlink->llink = p->llink;
			p->llink->rlink = p->rlink;
			free(p);
			return;
		}
		p = p->rlink;
	}
}

//노드 찾기: 이름을 받아와서, head다음노드부터 tail직전 노드까지 탐색하며
 //                 받아온 이름과 탐색한 이름이 같으면 그때 그 노드의 점수 출력
void search_node() {
	char n[20];
	struct NODE* p;
	p = head;

	printf("학생의 이름 : ");
	scanf("%s", n);

	int myscore;

	while (p->rlink != tail) {
		if (!strcmp(n, p->name)) {
			printf(" 학생의 점수: %d \n", p->score);
			myscore = p->score;
		}
		p = p->rlink;
	}
}

//메모리 삭제
void free_node() {
	struct NODE* p;
	p = head;
	while (p != NULL) {
		free(p);
		p = p->rlink;
	}

}

int	main() {
	int menu = 0;
	init();
	while (menu != 5)
	{
		printf("1.입력 2.제거 3.검색 4.종료\n메뉴선택 : ");
		scanf("%d", &menu);
		switch (menu) {

		case(1):
			push_back();
			break;
		case(2):
			remove_node();
			break;
		case(3):
			search_node();
			break;
		case(4):
			free_node();
			break;
		default:
			printf("1과 5사이의 정수를 입력하세요");
			break;
		}
	}
}