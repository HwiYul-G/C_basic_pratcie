#include <stdio.h>
typedef struct SENSOR {
	/* ���� �ȵǸ� 0, �����Ǹ� 1 �̴�.*/
	int sensor_flag;
	int data;
} SENSOR;

int main() {
	volatile SENSOR* sensor;
	/* ���� �������� �ʴ� ���� ��� ���� ������ ����*/
	while (!(sensor->sensor_flag)) {
	}
	printf("Data : %d \n", sensor->data);
}
/*
	�̷��� ���� ���� �����Ϸ��� SENSOR�� ����Ű�� ������ Ÿ���� sensor��� ������ ���� ����ȭ�� �������� �ʴ´�.
	volatile�� �ǹ̴� '����������'�̴�.
	sensor�� volatile keyword�� �ٿ��� ���� sensor->sensor_flag�� ���� '���������� ���� �� �ֱ� ����'��
	�̿� ���� ����ȭ �۾��� �������� ����� �ǹ̰� �ȴ�.
	���� �����Ϸ��� �� �ҽ��� �ǹ� �״�� �������ϰ� �Ǿ� �츮�� ���ϴ� ����� ���� �� �ִ�.
*/