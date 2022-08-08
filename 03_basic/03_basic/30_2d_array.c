/*
	배열의 배열 
	int형 배열의 배열 :  배열의 각 원소가 int형의 배열인 것
	이러한 배열을 정의하기 위해선
	(배열의 타입) (배열의 이름)[][]; 으로 정의할 수 있다.
	int arr[3][2]; 는 배열의 각 원소 3개가 원소 2개를 가지는 int형 배열이고 이름은 arr이다를 의미한다.

	arr[m][n] : m x n개의 변수를 가지는 배열을 선언한 것이다.
	사실 메모리엔 모든 배열이 일차원 배열과 다름없이 들어간다. 그런데 왜 2차원 배열이라고 할까?
	=> [1] 2차원 배열이라고 하는 이유.

*/
#include <stdio.h>

int main() {
	// [1] 2차원 배열이라고 하는 이유
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	printf("arr 배열의 2 행 3 열의 수를 출력 : %d \n", arr[1][2]);
	printf("arr 배열의 1 행 2 열의 수를 출력 : %d \n", arr[0][1]);
	// 실제로는 2차원이나 1차원이나 메모리상에서 모두 연속적으로 쭈르륵 존재한다.


	int score[3][2];
	int i, j;

	for (i = 0; i < 3; i++)  // 총 3 명의 학생의 데이터를 받는다
	{
		for (j = 0; j < 2; j++) {
			if (j == 0) {
				printf("%d 번째 학생의 국어 점수 : ", i + 1);
				scanf("%d", &score[i][j]);
			}
			else if (j == 1) {
				printf("%d 번째 학생의 수학 점수 : ", i + 1);
				scanf("%d", &score[i][j]);
			}
			else {}
		}
	}

	for (i = 0; i < 3; i++) {
		printf("%d 번째 학생의 국어 점수 : %d, 수학 점수 : %d \n", i + 1,
			score[i][0], score[i][1]);
	}
	/*
		2차원 배열 정의하기
		int arr[2][3] = {1,2,3,4,5,6}; 이렇게 선언했다. 하지만 아래와 같이해도 괜찮다.
		int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

		int arr[] = {1,2,3,4}; 이렇게 배열을 정의할 수도 있다.
		이렇게 할 수 있는 이유는 컴파일러가 원소의 개수가 4개란느 것을 정확히 알기 때문에
		자동적으로 4를 넣어서 생각한다.

		하지만 int arr[];는 되지 않는다.
		그 이유는 배열의 크기는 임의로 정해지지 않기 때문이다.
		이렇게 배열을 정의한 경우 배열의 크기를 알 수 없다는 오류를 내뿜는다.

		이 아이디어를 2차원 배열에도 그대로 적용할 수 있다.
		int arr[][3] = {{4,5,6}, {7,8,9}};
		이렇게하면 자동으로 2를 채워 준다.

		int arr[][2] = {{1,2},{3,4},{5,6},{7}};
		이렇게 한 경우는 정의할 때 [][2]로 무조건 언소가 2인 1차원 배열들이 생기게 된다.
		따라서 마지막에 {7}을 한 것은 arr[3] = {1}이라해도 상관 없는 것처럼 {7,0} 처리가 된다.

		int arr[2][] = {{4,5,6}, {7,8,9}};
		이는 컴파일 하면 arr 첨자가 없고 이니셜라이저가 너무 많다는 오류가 난다.
		C에서는 다차원 배열의 경우 맨 앞의 크기를 제외한 나머지 크기들을 정확히 지정해줘야 오류가 발생하지 않는다.

		[3차원 배열, 그 이후 차원의 배열들]
		3차원 배열은 []를 3개 사용해서 하면 된다.
		예를 들어서 int brr[2][3][4]; 이다.

		이는 2차원과 달리 평면이 아니라 상상하기 조금 어려운데
		int arr[2][3]이라는 것이 4개의 층으로 쌓여있다고 생각하면 된다.

		그리고 이러한 것은 n차원으로 계속 이어나갈 수 있다.

	*/

}