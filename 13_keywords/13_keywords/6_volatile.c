#include <stdio.h>
typedef struct SENSOR {
	/* 감지 안되면 0, 감지되면 1 이다.*/
	int sensor_flag;
	int data;
} SENSOR;

int main() {
	volatile SENSOR* sensor;
	/* 값이 감지되지 않는 동안 계속 무한 루프를 돈다*/
	while (!(sensor->sensor_flag)) {
	}
	printf("Data : %d \n", sensor->data);
}
/*
	이렇게 해준 순간 컴파일러는 SENSOR를 가리키는 포인터 타입인 sensor라는 변수에 대해 최적화를 수행하지 않는다.
	volatile의 의미는 '변덕스러운'이다.
	sensor에 volatile keyword를 붙여준 순간 sensor->sensor_flag의 값이 '변덕스럽게 변할 수 있기 때문'에
	이에 대한 최적화 작업을 수행하지 말라는 의미가 된다.
	따라서 컴파일러는 위 소스를 의미 그대로 컴파일하게 되어 우리가 원하는 결과를 얻을 수 있다.
*/