#include <stdio.h>
#include <stdlib.h>

void get_average(int num_student, int num_subject, int(*scores)[num_student]);

int main(int argc, char** argv) {
	int subject, students;

	printf("과목 수 : ");
	scanf("%d", &students);

	printf("학생의 수 : ");
	scanf("%d", &students);

	int(*scores)[studnets] =
		(int(*)[studnets])malloc(sizeof(int) * students * subject);

	for (int i = 0; i < subject; i++) {
		printf("과목 %d의 점수 -------- \n", i);
		
		for (int j = 0; j < students; j++) {
			printf("학생 %d의 점수 입력 : ", j);
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
		printf("과목 %d 평균 점수 : %d \n", i, sum / num_student);
	}
}
/*
	2차원 배열을 동적할당 할 때 어떤 방식을 사용하는 것이 좋은가?

	되도록이면 연속된 공간에 2차원 배열을 할당하는 방법을 사용하는 것이 좋다.
	- malloc은 상당히 느린 함수들 중 하나이다. 따라서 malloc의 호출 횟수를 최소한으로 하는 것이 좋다.
	  따라서 배열의 높이만큼 malloc을 호출해야하는 전자의 방법은 height가 커질 수록 상당히 느려진다.
	- 전자의 ㅂ아법으로 메모리 원소에 접근하기 위해선 2 단계의 메모리 접근이 필요하다.
	  예를 들어 arr[3][2]의 경우 먼저 arr[3]을 읽은 뒤에, 해당 주소에 가서 다시 [2] 연산을 해야한다.
	  반면 후자의 경우 컴파일러가 다이렉트로 메모리 arr[3][2]에 접근할 수 있다.
	- 메모리가 연속적으로 있을 경우 접근이 훨씬 빠르다.

	물론 후자의 방식의 경우 배열 포인터를 사용하기 때문에 배열의 선언이 좀 길어지는 면이 있다.
	@ 배열 포인터 : 배열을 가리키는 하나의 포인터로 "배열만 가리킬 수 있는 하나의 포인터"이다.
		int (*arr)[N] 같은 방식으로 선언한다. 이는 int 타입의 인덱스 N개를 가지고 있는 배열을 가리키는 포인터이다.
*/