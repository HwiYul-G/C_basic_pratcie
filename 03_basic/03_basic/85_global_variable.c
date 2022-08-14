#include <stdio.h>

// 전역 변수(global variable) : 어떤 지역에도 속해있지 않은 변수
// 전역 변수는 위의 지역 변수와는 달리 코드 어느 곳에서도 접근할 수 있다.
int global = 0;

int function() {
	global++;
	return 0;
}

int how_many_called = 0;
int function2() {
	how_many_called++;
	printf("function 2 called : %d \n", how_many_called);
	/*
		위 프로그램에서는 function2라는 변수가 몇번 호출 되는 지 알려준다.
		how_many_called 이라는 변수는 function2 함수를 몇 번이나 호출 했는 지 카운트 해준다.
		how_many_called를 지역변수로 만들었다면 함수 종료 후 파괴도므로 정보를 보관할 수 없다.
	*/
	return 0;
}
int how_many_called2 = 0;
int function3() {
	how_many_called2++;
	printf("function 3 called : %d \n", how_many_called2);
	return 0;
}
/*
	또 다른 함수 function3의 호출 회수도 세는 변수를 지정했다.
	전역 변수는 모든 함수에서 접근할 수 있기때문에
	이를 위해 다른 변수 how_many_called2를 도입하게 되었다.

	그렇다면 이렇게 10개의 함수에 대해 각각 호출 회수를 세기 위해서는 아마도 10개의 전역 변수가 필요하게 된다.

	이는 심각한 문제일 수 있다.
	전역 변수는 모든 함수에서 접근할 수 있기 때문에 전역 변수를 사용할 때엔 매우 주의를 기울여라 한다.
	심지어 위처럼 전역 변수를 수십 개 선언하다 보면 필연적으로 문제가 생기게 된다.

	=> 많은 수의 전역 변수를 선언하지 않는 것을 권장한다.
*/

int main() {
	printf("%d \n", global);
	global = 10;
	function();
	printf("%d \n", global);

	// ======= 함수 호출 횟수 세기 =======
	function2();
	function2();
	function2();
	function2();
	return 0;
}
/*
	지역 변수의 겨우 함수가 종료될 때 파괴되었는데,
	전역 변수의 경우 프로그램이 시작할 때 만들어 졌다가 프로그램이 종료될 때 파괴된다.

	전역 변수는 지역 변수와 달리 메모리의 data segment(데이터 영역)에 할당된다.

	한 가지 재미있는 것은 모든 전역 변수들은 정의 시
		자동으로 0으로 초기화 된다.

	만일 global이 지역 변수 같았더라면 
		일단 컴파일 시에 global 변수가 초기화되지 않고 사용되었다라는 경고를 냈을 것이다.
	하지만 컴파일러는 전역 변수는 따로 초기화를 하지 않는다면 디폴트로 0으로 초기화 한다.
*/