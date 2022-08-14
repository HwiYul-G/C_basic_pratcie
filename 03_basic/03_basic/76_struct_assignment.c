#include <stdio.h>
char copy_str(char* dest, char* src);
struct TEST {
	int i;
	char c;
};
struct TEST2 {
	int i;
	char str[20];
};
int main() {
	struct TEST st, st2;

	st.i = 1;
	st.c = 'c';

	st2 = st;
	/*
		변수 i를 j에 대입하면 i의 값이 j의 값에 그대로 '복사'되는 것처럼,
		st2의 멤버 i의 값은 st의 멤버 i의 값과 같아지고,
		st2의 멤버 c의 값은 st의 멤버 c의 값과 같아졌다.
		이는 상당히 합리적이고 대입연산자의 역할을 잘 해내고 있다.
	*/

	printf("st2.i : %d \n", st2.i);
	printf("st2.c : %c \n", st2.c);

	// ================
	struct TEST2 a, b;
	
	b.i = 3;
	copy_str(b.str, "hello, world");

	a = b;	// 대입연산자 = 을 통해 구조체의 모든 멤버 데이터가 일대일 대응 되어서 잘 됨을 알 수 있다.

	printf("a.str : %s \n", a.str);
	printf("a.i : %d \n", a.i);
	

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