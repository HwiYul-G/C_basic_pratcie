/*
	pointer : 특정한 데이터의 메모리 상의 (시작) 주소값을 보관하는 변수

	const int a = 3; // int 변수 a를 상수로 정의
	const : 이 데이터의 내용은 절대로 바뀔 수 없다.
	=> int 변수 a의 값은 절대 바뀌면 안된다.

	그리고 const를 이용해 상수로 정의함으로써
	값이 변경될 가능성이 있는 문장조차 허용되지 않는다.
	=> 상수로 해놓는 것은 실수를 잡아주기 때문에 const 키워드를 붙여주는 습관을 길러야함.

	
*/

#include <stdio.h>

int main() {
	int a, b;
	const int* pa = &a;

	*pa = 3; // 올바르지 않은 문장
	pa = &b; // 올바른 문장

	// 위와 같이 실행하면 'l-value가 const 개체를 지정합니다.' 라는 오류가 뜬다.
	/*
		const int* pa = &a;
		위 문장을 보면, 저 포인터는 const int 형을 가리키는 포인터인데, 어떻게 int형 변수 a의 주소값이 대입될 수 있지? 할 수 있다.
		하지만, const라는 키워드는 "이 데이터의 '값'은 절대로 바뀌면 안된다." 라는 키워드이다.

		다시말해, const int a라는 변수는 int형 변수 a인데 값이 절대로 바뀌면 안되는 변수일뿐이다.
		따라서, const int a 변수도 그냥 int형이라 말할 수 있다. (다만 '변'수가 아닐 뿐)

		따라서 const int*의 의미는 const int형 변수를 가리킨다는 것이 아니다.
		int형 변수를 가리키는데 그 값을 절대로 바꾸지 말라는 의미이다.
		즉, pa는 어떠한 int형 변수를 가리키고 있다. 그런데 const가 붙었으므로 pa가 가리키는 변수의 값은 절대 바뀌면 안된다.

		여기서 pa가라는 부분을 강조한 이유는 a 자체는 변수 이므로 값이 자유롭게 변경될 수 있기 때문이다.
		하지만 pa를 통해서 a를 간접적으로 가리킬 땐
		컴퓨터가 "아 내가 const인 변수를 가리키고 있구나"로 생각하기 때문에 값을 바꿀 수 없게 된다.

		결과적으로 *pa = 3;은 오류를 출력하게 된다.
		물론 a = 3;은 오류를 출력하지 않는다. 변수 a 자체는 const가 아니기 때문이다.

		pa = &b; 는 옳은 문장이다.	
		(const int* pa) 는 int형 데이터를 담은 공간의 시작 주소값을 가리키는 pa가 가리키는 값을 바꾸면 안된다는 것이고, pa가 가리키는 주소값은 바꿔도 된다는 의미?

		왜 그런지 아래 예제와 비교하면서 이해해보자.

	*/

	int a2, b2;
	int* const pa2 = &a2;

	*pa2 = 3;	//올바른 문장
	pa = &b2; // 올바르지 않은 문장
	/*
		위의 예제도 l-value가 const 개체를 지정합니다. 라는 오류가 발생한다.

		int* const pa = &a;
		위의 문장을 보면 int*를 가리키는 pa라는 포인터를 정의했다.
		이번에는 const가 앞이 아니라 int*와 pa 사이에 놓여있다.
		const의 의미를 잘 생각해보면, 이는 pa의 값이 바뀌면 안된다는 것이다.

		그런데 포인터에는 가리키는 데이터의 주소값, 즉 위의 경우 a의 주소값이 pa에 저장된다.
		따라서 pa가 const라는 의미는 pa의 값이 절대로 바뀔 수 없다는 것이다.
		pa는 포인터가 가리키는 변수의 주소값이 들어있으므로 결과적으로 pa가 처음에 가리키는 것(a) 말고 다른 것은 건드릴 수 없다.

		하지만 pa가 가리키는 값을 바꾸면 안된다는 말을 하지 않았기 때문에 *pa = 3;은 올바른 문장이 된다.

	*/
	int a3, b3;
	const int* const pa3 = &a;
	*pa3 = 3; // 올바르지 않은 문장
	pa3 = &b3; // 올바르지 않은 문장

	/*
		f(const int a);
		main{
			int a =3;
			f(a);
		}

		위와 같은 방식으로 const int에 int형 데이터를 대입해줄 수 있다.

		const int *p;에서 포인터를 빼고보면 const int 타입이다.
		const int는 변경불가능하다. const int*는 const int를 참조하는 포인터이고 const int에 int를 넣을 숭 ㅣㅆ다.
		const int 타입은 const int a = 3;이라고 했으면 이후에 변경이 불가능하다.

		const int* p = &a;라고 하면 a는 int형이나 const int형이 될 수 있다.
		그걸(a를) p라는 const int에 대한 포인터로 참조한 거고 
		const int 포인터니 그걸 역참조하면 const int 타입이므로 *p =5; 이렇게 변경할 수 없다.

		역참조하지 않는 '값' 자체는 const int* p = &a;에서 p = &b;로 참조하는 변수를 바꿀 수는 있다.
		*p = 5;는 역참조를 했으니 const int 타입의 연산인거고
		*p = &b;는 포인터 자체에 대한 연산이다.
		
		const int*p // const int에 대한 포인터 (const int를 참조함)
		int* const p // int*에 대한 const 포인터 (그 주소가 바뀌면 안됨)
						-> const로 한정받고 있는 int*
		const int* const p // const int에 대한 const 포인터
						-
		
		
	*/
	return 0;
}