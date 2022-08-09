/*
	��� �����͵��� �޸� ���� Ư�� ������ ����Ǿ� �ִ�.
	���Ǹ� ���� Ư���� ������ '��'�̶�� ����. �� �濡�� �����͵��� ���� �ȴ�.

	�� ���� ũ��� ���� 1byte�� ���� �ȴ�. ���� �츮�� 4byte¥�� int�� ������ �����ϸ� �޸� �� 4ĭ�� �����ϰ� �ȴ�.

	���α׷� �۵� �� ��ǻ�ʹ� ���� ��鿡 �ִ� �����͸� �ʿ�� �ϰ� �ȴ�.
	����, � �濡�� �����͸� ������ �� �����ϱ� ���� �� �濡 ������ �ּ�(address)�� �ٿ��ش�.

	���� ��� int a = 123; �̶�� ���� a�� �����ߴٸ�, Ư���� �濡 4ĭ�� �����ϴ� 123�̶� ���� ���� ���� a�� ���ǵȴ�.
	�׸��� �� ���� �����ּҸ� ���Ƿ� 0x152839��� ����. (���� �ּ� �������� 4byte�� �����ϴ� ���̴�)

	�׸��� ���� a = 10�̶�� �ϸ�
	0x152839��ġ���� ���� 4byte�� ������ �ִ� �����͸� 10���� �ٲ۴�.

	���� ��ǻ�Ͱ� 32bit �ü����� ��ǻ�͵��� �ּҰ��� ũ�Ⱑ 32bit(�� 4byte)�� ��Ÿ������.
	= �ּҰ��� 0x0000 0000 ~ 0x FFFF FFFF������ ���� ������.
	(������ ���� 64bit �ü���� ����Ѵ�.)

	���⼭ 32 bit�� ����� �� �ִ� �ּҰ��� �������� 2^32 byte, 
	�� RAM�� �ִ� 4GB���� �ۿ� ����� �� ���ٴ� ����� �� �� �ִ�.

	�׷��� C�� ���� ����� ���� ������ '������'��� ���� �������.
	�����ʹ� int�� char ������� �ٸ� ���� ���� �ƴϴ�. �����͵� '����'�̴�.
	int�� ������ ���� ������, flaot�� ������ �Ǽ� �����͸� �����ߴ� ��ó��, �����͵� Ư���� �����͸� �����ϴ� �����̴�.

	�����ʹ� �����Ͱ� ����� �ּҰ��� �����ϴ� �����̴�.
	�� �κ��� �׳� �ܿ���! "�����ʹ� �����Ͱ� ����� (����)�ּҰ��� �����ϴ� ����"�̴�.

	������ ������ �� int�� charó�� type�� �ִ�. �׸��� �����Ϳ��� type�� �ִ�.
	�� ���� �����Ͱ� �޸� ���� int�� �������� �ּҰ��� �����ϴ� �����Ϳ� char �� �������� �ּ��� ���� �����ϴ� �����Ͱ� ���� �ٸ��ٴ� ���̴�.

	�׷��� �����ʹ� �ּҰ��� �����ϴ� �Ű�, �츮�� �ַ� ����ϴ� ��ǻ�ʹ� �ּҰ��� 64bit = 8Byte�̴�.
	[1]�׷��� �������� ũ��� ��� ������ �� �ƴѰ�? �׷��� �� �����ʹ� type�� �����°�?

	[ === &������ === ]
	�����Ͱ� ����� �ּҰ��� �����ϴ� ������ �����͸� �����Ͽ����� ���� ����־���ϴµ�
	�츮�� �������� �ּҰ��� ��� �˱�? �̴� �ٷ� &������ �����̴�.

	�׷��� &�� bit���� AND �����ڷ� �˰� �ִµ�??
	bit ������ ���� AND �������� ����� 2���� �ǿ����ڸ� �䱸�Ѵ�
	a&b; �� ������ a&�� �ȵȴ�.

	�׷��� �츮�� ���� ����� &�����ڴ� ���� �ǿ����ڰ� 1���� ����(unary) �������̴�.
	���� bit������ ���� AND �����ڿʹ� �ٸ��� �ؼ��ȴ�.
	���� &�����ڴ� �ǿ������� �ּҰ��� �ҷ��´�.

	���� ��� � ���� a�� �ּҰ��� �˰� �ʹٸ� &a�� ����ϸ� �ȴ�.

*/

#include<stdio.h>

