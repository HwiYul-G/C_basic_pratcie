#include <stdio.h>

int* function() {
	/*
		���� ���� ����� static Ű���带 ���̸� �ȴ�.
		�׸��� �ش� ����(���� ����)�� ����� ������ ������� ���� �ı����� �ʴ´�.
	*/
	static int a = 2;
	return &a;
}

int func1() {
	static int how_many_called = 0;
	how_many_called++;
	printf("func1 called : %d \n", how_many_called);
	return 0;
}
int func2() {
	static int how_many_called = 0;
	how_many_called++;
	printf("func2 called : %d \n", how_many_called);
	return 0;
}


int main() {
	int* pa = function();
	printf("%d \n", *pa);
	/*
		static ���� (���� ����)�� ����� ������ ����� ���� �ı����� �ʴ´�.
		���� a�� ���ǵ� ���� �ۿ��� int*pa = function();�� ���� �����ص�
		a�� �Ҹ���� �ʾұ� ������ 2��� ���� �� ��µȴ�.

		�׷��� �ǹ��� �����.
		function�� ������ ȣ���ϸ� a�� ������ 2�� �ʱ�ȭ �ǳİ� ���� �� �ִ�.
		������ a�� �� �ѹ��� �ʱ�ȭ �ȴ�.

		�� static int a = 2;��� ������ �� �� �� ����Ǹ�, 
		�� ���� ���� function�� �������� �ʴ��� 
		a��� ���� ������ �̹� ���ǵǾ� �ִ� �����̴�.

		���� �̿� ���� ���� ������ ����ϸ� �ش� �Լ��� �� �� ȣ��Ǿ��� ���� ���� ������ �� �ִ�.
	*/
	func1();
	func2();
	func1();
	func2();
	func2();
	func2();
	func1();
	func1();
	func2();
	/*
		����� ���� ������ ��� 'global ����'(���� ����) ó�� ������ ������ ����ǰ� ���α׷��� ����� �� �ı��ȴ�.
		���� ���� ����ó�� ���� ������ ���� �� Ư���� ���� ������ ���� �ʴ� �� 0���� �ڵ� �ʱ�ȭ �ȴ�.
	*/
	return 0;
}