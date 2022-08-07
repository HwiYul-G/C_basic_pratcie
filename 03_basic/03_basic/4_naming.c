#include<stdio.h>

int main() {
	int a, b, c, hi;
	float d, e, f, bravo;
	double g, programming;
	long h;
	short i;
	char j, k, hello, mineral;

	// 오래된 버전의 C(C89)를 사용한다면, 변수 선언시 반드시 최상단에 위치해야 한다.
	// 하지만 최신 버전의 C는 변수를 사용할 때 아무데나 선언 해도 된다.

	// 변수 선언시 주의해야할 점이 있다.
	int a, A; // a와 A는 다른 변수임
	int 1hi; // Error : 숫자가 앞에 위치할 수 없다.
	int hi123, hi123i, h1234324; // 숫자가 뒤에 있으면 괜찮다.


	return 0;
}