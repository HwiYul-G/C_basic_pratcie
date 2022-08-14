#include <stdio.h>

int compare(char* str1, char* str2);

int main() {
	char str[20] = "hello every1";
	char str2[20] = "hello everyone";
	char str3[20] = "hello every1 hi";
	char str4[20] = "hello every1";

	if (compare(str, str2)) {
		printf("%s 와 %s 는 같다 \n", str, str2);
	}
	else {
		printf("%s 와 %s 는 다르다 \n", str, str2);
	}

	if (compare(str, str3)) {
		printf("%s 와 %s 는 같다 \n", str, str3);
	}
	else {
		printf("%s 와 %s 는 다르다 \n", str, str3);
	}

	if (compare(str, str4)) {
		printf("%s 와 %s 는 같다 \n", str, str4);
	}
	else {
		printf("%s 와 %s 는 다르다 \n", str, str4);
	}

	return 0;
}

int compare(char* str1, char* str2) {
	/*
		만일 str1과 str2가 같다면 이 부분이 실행되고 아니면 지나간다.
		참고로 if문에서 0이 아닌 값이 들어가면 무조건 '참'으로 처리된다.
	*/
	while (*str1) {
		if (*str1 != *str2) {
			return 0; // 0은 false
		}
		str1++;
		str2++;
	}
	if (*str2 == '\0') return 1;
	return 0;	// str1의 내용 부분을 str2가 담고 있지만 더 긴 내용인 경우
}