/*
	��¥ 2���� �迭 �Ҵ��ϱ�

	�ּ��ϰԵ� �� ����� VS���� �۵����� �ʴ´�.
	VS�� C �����Ϸ��� VLA�� �������� �ʱ� �����̴�.
	������ GCC�� Clang���� �����Ϸ����� ��밡���� ����̴�.

	����� VLA�� C99 ǥ�ؿ� ������, VS�� C �����Ϸ��� C90�� ����ϰ� �ִ�.

	====
	�ռ� ���Ҵ� ������� ��¥ 2���� �迭ó�� �޸𸮿� ���������� �����ϴ� �迭�� ���� �� ����.
	�ֳ��ϸ� 1���� �迭���� �޸��� ��� �Ҵ��ϸ鼭 �޸� �������⿡ ������ ������� ���̱� �����̴�.

	���� �޸𸮿� ���������� �����ϴ� ��¥ 2���� �迭�� ����� ���ؼ�
	�ݵ�� malloc�� ���� �ش� ũ���� ������ �Ҵ��ؾ� �Ѵ�.

	���� ��� int arr[height][width];�� ���� ���� �迭�� �Ҵ��Ѵٰ� ����.
	�� ��� �ʿ��� �޸��� ũ��� height*width*sizeof(int)�̴�.
	�̷��� �޸𸮸� �Ҵ�������, ���� �ش� �޸𸮸� 2���� �迭�̶�� �����ض�! ��� �����Ϸ����� �˷�����Ѵ�.
	���� �� ��� �ش� �޸� �ּҰ����� 2���� �迭�� ����Ű�� �����Ϳ� �����ϸ� �ȴ�.

	2���� �迭 �������� ��� ������ ������ �����ϱ� ���ؼ� �ݵ�� ������ Ÿ�� �ȿ� '�����'�� �����Ѵ�.
	���� �Ʒ��� ���� 2���� �迭 ������ arr�� ������ �� �ִ�.

	int (*arr)[width] = (int(*)[width])malloc(height * width * sizeof(int));
	arr�� �����Ϸ� ������� ���� ũ�Ⱑ width�� 2���� �迭�� ����Ű�� ����! ��� ������ �� �ִ�.
	�� ���� �����ؾ��� ���� arr�� ������ �� �ݵ�� width�� ���� �迭�� ���� ���� �� �� �����ؾ��Ѵ�.

	���� ��
	int width;
	int (*arr)[width] = (int (*) [width])malloc(height * width * sizeof(int);
	scanf("%d", &width);
	�� �ϰԵǸ� arr�� ����� 2���� �迭�� ������ �� ����. 
	
	int width;
	scanf("%d", &width);
	int (*arr)[width] = (int (*) [width])malloc(height * width * sizeof(int);
	�ݵ�� �̿� ���� width�� ���� 2���� �迭�� �� ���̰� �� �Ŀ� �迭 �����͸� �����ؾ��Ѵ�.

*/
#include <stdio.h>
#include <stdlib.h>

void print_array(int width, int(*arr)[width], int height);
int main() {
	int width, height;
	printf("�迭 �� ũ�� : ");
	scanf("%d", &width);
	printf("�迭 �� ũ�� : ");
	scanf("%d", &height);

	int(*arr)[width] = (int(*)[width])malloc(height * width * sizeof(int));
	for (int i = 0; i < height; i++) {
		for (int j = 0; i < width; j++) {
			int data;
			scanf("%d", &data);
			arr[i][j] = data;
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	free(arr); // arr�� ��� �����Ͱ� �޸𸮿� ���������� �־� free���� arr�� ���� �� �� ���� �����ϸ� �ȴ�.

	return 0;
}

void print_array(int(*arr)[width], int width, int height) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	/*
		������ ���� '�迭 ������'�� �ٸ� �Լ��� ���ڷ� �����ϰ� ���� ���̴�.
		�� �Լ�ó�� �� ��� �����Ϸ��� �迭�� ������ int (*arr)[width] �� ���� width�� ���� �� �� ����.
		�׷��� �Ʒ��� ���� ������ �߻��Ѵ�.
		error : 'width' undeclared here (not in a function)
			| void print_array(int (*arr)[width], int width, int height){

		
		�ذ�å�� �����ϴ�.
		�����Ϸ��� arr�� ���Ǹ� �� �� width�� ��ü�� �� �� �ֵ���
		, width�� arr�� ���� ������ ������ ������ �ٲ��ָ� �ȴ�.
		void print_array(int width, int(*arr)[width], int height); �̷� ������ �ϸ� �ȴ�.
	*/
}

void print_array(int width, int(*arr)[width], int height) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
