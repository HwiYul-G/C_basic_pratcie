/* ## �� ��� */
#include <stdio.h>
#define AddName(x, y) x##y

int main(int argc, char** argv) {
	int AddName(a, b);

	ab = 3;

	printf("%d \n", ab);	// 3

	return 0;
}
/*
	#�� ģ������ ##�� ���� ������ ����.
	#�̳� ##�̳� ��� '��ó���⹮'������ ����� �� �ִ�.
	�� #define������ ����� �� �ִٴ� ������ �˾Ƶθ� �ȴ�.

	##���� �Էµ� ���� �ϳ��� �����ִ� ������ �Ѵ�.

	#define AddName(x, y) x##y ������ x##y�� x�� �ִ� �Ͱ� y�� �ִ� ���� �ϳ��� �����ش�.
	���� int AddName(a,b); �̺κ��� ��ó���⿡ ���� int ab;�� ġȯ�ȴ�.

	���� �����Ϸ��� ab��� �̸��� ������ �����ϰ� �ǰ� �� �ڷ� �� ���� ���̴�.

	��ũ�� �Լ��� �������� ������ ���鵵 ������
	��ȣ�� ����� ���� �ʾ� ������ ���� ��� (�� ��� ������� ��ٷӴ�) �� �������� ����.
	�̷��� ������ �ذ��ϱ� ���� C������ �Ǵٸ� �ذ�å�� �����ߴµ� �̰��� inline(�ζ���)�Լ��̴�.
*/