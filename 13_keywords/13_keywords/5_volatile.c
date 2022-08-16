/*
	volatile 키워드는 아주 특수한 상황이 아니고선 사용하지 않는 키워드이다.
	volatile 키워드를 사용하는 경우는 대부분 외부 하드웨어와 통신할 때 사용하게 된다.

	만일 특정한 외부 센서와 소통하는 프로그램을 만든다고 하자.
	이 센서는 RAM의 특정 영역을 이용하는데,
	만일 센서에 값이 감지되지 않으면 그 곳의 값이 0이 되어 무언가 감지되면
	그 부분의 값을 1로 이용한다고 하자.

	그러면 십중팔구 아래와 같은 코드를 작성할 것이다.
*/
#include <stdio.h>
typedef struct SENSOR {
	int sensor_flag; // 감지 안되면 0, 감지 되면 1
	int data;
} SENSOR;
/*
	typedef를 위와 같이 써줌으로 typdef struct SENSOR SENSOR한 효과를 낼 수 있다.
*/
int main() {
	SENSOR* sensor;
	// 값이 감지되지 않는 동안 계속 무한 루프를 돈다.
	while (!(sensor->sensor_flag)) {
	}
	printf("Data : %d \n", sensor->data);
	return 0;
}
/*
	우리가 이 코드를 볼 땐 이상을 느끼지 못한다.
	하지만 컴파일러는 '과하게 똑똑'해서 우리가 사용한 while문을 최적화해버린다.
	보통의 상황ㅇ서 sensor->sensor_flag의 값이 바꾸니느 경우는 없기 때문에
	굳이 while문을 배번 돌릴 때마다 값을 비교할 필요가 없게 된느 것이다.
	그냥 컴파일러는 값을 딱 한 번만 읽고 0이 아니라면 그냥가고, 0이라면 while문을 무한이 돌리는 것으로 생각해버린다.

	결과적으로 위의 코드를 컴파일러는 아래와 같이 바꾼다.
	#include <stdio.h>
	typedef struct SENSOR {
		int sensor_flag;
		int data;
	} SENSOR;
	
	int main() {
		SENSOR* sensor;
		if (!(sensor->sensor_flag)) {
			while (1) {
			}
		}
		printf("Data : %d \n", sensor->data);
	}
	
	이는 우리가 결코 원하던 결과가 아니다.
	만일 센서에 값이 감지되었다고 해도 while문을 절대로 탈출 할 수 없게 되어
	무한 루프를 돌게 된다.
	우리는 컴파일러가 최적화 작업을 수행햐는 것울 원치 않는다.

	이를 컴파일러에게 알려주기 위해선 2가지 방법이 있다.
	1) 컴파일러의 최적화 옵션을 빼버리는 것
		gcc에서는 단순휘 최적화 옵션을 안주면 된다.
		VS에선 프로젝트 속성의 C/C++-최적화에서 사용 안함을 선택하면 된다.
	그런데 최적화를 하지 않기엔 그 손실이 너무 크다.
	최적화 옵션을 끄는 순간 다른 코드들의 최적화도 하지 않겠다는 의미가 되기 때문이다.

	이를 위해 volatile 키워드가 생겨났다.
	=>6_volatile.c


*/