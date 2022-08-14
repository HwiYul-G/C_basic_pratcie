/*
	여태 구조체 변수를 정의할 때 아래와 같이 작성했다.
	struct Anomynous Var, Var2;

	그런데 구조체 변수를 정의하는 색다른 방법이 있다.
*/
#include <stdio.h>
char copy_str(char* dest, char* src);
int Print_Obj_Status(struct obj OBJ);

struct obj {
	/*
		기본적으로 우리가 하던 것처럼
		struct obj라는 구조체를 정의했고 멤버는 아래와 있다.
		그런데 아래 있는 Ball은 무엇인가?

		이는 바로 struct obj형의 Ball이란 구조체 변수를 정의하라는 것이다.
		이로써 main 함수에서 struct obj Ball; 이라고 쓴 것을 안쓰고 할 수 있다.

		사실 main 함수에서 struct obj Ball; 이라고 쓴 것과 동일하다.
	*/
	char name[20];
	int x, y;
} Ball;

int main() {
	Ball.x = 3;
	Ball.y = 4;
	copy_str(Ball.name, "RED BALL");

	Print_Obj_Status(Ball);
	return 0;
}

char copy_str(char* dest, char* src) {
	while (*src) {
		*dest = *src;
		src++;
		dest++;
	}

	*dest = '\0';

	return 1;
}
int Print_Obj_Status(struct obj OBJ) {
	printf("Location of %s \n", OBJ.name);
	printf("( %d, %d ) \n", OBJ.x, OBJ.y);
	return 0;
}