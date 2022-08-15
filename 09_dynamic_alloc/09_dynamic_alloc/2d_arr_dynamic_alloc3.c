/*
	진짜 2차원 배열 할당하기

	애석하게도 이 방법은 VS에선 작동하지 않는다.
	VS의 C 컴파일러가 VLA를 지원하지 않기 때문이다.
	하지만 GCC나 Clang같은 컴파일러에선 사용가능한 방법이다.

	참고로 VLA는 C99 표준에 들어갔지만, VS의 C 컴파일러는 C90을 사용하고 있다.

	====
	앞서 보았던 방식으론 진짜 2차원 배열처럼 메모리에 연속적으로 존재하는 배열을 만들 수 없다.
	왜냐하면 1차원 배열들을 쭈르륵 계속 할당하면서 메모리 여기저기에 퍼져서 만들어질 것이기 때문이다.

	따라서 메모리에 연속적으로 존재하는 진짜 2차원 배열을 만들기 위해선
	반드시 malloc을 통해 해당 크기의 공간을 할당해야 한다.

	예를 들어 int arr[height][width];와 같이 생긴 배열을 할당한다고 하자.
	이 경우 필요한 메모리의 크기는 height*width*sizeof(int)이다.
	이렇게 메모리를 할당했으면, 이제 해당 메모리를 2차원 배열이라고 생각해라! 라고 컴파일러에게 알려줘야한다.
	따라서 이 경우 해당 메모리 주소값으로 2차원 배열을 가리키는 포인터에 전달하면 된다.

	2차원 배열 포인터의 경우 포인터 연산을 수행하기 위해선 반드시 포인터 타입 안에 '행길이'가 들어가야한다.
	따라서 아래와 같이 2차원 배열 포인터 arr을 정의할 수 있다.

	int (*arr)[width] = (int(*)[width])malloc(height * width * sizeof(int));
	arr은 컴파일러 입장애허 행의 크기가 width인 2차원 배열을 가리키는 구나! 라고 생각할 수 있다.
	한 가지 주의해야할 점은 arr을 정의할 때 반드시 width에 실제 배열의 넓이 값이 들어간 후 정의해야한다.

	예를 들어서
	int width;
	int (*arr)[width] = (int (*) [width])malloc(height * width * sizeof(int);
	scanf("%d", &width);
	를 하게되면 arr이 제대로 2차원 배열을 참조할 수 없다. 
	
	int width;
	scanf("%d", &width);
	int (*arr)[width] = (int (*) [width])malloc(height * width * sizeof(int);
	반드시 이와 같이 width에 실제 2차원 배열의 행 길이가 들어간 후에 배열 포인터를 선언해야한다.

*/
#include <stdio.h>
#include <stdlib.h>

void print_array(int width, int(*arr)[width], int height);
int main() {
	int width, height;
	printf("배열 행 크기 : ");
	scanf("%d", &width);
	printf("배열 열 크기 : ");
	scanf("%d", &height);

	int(*arr)[width] = (int(*)[width])malloc(height * width * sizeof(int));
	for (int i = 0; i < height; i++) {
		for (int j = 0; i < width; j++) {
			int data;
			scanf("%d", &data);
			arr[i][j] = data;
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	free(arr); // arr의 모든 데이터가 메모리에 연속적으로 있어 free역시 arr에 대해 딱 한 번만 수행하면 된다.

	return 0;
}

void print_array(int(*arr)[width], int width, int height) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	/*
		주의할 점은 '배열 포인터'를 다른 함수에 인자로 전달하고 싶을 때이다.
		이 함수처럼 할 경우 컴파일러가 배열의 정의인 int (*arr)[width] 을 보고 width가 뭔지 알 수 없다.
		그래서 아래와 같은 오류가 발생한다.
		error : 'width' undeclared here (not in a function)
			| void print_array(int (*arr)[width], int width, int height){

		
		해결책은 간단하다.
		컴파일러가 arr의 정의를 볼 때 width의 정체를 알 수 있도록
		, width가 arr의 정의 앞으로 오도록 순서를 바꿔주면 된다.
		void print_array(int width, int(*arr)[width], int height); 이런 식으로 하면 된다.
	*/
}

void print_array(int width, int(*arr)[width], int height) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
