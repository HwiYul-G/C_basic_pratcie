/*
	�ڱ� �ڽ��� ȣ���ϴ� �Լ��� �̿��ؼ�
	1 ���� Ư���� �������� ���� ���ϴ� ���α׷��� ��������. (���̵� : ��)
*/
#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>

int recursive_multiply(int n);

int main() {
	int n;
	printf("1���� n���� ���� ���մϴ�. n�� ���� ? : ");
	scanf("%d", &n);

	int result = recursive_multiply(n);
	printf("��� : %d", result);
	return 0;
}

int recursive_multiply(int n) {
	if (n == 1) return 1;
	return n * recursive_multiply(n - 1);
}