#include<stdio.h>
#define square(x) x*x

int main() {
	printf("square(3) : %d \n", square(3));
	return 0;
}
/*
	��ũ�� �Լ��� �����ϴ� ���
	#define �Լ� �̸�(����) ġȯ�� ��

	#define square(x) x*x
	�� ������ �ǹ̴� square��� �̸��� ��ũ�� �Լ��̰� ���ڷ� x�� x*x�� ġȯ�Ѵٴ� �ǹ��̴�.
	#define���� �տ��� ��� ��ó�� '��� ���� �ٸ� ������ ġȯ���ִ� ��'�̶�� �����.
	���⼭�� �� ������ �����ϴ�. square(x)�κ��� x*x�� ġȯ�� �ش�.

	���� printf("square(3) : %d \n", square(3));��� ������
	printf("square(3) : %d \n", 3 * 3); �� ��Ȯ�� �����ϰ� �ȴ�.
	
	���� ���� ���� '��ũ�� �Լ�'��� �θ��� ������ ���� �ϴ� ���� �Լ��� ����ϱ� �����̴�.
	���� int square(x)��� �Լ��� ���� x*x�� �����ϰ� �Ͽ��ٸ� ���״�� 3*3�� ���ϵ� ���̴�.
	������ �� ��ũ�� �Լ��� ��¥ �Լ��� ������ ���̰� �ִ�.

	printf("square(3) : %d \n", square(3));
	�츮�� �����Ϸ��� �����ϰ� �� ������ ��� �ؼ����� ����.
	int square(int x)��� ���� �Լ��� �ִٸ�, square��� �Լ��� ȣ���ؼ� ���ڿ� 3�� �����ϰ� 9�� �����Ѵٰ� �ȴ�.
	������ ��ũ�� �Լ��� �� ������ ������ �Ǳ� ����
	printf("square(3) : %d \n", 3 * 3); ���� �ٲ������.

	���⼭ �߿��� ���� '������ �Ǳ� ����' �κп� �ִ�.
	�ٽ� ���� ��ǻ�ʹ� �Լ��� ȣ���ϰ� ���ñ� ���ñ� �ϴ� �κ� ���� �׳� 3*3�� ����Ѵ�.
	�̴� �ռ� ���Ҷ� #define���� ���� ġȯ�� �����ϴ�.
*/