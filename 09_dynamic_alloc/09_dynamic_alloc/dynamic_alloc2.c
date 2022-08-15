/*
	malloc�� ��� �Ҵ��ұ�?

	stack	// �޸� ���� �ּ�
	heap
	data seg(����, ���� ����)
	read only data
	code

	�̷��� �޸� �������� stack, data seg, read only data ������ malloc �Լ���
	���� �ǵ帱 �� ���� �κ��̴�.
	�� �κ��� ũ��� �ݵ�� ������ �� 100% �������� �Ѵ�.

	������ heap�� ��� �ٸ���.
	heap �κ��� ����ڰ� �����Ӱ� �Ҵ��ϰų� ������ ���� �ִ�.
	���� malloc �Լ��� �� heap ������ �̿��Ѵ�.

	���� �Ҵ�� ������ �����ο� ��ŭ ����� ����ؾ��Ѵ�.
	���� ���� �Ҵ��ߴµ� �������� ������ ������ ����ȴ�.
	�ٸ� �κ��� ��ǻ�Ͱ� �˾Ƽ� ó���ϹǷ� ������ �߻��� ������ ������
	���� �ΰ��� �ٷ�� ������ ö���� �����ؾ��Ѵ�.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int student;
	int input;
	int* score;
	int sum = 0;

	printf("�л��� ����? : ");
	scanf("%d", &student);

	score = (int*)malloc(student * sizeof(int));

	for (int i = 0; i < student; i++) {
		printf("�л� %d�� ���� : ", i);
		scanf("%d", &input);

		score[i] = input;
	}

	for (int i = 0; i < student; i++) {
		sum += score[i];
	}

	printf("��ü �л� ��� ���� : %d \n", sum / student);
	free(score);

	return 0;
}