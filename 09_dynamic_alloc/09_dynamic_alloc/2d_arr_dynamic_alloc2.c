#include <stdio.h>
#include <stdlib.h>

void get_average(int** arr, int numStudent, int numSubject);

int main(int argc, char** argv) {
    int i, j, input, sum = 0;
    int subject, students;
    int** arr;
    // �츮�� arr[subject][students] �迭�� ���� ���̴�.

    printf("���� �� : ");
    scanf("%d", &subject);

    printf("�л��� �� : ");
    scanf("%d", &students);

    arr = (int**)malloc(sizeof(int*) * subject);

    for (i = 0; i < subject; i++) {
        arr[i] = (int*)malloc(sizeof(int) * students);
    }

    for (i = 0; i < subject; i++) {
        printf("���� %d ���� --------- \n", i);

        for (j = 0; j < students; j++) {
            printf("�л� %d ���� �Է� : ", j);
            scanf("%d", &input);

            arr[i][j] = input;
        }
    }

    for (i = 0; i < subject; i++) {
        sum = 0;
        for (j = 0; j < students; j++) {
            sum += arr[i][j];
        }
        printf("���� %d ��� ���� : %d \n", i, sum / students);
    }

    for (i = 0; i < subject; i++) {
        free(arr[i]);
    }

    free(arr);

    return 0;
}

void get_average(int** arr, int numStudent, int numSubject) {
    int i, j, sum;

    for (i = 0; i < numSubject; i++) {
        sum = 0;
        for (j = 0; j < numStudent; j++) {
            sum += arr[i][j];
        }
        printf("���� %d ��� ���� : %d \n", i, sum / numStudent);
    }
    /*
        �Լ��� void ���̰� int** arr�� int numStudent, int numSubject�� ���ڷ� �ް� �ִ�.
        arr�� 2���� �迭ó�� �ൿ�Կ��� �Ұ��ϰ� ����� �ܼ��� ���Ұ� int*�� �迭�̱� ������
        (1���� �迭�� ��� �ܼ��� �迭 Ÿ�Կ� *�� ���̸� �ȴ�)
        ���� ���� int**arr�� ������ 2���� �迭ó�� ���� ������ ���� ������ ��� �ȴ�.
        (2���� �迭�� ��� int (*arr)[3]�� ���� ���� ���� ������ �־�� �Ѵ�.
    */
}