/* ������ �̸� ����ϱ� */
#include <stdio.h>
#define PrintVariableName(var) printf(#var "\n");

int main(int argc, char** argv) {
	int a;

	PrintVariableName(a);

	return 0;
}
/*
	PrintVariableName(var) printf(#var "\n");
	#define�� ���� ��ó���������� ���Ǵ� �� �� #�� �ִµ�,
	��� '����' �տ� #�� ���̸� �� ���ڸ� ���ڿ��� �ٲ������.
	���� PrintVariableName(a); ��
	printf("a" "\n");���� �ٲ�� �ȴ�.
	�̶� C���� ������ �� ���� ���ڿ��� �׳� �ϳ��� ���ڷ� �������Ƿ�
	printf("a\n");�� �ȴ�
	#�� ���ڿ� ������ "�̰��� ���ڿ��� �ٲ۴�"��� �����ϸ� �ȴ�.
	
*/