#include <stdio.h>

int main() {
	// &, |, ^(XOR), <<, >>, ~(반전)
	int a = 0xAF; // 1010 1111
	int b = 0xB5; // 1011 0101

	printf("%x \n", a & b);   // a & b = 10100101 -> a5
	printf("%x \n", a | b);   // a | b =10111111 -> bf
	printf("%x \n", a ^ b);   // a ^ b = 00011010 -> 1a
	printf("%x \n", ~a);      // ~a = 1....1 01010000 -> ffffff50
	printf("%x \n", a << 2);  // a << 2 = 1010111100 -> 2bc
	printf("%x \n", b >> 3);  // b >> 3 = 00010110 -> 16

	// 연산자 우선순위가 있음
	int c = 10;
	int d = 11;
	int e = 12;
	a = b + c + d + e; // b+c를 계산하고 그 결과를 반환하면 C이고 C +d를 반환하면 D이고 D+e를 E라고 하면 a = E가 된다.
	
	// 왼쪽 우선이였다면 a = b; b = c; c = d; d = 3의 형식으로 계산 되어 a, b, c에는 알 수 없는 값이 들어간다.
	// 하지만 오른쪽 우선이므로 위의 식은 d = 3, c =d, b=c, a=b 형식으로 계산되어 a,b,c,d의 값이 모두 3이 될 수 있다.
	a = b = c = d = 3;

	
	return 0;
}