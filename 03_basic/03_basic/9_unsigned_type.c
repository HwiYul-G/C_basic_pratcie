#include <stdio.h>

int main() {
	unsigned int b = -1;
	printf("b�� ����ִ� ���� unsigned int�� �ؼ� ���� �� �� : %u \n", b);

	b = 4294967295;
	printf("b : %u \n", b);
	b++;
	printf("b : %u \n", b);

	return 0;
}

/*
	unsigned int�� ��� ������ ���� 0 ~ 4294967295������ ���� ǥ���� �� �ִ�.
	unsigned int ���� intó�� 32bit�� �����Ѵ�. 
	unsigned int�� ��� int ������ 2�� ���� ǥ���� ���� ������ �ؼ��� ���� ������ �����Ѵ�.

	unsigned int�� -1�� �����ϸ� -1�� 0xFFFF FFFF�� ǥ���ǹǷ� ���� ū ����  ����.
	%u�� unsigned Ÿ������ �ؼ��϶�� �ǹ��̴�.

	���� unsigned int �󿡼��� �����÷ο찡 �߻��Ѵ�. b�� �ִ밪�� +1�� �߰��Ѵٸ� 0�� ������ �ȴ�.
*/