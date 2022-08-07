#include <stdio.h>
int main() {
	int a = 1, b = 1, c = 1, d = 1;

	a = a + 1;
	printf("a : %d \n", a);
	b += 1;
	printf("b : %d \n", b);
	++c;	// prefix :  1을 더해준 후 결과를 돌려줌
	printf("c : %d \n", c);
	d++; // postfix : 결과를 돌려준 이후 1을 더해줌
	printf("d : %d \n", d);

	// 전위형과 후위형 차이 보기
	int a1 = 1;
	printf("++a1 : %d \n", ++a1); // 2
	
	a1 = 1;
	printf("a1++ : %d \n", a1++); // 1
	printf("a1 : %d \n", a1); // 2

	return 0;
}

