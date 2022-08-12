/*
	함수포인터..
	함수가 메모리 상에 있다는 것인가? 그렇다.
	프로그램 코드 자체가 메모리 상에 존재한다. 우리는 이전에 컴파일러가 하는 작업이 우리가 '인간에게 친숙한 언어'로 쓰여진 프로그램 코드를 '컴퓨터에게 친숙한 언어'
	즉 수 데이터들로 바꿔주어 실행 파일을 생성한다고 배웠다. 이렇게 바뀐 실행 파일을 실해앟게 되면 프로그램의 수 코드가 메모리 상에 올라가게 된다.

	즉 메모리 상에 함수 코드가 들어간다.

	이때 변수를 가리키는 포인터 처럼 함수 포인터는 메모리 사엥 올라간 함수의 '시작 주소'를 가리키는 역할을 하게 된다.
	그렇다면 함수 포인터가 함수를 포인트 하기 위해서는 그 함수의 시작 주소 값을 알아야한다. 
	그런데 배열과 마찬가지로 함수의 이름이 바로 함수의 시작 주소값을 나타낸다.

	=========
 
	아래의 부분에서 int(*pmax)(int, int); 가 함수 포인터 pmax의 정의이다.
	이 함수 포인터 pmax는 함수의 리턴값이 int형이고 두 개의 각각 int인 함수를 가리키는 구나!
	따라서 우리는 pmax 함수 포인터로 특정한 함수를 가리킬 때, 그 함수는 반드시 pmax의 정의와 일치해야 한다.
	(함수의 리턴형) (*포인터 이름) (인지들...)
	만일 인자가 없다면 괄호 안을 비워 두면 된다. 즉 int (*a) ()의 형태이면 된다.

	pmax가 max 함수를 가리키는 부분을 보자.
	pmax = max;
	max 함수가 pmax의 정의와 일치하므로 max함수의 시작 주속밧을 pmax에 대입할 수 있다.
	앞에서 말했듯 특정한 함수의 '시작 주소 값'을 알려면 그냥 함수 이름을 넣으면 된다.
	pmax = &max;의 형식은 틀린 것이다.

	함수 포인터인 pmax를 사용할 때도 마치 일반적인 함수를 사용하는 것처럼 pmax(a, b)를 하면 된다.

	이는 배열에서 아래와 같은 상황이다.
	int arr[3]
	int *p = arr; // &arr[0];
	arr[2] == p[2] // true
*/
#include <stdio.h>

int max(int a, int b);
int donothing(int c, int k);
int main() {
	int a, b;
	int (*pmax)(int, int);
	pmax = max;

	scanf("%d %d", &a, &b);
	printf("max(a, b) : %d \n", max(a, b));
	printf("pmax(a, b) : %d \n", pmax(a, b));

	// ==================================
	int a2, b2;
	/*
		return 타입이 int이고 args가 int, int인 함수 포인터를 정의하였다.
		donothing func와 max func가 모두 이 조건을 만족한다.
		즉 이들은 인자의 변수들도 다루고 하는 일도 다르지만 리턴 값이 int로 같고 2개의 인자 모두 int이므로 pfunc가 두 개의 함수를 다 가리킬 수 있다.
	*/
	int (*pfunc)(int, int);
	pfunc = max;

	scanf("%d %d", &a2, &b2);
	printf("max(a2, b2) : %d \n", max(a2, b2));
	printf("pfunc(a2, b2) : %d \n", pfunc(a2, b2));

	pfunc = donothing;

	printf("donothing(1,1) : %d \n", donothing(1, 1));
	printf("pfunc(1,1) : %d \n", pfunc(1, 1));
	//============================================
	/*
		그런데 함수 포인터를 만들 때, 인자의 형이 무엇인지 알기 힘든 경우가 종종 있다.
		예를 들어 아래와 같은 함수의 원형을 보자.
		
		int increase(int (*arr)[3], int row);
		
		두 번째 인자의 형은 int인데 첫 번째 인자의 형은 뭘까?
		사실 간단하다. 특정 타입의 인자를 판별하는 일은 단순히 변수의 이름만 빼면 된다.
		따라서 첫 번째 인자의 형은 int(*)[3]이다.

		즉 위의 함수를 가리키는 함수 포인터 원형은 아래와 같다.
		int (*pfunc) (int(*)[3], int);
		
		
	*/

	return 0;
}

int max(int a, int b) {
	if (a > b)return a;
	else return b;

	return 0;
}
int donothing(int c, int k) { return 1; }