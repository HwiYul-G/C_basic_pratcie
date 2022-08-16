/*
	[ 여러가지 typedef들 ]

*/

#include <stdio.h>
int add(int a, int b) { return a + b; }
typedef int CAL_TYPE;
typedef int (*Padd)(int, int);	// 함수 포인터
typedef int Arrays[10];
int main() {
	CAL_TYPE a = 10;
	Arrays arr = { 1,2,3,4,5,6,7,8,9,10 };
	Padd ptr = add;	// int (*ptr) (int, int) = add; 와 동일하다.
	printf("a : %d \n", a);	// 10
	printf("arr[3] : %d \n", arr[3]);	// 4
	printf("add(3, 5) : %d \n", ptr(3, 5));	// 8
	return 0;
}
