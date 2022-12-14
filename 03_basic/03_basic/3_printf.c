#include <stdio.h>

int main() {
	float a = 3.141592f;
	double b = 3.141592;
	int c = 123;
	
	// .2f는 무조건 소수점 둘째 자리까지만 표시하란 뜻
	// %.100f로 하면 3.1415920000 ... 00으로 표시해 100개를 출력하게 함
	printf("a : %.2f \n", a); //3.14

	// %d가 아니라 %5d인데 .5가 아니다.
	// 이 말은 숫자의 자리수를 5자리로 맞추라는 것이다.
	// 따라서 앞에 공백 2개를 만들고 123을 표현한다.
	printf("c : %5d \n", c); //  123
	// 123456을 표시할 때, %5d 조건을 주면 이 때는 그냥 123456을 다 표시한다.

	// 위의 2가지를 함께 표시하면 전체 자리수를 6자리로 하고
	// 소수점 이하 3째짜리 까지 표시한다는 뜻
	printf("b : %6.3f \n", b);//  3.142

	return 0;
}