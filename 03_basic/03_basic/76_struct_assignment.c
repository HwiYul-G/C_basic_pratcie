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
		���� i�� j�� �����ϸ� i�� ���� j�� ���� �״�� '����'�Ǵ� ��ó��,
		st2�� ��� i�� ���� st�� ��� i�� ���� ��������,
		st2�� ��� c�� ���� st�� ��� c�� ���� ��������.
		�̴� ����� �ո����̰� ���Կ������� ������ �� �س��� �ִ�.
	*/

	printf("st2.i : %d \n", st2.i);
	printf("st2.c : %c \n", st2.c);

	// ================
	struct TEST2 a, b;
	
	b.i = 3;
	copy_str(b.str, "hello, world");

	a = b;	// ���Կ����� = �� ���� ����ü�� ��� ��� �����Ͱ� �ϴ��� ���� �Ǿ �� ���� �� �� �ִ�.

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