/* 라디안에서 도로 바꾸기*/
#include <stdio.h>
// #define RADTODEG(x) (x) * 57.295
#define RADTODEG(x) ((x) * 57.295)

int main(int argc, char** argv) {
	printf("5 rad 는 : %f 도", RADTODEG(5)); // 5 rad 는 : 286.475000 도
	/*
		RADTODEG(1+4) 를 하더라도 (1+4) * 57.295 로 잘 바뀌어 원하는 결과를 출력할 수 있게 된다.
		그렇다면 위와 같이 정의한 RADTODEG는 문제가 없을까?
	*/
	printf("5 rad 는 : %f 도", 1 / RADTODEG(5));
	/*
		위 문장을 수행하면 문제가 발생하게 된다.
		위 문장은 전처리기에의해 printf("5 rad 는 : %f 도", 1 / 5 * 57.295);로 변화된다.
		우리가 원하는 결과인 1 / (5 * 57.295)와 다른 것이 나타난다.

		이를 해결하기 위해 역시 전체 수식을 소괄호로 감싸
		#define RADTODEG(x) ((x) * 57.295)로 만들어야한다. 이는 상당히 귀찮은 일이다.
		사소한 실수 하나로 꽤 큰 문제가 초래될 수 있기에..
	*/
	return 0;
}
