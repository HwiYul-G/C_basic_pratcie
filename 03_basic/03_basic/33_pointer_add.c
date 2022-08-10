#include <stdio.h>

int main() {
	int a;
	int* pa;
	pa = &a;

	printf("pa의 값 : %p \n", pa);		// random하게 바뀌는데 0x 7ffd 6a32 fc4c
	printf("(pa + 1)의 값 : %p \n", pa + 1);	// 0x 7ffd 6a32 fc50 (16진수이므로 c는 12이고 + 4를 하면 올림이 됨)

	// 포인터의 형이 int*이고 +1을 한 건 int가 4byte이기 때문일까?
	int a;
	char b;
	double c;
	int* pa = &a;
	char* pb = &b;
	double* pc = &c;
	// 위에서 생각한 int라서 4byte가 더해진 건 아닐까라는 예상은 맞았다.
	// int*형 pa의 경우 4byte가 더해짐(예상과 동일)
	printf("pa의 값 : %p \n", pa);	// 0x 7ffc f64a 2e04 
	printf("(pa + 1)의 값 : %p \n", pa + 1); //0x 7ffc f64a 2e08
	// char*인 pb의 경우 1byte가 더해짐 (예상과 동일)
	printf("pb의 값 : %p \n", pb);	// 0x 7ffc f64a 2e03
	printf("(pb + 1)의 값 : %p \n", pb + 1);	//0x f77c f64a 2e04
	// double*은 8byte이므로 8byte가 더해짐(예상과 동일)
	printf("pc의 값 : %p \n", pc);	// 0x 7ffc f64a 2e08 
	printf("(pc + 1)의 값 : %p \n", pc + 1);	// 0x 7ffc f64a 2e10 

	// 그런데 왜 포인터가 가리키는 형의 크기만큼 더할까?

	// 우선 빼기도 가능한지 해보자.
	int a;
	int* pa = &a;

	printf("pa 의 값 : %p \n", pa);	// 0x 7ffe 4f4f a47c 
	printf("(pa - 1) 의 값 : %p \n", pa - 1); // 0x 7ffe 4f4f a478  (예상대로 4만큼 빠짐)

	// 포인터끼리의 덧셈
	int a;
	int* pa = &a;
	int b;
	int* pb = &b;
	int* pc = pa + pb;	// error C2110 : '+' : 두 포인터를 더할 수 없습니다.
	/* 
		C에서는 두 포인터끼리의 덧셈을 허용하지 않는다.
		왜 두 포인터끼리의 덧셈을 허용하지 않을까?
		사실, 포인터끼리의 덧셈은 아무런 의미가 없을 뿐더러 필요 하지도 않는다.
		두 변수의 메모리 주소를 더해서 나오는 값은 
			이전에 포인터들이 가리키던 두 개의 변수와 아무련 관련이 없는 메모리 속 임의의 지점이다.
		아무런 의미가 없는 프로그램 상에 상고나없는 지점을 가리킨다.

		그렇다면 왜 포인터에 정수를 더하는 것은 왜 될까?
		이는 조금 이따가 보자.
	*/

	// 그런데 놀랍게도 포인터끼리의 뺄셈은 가능하다.
	int a;
	int* pa = &a;
	int* pb;

	*pa = 3;
	pb = pa;	
	// pa에 저장되어 있는 값(pa가 가리키고 있는 변수의 주소값)을 pb에 대입
	// 따라서 pb도 pa가 가리키던 것의 주소값을 가지게 된다.
	// 결과적으로 pa와 pb가 모두 a를 가리키게 된다.
	// 주의해야할 점은 pa와 pb가 형이 동일해야한다.	
	// 만일 형이 다르면 형변환을 해줘야한다.

	printf("pa 가 가리키고 있는 것 : %d \n", *pa);
	printf("pb 가 가리키고 있는 것 : %d \n", *pb);


	return 0;
}