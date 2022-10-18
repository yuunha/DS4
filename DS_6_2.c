#define _CRT_SECURE_NO_WARINGNS
#include <stdio.h>
#include <windows.h>

int main()
{
	//1.100자 이하의 문자열 입력받기
	char  s1[100];//크기가 100인 char형 배열s1 선언
	printf("문자열을 입력하세요.");
	gets(s1);     //입력받은 문자열을 s1에 저장

	//2.getch()이용해 문자열 따라치기
	printf("따라치세요");
	for (int i = 0; i < 100; i++) {
	int c1 = _getch();   //(1)문자를 입력받는다.
	
	// (3)문자c1이 입력될때마다 s[0],s[1],s[2] 순서대로 문자를 하나씩 비교
	if (c1 !=s1[i]) {   
	//만약,새로 입력받은 문자(c1)가 처음입력받은 문자열의 i번째 문자(s1[i])과 다르다면,       
		printf("\a\n");  // >경고음을 발생시킨 후,
		break;           //종료시킨다.
	}
	printf("%c", c1);   //(2)입력받은 문자를 출력한다.
		
	}

	return 0;
}


