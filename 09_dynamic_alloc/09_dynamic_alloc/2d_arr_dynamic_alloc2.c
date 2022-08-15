#include <stdio.h>
#include <stdlib.h>

void get_average(int** arr, int numStudent, int numSubject);

int main(int argc, char** argv) {
    int i, j, input, sum = 0;
    int subject, students;
    int** arr;
    // 우리는 arr[subject][students] 배열을 만들 것이다.

    printf("과목 수 : ");
    scanf("%d", &subject);

    printf("학생의 수 : ");
    scanf("%d", &students);

    arr = (int**)malloc(sizeof(int*) * subject);

    for (i = 0; i < subject; i++) {
        arr[i] = (int*)malloc(sizeof(int) * students);
    }

    for (i = 0; i < subject; i++) {
        printf("과목 %d 점수 --------- \n", i);

        for (j = 0; j < students; j++) {
            printf("학생 %d 점수 입력 : ", j);
            scanf("%d", &input);

            arr[i][j] = input;
        }
    }

    for (i = 0; i < subject; i++) {
        sum = 0;
        for (j = 0; j < students; j++) {
            sum += arr[i][j];
        }
        printf("과목 %d 평균 점수 : %d \n", i, sum / students);
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
        printf("과목 %d 평균 점수 : %d \n", i, sum / numStudent);
    }
    /*
        함수는 void 형이고 int** arr과 int numStudent, int numSubject를 인자로 받고 있다.
        arr은 2차원 배열처럼 행동함에도 불고하고 사실은 단순히 원소가 int*인 배열이기 때문에
        (1차원 배열의 경우 단순히 배열 타입에 *만 붙이면 된다)
        위와 같이 int**arr로 기존의 2차원 배열처럼 열의 개수에 대한 정보가 없어도 된다.
        (2차원 배열의 경우 int (*arr)[3]과 같이 열에 대한 정보가 있어야 한다.
    */
}