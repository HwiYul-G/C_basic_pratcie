/*
	ifdef와 endif는 무언가 if문과 관련있다.
	if문처럼 특정한 조건에만 수행된다.
*/
#include <stdio.h>
#define A	// 이 부분이 A이면 ifdef A 부분이 실행되고, B이면 ifdef B부분이 실행된다.
// #define B // #define A와 B를 둘다 정의하면 두 부분이 모두 포함된다.
int main() {
#ifdef A
	printf("AAAA \n");
#endif
#ifdef B
	printf("BBBB \n");
#endif
	return 0;
}
/*
	#ifdef (매크로이름)
		매크로이름이 정의되어 있다면 이 부분이 코드에 포함되고
		그렇지 않다면 이 부분이 코드에 포함되지 않는다.
	#endif

	ifdef는 endif와 짝을 지어서 사용한다.
	ifdef에서 지정한 매크로가 정의되어 있었다면 
	ifdef와 endif 속에 있는 코드가 포함되고 
	그렇지 않다면 코드에 포함되지 않는 것으로 간주된다.

	이와 같은 기능을 도대체 왜 만들었을까?
	이러한 '조건부 컴파일(특정한 조건에 따라 컴파일 되는 부분이 다른 것)'은 상당히 유용하게 쓰인다.

	예를 들어 계산기 프로그램을 만드는데,
	계산기 모델마다 조금씩 메모리와 CPU가 틀려서 어떤 계산기에는 double을 사용할 수 있지만 어떤 모델에선 float만 사용할 수 있다고 하자.

	그렇다면 각각 이 계산기를 위해 다음과 같이 소스를 짜야할 것이다.

	// 계산기 1을 위한 코드 caculator1.c
	float var1, var2;
	// do sth

	// 계산기 2를 위한 코드 calculator2.c
	double var1, var2;
	// do sth

	하지만 조건부 컴파일을 이용하면 이 2개의 파일로 나눠서 했던 작업을 다음과 같이 줄일 수 있다
	#define CACULATOR_MODEL_1

	#ifdef CALCULATOR_MODEL_1
	float var1, var2;
	#endif

	#ifdef CALCULATOR_MODEL_2
	double var1, var2;
	#endif;// do something

	위의 경우 define 되는 것이 무엇이냐에 따라 간단히 무엇을 컴파일 할 것인지 나타낼 수 있다.
	사실 ifdef와 endif가 사용되는 경우는 이것보다 훨씬 많다.
	
	위 조건부 컴파일에서 #else라는 것도 사용할 수 있는데 
		#ifdef의 경우 이외의 나머지 것들을 처리하는 것이다.
	이 역시 #endif로 항상 끝을 맺어 주어야 한다.

	#ifdef CALC_1
	// do sth
	#else
	// do sth else
	#endif

	#ifdef의 친구로 #ifndef도 있는데 이는 '매크로가 정의되어 있지 않다면' 참이 된다.
	#ifdef의 정반대이다.

	헤더파일이 2번 중복되서 include 되지 않기 위해선 헤더파일에 아래와 같은 조건문을 넣는다.
	#ifndef A
	// 함수의 원형, 구조체 등등 선언
	#defineA
	#endif

	혹은
	#define B
	#ifdefA
	#endif
	#ifdef B
	//함수의 원형, 구조체 등등 선언
	#define A
	#endif
*/