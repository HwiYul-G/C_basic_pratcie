// for�� (statement)
#include <stdio.h>

/*
    for(�ʱ��; ���ǽ�; ������){}
    - �ʱ�� : ������� �ʱ�ȭ �� (������� �ݺ����� �󸶳� �ݺ������� �˱� ���� �� ����)
    - ���ǽ� : ������ true �� ���� ���� ������
    - ������ : i++, i-=2 ��


*/

int main() {
    int i;
    for (i = 0; i < 20; i++) {
        printf("���� : %d \n", i);
    }

    int sum = 0;
    for (i = 0; i < 20; ++i) {
        sum += i;
    }
    printf("1���� 19������ �� : %d \n", sum);

    sum = 0;
    for (i = 0; i <= 10000; ++i) {
        sum += i;
    }
    printf("1���� 10000������ �� : %d \n", sum);

    int subject, score;
    double sum_score = 0;

    printf("�� ���� ���� ������ �Է¹��� ���ΰ���?");
    scanf("%d", &subject);

    printf("\n �� ������ ������ �Է��� �ּ��� \n");
    for (i = 0; i <= subject; i++) {
        printf("���� %d : ", i);
        scanf("%d", &score);
        sum_score += score;
    }
    printf("��ü ������ ����� : %.2f \n", sum_score / subject);


    return 0;
}