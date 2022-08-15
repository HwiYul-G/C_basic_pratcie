#include <stdio.h>
#include <stdlib.h>

void get_average(int num_student, int num_subject, int(*scores)[num_student]);

int main(int argc, char** argv) {
	int subject, students;

	printf("���� �� : ");
	scanf("%d", &students);

	printf("�л��� �� : ");
	scanf("%d", &students);

	int(*scores)[studnets] =
		(int(*)[studnets])malloc(sizeof(int) * students * subject);

	for (int i = 0; i < subject; i++) {
		printf("���� %d�� ���� -------- \n", i);
		
		for (int j = 0; j < students; j++) {
			printf("�л� %d�� ���� �Է� : ", j);
			scanf("%d", &scores[i][j]);
		}
	}

	get_average(students, subject, scores);
	free(scores);

	return 0;
}

void get_average(int num_studnet, int num_subject, int(*scores)[num_studnet]) {
	int sum = 0;
	for (i = 0; i < num_subject; i++) {
		sum = 0;
		for (j = 0; j < num_student; j++) {
			sum += arr[i][j];
		}
		printf("���� %d ��� ���� : %d \n", i, sum / num_student);
	}
}
/*
	2���� �迭�� �����Ҵ� �� �� � ����� ����ϴ� ���� ������?

	�ǵ����̸� ���ӵ� ������ 2���� �迭�� �Ҵ��ϴ� ����� ����ϴ� ���� ����.
	- malloc�� ����� ���� �Լ��� �� �ϳ��̴�. ���� malloc�� ȣ�� Ƚ���� �ּ������� �ϴ� ���� ����.
	  ���� �迭�� ���̸�ŭ malloc�� ȣ���ؾ��ϴ� ������ ����� height�� Ŀ�� ���� ����� ��������.
	- ������ ���ƹ����� �޸� ���ҿ� �����ϱ� ���ؼ� 2 �ܰ��� �޸� ������ �ʿ��ϴ�.
	  ���� ��� arr[3][2]�� ��� ���� arr[3]�� ���� �ڿ�, �ش� �ּҿ� ���� �ٽ� [2] ������ �ؾ��Ѵ�.
	  �ݸ� ������ ��� �����Ϸ��� ���̷�Ʈ�� �޸� arr[3][2]�� ������ �� �ִ�.
	- �޸𸮰� ���������� ���� ��� ������ �ξ� ������.

	���� ������ ����� ��� �迭 �����͸� ����ϱ� ������ �迭�� ������ �� ������� ���� �ִ�.
	@ �迭 ������ : �迭�� ����Ű�� �ϳ��� �����ͷ� "�迭�� ����ų �� �ִ� �ϳ��� ������"�̴�.
		int (*arr)[N] ���� ������� �����Ѵ�. �̴� int Ÿ���� �ε��� N���� ������ �ִ� �迭�� ����Ű�� �������̴�.
*/