/*
	���α׷����� �ϸ鼭 �������� �۾����� '�ݺ���'���� �ؾ��ϴ� ������ �����ִ�.
	���� ��� ���� a�� b�� �ִ밪�� ���ϴ� ���� �����غ���.
	�̸� ���α׷��� �� �ʿ��ϸ� �Ź�
	int max;
	if(a>=b) max = a;
	else max = b;
	�� �ؾ��Ѵ�. �̷��� ���� �� �ι� ����� ���� �ٿ��ֱ� �ϸ� �ǹǷ� �δ㽺���� �ʴٰ� ������ �����ִ�.
	
	������ �̷� ����� �ո����ϱ�?
	�Ź� ���� �ٿ��ֱ⸦ �Ѵٸ� �ҽ��ڵ尡 ������������ �� ���� ���� ���������. (�������� ��������.)

	�̷� ��� '�ִ밪�� ����ϴ� �Լ��� ����� ������ �ȴ�.'

	�츮�� �� �� �ڵ带 �Ź� ���� ��� �� ���� �Է¹޾Ƽ� ū ���� ����ϴ� �Լ��� ������ ����ϸ� �ȴ�. 
	(���� ������ �� �ڵ尡 �ƴ�����)
*/

#include <stdio.h>
// �Լ��� ����(definition) �κ�
// int�� �� �Լ��� int���� ������ ��ȯ�Ѵٴ� ���̴�.
// ()�� �Լ��� �̸��� ���Ե� ���� �ƴ϶� ���� �ٴ� ��ȣ�� �̰��� �Լ��� ����� �ǹ��Ѵ�.
int print_hello() {
	// �Լ��� ��ü(body)��� �Ѵ�.
	printf("Hello!! \n");
	// int���� 0�� ��ȯ�Ѵ�. -> 0�̶�� �����Ͱ� �޸𸮻��� 4 byte�� �����Ͽ� ��ȯ�ȴ�.
	return 0; 
}

// �Լ��� ������ 2���� ���°� �ִ�.
// �ϳ��� ��ȯ�� �Ǿ� ���Ḧ �ϰ� �Ǵ� ���̰�, �ٸ� �ϳ��� �Լ��� �� �κб��� ����Ǿ� ����Ǵ� ���̴�.
// �Լ��� ��ȯ�� �����ϴ� ���� �����ϴ�.
// �� ���� �߿��� ����� return�� �����ϸ� �Լ��� ������ ����Ǿ� �Լ��� ȣ���Ͽ��� �κ����� ���ư���.
int return_func() {
	printf("�� ����ȴ� \n");
	return 0;
	printf("�� �ȵ� �Ф�\n");
}

// ��ȯ��
int ret() { return 1000; }

int main() {
	printf("�Լ��� �ҷ����� : ");
	// ������ �Լ��� ȣ��(call)�ϴ� �κ�.
	// ()���Լ��� �̸��� ���ԵǴ� ���� �ƴϴ�. ������ ()�� �������ν� �����Ϸ����� '���� ���� �� ���� �Լ���'��� ���� �����ִ� ���̴�.
	// ���� print_hello;��� ���� �����Ϸ��� '��򰡿� print_hello'��� ������ �����߳� ��� �����Ѵ�.
	// �Լ��� ȣ��Ǹ� ���α׷��� �Լ��� ������ �����ϰ� �ٽ� ���� ����Ƿ��� �κ����� ���ƿ´�.
	print_hello();	

	printf("�� �θ���? : ");
	print_hello();

	return_func();

	int a = ret();	// ȣ���̴� �׾ ������ �����, �Լ��� �׾ ���ϰ��� �����.
	printf("ret() �Լ��� ��ȯ�� : %d \n", a);
	return 0;
}