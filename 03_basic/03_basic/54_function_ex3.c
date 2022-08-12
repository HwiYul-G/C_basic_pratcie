/*
	자기 자신을 호출하는 함수를 이용해서
	1 부터 특정한 수까지의 곱을 구하는 프로그램을 만들어보세요. (난이도 : 下)
*/
#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>

int recursive_multiply(int n);

int main() {
	int n;
	printf("1부터 n까지 수를 곱합니다. n의 값은 ? : ");
	scanf("%d", &n);

	int result = recursive_multiply(n);
	printf("결과 : %d", result);
	return 0;
}

int recursive_multiply(int n) {
	if (n == 1) return 1;
	return n * recursive_multiply(n - 1);
}