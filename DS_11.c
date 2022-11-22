#include <stdio.h>
#include <stdlib.h>

 struct TreeNode {
    int key;    // key 값
    struct TreeNode* left;    // left child
    struct TreeNode* right;     // right child
};
 
struct TreeNode* search(struct TreeNode* root, int key) {

    if (root == NULL) {            // case1) 루트가 비어있는 경우->에러
        printf("Error : 값을 찾을 수 없습니다\n");
        return root;
    }
    else if (key == root->key) {    // case2)받아온 key = 루트의 key ->값을 찾음
        return root;
    }
    else if (key < root->key) {    // case3)받아온 key<루트의 키 ->왼쪽 서브트리 탐색 
        search(root->left, key);
    }
    else if (key > root->key) {    // case4)받아온 key<루트의 키 -> 오른쪽 서브트리 탐색
        search(root->right, key);
    }
}

void print_tree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d\n", root->key);
    print_tree(root->left);
    print_tree(root->right);
}

struct TreeNode* insert(struct TreeNode* root, int key) {
    struct TreeNode* ptr;     // 탐색하는 포인터 
    // newNode 생성
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));    
    newNode->key = key;                                
    newNode->left = newNode->right = NULL;   
    //case1) 루트가 비어있는 경우-> 루트에 newnode삽입
    if (root == NULL) {     
        root = newNode;
        return root;
    }
 
    ptr = root;    // root 노드부터 탐색 진행  

    while (ptr) {//포인터변수가 null이 아닌동안 반복
        // case2) 같은값인 경우-> error
        if (key == ptr->key) {    
            printf("Error : 중복값은 허용되지 않습니다!\n");
            return root;
        }
        //case2) 받아온 key<루트의 키 ->왼쪽서브트리
        else if (key < ptr->key) {    
            if (ptr->left == NULL) {  // 왼쪽이 비어있다면 추가 
                ptr->left = newNode;
                return root;
            }
            else {    // 비어있지 않다면 다시 탐색 진행 
                ptr = ptr->left;
            }
        }
        //case3)받아온 key>루트의 키 ->오른쪽서브트리
        else {     
            if (ptr->right == NULL) {    // 오른쪽이 비어있다면 추가 
                ptr->right = newNode;
                return root;
            }
            else {    // 비어있지 않다면 다시 
                ptr = ptr->right;
            }
        }
    }

}


struct TreeNode* delete_node(struct TreeNode* root, int key) {
    struct TreeNode* del = NULL;    // 삭제할 노드     
    struct TreeNode* parent = NULL;    // 삭제할 노드의 부모 노드 
    struct TreeNode* leftL= NULL;    // 삭제할 노드의 왼쪽 서브트리에서 가장 큰 노드 
    struct TreeNode* parentL = NULL;    // leftL의 부모노드 
    struct TreeNode* child = NULL;        // 삭제할 노드의 자식 노드 

    del = root;
    //삭제할 노드 찾아서(key값 비교) del에 넣기
    while (del != NULL) {    
        if (key == del->key) {
            break;
        }
        parent = del;
        if (key < del->key) {
            del = del->left;
        }
        else {
            del = del->right;
        }
    }
    if (del == NULL) {
        printf("Error : 존재하지 않는 키\n");
        return root;
    }

    // case1)삭제할 노드의 자식X 
    if (del->left == NULL && del->right == NULL) {   
        //2.1)부모노드 O -> 부모의 자식노드 삭제
        if (parent != NULL) {   
            if (parent->left == del) {    // 부모노드의 왼쪽노드 삭제 
                parent->left = NULL;
            }
            else {    // 부모노드의 오른쪽 노드 삭제
                parent->right = NULL;
            }
        }
        else {    // 2.2)부모노드가 없는 경우 : root 노드 삭제 
            root = NULL;
        }
    }
    // case2)삭제할 노드의 자식 2개
    else if (del->left != NULL && del->right != NULL) {    
        leftL = del; //삭제할 노드
        leftL = del->left; //왼쪽 서브트리 탐색 위해서

        //1. 왼쪽 서브트리의 가장 큰 값 찾기->LeftL에 대입
        while (leftL->right != NULL) {    
            parentL = leftL;
            leftL = leftL->right;
        }
      
        parentL->right = leftL->left;    // successor의 자식 노드 위치 변경 
        leftL->left = del->left;    // successor를 삭제할 노드의 위치로 옮긴 것과 같음 
        leftL->right = del->right;

        if (parent != NULL) {    // 삭제할 노드의 부모노드가 있을 때 
            if (parent->left == del) {
                parent->left = leftL;
            }
            else {
                parent->right = leftL;
            }
        }
        else {
            root = leftL;
        }
    }
    else {    //     삭제할 노드의 자식 노드가 1개인 경우 
        if (del->left != NULL) {    // 왼쪽 노드 
            child = del->left;
        }
        else {    // 오른쪽 노드 
            child = del->right;
        }

        if (parent != NULL) {    // 부모노드가 있는 경우 
            if (parent->left == del) {    // 부모노드의 왼쪽 노드로 삭제할 노드의 자식노드 연결 
                parent->left = child;
            }
            else {    // 부모노드의 오른쪽 노드로 삭제할 노드의 자식노드 연결  
                parent->right = child;
            }
        }
        else {
            root = child;
        }
    }
    free(del);    // 메모리해제 
    return root;
}

int main() {
    struct TreeNode* root = NULL;
    struct TreeNode* ptr = NULL;
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 10);

    print_tree(root);
    printf("\n");

    ptr = search(root, 7);
    printf("%d\n", ptr->key);

    root = delete_node(root, 7);
    ptr = search(root, 7);

    ptr = search(root, 5);
    printf("%d\n", ptr->key);

    root = delete_node(root, 5);
    ptr = search(root, 5);

    return 0;
}


