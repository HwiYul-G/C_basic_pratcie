#include <stdio.h>

int main() {
	int guess = 5; // �츮�� �Ҽ����� �Ǻ��ϰ� �ִ� �� 
	int prime[1000];

	int index = 1; // for�� ����

	prime[0] = 2;
	prime[1] = 3;
	for (;;) {
		int ok = 0; // ó�� �� �Ҽ��� Ư���� ���� ���
		for (int i = 0; i <= index; i++) {
			// guess ������ ��� �Ҽ���� �������� �۾�.
			// index �� (�迭�� ����� �Ҽ��� ���� -1 )�ε�, prime[i]�� �����ϹǷ� �迭�� ��� �Ҽ���� ������
			if (guess % prime[i] != 0) {
				// ���� guess�� prime[i]�� �������� ������ ok�� 1 ������Ų��.
				ok++;
			}
			else {
				// ���� �������� �Ҽ��� �ƴϹǷ� break�� ���� for loop�� ������.
				break;
			}
		}
		// ���� ok�� prime �迭�� ����� �Ҽ��� ���� �� index+1�� ���ٸ�
		// �ڱ� �ڽ� �̸��� ��� �Ҽ���ε� �� ���� �������ٴ� ���̹Ƿ� �Ҽ��̴�.
		// �̶� �����ؾ� �� ���� 1���� ���� �˻��� ������ ok�� 0���� ���µǾ�� �Ѵ�. �׷��� ��Ȯ�� ����� ���� �� �ִ�.
		if (ok == (index + 1)) {
			index++;
			prime[index] = guess;
			printf("�Ҽ� : %d \n", prime[index]);
			if (index == 999) break;
		}
		guess += 2;
	}

	return 0;
}