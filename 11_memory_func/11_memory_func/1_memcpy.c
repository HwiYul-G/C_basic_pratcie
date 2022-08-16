/*
	메모리에 관련된 C 표준 라이브러리에서 기본으로 지원되는 것들에 대해 앙라보자.
	일단 메모리를 직접적으로 가지고 논다고 말할 수 있는 함수들은
		memmove, memcpy, memcmp, memset 등이 있다.
	우리는 여기서 대표적인 3개의 함수인 memmove, memcpy, memcmp만 알아보자.

	이 함수들 모두 string.h에 정의되어 있다.
*/

#include<stdio.h>
#include<string.h>

int main() {
	char str[50] = "I love Chewing C hahaha";
	char str2[50];
	char str3[50];

	// strlen함수는 문자열 길이를 리턴해주는 함수로
	// strlen("abc");를 하면 3이 리턴된다. 이때 마지막의 NULL 문자는 세지 않으므로 + 1을 더한만큼 복사해야한다(NULL공간)
	memcpy(str2, str, strlen(str) + 1); // str로부터 strlen(str)+1만큼의 문자를 str2로 복사해라
	memcpy(str3, "hello", 6);

	printf("%s \n", str); // I love Chewing C hahaha 
	printf("%s \n", str2); // I love Chewing C hahaha 
	printf("%s \n", str3); // hello
	/*
		memcpy는 메모리의 특정한 부분으로부터 얼마까지의 부분을 다른 메모리 영역으로 복사해주는 함수이다.
		위와 같이 문자열을 복사하는데 사용될 수 있다.

		물론 문자열 복사를 전문적으로 하는 함수는 strcpy이다.
		하지만 위와 같이 memcpy를 사용하는 것도 나쁘지 않다.
	*/

	return 0;
}