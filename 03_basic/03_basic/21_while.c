/* while 문 */
#include <stdio.h>
/*
    while은 명령을 실행하기 전에 조건식이 참인지 먼저 검사함
    do-while은 먼저 명령을 실행 한 뒤 조건식을 검사한다.
    따라서, 처음부터 조건식이 참이 아니라도 명령을 먼저 실행한 다음 조건식을 검사하기 때문에 최소 1번은 수행된다.
*/
int main() {
    int i = 1, sum = 0;

    while (i <= 100) {
        sum += i;
        i++;
    }

    printf("1 부터 100 까지의 합 : %d \n", sum);

    i = 1, sum = 0;
    do {
        sum += i;
        i++;
    } while (i < 1);
    printf("sum : %d \n", sum);

    return 0;
}