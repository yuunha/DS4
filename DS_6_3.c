#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char ch;
	//문자수,문자수,줄수 변수 선언
	int countC1 = 0; //문자 수(공배 제외)
	int countJ = 0; //줄 수
	int countG = 0;//공백문자수

	//txt입력받기
	FILE* fp;
	fp = fopen("test.txt", "r");
	char buf[500];
	fread(buf, 1,strlen(buf), fp); //전체읽기
	fclose(fp);  //파일 포인터 닫기

	for (int i = 0; i < 500; i++) {
		if (buf[i] > 'a' && buf[i] < 'z') {         //글자수 세기(소문자)
			countC1++;
		}
		else if (buf[i] > 'A' && buf[i] < 'Z') {  //글자 수 세기(대문자)
			countC1++;
		}
		else if (buf[i] == '\n') {  //줄 수 세기
			countJ++;
		}
		else if (buf[i] == ' ') {  //공백수 세기
			countG++;
		}	
	}
	printf("문자 수(공백포함):%d\n 문자수(공백 제외)%d\n 줄수:%d", countC1 + countG,countC1,countJ+1);
	           //문자수+공백수=문자수(공백포함)=countC1+countG/문자수(공백제외)=countC1/줄수=countJ+1

}

	


