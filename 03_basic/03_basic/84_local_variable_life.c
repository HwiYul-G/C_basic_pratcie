#include <stdio.h>

void function() {
	int a = 2;
}

int main() {
	int a = 3;
	function();
	/*
		분명히 function에서 a에 2를 대입했음에도
		main 함수에서는 이전의 a의 값인 3이 나왔다.
		이런 결과가 나온 이유는 어떠한 함수 내에서 일반적으로 정의된 변수는
			해당 함수 내에서만 접근할 수 있기 때문입니다.

		이렇게 해당 지역에서만 접근할 수 있다고 해서
		위와 같은 변수들을 '지역 변수'라고 한다.

		즉 main 함수 안의 a와 function 안 a는 컴파일러가 보기에도 다른 변수로 취급된다.
	*/
	printf("a = %d \n", a);
	
	//===========================
	int b = 3;
	{
		int b = 4;
		printf("b = %d \n", b);
	}
	printf("b = %d \n", b);
	/*
		중괄호 {}는 하나의 지역으로 취급된다.
		해당 지역에서 정의된 변수는 바깥 지역에서 정의된 같은 이름의 변수를 가리게 된다.
		예를 들어 4로 초기화된 b는 바깥의 3으로 초기화 된 b를 완전히 가리게 된다.

		따라서 printf에는 4가 출력되고, 바깥의 printf에는 3이 출력된다.
		위의 두 b는 아예 다른 변수로 취급된다.

		또한 바깥 지역에서 안쪽 지역에 정의된 변수를 사용할 수 없다.

		예를 들어서
		int main(){
			{int b = 4;}
			printf("b = %d \n", b);
		}

		이를 수행하면 컴파일 오류가 발생한다.
		error : 'b' undeclared (first use in this function)
		note : each undeclared identifier is reported only once for each function it appears in

		왜냐하면 b는 printf가 살고 있는 지역보다 안쪽에서 정의된 녀석이므로 바깥에서 볼 수 없다.
	*/
	return 0;
}