#include <stdio.h>

// 열의 개수가 2인 2차원 배열과 총 행의 수를 인자로 받는다.
// int (*arr)[2]라는 표현법은 인자를 받는 것이 어렵게 느껴질 수 있다.
// 그래서 "오직" 함수의 인자인 경우에만 int arr[][2] 이러한 형태로 인자를 표현할 수 있다.
// 이는 오직 함수의 인자만 적용되는 것이므로 int parr[][3] = arr; 이렇게 하면 오류가 난다.
// 그 이유는 컴퓨터는 parr을 열의 개수가 3개이고 행의 개수는 정해지지 않으 배열이라 생각했기 때문이다.
// 행의 개수를 생략했다면 배열 정의시 초기화도 해주어야하는데 위의 경우는 그러지 않으므로
int add1_element(int(*arr)[2], int row);

// 응용력을 이용해서 다차원 배열의 인자도 정의할 수 있다.
int multi(int* (arr)[3][2][5]);

int main() {
	int arr[3][2];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	add1_element(arr, 3);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("arr[%d][%d] : %d \n", i, j, arr[i][j]);
		}
	}

	return 0;
}

int add1_element(int(*arr)[2], int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 2; j++) {
			arr[i][j]++;
		}
	}
	return 0;
}
// (int arr[][3][2][5]) 로 할 수 있다.
int multi(int* (arr)[3][2][5]) {
	arr[1][1][1][1] = 1;
	return 0;
}