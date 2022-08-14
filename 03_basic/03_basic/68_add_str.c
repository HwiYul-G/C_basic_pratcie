#include<stdio.h>

int stradd(char* dest, char* src);

int main() {
	char str1[100] = "hello my name is ";
	char str2[] = "Psi";

	printf("합치기 이전 : %s \n", str1);

	stradd(str1, str2);

	printf("합친 이후 : %s \n", str1);

	return 0;
}

int stradd(char* dest, char* src) {
	// dest의 끝 부분을 찾는다.
	while (*dest) {
		dest++;
	}
	// while문 이후에 dest는 dest 문자열의 NULL문자를 가리킨다.
	// 이제 src의 문자열들을 dest의 NULL 문자가 있는 곳부터 복사한다.
	while (*src) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = NULL; // 마지막으로 dest에 NULL 추가 (왜냐하면 src에서 NULL이 추가되지 않았으므로)
	return 1; // 정상종료
}