// for문 (statement)
#include <stdio.h>

/*
    for(초기식; 조건식; 증감식){}
    - 초기식 : 제어변수가 초기화 됨 (제어변수는 반복문을 얼마나 반복할지를 알기 위해 둔 변수)
    - 조건식 : 조건이 true 일 때만 일을 수행함
    - 증감식 : i++, i-=2 등


*/

int main() {
    int i;
    for (i = 0; i < 20; i++) {
        printf("숫자 : %d \n", i);
    }

    int sum = 0;
    for (i = 0; i < 20; ++i) {
        sum += i;
    }
    printf("1부터 19까지의 합 : %d \n", sum);

    sum = 0;
    for (i = 0; i <= 10000; ++i) {
        sum += i;
    }
    printf("1부터 10000까지의 합 : %d \n", sum);

    int subject, score;
    double sum_score = 0;

    printf("몇 개의 과목 점수를 입력받을 것인가요?");
    scanf("%d", &subject);

    printf("\n 각 과목의 점수를 입력해 주세요 \n");
    for (i = 0; i <= subject; i++) {
        printf("과목 %d : ", i);
        scanf("%d", &score);
        sum_score += score;
    }
    printf("전체 과목의 평균은 : %.2f \n", sum_score / subject);


    return 0;
}