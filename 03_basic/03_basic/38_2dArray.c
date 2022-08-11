/*
	int a[2][3];
	2차원 배열은 1차원 배열이 여러 개 있다고 생각하면 된다.
	위의 a라는 이름의 배열은 int a[3]짜리 배열 2개가 메모리에 연속적으로 존재한다.
	
	메모리에 2차원으로 존재하는 게 아니다.
	컴퓨터 메모리 구조는 1차원 이므로 항상 선형으로 퍼져있다.
	0x1230	a[0][0]
	0x1234	a[0][1]
	0x1238	a[0][2]
	0x124C	a[1][0]
	0x1240	a[1][1]
	0x1244	a[1][2]
	실제로 원소의 주소값을 찍어보면 메모리 상에 위와 같이 나타난다.

	그럼 2차원 배열에서 arr[0]와 같은 얘들은 무엇을 의미할까?
*/
#include <stdio.h>
int main() {
	int arr[2][3];

	printf("arr[0] : %p \n", arr[0]);	// 0x 7ffd a354 e530 
	printf("&arr[0][0] : %p \n", &arr[0][0]); // 0x 7ffd a354 e530 

	printf("arr[1] : %p \n", arr[1]);	// 0x 7ffd a354 e53c
	printf("&arr[1][0] : %p \n", &arr[1][0]); // 0x 7ffd a354 e53c

	/*
		arr[0]의 값이 arr[0][0]의 주소값과 같고
		arr[1]의 값이 arr[1][0]의 주소값과 같다.
		이를 통해 알 수 있는 사실은 
			"1차원 배열과 마찬가지로 sizeof나 주소값연산자(&)와 사용되지 않을 경우,
			arr[0]은 arr[0][0]을 가리키는 포인터로 암묵적으로 타입 변환되고,
			arr[1]은 arr[1][0]을 가리키는 포인터로 타입 변횐돤다."
		는 것이다.

		1차원 배열 int arr[]에서 arr과 &arr[0]는 그 자체로 완전히 다른 것이였던 것처럼
		2차원 배열 int arr[][]에서 arr[0]와 &arr[0][0]와 다르다.
		다만 암묵적으로 타입 변환 시에 같은 것으로 변할 뿐이다.

		따라서 sizeof 를 사용하였을 경우 2차원 배열의 열의 개수를 계산할 수 있다.
	*/
	int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
	printf("전체 크기 : %d \n", sizeof(arr));	// 4byte x 6 = 24byte
	printf("총 열의 개수 : %d \n", sizeof(arr[0]) / sizeof(arr[0][0]));	// (4byte*3) / (4byte*1)
	printf("총 행의 개수 : %d \n", sizeof(arr) / sizeof(arr[0]));	// (4byte * 3 *2) / (4byte*3)
	/*
		sizeof(arr[0])를 하면 0번째 행의 길이(총 열의 개수)가 나온다.
		sizeof 연산자의 경우 포인터로 타입 변환을 시키지 않기 때문에 
			sizeof(arr[0])는 마치 sizeof에 1차원 배열을 전달한 것과 같다.

		그리고 sizeof(arr[0][0])을 하게 된다면 int의 크기인 4를 리턴하게 되어서 총 열의 개수를 알 수 있게 된다.

		이때 arr[0][0]의 형이 int이므로 arr[0]은 int*형이 되겠고, 마찬가지로 arr[1]도 int*형이 된다.

		그렇다면 만일 2차원 배열의 이름을 포인터에 전달하기 위해서는 해당 포인터의 타입이 뭘까?
		arr[0]는 int*가 보관할 수 있으니, arr은 int**이 보관할 수 있을까?
		=> 그런데 답은 NO이다.
	*/

	/*
		== 포인터 형(type)을 결정짓는 2가지 요소 ==
		포인터 형을 결정짓는 2가지 요소를 이야기하기 전에, 
			위에서 배열의 이름이 왜 int**형이 될 수 없는 지에 대해 먼저 이야기 해보자.
		만일 int**형이 될 수 있다면 맨 위에서 했던 것처럼 int**형 포인터가 배열의 이름을 가리킨다면 배열의 원소에 자유롭게 접근할 수 있어야할 것이다.

	*/
	int arr[2][3] = { {1,2,3},{4,5,6} };
	int** parr = arr;	// warning : assignment to 'int **' from incompatible pointer type ' int(*)[3]' 

	printf("arr[1][1] : %d \n", arr[1][1]);	// 5
	printf("parr[1][1] : %d \n", parr[1][1]); // [1] 8834 segmentation fault (core dumped)

	/*
		int arr[3]; 이라 했는데 arr[10] = 2;와 같이 허가되지 않은 공간에 접근하기만 해도 위와 같은 오류가 발생한다고 했다.

		위의 예제도 마찬가지이다. parr[1][1]에서 이상한 메모리 공간에 접근해서 발생한 것이다.
		왜 이상한 공간에 접근했을까?

		먼저 int arr[10] 이라는 배열에서 x번 째 원소의 주소를 알아내는 방법을 생각해보자.
		만일 배열의 시작주소를 arr이라 한다면 arr[x]의 주소값은 arr + 4x와 같이 나타낼 수 있다.

		int arr[a][b]는 int arr[b]짜리 배열이 메모리에 a가 존재하는 것이라 생각하면 된다.
		따라서 arr[x][0]의 주소값은 x번째 int arr[b]짜리 배열이 된다.
		그렇다면 arr[x][0]의 주소값은 arr + 4bx가 된다.
		왜냐하면 arr[b] 배열의 크기는 4b이니까 x번째 배열의 시작 주소는 4bx가 되기 때문이다.

		따라서 arr[x][y]의 시작 주소값은
		arr + 4bx + 4y가 된다.

		여기서 중요한 점은 arr[x][y]의 주소값을 정확히 계산하기 위해서는 x,y뿐만아니라 b가 뭔지 알아야한다.

		따라서 2차원 배열을 가리키는 포인터를 통해서 원소들을 정확히 접근하기 위해서는;
			1) 가리키는 원소의 크기(여기서 4)
			2) b의 값
		위의 2가지 정보가 포인터의 타입에 명시되어 있어야지 컴파일러가 원소를 올바르게 접근할 수 있다.
		그렇다면 실제로 2차원 배열을 가리키는 포인터는 어떻게 생겼는 지 보자.
	*/
	int arr[2][3] = { {1,2,3},{4,5,6} };
	int(*parr)[3] = arr;	// int (*parr)[3] : 크기가 3인 int형 배열을 가리키는 포인터

	printf("parr[1][2] : %d , arr[1][2] : %d \n", parr[1][2], arr[1][2]);	// 둘다 6이란 결과가 나온다.

	/* 2차원 배열을 가리키는 포인터는 배열의 크기에 관한 정보가 있어야한다고 했다.
		2차원 배열을 가리키는 포인터는 아래와 같이 써주면 된다.
		(배열의 형) (* 포인터이름) [2차원 배열의 열개수];
		int (*parr)[3];
		위와 같이 정의한 포인터 parr을 해석해보면 int형 2차원 배열을 가리키는데, 그 배열의 한 행의 길이가 3(열이 3)이라는 사실을 알 수 있다.

		그런데 저 parr은 사실 크기가 3인 배열을 가리키는 포인터를 의미한다.
		1차원 배열에서 배열의 이름이 첫 번째 원소를 가리키는 포인터로 타입 변환된 것처럼
		2차원 배열에서 배열의 이름이 첫 번째 행을 가리키는 포인터로 타입 변환 되어야한다.
		그리고 첫 번재 행은 사실 크기가 3인 1차원 배열이다.
	*/
	int arr[2][3];
	int brr[10][3];
	int crr[2][5];

	int(*parr)[3];
	parr = arr; // OK
	parr = brr; // OK
	parr = crr; // NO! parr은 크기가 3인 1차원 배열을 가리키는 포인터이므로 크기가 5인 1차원 배열이 2개인 crr은 가리킬 수 없다.

	// 아까 오류가 났던 **parr을 이용한 아래의 코드는 무슨 일을 했던 것일까?
	int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
	int** parr;

	parr = arr;

	printf("parr[1][1] : %d \n", parr[1][1]);  // 버그!
	/*
		parr에는 arr 배열의 주소값이 들어가 있기는 하다.
		하지만 parr[1][1]은 어떻게 해석될까?
		parr[1][1]은 *(*(parr+1)+1)과 동일한 문장이다. 
		
		parr은 int*을 가리키는 포인터이고 int*의 크기는 8byte이므로 parr + 1을 하면 실제 주소값이 8 증가하게 된다.
		따라서 parr + 1은 arr배열의 세 번째 원소의 주소값을 가리키게 된다. (왜냐하면 int는 4byte이기 때문이다.)
		따라서 *(parr+1)은 3이 된다. 
		그리고 나서 *(parr +1) + 1을 하면 몇이 증가할까? 현재 parr+1의 타입은 int*이다.
		따라서 int형의 크기만큼인 4가 늘어나게 된다. 결국 *(parr +1) + 1은 7이다.

		그래서 결국 *(*(parr +1)+1)은 마치 주소값 7에 있는 값을 읽어라 하는 말과 동일하므로 오류가 난 것이다.
	*/

	/* ==== 포인터 배열 ====
		포인터 배열은 말 그대로 '포인터들의 배열'이다. 
		배열 포인터는 배열을 가리키는 포인터이고 포인터 배열은 포인터들을 모은 배열이다.
	*/
	int* arrPointer[3];
	int a = 1, b = 2, c = 3;
	arrPointer[0] = &a;
	arrPointer[1] = &b;
	arrPointer[2] = &c;

	printf("a : %d, *arr[0] : %d \n", a, *arr[0]);
	printf("b : %d, *arr[1] : %d \n", b, *arr[1]);
	printf("b : %d, *arr[2] : %d \n", c, *arr[2]);

	printf("&a : %p, arr[0] : %p \n", &a, arr[0]);

	return 0;
}