#include <stdio.h>

int main() {
	int total;
	printf("��ü �л� �� : ");
	scanf("%d", &total);
	int arr[total]; // Error : �迭�� ũ�⸦ ������ ���� ������ �� ���� ������ -> �̸� ���Ѵٸ� �����Ҵ��� �̿��ؾ���
	//�迭�� ũ�⸦ ������ ���� ������ �� ���� ������ ó���� �����Ϸ��� �迭�� ó���� �� �޸� �� ������ ��ƾ� �ϴµ�
	// �̶�, ��ƾ��ϴ� ������ ũ�Ⱑ �ݵ�� ����� �־����� �ϱ� �����̴�.
	int ave = 0;

	for (int i = 0; i < total; i++) {
		printf("%d ��° �л��� ������? ", i + 1);
		scanf("%d", &arr[i]);
	}

	ave = ave / total;
	printf("��ü �л��� ����� : %d \n", ave);

	for (int i = 0; i < total; i++){
		printf("�л� %d : ", i + 1);
		if (arr[i] >= ave)
			printf("�հ� \n");
		else
			printf("���հ� \n");
	}

	return 0;
}