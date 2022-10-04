#include <stdio.h>
//재귀함수
int func1(int n) {    
    if (n <= 3) return n - 1;                               //첫번째 경우> 수열의 1,2,3번째 값은 0,1,2이다.
    else{        
        return func1(n - 1) + func1(n - 2) + func1(n - 3);  //두번째경우(n>3일때),수열의 값은 직전 값 3개를 더한 값이다.  
    }
}
//비재귀함수
int func2(int n) { 
    int t1 = 0, t2 = 1, t3 = 2, next;
     
    if (n == 1) {             //n이 1,2,3 일때는 0,1,2를 출력한다.
        printf("%d", 0);
    }
    else if (n == 2) {
        printf("%d", 1);
    }
    else if (n == 3) {
        printf("%d", 2);
    }
    else {
        for (int i = 0; i < n-3; i++) {
            next = t1 + t2 + t3;        //next에 직전 세 수의 합을 대입한다.
            t1 = t2;                    //그 후, t1,t2,t3에 각각 t2,t3,next를 대입
            t2 = t3;                    //즉, t1,t2,t3에 한 칸씩 뒤로 밀린 값을 대입해서
            t3 = next;                  //다음 반복때는 한 칸 씩 뒤로 밀린 세 수를 더한다.
                                        //이것을 반복한다.
        }
        printf("%d\n", next);
    }
    return 0;
}
int main()
{
    printf("%d\n", func1(2));
    printf("%d\n",func1(44));
    func2(2);
    func2(44);
    return 0;
}

