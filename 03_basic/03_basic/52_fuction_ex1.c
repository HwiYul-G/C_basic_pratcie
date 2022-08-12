/*
	사용자로 부터 5 명의 학생의 수학, 국어, 영어 점수를 입력 받아서 
	평균이 가장 높은 사람 부터 평균이 가장 낮은 사람까지 정렬되어 출력하도록 하세요. 
	특히, 평균을 기준으로 
	평균 이상인 사람 옆에는 '합격', 아닌 사람은 '불합격' 을 출력하게 해보세요 (난이도 : 中上).
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
		printf("%d 번째 학생의 점수 입력 : ", i + 1);
		for (int j = 0; j < 3; j++) {
			scanf("%d", &people[i][j]);
		}
	}

	average_of_person(avg_of_person, people, 5); // avg에 값 넣음
	double people_avg = average_of_people(avg_of_person, 5); // 평균값 구함
	printf("\n 전체 평균 : %.2f \n", people_avg);
	for(int i = 0; i < 5; i++) {
		printf("%d 번재 학생의 평균 : %.2f \n", i + 1, avg_of_person[i]);
	}
	printf("\n");

	sort_by_avg(avg_of_person, people, 5);
	for (int i = 0; i < 5; i++) {
		if (avg_of_person[i] >= people_avg) {
			for (int j = 0; j < 3; j++) {
				printf("%d ", people[i][j]);
			}
			printf("합격\n");
		}
		else {
			for (int j = 0; j < 3; j++) {
				printf("%d ", people[i][j]);
			}
			printf("불합격\n");
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
	// 선택정렬
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
	가장 직관적으로 이해하기 쉬운 Bubble Sort
	( 5 1 4 2 8 ) -> (1 5 4 2 8 )
	( 1 5 4 2 8) -> (1 4 5 2 8)
	(1 4 5 2 8) -> (1 4 2 5 8)
	(1 4 2 5 8) -> (1 4 2 5 8)
	다시 index 2번 자리부터 비교 시작
	(1 4 2 5 8) -> (1 2 4 5 8)
	(1 2 4 5 8) -> (1 2 4 5 8)
	(1 2 4 5 8) -> (1 2 4 5 8)
	다시 index 3번 자리부터 비교 시작
	(1 2 4 5 8) -> (1 2 4 5 8)
	(1 2 4 5 8) -> (1 2 4 5 8)
	index 4번 자리 부터 비교 시작
	(1 2 4 5 8) -> (1 2 4 5 8)

	이러한 Bubble_sort 함수를 만들기 위해선 어떻게 해야할까?
	Bubbule_sort(int* arr, int num_element);
	swap(double *pele); // pele가 가리키는 원소와 그 다음 원소를 바꿔주는 함수

	void Bubble_sort(int *arr, int num_element){
	
	}
	void swap(double *pele){
		double temp = *pele;
		*pele = *(pele+1);
		*(pele+1) = temp;
	}
*/