#include <stdio.h>

int swap1(int a, int b) {
	int tmp = a;

	a = b;
	b = tmp;

	return 0;
}

int swap2(int* a, int* b) {
	int tmp = *a;

	*a = *b;
	*b = tmp;

	return 0;
}

int main() {
	int i = 3, j = 5;

	printf("SWAP1 이전 : i : %d, j: %d \n", i, j);
	swap1(i, j);
	printf("SWAP1 이후 : i : %d, j : %d \n", i, j);
	/*
		위의 swap1의 결과는 i와 j의 값이 변환되지 않는다. 
		그 이유는 swap1 함수의 변수 a, b가 모두 swap 함수 내부에서 선언된 변수들이기 때문이다.
		다시 말해 a와 b는 i와 j의 어떤 연관도 없다. 다만 a,b의 초깃값이 i, j를 이용한다는 점을 제외하면

		swap1함수의 이용은 아래의 코드와 같다.
		int i, j;
		int temp, a, b;
		// 함수를 호출해 인자를 전달하는 부분
		a = i;
		b = j;
		// 함수의 몸체 실행
		temp = a;
		a = b;
		b = temp;

		이는 포인터를 이용하면 해결할 수 있다.
	*/
	printf("SWAP2 이전 : i : %d, j: %d \n", i, j);
	swap2(&i, &j);
	printf("SWAP2 이후 : i : %d, j : %d \n", i, j);
	/*
		swap2에서 원하는 바가 수행된 이유는 a와 b에 i,j의 주소값을 전달해 a와 b로 하여금 i와 j를 가리키게 만든 것이다.
		따라서 swap2 함수 내부에서 a와 b의 값을 교환하는 것이 아니라 a와 b가 가리키는 두 변수의 값을 교환했으므로 
			(*a, *b) 결과적으로 i와 j의 값이 바뀌게 된 것이다.

		결론적으로 어떤 함수가 특정한 타입의 변수/배열의 값을 바꾸려면 함수의 인자는 반드시 그 타입을 가리키는 포인터를 이용해야한다.
	*/
	return 0;
}