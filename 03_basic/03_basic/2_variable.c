#include <stdio.h>

/*
	char		1byte				unsigned char는 0~255까지, signed char는 -128~127까지
	short		min 2byte			signed short는 -32,768~32,767 , unsigned short : 0~65,535
	int			min 2byte, 보통 4byte
	long		min 4byte, 32bit의 경우 4byte, 64bit의 경우 8byte
	long long	min 8byte
	float		4byte
	double		8byte

	여기서 중요한 것은 각 타입들의 크기는 char, float, double 말고 정해진 것이 없다.
	int의 경우 C 표준을 읽어보면 최소 2byte인 타입이라 되어 있지 몇 바이트로 처리하라고 되어있진 않다.
	하지만 대부분의 시스템에서 int는 4 byte로 구현되어 있다.


*/

int main() {
	int a; // int 형의 데이터를 보관
	a = 10;
	printf("a의 값은 : %d \n", a);

	int b;
	b = 127;
	printf("a의 값은 %d 진수로 %o 입니다. \n", 8, b);
	printf("a의 값은 %d 진수로 %d 입니다. \n", 10, b);
	printf("a의 값은 %d 진수로 %x 입니다. \n", 16, b);
	// %d, %o, %x는 인자의 값을 출력하는 형식이다. o는 8진수 x는 16진수

	// double의 경우 int 형에 비해 덩치가 2배나 크지만 그 만틈 엄청ㄴ 크기의 숫자를 다룰 수 있다.
	// 대신 처음 15 개의 숫자들만 정확하고 나머지는 10의 지수 형태로 표현된다.
	float a = 3.141592f; // float은 f를 붙여야 double과 구분할 수있다.
	double b = 3.141592;
	printf("a : %f \n", a);
	printf("b : %f \n", b);
	printf("a : %d \n", a); // a는 지금 정수형 변수가 아니므로  %d로 출력하면 잇한 숫자가 나온다.
	// 설령 a = 3f, b = 3; 이라고 해도 이미 a와 b를 실수형 변수로 선언하였으므로 컴퓨터는 a, b를 정수로 보지 않는다.
	// 따라서 실수형 변수를 출력하는 형식인 %f를 사용해야 한다.

	// 주의할 사항은 printf에서 %f를 이용해 수를 출력할 때 언제나 소수점을 뒤에 붙여야 한다.
	printf("%f", 1); // 화면에 이상한 값 (아마 0)이 출력될 것
	printf("%f", 1.0); // 제대로 1.0이 출력됨

	return 0;
}
