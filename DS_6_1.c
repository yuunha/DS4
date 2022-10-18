#include <stdio.h>
#include <math.h>
typedef struct Circle {
    double radius, x,y;
}circle;
typedef struct Point {
    double x,y;
}point;
int Circle1(circle c, point p) {
    //원 구조체 선언
    //3가지 경우
    double xy = sqrt(pow(c.x - p.x,2.0) + pow(c.y - p.y,2.0));
    //1.원 안
    if (c.radius > xy)//두 점 사이의 거리>지름 인 경우
        printf("원 안\n");
    //2.원 위
    else if (c.radius == xy)  //두 점 사이의 거리=지름 인 경우
        printf("원 위\n");
    //3.원 밖
    else                       //두 점 사이의 거리<지름 인 경우
        printf("원 밖\n");
}
int main()
{
    circle c1; circle c2;
    point p1;
    c1.x = 3.0;c1.y = 3.0;
    c1.radius = 3.0;
    p1.x = 3.0;p1.y = 6.0;
    c2.x = 3.0;c2.y = 3.0;
    c2.radius = 6.0;

    //Circle1(c1, p1);
    Circle2(c1, c2);
    return 0;
}
int Circle2(circle c1, circle c2) {
    double xy = sqrt(pow(c1.x - c2.x, 2.0) + pow(c1.y - c2.y, 2.0));
    //c1의 반지름이 c2의 반지름보다 클때 와 작을 때로 나눈다
    if (c1.radius > c2.radius) {           //1.c1의 반지름이 c2의 반지름보다 클 경우
        if (((xy + c2.radius) == c1.radius) || ((c1.radius + c2.radius) == xy)) { 
                                                 //1-(1).(두 원의 중심 사이의 거리+c2의 반지름)이 c1의 반지름의 길이와 같거나,
                                                   //c1의 반지름과 c2의 반지름의 길이를 더한 값이 두 원의 중심 사의 길이와 같다면,
            printf("한 점 일치\n");                          //"한점일치"이다.
        }
        else if ((xy + c2.radius) > c1.radius) {  //1-(2).두 원의 중심 사이의 거리와 c2의 반지름을 더한 값이 c1의 반지름의 길이보다 크면,
            printf("두점 일치\n");                           //"두점일치"이다.
        }
        else if ((xy + c2.radius) < c1.radius) { //1-(3).두 원의 중심 사이의 거리와 c2의 반지름을 더한 값이 c1의 반지름으 길이보다 작으면.
            printf("c2가 c1에 속함\n");                      //"c2가 c1에 속함"이다.
        }
    }
    else {                                            //2.c1의 반지름이 c2의 반지름보다 작을 경우
        if ((c1.radius == c2.radius) && (c1.x == c2.x) && (c1.y == c2.y)) {        
                                                      //2-(1).c1과 c2의 x좌표,y좌표,반지름(radius)가 모두 일치하면,        
            printf("일치\n");                                     //"일치"이다.
        }
        else if (((xy + c1.radius) == c2.radius) || ((c1.radius + c2.radius) == xy)) {  
                                                       //2-(2)(두 원의 중심 사이의 거리+c1의 반지름)이 c2의 반지름의 길이와 같거나,
                                                       //c1의 반지름과 c2의 반지름의 길이를 더한 값이 두 원의 중심 사의 길이와 같다면,            
            printf("한 점 일치\n");                              //"한점일치"이다.
        }
        else if ((xy + c1.radius) > c2.radius) { //2-(3).두 원의 중심 사이의 거리와 c1의 반지름을 더한 값이 c2의 반지름의 길이보다 크면,
            printf("두 점 일치\n");                         //"두점일치"이다.
        }
        else if ((xy + c1.radius) < c2.radius) { //2-(4).두 원의 중심 사이의 거리와 c1의 반지름을 더한 값이 c2의 반지름의 길이보다 작으면.
            printf("c1이 c2에 속함\n");                             //"c1이 c2에 속함"이다.
        }
    }
}

