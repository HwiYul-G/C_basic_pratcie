/*
	현재까지 모든 소스 코드를 하나의 소스 파일에서 작성했다.
	사실 현재까지 한 프로그램의 총 소스 길이는 그다지 길지 않았고 혼자 만들기 때문에
	하나의 파일에 모조리 작성해도 상관 없었다.

	하지만 프로그래머가 되어서 회사에서 프로그래밍을 한다면,
	소스의 길이도 수천~수만줄에 이르고
	여러 사람들이 만들기 때문에 파일을 여러 개로 나누어야 할 필요성이 있다.

	물론 파일을 나눌 때엔 비슷한 작업을 하는 것 끼리 나누는 것이 좋다.
*/
#include <stdio.h>
char compare(char* str1, char* str2);
int main() {
	char str1[20];
	char str2[20];

	scanf("%s", str1);
	scanf("%s", str2);

	if (compare(str1, str2)) {
		printf("%s 와 %s 는 같은 문장 입니다. \n", str1, str2);
	}
	else {
		printf("%s 와 %s 는 다른 문장 입니다. \n", str1, str2);
	}
	/*
		if(compare(str1, str2)){}
		이 부분을 보면 compare()는 두 문자열이 같으면 1, 다르면 0을 리턴하는 함수이다.
		그런데 if문의 경우 괄호 안의 값이 0이면 거짓 그 외이면 참으로 판단하므로
		우리가 원하는 결과를 얻을 수 있던 것이다.

		그렇다면 이번엔 이 파일을 강좌의 주제에 맞게 분할해보자.
		compare 함수는 상당히 다른 일을하고 있어서 굳이 main과 같은 파일에 둘 필요가 없다.
	*/
	return 0;
}

char compare(char* str1, char* str2) {
	while (*str1) {
		if (*str1 != *str2) {
			return 0;
		}

		str1++;
		str2++;
	}

	if (*str2 == '\0') return 1;

	return 0;
}