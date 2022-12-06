#include <stdio.h>

#define MAX 10


int arr[MAX];
int arr1[MAX];
void mergeSort(int data[], int p, int r);
void merge(int data[], int p, int q, int r);

int bubbleSort(int arr[]) {
    //임시 변수
    int temp = 0;

    printf("정렬 전 : ");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }
    //오름차순 정렬
    for (int i = 0; i < MAX - 1; i++)
    {
        for (int i = 0; i < MAX; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        for (int j = 0; j < MAX - 1 - i; j++)
        {
            
            if (arr[j] > arr[j + 1])         //바로 앞뒤를 비교해서 앞이 더 크면 바꾼다
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    //오름차순 정렬된 출력
    printf("\n");
    printf("\nbubble정렬 후 : ");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void quickSort(int arr[], int L, int R) {
    
    int left = L, right = R;
    int pivot = arr[(L + R) / 2];    // pivot 설정 (가운데) 
    int temp;

    do
    {
        while (arr[left] < pivot)    // left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
            left++;
        while (arr[right] > pivot)    // right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
            right--;
        if (left <= right)    // left가 right보다 왼쪽에 있다면 교환 
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            /*left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동*/
            left++;
            right--;
        }
    } while (left <= right);    // left가 right 보다 오른쪽에 있을 때까지 반복 

  /* recursion */
    if (L < right)
        quickSort(arr, L, right);    // 왼쪽 배열 재귀적으로 반복 

    if (left < R)
        quickSort(arr, left, R);    // 오른쪽 배열 재귀적으로 반복 
}

printQucikSort(int arr[]) {
    printf("\n");

    printf("\n정렬 전 : ");
    for (int j = 0; j < MAX; j++) {
        printf("%d ", arr[j]);
    }
    quickSort(arr, 0, MAX - 1);

    printf("\n");

    printf("quick정렬 후 : ");
    for (int j = 0; j < MAX; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");
}


void insertionSort(int* arr) {
    int i, j, key;

    for (i = 1; i < MAX; i++) {
        key = arr[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사


        for (j = i - 1; j >= 0 && arr[j] > key; j--) { // key가 더 큰 값일 때까지 
            arr[j + 1] = arr[j]; // 한 칸 뒤로 이동 
        }
        for (int j = 0; j < MAX; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
        arr[j + 1] = key; // 알맞은 위치에 key 삽입 
    }
}



void mergeSort(int data[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort(data, p, q);
        mergeSort(data, q + 1, r);
        merge(data, p, q, r);
    }
}
void merge(int data[], int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    int tmp[8]; // 새 배열
    while (i <= q && j <= r) {
        if (data[i] <= data[j]) tmp[k++] = data[i++];
        else tmp[k++] = data[j++];
    }
    while (i <= q) tmp[k++] = data[i++];
    while (j <= r) tmp[k++] = data[j++];
    for (int a = p; a <= r; a++) data[a] = tmp[a];
}
void printMergeSort(int arr[]) {

    printf("\n");

    printf("정렬 전:");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    mergeSort(arr, 0, 7);
    printf("\nmerge정렬 후");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
}
int main()
{
    // 버블 정렬
    int data[MAX]
        = { 5 , 15 , 70 , 20 , 1 ,
            4 , 10 , 2 , 8  , 11,
             };
    bubbleSort(data);

    //퀵정렬
    int arr[MAX] 
        = { 5 , 15 , 70 , 20 , 1 ,
            4 , 10 , 2 , 8  , 11,
             };
    
    printQucikSort(arr);

    int arr1[MAX]
        = { 5 , 15 , 70 , 20 , 1 ,
            4 , 10 , 2 , 8  , 11,
             };
    printMergeSort(arr1);



    int arr3[MAX]
        = { 5 , 15 , 70 , 20 , 1 ,
            4 , 10 , 2 , 8  , 11,
            };
    int i;
    printf("\n\n정렬 전 : ");
    for (i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr3);
    printf("insertion정렬 후 : ");
    for (i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
