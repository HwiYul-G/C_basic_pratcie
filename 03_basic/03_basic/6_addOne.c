#include <stdio.h>
int main() {
	int a = 1, b = 1, c = 1, d = 1;

	a = a + 1;
	printf("a : %d \n", a);
	b += 1;
	printf("b : %d \n", b);
	++c;	// prefix :  1�� ������ �� ����� ������
	printf("c : %d \n", c);
	d++; // postfix : ����� ������ ���� 1�� ������
	printf("d : %d \n", d);

	// �������� ������ ���� ����
	int a1 = 1;
	printf("++a1 : %d \n", ++a1); // 2
	
	a1 = 1;
	printf("a1++ : %d \n", a1++); // 1
	printf("a1 : %d \n", a1); // 2

	return 0;
}

