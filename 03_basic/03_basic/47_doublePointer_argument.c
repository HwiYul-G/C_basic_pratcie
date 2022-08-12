/*
	어떤 함수가 특정한 타입의 변수/배열의 값을 바꾸려면 
	함수의 인자는 반드시 타입을 가리키는 포인터 형을 이용해야한다.
*/
#include <stdio.h>

int pswap(int** ppa, int** ppb);
int main() {
	int a, b;
	int* pa, * pb;

	pa = &a;
	pb = &b;

	printf("pa 가 가리키는 변수의 주소값 : %p \n", pa);	//0x7ffc5ffd7520 
	printf("pa 의 주소값 : %p \n \n", &pa);	// 0x7ffc5ffd7528 
	printf("pb 가 가리키는 변수의 주소값 : %p \n", pb);	// 0x7ffc5ffd7524 
	printf("pb 의 주소값 : %p \n", &pb);	// 0x7ffc5ffd7530

	printf(" ------------- 호출 -------------- \n");
	pswap(&pa, &pb);
	printf(" ------------- 호출끝 -------------- \n");

	printf("pa 가 가리키는 변수의 주소값 : %p \n", pa);	// 0x7ffc5ffd7524 
	printf("pa 의 주소값 : %p \n \n", &pa);	// 0x7ffc5ffd7528
	printf("pb 가 가리키는 변수의 주소값 : %p \n", pb);	// 0x7ffc5ffd7520
	printf("pb 의 주소값 : %p \n", &pb);	// 0x7ffc5ffd7530

	return 0;
}

int pswap(int** ppa, int** ppb) {
	int* temp = *ppa;

	printf("ppa가 가리키는 변수의 주소값 : %p \n", ppa);// 0x7ffc5ffd7528
	printf("ppb가 가리키는 변수의 주소값 : %p \n", ppb);	// 0x7ffc5ffd7530 

	*ppa = *ppb;
	*ppb = temp;
	
	return 0;
}