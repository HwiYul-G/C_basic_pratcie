#include <stdio.h>
/* 전처리기 명령에는 ; 를 붙이지 않는다! */
#pragma pack(1)
struct Weird {
	char arr[2];
	int i;
};
int main() {
	struct Weird a;
	printf("size of a : %d \n", sizeof(a));	// 6
	return 0;
}
/*
	pragma 키워드를 사용하니 예상한대로 6으로 잘 나온다.
	#pragma pack(1) 은 MS계열의 컴파일러들에만 유효한 문장인데,
	구조체를 1byte 단위로 정렬하라는 뜻이다.

	즉 구조체의 크기가 1의 배수가 되게 하라는 것이다. 1외에도 2,4,8,16 등이 올 수 있다.
	만일 기본값, 즉 더블 워드 경계로 정렬하기 위해서는 #pragma pack(4)로 하면 된다.

	9_pragma.c에서 이어서
*/