int main() {
	int a;
	a = 2;

	printf("%p \n", &a); // ���ึ�� �ٸ� ����� ���δ�.
	// ���� ���忡�� &a(a�� �ּҰ�)�� %p(16���� ����)�� ����϶�� �����ߴ�.
	// �׷��� ������ ��µ� ����� 8byte(16������ 16�ڸ�)�� �ƴϴ�.
	// �ּ� ���� ������ 8byte�� ũ�� �� 16������ 16�ڸ��ε� �տ� 0�� �߷��� ��µ��� �ʴ´�.
	// ���� ������ ��µ� ���� 0x 7ffe 37d0 3104 ��� ���� 0�� �����Ǿ��� �� 0x 0000 7ffe 37d0 3104�� �ȴ�.

	//���� pointer�� ���� �־��
	int* p;
	p = &a;
	printf("������ p�� ����ִ� �� : %p \n", p); // 1)
	printf("int ���� a�� ����� �ּ� : %p \n", &a); // 2) : 1)�� ������ ����� ���� ���̴�.

	/*
		[ * ������]
		�����ʹ� �����Ͱ� �ִ� ���� �ּҰ��� �����ϴ� �����̴�.
		�̶� �����ʹ� �ּҰ��� �����ϴ� ������ ���� *�� �������ν� ���ǵǰ�, & �����ڷ� Ư�� �������� �޸𸮻� �ּҰ��� �˾ƿ� �� �ִ�.

		&�����ڰ� � �������� �ּҰ��� ��� �����ڶ��, �Ųٷ� �ּҰ����� �ش� �ּҰ��� �����Ǵ� �����͸� �������� �����ڰ� �ʿ��ϰ� �̰��� *�������̴�.

		a*b; // a�� b�� ���ϴ� ���� ������ (���� ������)
		a*; // ����
		*a; // ���� * ������.
		* �������� ������ "��(������)�� ������ ����� �ּҰ��� ��ġ�� �����ͷ� ��������!�̴�."
	*/
	int* p2;
	int a2;

	p2 = &a; // p2�� a2�� �ּҸ� ����
	a2 = 2;

	printf("a2 �� �� : %d \n", a2);
	printf("*p2 �� �� : %d \n", *p2); // p�� ����� �ּ�(���� a�� �ּ�)�� �ش��ϴ� ������, �� ���� a��ü�� �ǹ�

	// *�� ���õ� ������ �ϳ� �� ����
	int* p3;
	int a3;

	p3 = &a3;	// ������ ���� p3�� a3�� �ּҰ��� ��� ��
	*p3 = 3;	// p3�� ����� �ּҰ��� ��ġ�� �����͸� 3���� ��

	printf("a �� �� : %d \n", a3);
	printf("*p �� �� : %d \n", *p3);
	/*
		�����Ͷ�� �� ��ü�� �ǹ̸� �����غ���.
		int a = 3; �� ��, a�� 0x12A3BE72��� �����ּҸ� ������ 3�̶�� ���� ������ �ִ�.

		������ p��� ������ ox12A3B388�� �����ּҷ� ���� ��, int*p = &a; �� �ϸ�
		0x12A3B388�� �����ּҷ� �ϴ� ������ a�� ���� �ּ��� 0x12A3BE72�� ���� �ȴ�.

		�̷��� ������ p�� � ���� a�� �ּҰ��� ����Ǿ� �ִٸ�, ������ p�� ���� a�� ����Ų�ٶ�� ���Ѵ�.
		�׸��� �����͵� "�����Ͱ� ����� (����)�ּҰ��� �����ϴ� ����"�̹Ƿ�, �� �����̹Ƿ� �ڽ��� �ּҰ��� ������ Ư�� �޸� ������ �����Ѵ�.

		[�����ʹ� �� Ÿ���� ������?]
		�����ʹ� �ּҰ��� �����ϴµ� �� Ÿ���� �ʿ��ұ�?
		������ �ּҰ��� 32bit �ý��ۿ��� 8byte�̰� 64bit �ý��ۿ��� 8byte�ε� pointer��� Ÿ���� ����� �˵ɱ�?

		pointer��� Ÿ���� �ִٰ� �����ϰ� �Ʒ��� �ڵ带 ����.
		int a;
		pointer *p;
		p = &a;
		*p = 4;
		
		��ǻ�� ���忡�� ���� �ڵ带 ��� �ؼ��ұ�? ������ *p = 4; ���� ������ �ȴ�.
		������ p���� ������ ���� a�� ���� �ּ� ���� �� �ִ�. 
		���⼭ ������ a�� �޸𸮿��� �����ϴ� ��� �ּҵ��� ��ġ�� �� ���� �ƴ϶�, '�����ּ�'�� �� �ִٴ� ���̴�.
		����, *p ��� ���� �� ��ǻ�ʹ� �޸𸮿��� �󸶸�ŭ�� �о�� ���� �� ���� ����.

		���� int* p;�� �����Ѵٸ� ������ p�� int*��� ����� ���� �� �����ʹ� int �����͸� ����Ű�� ���� �˰� �ȴ�.
		���� �����ּҷκ��� ��Ȯ�� 4����Ʈ�� �о� ��� ���� �ٲٰ� �ȴ�.
	*/

	//Pointer�� �����̴�. => �����Ϳ� �� �ּҰ��� �ٲ� �� �ִ�.
	int a4;
	int b4;
	int* p4;

	p4 = &a4;
	*p4 = 2;
	p4 = &b4;
	*p4 = 4;

	printf("a4 : %d \n", a4); // ������ 2
	printf("b4 : %d \n", b4); // ������ 4


	return 0;
}