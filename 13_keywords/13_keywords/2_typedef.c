/* typedef 의 이용 */
#include <stdio.h>
struct HUMAN {
    int age;
    int height;
    int weight;
    int gender;
};

typedef struct HUMAN Human;
int Print_Status(Human human);
/*
    typedef (이름을 새로 부여하고자 하는 타입) (새로 준 타입의 이름)
    다시 말해 위에서 썼던 코드는 struct HUMAN이라는 타입에 Human이라는 다른 이름을 붙인 것이다.
    즉 struct HUMAN을 Human이라고 써도 된다는 것이다.
    물론 기존의 이름을 없애 버린 것은 아니기에 struct HUMAN이라고 작성해도 된다.

    struct HUMAN a;
    Human a;
    둘은 동일한 것이 된다.

    typedef를 이용하는 이유는 이렇게 형을 간단히 쓴다는 이유만은 아니다.
    3_typedef.c를 보자
*/

int main() {
    Human Adam = { 31, 182, 75, 0 };
    Human Eve = { 27, 166, 48, 1 };

    Print_Status(Adam);
    Print_Status(Eve);
}

int Print_Status(Human human) {
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