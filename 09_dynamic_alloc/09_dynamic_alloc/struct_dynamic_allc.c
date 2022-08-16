/*
	구조체 역시 '사용자가 만든 하나의 데이터 타입'이다.
	다시 말해 구조체도 int처럼 사용할 수 있다는 것이다.
	따라서 구조체 배열을 malloc을 이용해 지지고 볶는 일은 전혀 이상할 것이 없다.
*/
#include <stdio.h>
#include <stdlib.h>

struct Something {
	int a, b;
};

int main() {
	struct Something* arr; // struct Something을 가리키는 포인터
	int size, i;

	printf("원하시는 구조체 배열의 크기 : ");
	scnaf("%d", &size);

	/*
		malloc을 이용해 arr을 위한 공간을 할당해 준다.
		이에 필요한 크기는 당연히 sizeof(struct Somthing_*size) 이다.

		만일 sizeof 대신 구조체의 실제 크기를 계산해서 더하는 경우 오류가 발생한다.
		예를 들어 Something 구조체의 경우 1개당 8byte를 차지한다고 볼 수 있는데 사실 그렇지 않을 수도 있다.

		물론 위 경우는 좀 특별하지만,
		예를 들어 구조체의 크기가 10byte일 경우 컴퓨터가 '더블 워드 경계(double world boundary)'에 놓음으로
		속도를 향상시키는 경우가 있다.
		이 경우 구조체의 크기는 12byte로 간주될 수 있다.
		=> 언제나 sizeof를 사용해야 한다는 점을 기억!
	*/
	arr = (struct Something*)malloc(sizeof(struct Something) * size);

	for (i = 0; i < size; i++) {
		printf("arr[%d].a : ", i);
		scnaf("%d", &arr[i].a);
		printf("arr[%d].b : ", i);
		scanf("%d", &arr[i].b);
	}

	for (i = 0; i < size; i++) {
		printf("arr[%d].a : %d, arr[%d].b : %d \n", i, arr[i].a, i, arr[i].b);
	}
	free(arr);

	return 0;
}