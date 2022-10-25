#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

    int a1, a2, a3, a4;
    //1.행렬 A,B의 행의 개수,열의 개수를 입력받는다
    printf("A의 행의 개수:");
    scanf("%d", &a1);
    printf("A의 열의 개수:");
    scanf("%d", &a2);
    printf("B의 행의 개수:");
    scanf("%d", &a3);
    printf("B의 열의 개수:");
    scanf("%d", &a4);
    
    //행렬A,B,A*B를 2차원배열로 선언한다
    int** arr1; //행렬A
    int** arr2;  //행렬B
    int** mul;  // A*B

    //2.행렬을 배열을 통해 동적할당
    //행렬A를 배열을 통해 동적할당
    arr1 = (int**)malloc(sizeof(int)*a2);  //배열의 세로 동적할당
    for (int i = 0; i < a1; i++) {              //배열의 가로 동적할당;
        arr1[i] = (int*)malloc(sizeof(int)*a1);
    }
    //행렬B를 배열을 통해 동적할당
    arr2 = (int**)malloc(sizeof(int) * a4); //배열의 세로 동적할당
    for (int i = 0; i < a3; i++) {               //배열의 가로 동적할당
        arr2[i] = (int*)malloc(sizeof(int) * a4);
    }
    //행렬mul을 배열을 통해 동적할당
    mul = (int**)malloc(sizeof(int) * a2);//배열의 세로 동적할당
    for (int i = 0; i < a2; i++) {             //배열이 가로 동적할당
        mul[i] = (int*)malloc(sizeof(int) * a2);
    }
 
    //3.행렬의 원소 입력받기
    //행렬A의 원소 입력받기(arr1배열)
    for (int a = 0; a < a1; a++){
        for (int b = 0; b < a2; b++) {    
            printf("arr1[%d][%d]입력:", a, b);
            scanf("%d", &arr1[a][b]);
        }
    }//행렬B의 원소 입력받기(arr2배열)
    for (int c = 0; c < a3; c++) {
        for (int d = 0; d < a4; d++) {
            printf("arr2[%d][%d]입력:", c, d);
            scanf("%d", &arr2[c][d]);
        }
    }
    //행렬A와B의 곱을 계산해 mul의 원소로 대입
    for (int e = 0; e < a1; e++) {
        for (int f = 0; f < a4; f++) {
            mul[e][f] = 0;
            for (int k = 0; k < a2; k++)
                mul[e][f] += arr1[e][k] * arr2[k][f];//행렬의 곱 계산
            printf("결과: %d행 %d열: %d\n", e+1, f+1, mul[e][f]);
        }
    }
    //동적 할당 해제
    for (int g = 0; g <a1 ; g++) {
        free(arr1[g]);
    }
    free(arr1);
    for (int h = 0; h <a3; h++) {
        free(arr2[h]);
    }
    free(arr2);
    for (int n = 0; n <a2 ; n++) {
        free(mul[n]);
    }
    free(mul);

    return 0;
}

