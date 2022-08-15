/*
	== 변수의 생존 기간 ==
	앞에선 변수가 어떤 범위에서 접근 가능한지 이야기 했다.
	그렇다면 이번에는 정의한 변수가 얼마나 살아 있는지 이야기할 차례이다.

	일반적으로 정의된 변수들은 자신이 정의된 지역을 빠져나갈 때 파괴된다.
	자신이 정의된 위치를 포함하고 있는 {}를 벗어날 때 해당 변수가 사라지게 된다는 뜻이다.

*/
#include <stdio.h>

int* function() {
	int a = 2;
	return &a;
}

int main() {
	int* pa = function();
	printf("%d \n", *pa);	// [1]    30588 segmentation fault (core dumped) 
	/*
		.c: In function ‘function’:
		.c:줄번호: warning: function returns address of local variable [-Wreturn-local-addr]
		return &a;
				^~
		function이란 함수가 지역 변수의 주소값을 리턴한다고 경고했다.

		a라는 변수는 지역 변수이다.  따라서 a가 정의된 지역인 function을 빠져나가면 a는 소멸된다.
		즉 a는 사용할 수 없다.

		하지만 위의 예시처럼 int* pa = function(); 을 통해 a의 주소값을 리턴해서
		function 외부에서 a를 사용하려 한다면 어떨까?

		이 경우 pa는 이미 파괴딘 변수를 가리키고 있어서 문제된다.
		따라서 위 코드는 프로그램 실행시 오류를 발생하게 된다.

		그럼, 지역을 빠져나가도 파괴되지 않는 변수는 없을까? 라는 생각을 하게 된다.
		=> 이를 정적 변수(static variable)이라고 한다.


	*/
}