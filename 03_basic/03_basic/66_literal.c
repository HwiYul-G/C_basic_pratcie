#include <stdio.h>

int main() {
	char str[] = "sentence";
	char* pstr = "sentence";

	printf("str : %s \n", str);
	printf("pstr : %s \n", pstr);
	/*
		char* pstr = "sentence";가 조금 이상하게 느껴진다.
		sentence는 문자열이고, 어떤 변수의 주소값이 아니다.
		pstr는 char형을 가리키는 포인터이므로 char형 변수의 주속밧이 들어가야한다.

		그런데 우리는 "sentence"를 특정한 주소값처럼 사용하고 있다.
		그런데, "sentence"라는 문자열은 주소값이 맞다.
		그렇다면 무엇의 주소값인가? 바로 "sentence"라는 문자열이 저장된 주소값(시작주소값)이다.

		믿기지 않는 다면
		printf("%d \n", "sentence");를 실행해보라.
	*/
	printf("%d \n", "sentence");
	// 정말로 특정한 수가 출력됨을 알 수 있다. 그렇다면 이 "sentence"는 도데체 무엇일까?

	char str2[] = "hello";
	char* pstr2 = "goodbye";

	str2[1] = 'a';
	pstr2[1] = 'a';
	/*
		위의 코드를 실행해보면 성공적으로 컴파일 했어도 실행 시 오류가 난다.
		
		우선 pstr2[1] = 'a';를 주석처리한 후 실행해보면 제대로 실행됨을 알 수 있다.
		즉 pstr2[1] = 'a';가 문제인 것이다.
		왜 문제가 발생한 것일까? 
		
		가장 위의 예제에서 pstr의 값을 읽기만 했을 때(printf함수는 값을 변경하지 않는다.)
		정상적으로 실행되었지만, 아래에서 pstr2[1] = 'a'; 를 통해 pstr2의 값을 변경하였을 때 오류가 출력된 것을 보아
		마치 상수처럼 컴퓨터에서 값을 변경하도록 허락하지 않는 것 같다.
	*/

	/*
		literal(리터럴)
		프로그래밍 언어에서 literal이란 소스 코드상에서 '고정된 값'을 가지는 것을 일컫는다.
		특히 C언어의 경우 큰 따옴표(")로 묶인 것들을 문자열 리터럴(string literal)이라고 부른다.

		char *pstr = "goodbye";
		printf("why so serious?");
		scanf("%c", str[0]);

		그렇다면 위의 3개의 문장에서 문자열 리터럴은 무엇인가?
		바로 goodbye, why so serious, %c 모두가 리터럴이다.

		컴퓨터는 이러한 리터럴들을 따로 모아서 보관한다. 
		즉 프로그램을 실행하면 메모리 상의 특별한 곳에 리터럴들이 쭈르륵 보관되어 있는 공간이 생긴다.

		따라서 char *pstr = "goodbye"를 실행하게 되면 
		컴퓨터는 "goodbye"의 시작 주소값을 가져와서 pstr에 대입 해라 라는 의미의 작업을 실행한다.
		따라서 pstr은 "goodbye"라는 리터럴을 가리키고 printf("%s", pstr)을 했을 때 goodbye를 성공적으로 출력할 수 있게 된다.

		그런데 아까 말했던 것처럼 리터럴의 조건은 "소스 코드 상에서 고정된 값을 가지는 것들"이다.
		즉 실제 프로그램 싫애 중에서도 리터럴의 값은 절대로 변경되서는 안된다는 것이다.

		아까도 말했듯이 만일 hello라는 리터럴의 값을 실수로 hi로 변경했다면 
		사용자는 분명히 str에 hello라는 값을 넣으라고 명령했지만 hi가 들어가게 되어 큰 문제를 야기할 수 있다.

		따라서 리터럴이 보관되는 곳은 '오직 읽기만 가능한 곳'이 된다. 
		만일 이 곳을 함부러 변경하려고 시도하면 바로 프로그램이 강제종료 된다.

		그렇기 때문에 우리는 char str[] = "hello";를 했다면 str에 hello가 들어가고
		printf("why so serious");를 했다면 화면에 why so serious가 출력될 것이라고 보장할 수 있다는 것이다.
		왜냐하면 이 모든 문자열들이 string literal이라는 이름 하에 메모리 상의 특별한 공간에서 보호받고 있기 때문이다.

		// == 추가 설명 ==
		프로그램이 실행되어서 메모리에 로드되면 5가지의 영역(text segment, data segment, bsssegment, heap, stac)이 존재한다.
		이때 text segment에 프로그램 코드와 상수, 리터럴 등이 정의된다.
		왜냐하면 text segment에 있는 내용들은 only read 이기 때문이다.
		물론 이 사실은 컴파일러 구현에 따라 os 환경에 따라 다를 수 있다.
		// ====

		char *pstr2 = "goodbye";
		pstr2[1] = 'a';
		다시 위의 코드를 보자.
		goodbye는 문자열 맅럴이므로 text segment 영역에 저장된다. 그리고 이 곳은 오직 읽김 가능하므로
		쓰기를 시도할 때 오류를 뿜게 된다.

		반면에 printf("pstr2 : %s \n, pstr2);로 오직 read만을 수행하는 작업은 잘 실행된다.

		그렇다면 아래 코드는 어떨까?
		char str[] = "hello";
		사실 위의 hello는 리터럴이라고 부르기 애매하다. 왜냐하면 배열의 정의는 컴파일러에 의해 아래와 같이 해석되기 때문이다.
		char str[] = {'h', 'e','l', 'l', 'o', '\0'};
		이는 그냥 str이라는 배열에 hello라는 문자열을 복사하게 될 뿐이다.
		그리고 위의 배열은 text segment가 아니라 stack이라는 메모리 수정이 가능한 영역에 정의된다.
		따라서 str 안의 문자열은 수정이 가능하다.

		!! 참고로 VS2017 이상에서는 literal을 char*가 가리킬 수 없다.
		반드시 const char*가 가리켜야하며 덕분에 리터럴을 수정하는 괴랄한 짓을 컴파일 단에서 막을 수 있다.
		


		
	*/

	return 0;
}