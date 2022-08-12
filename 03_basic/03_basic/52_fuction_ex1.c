/*
	����ڷ� ���� 5 ���� �л��� ����, ����, ���� ������ �Է� �޾Ƽ� 
	����� ���� ���� ��� ���� ����� ���� ���� ������� ���ĵǾ� ����ϵ��� �ϼ���. 
	Ư��, ����� �������� 
	��� �̻��� ��� ������ '�հ�', �ƴ� ����� '���հ�' �� ����ϰ� �غ����� (���̵� : ��߾).
*/
#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>

void average_of_person(double* avg_of_person, int(*people)[3], int people_row);
double average_of_people(double avg_of_person[], int size);
void sort_by_avg(double* avg_of_person, int(*people)[3], int people_row);
void swap_rows(int people[5][3], int row1, int row2);
void swap(double* p1, double* p2);

int main() {
	int people[5][3];
	double avg_of_person[5];
	for (int i = 0; i < 5; i++) {
		printf("%d ��° �л��� ���� �Է� : ", i + 1);
		for (int j = 0; j < 3; j++) {
			scanf("%d", &people[i][j]);
		}
	}

	average_of_person(avg_of_person, people, 5); // avg�� �� ����
	double people_avg = average_of_people(avg_of_person, 5); // ��հ� ����
	printf("\n ��ü ��� : %.2f \n", people_avg);
	for(int i = 0; i < 5; i++) {
		printf("%d ���� �л��� ��� : %.2f \n", i + 1, avg_of_person[i]);
	}
	printf("\n");

	sort_by_avg(avg_of_person, people, 5);
	for (int i = 0; i < 5; i++) {
		if (avg_of_person[i] >= people_avg) {
			for (int j = 0; j < 3; j++) {
				printf("%d ", people[i][j]);
			}
			printf("�հ�\n");
		}
		else {
			for (int j = 0; j < 3; j++) {
				printf("%d ", people[i][j]);
			}
			printf("���հ�\n");
		}
	}


	return 0;
}

void average_of_person(double* avg_of_person, int(*people)[3], int people_row) {
	for (int i = 0; i < people_row; i++) {
		int temp_sum = 0;
		for (int j = 0; j < 3; j++) {
			temp_sum += people[i][j];
		}
		avg_of_person[i] = temp_sum / 3;
	}
}

double average_of_people(double avg_of_person[], int size) {
	double result = 0;
	for (int i = 0; i < size; i++) {
		result += avg_of_person[i];
	}
	return result / size;
}

void sort_by_avg(double* avg_of_person, int people[5][3], int people_row) {
	// ��������
	for (int i = 0; i < people_row - 1; i++) {
		for (int j = i + 1; j < people_row; j++) {
			if (avg_of_person[i] < avg_of_person[j]) {
				swap(&avg_of_person[i], &avg_of_person[j]);
				swap_rows(people, i, j);
			}
		}
	}
}

void swap_rows(int people[5][3], int row1, int row2) {
	int tmp = 0;
	for (int i = 0; i < 3; i++) {
		tmp = people[row1][i];
		people[row1][i] = people[row2][i];
		people[row2][i] = tmp;
	}
}


void swap(double* p1, double* p2) {
	double tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

/*
	���� ���������� �����ϱ� ���� Bubble Sort
	( 5 1 4 2 8 ) -> (1 5 4 2 8 )
	( 1 5 4 2 8) -> (1 4 5 2 8)
	(1 4 5 2 8) -> (1 4 2 5 8)
	(1 4 2 5 8) -> (1 4 2 5 8)
	�ٽ� index 2�� �ڸ����� �� ����
	(1 4 2 5 8) -> (1 2 4 5 8)
	(1 2 4 5 8) -> (1 2 4 5 8)
	(1 2 4 5 8) -> (1 2 4 5 8)
	�ٽ� index 3�� �ڸ����� �� ����
	(1 2 4 5 8) -> (1 2 4 5 8)
	(1 2 4 5 8) -> (1 2 4 5 8)
	index 4�� �ڸ� ���� �� ����
	(1 2 4 5 8) -> (1 2 4 5 8)

	�̷��� Bubble_sort �Լ��� ����� ���ؼ� ��� �ؾ��ұ�?
	Bubbule_sort(int* arr, int num_element);
	swap(double *pele); // pele�� ����Ű�� ���ҿ� �� ���� ���Ҹ� �ٲ��ִ� �Լ�

	void Bubble_sort(int *arr, int num_element){
	
	}
	void swap(double *pele){
		double temp = *pele;
		*pele = *(pele+1);
		*(pele+1) = temp;
	}
*/