/*
	malloc은 어디에 할당할까?

	stack	// 메모리 높은 주소
	heap
	data seg(정적, 전역 변수)
	read only data
	code

	이러한 메모리 구조에서 stack, data seg, read only data 영역은 malloc 함수가
	절대 건드릴 수 없는 부분이다.
	이 부분의 크기는 반드시 컴파일 때 100% 정해져야 한다.

	하지만 heap의 경우 다르다.
	heap 부분은 사용자가 자유롭게 할당하거나 해제할 수도 있다.
	따라서 malloc 함수도 이 heap 영역을 이용한다.

	힙은 할당과 해제가 자유로운 만큼 제대로 사용해야한다.
	만일 힙에 할당했는데 해제하지 않으면 공가니 낭비된다.
	다른 부분은 컴퓨터가 알아서 처리하므로 문제가 발생할 여지가 적지만
	힙은 인간이 다루기 때문에 철저히 관리해야한다.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int student;
	int input;
	int* score;
	int sum = 0;

	printf("학생의 수는? : ");
	scanf("%d", &student);

	score = (int*)malloc(student * sizeof(int));

	for (int i = 0; i < student; i++) {
		printf("학생 %d의 점수 : ", i);
		scanf("%d", &input);

		score[i] = input;
	}

	for (int i = 0; i < student; i++) {
		sum += score[i];
	}

	printf("전체 학생 평균 점수 : %d \n", sum / student);
	free(score);

	return 0;
}