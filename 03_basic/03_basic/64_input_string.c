#include <stdio.h>

int main() {
	char words[30];	// null값을 제외하고 최대 29자까지 들어가는 배열 생성

	printf("30 자 이내의 문자열을 입력해주세요! : ");
	scanf("%s", words);	//입력받는 형식이 %s로 문자열을 입력받음, words라는 배열 이름 자체가 이미 배열을 가리키는 포인터 이므로 주소값을 전달하고 있다.
	// 여기서 what is your name을 입력하면

	printf("문자열 : %s \n", words);	// 출력이 what만 된다.

	/*
		scanf는 엔터가 나오면 입력을 종료하는데 왜 what부분만 입력이 되었을까?
		=> 이어서 학습!

	*/

	// 생각해보기 1
	const char* str = "abcdefghi"; // char c_str[] ={"abcdefghi"};가 아니여도 잘 된다.
	printf("%s", str); 
	/* char c_str[] = {}; 로 한것과 cosnt char* str = ""; 으로 한 것의 차이점은
		const char*은 개개별 문자가 상수값으로 지정되어 수정이 불가능하다.
	*/

	// 생각해보기2
	char str_a[] = "abc";
	char str_b[] = "abc";

	if (str_a == str_b) {
		/* 이 부분이 실행되지 않는다.*/
		printf("str_a와 str_b는 같다.");
	}
	/*
		위가 안되는 이유는 배열 자체를 호출하면 배열의 내부 값이 아닌 배열의 주소를 호출하는데
		str_a와 str_b가 위치한 메모리 주소가 다르기 때문이다.

		이를 해결하기 위해선 그 값을 비교해주어야한다.
		이를 위해 int isEqual(char*a, char*b)이란 함수를 정의해 주었다.
	*/


	return 0;
}

int isEqual(char* a, char* b) {
	while (*a || *b) { // 그 값이 NULL일 때까지
		if (*a++ != *b++) return 0;
	}
	return 1;
}