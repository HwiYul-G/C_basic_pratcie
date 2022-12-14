#include <stdio.h>
// 형(type)이 다른 변수끼리의 대입이나 연산들이 모두 '불법'이다.

int main() {
	int a;
	double b;

	b = 2.4;
	a = b; // int에 double을?

	printf("%d", a); // 결과로 2가 나옴
	// 하지만 Output에 :warning C4244: '=' : conversion from 'double' to 'int', possible loss of data
	// 경고 C4244 : '=' : double에서 int로의 변환, 데이터 손실 가능성이 있음.
	// 이는 컴파일러 경고 메시지이다.
	// %d를 통해 정수부분만 출력하게 해서 그렇다고 생각할 수 있는데, %f로 바꿔 출력하면 더 이상한 결과가 나온다.

	// int 형 변수에 double 형 변수를 대입하면 소수 부분이 잘려서 정수 부분만 들어가게 된다.
	// 이는 각 변수들이 메모리 상에 저장되는 특징이 다르기 때문이다.
	// 왜냐하면 int 형 변수는 처음 정의되는 시작부터 메모리 상에 오직 정수 데이터만 받아 들이도록 설계되기 때문이다.

	/*
		[컴퓨터 실수를 표현하는 원리]
		컴퓨터 사엥서 실수를 표현하는 방법은 1) 고정 소수점(fixed point)와 2) 부동 소수점(floating point) 방식이다.
		사용하는 대부분의 컴퓨터의 경우 99.9% 부동 소수점 방식을 통해 실수를 표현하고 있다.
		그 이유는 고정 소수점 방식과 비교했을 때 같은 수의 비트만 사용해서 표현할 수 있는 수의 범위가 더 넓기 때문이다.

		이렇게 부동 소수점 방식을 통해 수를 표현하는 방법은 IEEE(국ㅈ 전기 전자 기술자 협회)에서 1985년에 IEEE-754라는 이름으로 표준화 했다.

		123, 1234.123, -234 이 수는 아래와 같이 과학적 표기로 나타낼 수 있다.
		1.23x10^2, 1.234123x10^-2, -2.34 x 10^2

		+-f x b^e 
		f : 가수, b : 밑(base), e : 지수

		컴퓨터 상에서는 이진체계를 사용하므로 b의 값은 2로 고정되어 있다.
		따라서 소수 데이터를 보고나할 때 f와 e의 값만 저장하면 된다. 그리고 맨 앞에 부호비트를 위해서 1bit 더 사용하게 된다.

		IEEE 754에서 정의한 부동 소수점에 따르면
		float의 경우 => sign bit : 1bit / exponent : 8 bit / mantissa : 23bit
		double의 경우 => sign bit : 1bit/ exponent : 11 bit / mantissa : 52bit

		[소수의 10진법 - 2진법, 진법 전환]
		이진법으로 표시된 소수를 한 번 십진법으로 바꿔보기
		0b 10010.1011 = 16 + 2 + 1/2 + 1/8 + 1/16 = 18.6875

		2진법으로 표시된 모든 소수들은 모두 십진법으로 변환 가능하다.
		10진법 소수도 2진법으로 가능하다.
		-118.625 = -111 0110 - 0.625 = -111 0110 - 1/2 - 1/8 = -111 0110. 101
		
		그런데 모든 10진법으로 표현된 수는 2진법으로 변환할 수 없다.
		예를 들어 0.1을 한 번 이진법으로 바꿔 보라. 10진법으로는 딱 소수점 한 자리 만으로 표현가능하지만,
		2진법으로 바꾼다면 무한 소수가 나타난다.
		0.1 = 2^-4 + 2^-5 + 2^-8 + 2^-9 + ... = 0.0001100110011... (2)
		
		무한 등비수열의 합을 구하는 방법을 안다면 0.1이 바뀐 무한 이진소수가 참임을 알 수 있다.

		컴퓨터는 이렇게 무한히 길게 나타나는 무한 소수들을 모두 메모리에 나타낼 수 없기 때문에
		일정 부분만 잘라서 메모리에 보관하게 된다. 따라서 필연적으로 오차가 발생하게 된다.

		[IEEE - 754 방식으로 소수 저장하기]
		1) 부호 bit은 0 이상이면 0, 아니라면 1이 할당됨
		2) 변환된 이진수를 정규화(Normalization)함.
			정규화는 어던 이진수를 1.xxx 꼴로 바꾸는 것이다.
			-118.625의 경우 이진수로 111 0110. 101이므로 1.110110101이 된다.
			그러면 가수 부분엔 1101 1010 1만 저장된다.
		3) 정규화 작업시 얼만큼의 shift 연산이 일어났는지 계산해 지수 부분에 얼마나 와야하는지 알게 된다.
		111 0110.101이 1.110110101이 되므로 shift연산이 오른쪽으로 6번 일어나서 지수는 6이 온다.

		0.1처럼 무한 소수로 표현되는 수들은 반올림하게 된다.
		Ex) 0.1 = 0.0001 1001 1001 1001 10011001 10011001 10011001 .. 으로 나가는데 float에 대입한다고 하면 float의 가수 부분이 23bit이므로 24번째 bit에서 반올림한다.
		따라서 0.1은 컴퓨터 상에선 0.00011001 10011001 1001101 로 보관된다.

		마지막으로 위에서 계산한 지수에 bias 처리를 해준다.
		이는 지수에 2^(e-1) -1 만틈을 더해준다는 뜻이다. 이때 e의 값은 지수 부분의 bit 수이다.
		float이면 8이므로 127, double은 11이므로 1023을 더하게 된다.

		왜 계산한 지수에 bias 처리를 해주냐면 지수가 언제나 양수가 아니기 때문이다.
		-118.625의 경우 정규화 시 지수고 +6이였으나 다른 소수들의 경우, 예를 들어 0.625는 이진수로 0.101인데
		정규화 시, 왼쪽으로 shift가 1번 되므로 지수가 음수(-1)가 된다.

		2의 보수 표현법으로 배운 우리로써는 그냥 정수표현하듯 2의 보수표현법으로 지수를 나타내면 안되냐? 라고 물을 수 ㅇㅆ다.
		이는 무조건 양수 값을 집어넣는 것이 컴퓨터 입장에서 크기를 비교하기 수월하기 때문이다.

		아무튼 float의 경우 지수에 들어가는 범위가 1-254까지이고,
			 double의 경우 1부터 2046까지 가능하다.
		이 말은 float의 지수 부분이 2^(-126)부터 2^(127)까지 가능하다는 의미이다.

		그렇다면 -118.625의 경우 지수 부분에 6+(127) = 133이 들어가게 된다.
		133은 2진수로 1000 0101이다. 따라서 flaot a = 118.625;를 한 변수 a의 메모리 구조를 살펴보면
		sign 1/ exponent(8bits) : 10000 0101 / fraction(23bit) 11011010 10000000 0000000이다.

		위에서 float형 변수를 이용하게 되면 지수가 1~254까지 처리가 된다고했는데 8bit로 처리할 수 있는 번위가 0~255까지이다.
		0과 255는 어디로 갔을까? 
		이 둘이 포함되지 않는 이유는 IEEE754에서 정상적이지 않는 수를 표현하기 위해 규칙을 정했기 때문이다.
		Denormalized number(비정상수) : 지수부 0, 가수부 0이 아님
		무한대						: 지수부 2^e-1, 가수부 0
		수가 아님(NaN)				: 지수부 2^e - 1, 0이 아님

		비정상수
		: 비정상수의 경우 2^(-127)보다도 작아서 지수 부분에 바이어스 처리르 해도 1이상이 되지 않는 수들을 말한다.
		따라서 이들의 경우 더이상 1.(가수부분)x2^(-127)형태로 표현할 수 없다.
		이 수들은 그대신 0.(가수부분)x2^(-127) 형태로 해석된다.

		무한대
		: 부호 비트 덕분에 IEEE754는 음의 무한대와 양의 무한대를 표현할 수 있다.
		무한대는 연산과정에서 표현할 수 잇는 가장 큰 수보다 더 큰 값이 들어가면 자동으로 발생한다.

		// NaN(수가 아님)
		Not a Number이다 이들은 엄밀히 값을 계산할 수 없는 연산 중 발생한다.
		무한대 - 무한대, -무한대 + 무한대, 0x무한대, 0 나누기 0, 무한대 나누기 무한대

	*/
	// 무한대가 나타나는 경우
	float a = 1. / 0.f;
	printf("a : %f \n", a);

	return 0;
}