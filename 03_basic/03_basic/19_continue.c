#include <stdio.h>

/*
	continue���� break���� ��������� �ϴ� ���� ������ �ٸ���.
	continume�� break�� �޸� for���� ���������� ���� �ƴ϶� �׳� pass ���ش�.

	break�� �Ʒ��� ��� ������ �����ϰ� loop�� ���������µ� continue�� �ٽ� ���� ���˺η� �����Ѵ�.

*/

// 5�� ����� ������ ���� ���
int main() {
	for (int i = 0; i < 100; i++) {
		if (i % 5 == 0) continue;
		printf("%d ", i);
	}

	return 0;
}