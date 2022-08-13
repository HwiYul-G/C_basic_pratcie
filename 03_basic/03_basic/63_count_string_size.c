// 프로그램을 하다보면 특정한 문자열에 들어가 있는 문자의 개수를 세는 일이 많다.
#include <stdio.h>

int str_length(char* str);
int main() {
	char str[] = "What is your name?";

	printf("이 문자열의 길이 : %d \n", str_length(str));

	return 0;
}
int str_length(char* str) {	// 인자가 char형을 가리키는 포인터형태이므로 char 배열을 취할 숭 ㅣㅆ다.
	int i = 0;
	while (str[i]) {// str[i]가 0이 될 때까지 == 즉 문자의 끝에 도달해 NULL문자가 되었을 때
		i++;
	}
	return i;
}