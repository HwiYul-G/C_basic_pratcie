/*

*/
#include <stdio.h>

int add_number(int* parr);
int max_number(int* parr);
int main() {
	int arr[3];

	for (int i = 0; i < 3; i++) {
		scanf("%d", &arr[i]);
	}

	add_number(arr);

	printf("배열의 각 원소 : %d, %d, %d", arr[0], arr[1], arr[2]);

	printf("========");
	int arr1[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
	printf("입력한 배열 중 가장 큰 수 : %d \n", max_number(arr1));

	return 0;
}

int add_number(int* parr) {
	/*
		arr이라는 배열을 가리키는 포인터가 add_number의 인자로 와야한다.
		일차원 배열을 가리키는 포인터는 int* 형이다. 
		
		그리고 arr은 배열의 시작 주소값을 가지고 있다. 즉 arr 과 &arr[0]는 동일하다.

		for문 내부를 보면 parr[i]를 통해 parr이 가리키는 배열의 i+1 번째 원소에 접근할 수 있다.
		arr[1]이 배열의 2번째 원소이므로 parr[i]++을 통해서 배열의 각 원소들의 크기를 모두 1씩 증가시킨다.
	*/
	for (int i = 0; i < 3; i++) {
		parr[i]++;
	}
	return 0;
}

int max_number(int* parr) {
	int max = parr[0];

	for (int i = 0; i < 10; i++) {
		if (parr[i] > max) {
			max = parr[i];
		}
	}

	return max;
}