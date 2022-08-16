/* 간단한 계산기 프로그램
    #include <stdio.h>
    int main() {
        int input;
        int a, b;

        while (1) {
            printf("--- 계산기 --- \n");
            printf("1. 덧셈 \n");
            printf("2. 뺄셈 \n");
            printf("3. 종료 \n");

            scanf("%d", &input);

            if (input == 1) {
                printf("두 수 : ");
                scanf("%d%d", &a, &b);
                printf("%d 와 %d 의 합 : %d \n", a, b, a + b);
            }
            else if (input == 2) {
                printf("두 수 : ");
                scanf("%d%d", &a, &b);
                printf("%d 와 %d 의 차 : %d \n", a, b, a - b);
            }
            else
                break;
        }

        return 0;
    }
*/

/*
    아래의 프로그램을 실제 계산기에 이용한다고 하자.
    그런데 우리가 이 프로그램을 사용할 계산기는 안타깝게도 CPU에서 32bit 정수 연산을 할 수 없다.
    오직 16bit 이하만 연산할 수 있다고 하자.

    그렇다면 이 계산기에서 int형을 사용하는 것은 불가능하고 short나 char형의 변수들만 선언해야한다.
    그런데 동일 프로그램인데 다른 기종의 계산기에선 int형이 사용가능하다고 하자.
    그렇다면 이 코드를 다시 또 바꿔줘야한다.
    이는 매우 번거로운 일이고 이를 위해사 아래와 같이 코드를 바꿔보자.
*/
/* 향상된 소스 코드 */
#include <stdio.h>
typedef int CAL_TYPE;
int main() {
    CAL_TYPE input;
    CAL_TYPE a, b;

    while (1) {
        printf("--- 계산기 --- \n");
        printf("1. 덧셈 \n");
        printf("2. 뺄셈 \n");
        printf("3. 종료 \n");

        scanf("%d", &input);

        if (input == 1) {
            printf("두 수 : ");
            scanf("%d%d", &a, &b);
            printf("%d 와 %d 의 합 : %d \n", a, b, a + b);
        }
        else if (input == 2) {
            printf("두 수 : ");
            scanf("%d%d", &a, &b);
            printf("%d 와 %d 의 차 : %d \n", a, b, a - b);
        }
        else
            break;
    }

    return 0;
}
/*
    변경한 소스코드 역시 잘 실행된다.
    다만 바뀐 것은 변수의 타입을 CAL_TYPE이라고 한 것이다.
    그리고 위에서 typedef를 통해 CAL_TYPE가 int형과 같다고 정의했다.
     만일 이 소스코드를 short나 char만 되는 계산기에 적용시키려면 어떠헥 해야 할까?
     기존에는 모든 변수의 타입을 전부다 수정해야 했지만
     이제는 typedef에서 CAL_TYPE의 형을 short나 char로 간단히 바꿔버리면 된다.
*/
