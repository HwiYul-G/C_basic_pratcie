/*
	구조체 포인터
	
	struct test 역시 하나의 형(타입)이다.
	즉 구조체는 한 개의 타입을 창조하는 것과 마찬가지이다. 마치 int나 char처럼
	그런데 이러한 타입을 가리킬 때 우리가 포인터를 어떻게 사용했나?
	바로 int*, char* 등으로 사용했다.
	구조체도 마찬가지이다.
	struct test* ptr을 사용하면 된다.
	이는 struct test형을 가리키는 포인터 ptr이라는 것을 의미한다.
	여기서 주의할 점은 ptr은 구조체가 아니다!
	ptr역시 다른 모든 포인터처럼 (컴퓨터마다 다르지만) 8byte공간을 차지한다.
	64bit 시스템이 대부분이기 때문에 8byte를 차지하는 것이다.
*/
#include <stdio.h>

struct test {
	int a, b;
};

int main() {
	struct test st;
	struct test* ptr;

	ptr = &st;

	(*ptr).a = 1;
	(*ptr).b = 2;

	printf("st 의 a 멤버 : %d \n", st.a);
	printf("st 의 b 멤버 : %d \n", st.b);
/*
	struct test* ptr;이 앞서 말한 것처럼
	struct test란 타입을 가리키는 포인터 ptr이다.

	따라서 ptr에 str의 주소값인 &str을 집어넣을 수 있다.

	그런데 아까는 구조체가 단순히 원소의 크기가 제각각인 배열이라고 했었다.
	그러면 구조체도 배열처럼 변수의 이름이 주소값이 되어야 하는 거 아닌가?
	다시 말해 우리가 int arr[100];을 정의했다면 이를 가리키는 포인터를 정의할 때
	int *ptr = arr;이라고 하지 int *ptr = &arr;이라 하지 않는다.

	상당히 좋은 의문이다.
	하지만 조금 아래에서 보면 구조체 변수의 이름은 역할이 살짝 다르다는 것을 알게 된다.
	그냥 보통 변수처럼(그래서 구조체 배열이라 부르지 않고 구조체 '변수'라고 부른다.)
	&를 붙여 구조체가 정의된 메모리의 주소값을 얻어온다고 생각하면 된다.

	이제 ptr은 test 구조체 st를 가리키는 포인터가 된다.

	그럼 이 ptr이 가리키는 구조체의 멤버의 값을 변경하는 부분을 보자.
	(*ptr)이 st와 동일하다는 것을 알 수 있다. 왜냐하면 ptr이 st를 가리키고 있기 때문이다.
	따라서 (*ptr).a = 1은 st.a = 1과 완전히 동힐하다. 그 아래 줄도 마찬가지이다.

	그런데 왜 굳이 괄호를 쳐 주어야 할까? 그냥 *ptr.a = 1; 이라고 하면 안될까?
	*ptr.a = 1;로 컴파일을 하면 아래와 같은 오류가 난다.
	error C2231: '.a' : 왼쪽 피연산자가 'struct'을(를) 가리킵니다. '->'를 사용하십시오.
	error C2100: 간접 참조가 잘못되었습니다.

	연산자 우선 순위표를 살펴보면
	가장 최 우선순위에 .이라는 구조체의 멤버를 지칭할 때 사용하는 .이 있다.
	이 .이 *(포인터)의 *보다 우선순위가 높다.
	따라서 *ptr.a를 사용하게 되면 ptr.a를 실행한 후 그 값에 *를 한것에 2가 들어가게 된다.
	즉 *ptr.a = *(ptr.a)와 동일한 문장이다. 그런데 위에도 말했듯 ptr은 단순히 포인터이다.
	ptr은 절대로 구조체가 아니다. 그런데 구조체가 아닌 것의 있지도 않은 a라는 멤버에 접근하니 컴파일 시 오류가 발생하는 것이다.

	결과적으로 구조체 포인터를 사용해서 멤버에 접근하려면 (*ptr).a와 같이 언제나 괄호로 감싸주어야한다.
	이는 상당히 귀찮은일이다. 따라서 C프로그래머들은 이 문제를 해결하기 위해 ->이라는 기호를 등장시켰다.

*/

	struct test st2;
	struct test* ptr2;
	ptr2 = &st2;
	ptr2->a = 1;
	ptr2->b = 2;
	printf("st 의 a 멤버 : %d \n", st.a);
	printf("st 의 b 멤버 : %d \n", st.b);
	/*
		(*ptr).a = 1이라는 문장을 ptr -> a = 1;로 간단히 표현할 수 있다.
	*/
	
	/*
		생각해보기1.
		구조체 안에 또다른 구조체 변수를 정의할 수 있을까?
		struct out_struct{
			int a;
			struct in_struct{
				int b;
			} is;
		};

		int main(){
			struct out_struct out;
			out.a = 1;
			out.is.b = 2;

			printf("out_struct의 멤버 a : %d \n", out.a);
			printf("out_struct의 멤버인 in_struct의 멤버 b : %d \n", in.b);
		}
	*/
	/*
		생각해보기 2. 구조체를 인자로 가지는 함수 생각해보기
	*/

	return 0;
}
