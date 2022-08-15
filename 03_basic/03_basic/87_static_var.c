#include <stdio.h>

int* function() {
	/*
		정적 변수 선언시 static 키워드를 붙이면 된다.
		그리고 해당 변수(정적 변수)는 선언된 범위를 벗어나더라도 절대 파괴되지 않는다.
	*/
	static int a = 2;
	return &a;
}

int func1() {
	static int how_many_called = 0;
	how_many_called++;
	printf("func1 called : %d \n", how_many_called);
	return 0;
}
int func2() {
	static int how_many_called = 0;
	how_many_called++;
	printf("func2 called : %d \n", how_many_called);
	return 0;
}


int main() {
	int* pa = function();
	printf("%d \n", *pa);
	/*
		static 변수 (정적 변수)는 선언된 범위를 벗어나도 절대 파괴되지 않는다.
		따라서 a가 정의된 지역 밖에서 int*pa = function();을 통해 접근해도
		a는 소멸되지 않았기 때문에 2라는 값이 잘 출력된다.

		그런데 의문이 생긴다.
		function을 여러번 호출하면 a가 여러번 2로 초기화 되냐고 물을 수 있다.
		하지만 a는 딱 한번만 초기화 된다.

		즉 static int a = 2;라는 문장은 딱 한 번 실행되며, 
		더 놀라운 점은 function을 실행하지 않더라도 
		a라는 정적 변수는 이미 정의되어 있는 상태이다.

		따라서 이와 같은 정적 변수를 사용하면 해당 함수가 몇 번 호출되었는 지도 쉽게 추적할 수 있다.
	*/
	func1();
	func2();
	func1();
	func2();
	func2();
	func2();
	func1();
	func1();
	func2();
	/*
		참고로 정적 변수의 경우 'global 변수'(전역 변수) 처럼 데이터 영역에 저장되고 프로그램이 종료될 때 파괴된다.
		또한 전역 변수처럼 정적 변수도 정의 시 특별한 값을 지정해 주지 않는 한 0으로 자동 초기화 된다.
	*/
	return 0;
}