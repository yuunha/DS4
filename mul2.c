#include <stdio.h>

void print_arr(int *arr,int size) {
	for (int i = 0; i < size; i++) {       
		printf("%d\n", arr[i]);  //3.arr[0]부터 arr[size-1]까지 출력
	}
}


int main(void)
{
	int arr1[] = {10, 20 ,30};
	int size1= sizeof(arr1) / sizeof(int); //1.main()에서 '배열'의 크기를 구한다.
	print_arr(arr1,size1);                 //2.arr1배열과 배열의 원소의 개수인size1을
	                                          //print_arr의 매개변수로 전달
	return 0;
}