#include <stdio.h>

int main() {
	// 배열은 변수가 여러개 모인 것이다.
	// 그리고 배열의 각 우너소는 메모리 상에 연속되게 놓인다는 특징이 있다.
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; i++) {
		printf("arr[%d]의 주소값 : %p \n", i, &arr[i]);
	}
	// for문 printf를 하면 4씩 증가하게 된다.
	// 따라서 포인터로도 배열의 원소에 쉽게 적용이 가능하다.
	// 이런 일이 가능한 일이 포인터는 자신이 가리키는 데이터의 '형'의 크기를 곱한 만큼 덧셈을 수행한다.
	// 즉 int* p = a; 라면 p +1을 할 때 p의 주소값에 사실은 1*4가 더해진다는 것이고,
	// p+3 을 하면 p의 주소값에 3*4인 12가 더해진다.


	// 배열의 원소를 가리키는 포인터를 만들어보자.
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// parr이라는 int형을 가리키는 포인터는 arr[0]라는 int형 변수를 가리킨다. (배열의 각 원소는 하나의 변수로)
	int* parr = &arr[0];	

	for (int i = 0; i < 10; i++) {
		printf("arr[%d]의 주소값 : %p ", i, &arr[i]);
		printf("(parr + %d)의 값 : %p ", i, (parr + i));

		if (&arr[i] == (parr + i)) {
			printf("--> 일치 \n");
		}
		else {
			printf("--> 불일치\n");
		}
	}
	// 위의 for문은 결과적으로 모두 "일치"한다.

	
	int arr[5] = { 1,2,3,4,5 };
	// 3[arr]은 이상한 표현이다. 이렇게 사용하면 가독성이 떨어져서 arr[3]으로 사용한다.
	// 하지만 앞에서 [] 연산자로 3[arr]을 *(3+arr)로 바꿔주므로 arr[3]과 동일한 결과를 출역할 수 있게 된다.
	printf("3[arr] : %d \n", 3[arr]);
	printf("*(3+a) : %d \n", *(arr + 3));
	
	// pointer의 정의
	// int형 포인터를 정의하기 위해 int* p; 와 int *p;를 둘다 사용해도 된다.
	int *p, *q, *r; // 포인터 변수를 선언하려면 이렇게 해야한다. \
	// int* p; 꼴로 선언한다면, 아래와 같이 실수할 확률이 높아진다.
	int *p, q, r; // p만 int를 가리키는 포인터이고 q, r은 평범한 int형 변수가 된다.
	// 따라서 int *p; 꼴로 선언하는 것이 좋다.

	return 0;
}