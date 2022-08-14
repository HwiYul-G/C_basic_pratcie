/*
	int형 변수의 경우
	int i, j = 0;
	i = j + 3;
	처럼 값을 더하는 것이 가능하다.

	하지만 문자열의 경우
	char str1[] = {"abc"};
	char str2[] = {"def"};
	str1 += str2;
	이라고 해서 str1이 "abcdef"가 되는 것은 아니다
	str1 + str2는 각 배열의 주소값을 더하는 것인데, 
	이전에 말했듯 배열의 이름은 포인터 상수이므로 대입연산 수행시 오류가 난다.
	// 상수 포인터 : const int* ptr1 = &data1; -> 상수를 가리키는 포인터, 포인터가 가리키고 있는 값이 상수로 그 값을 바꾸지 못한다.
	// 포인터 상수 : int* const ptr2 = &data2; -> 포인터 주소가 상수

	뿐만 아니라 문자열을 비교하는 것도 불가능 하다.
	if(str1 == str2) 불가능!
	왜냐하면 위 문장의 의미는 
	"str1의 문자열이 들어있는 메모리 상의 (시작)주소와 str2의 문자열이 들어가 있는 메모리상의 (시작)주소 값을 비교해라" 라는 의미이기 때문이다.
	따라서 우리가 원하는 방식으로 수행되지 않는다.

	물론 if(str1 == "abc")와 같은 문장도 제대로 수행되지 않는다.
	"abc"는 literal이다. 즉 str1과 "abc"를 비교한다는 것은 
	str1이 저장된 메모리 상의 주소값과 abc라는 string literal이 보관된 메모리 상의 주소값을 비교하는 문장이기 때문에
	저대로 우리가 원하는 str1의 문자열과 abc를 비교한다라는 뜻을 가질 수 없다.

	가장 짜증나는 문제는 문자열을 원하는 대로도 복사 못한다는 것이다.
	즉 int형 변수처럼 원하는 값을 "대입"할 수 없다.

	만일 우리가 str1 = str2; 라는 문장을 작성한다면
	str1에 str2의 값을 대입해라 라는 문장이 되는데 역시 str1의 값은 바뀔 수 없는 포인터 상수이므로 오류가 발생한다.
	아무튼 문자열을 다루는 데는 제약이 너무 많다.

	하지만 다행히 함수를 사용해서 그나마 편리하게 다룰 수 있다.

	일단 위에서 지적한 내용을 바탕으로 문자열을 자유롭게 다루려면 아래와 같은 함수들이 필요하다
	1) 문자열 내의 총 문자의 수를 세는 함수
	2) 문자열을 복사하는 함수
	3) 문자열을 합치는 함수 (더하는)
	4) 문자열을 비교하는 함수

	1)의 경우 이전에 한 적이 있는데 다시 작성하면 아래와 같다.

	int str_length(char* pstr){
		int i = 0;
		while(pstr++){
			i++;
		}
		return i;
	}

	2) 문자열을 복사하는 함수
	우리는 어떤 함수를 만들기 전에 반드시 고려해야 하는 사항들이 있따.
	 (1) 이 함수는 무슨 작업을 하는가? (자세할 수록 좋다)
	 (2) 함수의 리턴형이 무엇이면 좋을까?
	 (3) 함수의 인자로는 무엇을 받아야 하는가?

	특히 (1)의 경우 상당히 중요하다.
	무슨 함수를 만들어야 겠다라고 정하지 않고 무턱대고 함수를 만들다 보면 소스코드가 난잡해지고 이해하기 어려워진다.

	현재의 경우 우리는 말그대로 (1)문자열을 복사하는 함수 즉 a라는 문자열이 있으면 그 모든 내용을 b로 복사하는 함수이다.
	
	두번째로 함수의 리턴형을 생각해보자. 문자열을 복사하는 함수에 무슨 리턴형이 필요하냐고 물을 수 있는데
	(2) 복사가 성공적으로 이루어졌다면 1을 리턴하도록 한다. (즉 int형 함수)
	
	세 번째로 함수의 인자로 무엇을 받을 지 생각해보자.
	당연히 2 개의 문자열을 받아야하므로 포인터를 사용해야한다.
	(3) 이 때 문자열들은 char형 배열이므로 char*을 인자 2개로 가지는 함수를 만들자.

*/
#include <stdio.h>

int copy_str(char* dest, char* src);
int main() {
	char str1[] = "hello";
	char str2[] = "hi";

	printf("복사 이전 : %s \n", str1);

	copy_str(str1, str2);

	printf("복사 이후 : %s \n ", str1);

	return 0;
}

// src의 문자열을 dest로 복사한다. 단 dest의 크기가 src보다 커야한다.
int copy_str(char* dest, char* src) {
	// 문자열의 끝 값이 Null이므로 끝에 도달할 때까지 while이 계속 돌게 된다.
	while (*src) {
		*dest = *src; // src의 문자를 dest에 대입
		// src와 dest를 각각 1씩 증가
		// 포인터에 1을 더하면 단순히 주속밧이 1이 들어가는 것이아니라 
		// 포인터가 가리키는 타입의 크기를 곱한 만큼 증가한다.
		// 다시말해 배열의 그 다음 원소를 가리킬 수 있다.
		dest++;
		src++;
	}
	*dest = '\0';
	return 1;
}
// 하지만 위의 함수는 위험한 편이다.
// 왜냐하면 dest의 크기가 src의 크기보다 큰지 작은지 검사하지 않기 때문이다.
// 만일 dest의 크기가 src보다 작다면 메모리의 허락되지 않는 공간가지 침범하므로 큰 문제를 야기할 수 있다.

/*
	굳이 문자열을 복사하는 함수를 만들어야 되나? 라고 생각할 수도 있다.
	그래서 대안으로 아래와 같은 코드를 작성했다고 하자.
	char str[100];
	str = "abcdefg"; 
	그러나 이 방법으로 컴파일을 하게 되면 error C2106: '=' : 왼쪽 피연산자는 l-value여야 합니다.
	라는 오류를 만나게 된다.

	왜 그런 것일까? 아마 리터럴과 배열을 제대로 이해한 사람이라면 쉽게 답할 수 있을 것이다.
	str = "abcdefg"; 라는 문장은
	'str에 문자열 리터럴 abcdefg가 위치한 곳의 주소값을 넣어라'라는 뜻이다.
	그런데 우리가 이전에 배열에 대해 공부한 바로 배열 이름은 '상수'이다.
	즉 배열의 주소값을 바꿀 수 없다.
	// int* const p = &a;
	// p = &b; // error
	// *p = 10; // ok
	// 포인터 상수는 포인터가 가리키는 데이터 값은 변경할 순 있지만 주소를 수정할 순없다.
	array도 마찬가지로 array 자체의 값은 수정할 수 있지만 array 

	따라서 위의 코드는 상수에 값을 대입하는 의미라서 오류가 발생한다.
	
	그런데 char str[100] = "abcdefg";는 왜 말이 될까?
	이는 단순히 C언어에서 편의를 위헤 제공하는 방법이다. 오직 배열 '정의'시에만 사용할 수 있는 방법니다.
*/