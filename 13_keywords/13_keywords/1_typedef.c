/* ������ �ۼ��� ������ �ִ� �ڵ��̴�.
    ����ü�� ����� �� ������ ���� �ִµ� ����ü���� struct Ű���带 �ٿ����ϴ� ���̴�.
    ��Ȥ struct Ű���带 ������ ������
    error C2146: ���� ���� : ')'��(��) 'human' �ĺ��� �տ� �����ϴ�.
    error C2061: ���� ���� : �ĺ��� 'human'
    error C2059: ���� ���� : ';'
    error C2059: ���� ���� : ')'
    error C2449: ���� ������ '{'�� �ֽ��ϴ�. �Լ� ����� ���� �� �����ϴ�.
    error C2059: ���� ���� : '}'

    �̷��� ���� �׷��� �º��� �ȴ�.

    �׷��ٸ� �Ź� ������ struct HUMAN�̶�� �ۼ��ؾ��ұ�?
    
    ������ ����� �ִµ� �ٷ� typedef struct HUMAN Human; �̶�� ���̴�.
    ==> 2_typedef.c�� �ڵ� ������ ��

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