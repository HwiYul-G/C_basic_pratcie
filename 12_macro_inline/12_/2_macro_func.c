/* ��ũ�� �Լ�*/
#include <stdio.h>
#define square(x) x *x

int main(int argc, char** argv) {
	printf("square(3) : %d \n", square(3 + 1)); // 7

	return 0;
}
/*
	printf("square(3) : %d \n", square(3 + 1));
	�� ���忡�� �츮�� �ǵ��� 4*4�� ����ϴ� ���̿��� ���̴�.
	�׷��� 16�� �ƴ϶� ���� ������ ���� 7�� ���Դ�. 
	
	�� ������ ��ũ�δ� �ܼ��� "�� ġȯ�� ������."��� ���̴�

	��ó���⿡�� square(3+1)�� �Ʒ��� ���� ����ȴ�.
	printf("square(3) : %d \n", 3 + 1 * 3 + 1);
	�׷��� ���� 7�� ������ ���̴�. (������ �켱������ ����)

	�̸� �ذ��ϴ� ����� �ܼ��ϴ�
	#define square(x) x*x�� #define square(x) (x) * (x)�� �ٲٸ� �ȴ�.
*/