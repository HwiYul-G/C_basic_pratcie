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

	printf("�迭�� �� ���� : %d, %d, %d", arr[0], arr[1], arr[2]);

	printf("========");
	int arr1[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
	printf("�Է��� �迭 �� ���� ū �� : %d \n", max_number(arr1));

	return 0;
}

int add_number(int* parr) {
	/*
		arr�̶�� �迭�� ����Ű�� �����Ͱ� add_number�� ���ڷ� �;��Ѵ�.
		������ �迭�� ����Ű�� �����ʹ� int* ���̴�. 
		
		�׸��� arr�� �迭�� ���� �ּҰ��� ������ �ִ�. �� arr �� &arr[0]�� �����ϴ�.

		for�� ���θ� ���� parr[i]�� ���� parr�� ����Ű�� �迭�� i+1 ��° ���ҿ� ������ �� �ִ�.
		arr[1]�� �迭�� 2��° �����̹Ƿ� parr[i]++�� ���ؼ� �迭�� �� ���ҵ��� ũ�⸦ ��� 1�� ������Ų��.
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