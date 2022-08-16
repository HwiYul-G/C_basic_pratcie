/* 이전에 작성한 경험이 있는 코드이다.
    구조체를 사용할 때 귀찮은 점이 있는데 구조체마다 struct 키워드를 붙여야하는 점이다.
    간혹 struct 키워드를 붙이지 않으면
    error C2146: 구문 오류 : ')'이(가) 'human' 식별자 앞에 없습니다.
    error C2061: 구문 오류 : 식별자 'human'
    error C2059: 구문 오류 : ';'
    error C2059: 구문 오류 : ')'
    error C2449: 파일 범위에 '{'가 있습니다. 함수 헤더가 없는 것 같습니다.
    error C2059: 구문 오류 : '}'

    이러한 오류 테러를 맞보게 된다.

    그렇다면 매번 귀찮게 struct HUMAN이라고 작성해야할까?
    
    간단한 방법이 있는데 바로 typedef struct HUMAN Human; 이라는 것이다.
    ==> 2_typedef.c와 코드 차이점 비교

*/
#include <stdio.h>
int Print_Status(struct HUMAN human);
struct HUMAN {
    int age;
    int height;
    int weight;
    int gender;
};

int main() {
    struct HUMAN Adam = { 31, 182, 75, 0 };
    struct HUMAN Eve = { 27, 166, 48, 1 };

    Print_Status(Adam);
    Print_Status(Eve);
}

int Print_Status(struct HUMAN human) {
    if (human.gender == 0) {
        printf("MALE \n");
    }
    else {
        printf("FEMALE \n");
    }

    printf("AGE : %d / Height : %d / Weight : %d \n", human.age, human.height,
        human.weight);

    if (human.gender == 0 && human.height >= 180) {
        printf("HE IS A WINNER!! \n");
    }
    else if (human.gender == 0 && human.height < 180) {
        printf("HE IS A LOSER!! \n");
    }

    printf("------------------------------------------- \n");

    return 0;
}