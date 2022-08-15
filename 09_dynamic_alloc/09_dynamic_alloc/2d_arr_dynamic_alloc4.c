#include <stdio.h>
#include <stdlib.h>

void add_one(int width, int(*arr)[width], int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            arr[i][j]++;
        }
    }
}

void print_array(int width, int(*arr)[width], int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int width, height;
    printf("배열 행 크기 : ");
    scanf("%d", &width);
    printf("배열 열 크기 : ");
    scanf("%d", &height);

    int(*arr)[width] = (int(*)[width])malloc(height * width * sizeof(int));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int data;
            scanf("%d", &data);
            arr[i][j] = data;
        }
    }

    printf("----- Array ----- \n");
    print_array(width, arr, height);
    printf("----- Add one ----- \n");
    add_one(width, arr, height);
    print_array(width, arr, height);

    free(arr);
}
/*
    만일 컴파일 오류가 발생한다면 C 컴파일러로 컴파일 되는지 확인해봐야한다.
    VS의 경우 파일확장자를 .c로 지정해야 하고
    GCC를 사용하는 분들은 g++이 아니라 gcc로 컴파일해야 한다.
*/