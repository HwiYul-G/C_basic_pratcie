/* if 와 if- else if 의 차이*/
#include <stdio.h>
int main() {
    int num;

    printf("아무 숫자나 입력해 보세요 : ");
    scanf("%d", &num);

    if (num == 7) {
        printf("a 행운의 숫자 7 이군요!\n"); // 여기만 실행됨
    }
    else if (num == 7) {
        printf("b 행운의 숫자 7 이군요! \n");
    }

    // 비교
    if (num == 7) { 
        printf("c 행운의 숫자 7 이군요!\n");
    }
    if (num == 7) {
        printf("d 행운의 숫자 7 이군요! \n");
    }

    return 0;
}
/*
    else 문은 전제 조건이 '앞의 if문이 참이 아닐 때' 실행된다는 사실을 기본으로 깔고 있다.
    따라서 if-else if 시 앞의 if가 ture이면 else if는 실행되지 않는다.

    반면 if문 if문 으로 연결된 것은 둘다 실행된다.
*/