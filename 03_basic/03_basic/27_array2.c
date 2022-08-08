#include <stdio.h>

int main() {
	int total;
	printf("전체 학생 수 : ");
	scanf("%d", &total);
	int arr[total]; // Error : 배열의 크기를 변수를 통해 정의할 수 없게 규정함 -> 이를 원한다면 동적할당을 이용해야함
	//배열의 크기를 변수를 통해 정의할 수 없는 이유는 처음에 컴파일러가 배열을 처리할 때 메모리 상에 공간을 잡아야 하는데
	// 이때, 잡아야하는 공간의 크기가 반드시 상수로 주어져야 하기 때문이다.
	int ave = 0;

	for (int i = 0; i < total; i++) {
		printf("%d 번째 학생의 성적은? ", i + 1);
		scanf("%d", &arr[i]);
	}

	ave = ave / total;
	printf("전체 학생의 평균은 : %d \n", ave);

	for (int i = 0; i < total; i++){
		printf("학생 %d : ", i + 1);
		if (arr[i] >= ave)
			printf("합격 \n");
		else
			printf("불합격 \n");
	}

	return 0;
}