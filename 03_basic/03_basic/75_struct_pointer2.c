#include <stdio.h>

struct TEST {
	int c;
};

struct TEST2 {
	int c;
	int* pointer;
};

int add_one(int* a);

int main() {
	struct TEST t;
	struct TEST* pt = &t;
	
	// pt가 가리키는 구조체 변수 t의 멤버 c값을 0으로 한다.
	(*pt).c = 0;
	printf("t.c : %d \n", t.c);
	// pt가 가리키는 구조체 변수의 c 값을 1로 한다.
	pt->c = 1;
	printf("t.c : %d \n", t.c);
	/*
		struct TEST형의 구조체 변수 t와 struct TEST형을 가리키는 포인터 pt를 선언했다.
		struct TEST도 우리가 창조한 하나의 타입이고 이를 가리키는 포인터 역시 다른 모든 포인터와 같은 크기이다.
		즉 pt는 절대로 구조체가 아니고 
		pt는 단순히 구조체 변수 t가 저장되어 있는 메모리 공간의 주소값을 보관하고 있을 뿐이다.

		이때 pt는 t의 주소값을 가지고 있으므로 pt는 t를 가리키게 딘다.
		(*pt).c = 0;
		pt가 t를 가리키고 있기에 pt를 가지고 t의 값을 마음대로 조작할 수 있다.
		이전에 int *pi = &i;를 한 후 *pi를 쓰면 i를 간접적으로 나타낼 수 있었듯이
		*pt를 이용하면 pt가 가리키고 있는 struct TEST형의 변수, 즉 t를 나타낼 수 있게 된다.
		
		따라서 (*pt).c를 하면 t의 멤버 c를 의미하게 된다.
		이때 (*pt)로 *pt를 괄호로 감싸는 이유는 .의 우선순위가 *보다 높기때문에
		*pt.c라고 쓰면 pt가 있지도 않는 멤버 c를 가리키는 것을 의미하게 된다.
		
		아무튼 (*pt).c = 0;을 통해 우리는 t의 c멤버 값을 성공적으로 바꿀 수 있었다.
		 
		하지만 (*pt).c는 쓰기 너무 불편하다. 
		그래서 -> 이란 연산자를 만들었다.
		->의 의미는 "pt가 가리키는 구조체 변수의 멤버"를 의미한다.
		pt->c는 pt가 가리키는 구조체 변수, 즉 t의 멤버 c를 의미한다.
	*/

	struct TEST2 t2;
	struct TEST2* pt2 = &t2;
	int i = 0;

	t2.pointer = &i; // t2의 멤버 pointer는 i를 가리키게 된다.
	*t2.pointer = 3; // t2의 멤버 pointer가 가리키는 변수 즉 i의 값을 3으로 만든다.

	printf("i : %d \n", i);
	
	/*
		->가 *보다 우선순위가 높으므로 먼저 해석하게 된다.
		즉, (pt가 가리키는 구조체 변수의 pointer 멤버)가 가리키는 변수의 값을 4로 바꾼다
		라는 뜻이다.
	*/
	*pt2->pointer = 4; // *(pt->poiter) = 4;

	printf("i : %d \n", i);

	// 구조체 포인터 연습2
	struct TEST t3;
	struct TEST* pt3 = &t3;
	
	pt3->c = 0; // pt3가 가리키는 구조체 변수 c의 멤버값을 0으로한다.

	/*
		int add_one(int * a) 함수의 인자에 t3 구조체 변수의 멤버 c의 주소값을 전달한다.
	*/
	add_one(&t3.c);
	printf("t3.c : %d \n", t3.c);

	/*
		int add_one(int* a) 함수의 인자에 
		pt3이 가리키는 구조체 변수(즉 t3)의 멤버 c의 주소값을 전달하고 있다.
	*/
	add_one(&pt3->c); // pt3-> c == *(pt3).c 이므로 &pt3->c == &(*(pt3).c)
	printf("t3.c : %d \n", t3.c);

	return 0;
}

int add_one(int* a) {
	*a += 1;
	return 0;
}