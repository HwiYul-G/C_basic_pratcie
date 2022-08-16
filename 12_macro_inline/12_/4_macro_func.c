/* 변수의 이름 출력하기 */
#include <stdio.h>
#define PrintVariableName(var) printf(#var "\n");

int main(int argc, char** argv) {
	int a;

	PrintVariableName(a);

	return 0;
}
/*
	PrintVariableName(var) printf(#var "\n");
	#define과 같은 전처리문에서만 사용되는 것 중 #이 있는데,
	어떠한 '인자' 앞에 #을 붙이면 이 인자를 문자열로 바꿔버린다.
	따라서 PrintVariableName(a); 는
	printf("a" "\n");으로 바뀌게 된다.
	이때 C언어에서 연속한 두 개의 문자열은 그냥 하나의 문자로 합쳐지므로
	printf("a\n");이 된다
	#이 인자에 붙으면 "이것을 문자열로 바꾼다"라고 생각하면 된다.
	
*/