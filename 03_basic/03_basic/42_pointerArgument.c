/*
	포인터 : 특정한 변수의 메모리 상의 주소값을 저장하는 변수

*/
#include <stdio.h>

int change_val(int i) {
	i = 3;
	return 0;
}
int change_val2(int* pi) {
	printf("--- change_val2 함수 안에서 ---");
	printf("pi의 값 : %p \n", pi);
	printf("pi가 가리키는 것의 값 : %d \n", *pi);

	*pi = 3;

	printf("--- change_val2 함수 끝 ---");
	return 0;
}

int main() {
	int i = 0;

	printf("change_val() 호출 이전 i의 값 : %d \n", i);
	change_val(i);
	printf("change_val() 호출 이후 i의 값 : %d \n", i);
	/* 
		위를 수행하면 i의 값이 바뀌지 않았음을 알 수 있다.
		그 이유는 함수 change_val을 호출할 때 
			change_val 함수 안에서 정의된 변수 i는 main 함수의 i의 값을 전달 받은 후에, 
			change_val 함수 안에서 정의된 변수 i의 값을 3으로 변경하게 된다.

		A라는 함수에서 i라는 변수를 이용한다면 
		컴파일러는 이 변수 i가 오직 A함수에서만 정의되었다고 생각하지 다른 함수에서 정의되었는 지는 상관하지 않는다.
	*/
	i = 0;
	printf("i 변수의 주소값 : %p \n", &i);	// 0x7ffd3928afc4 
	printf("change_val2() 호출 이전 i의 값 : %d \n", i); // 0
	change_val2(&i);
	printf("change_val2() 호출 이후 i의 값 : %d \n", i); // 3
	/*
		위의 결과를 보면 함수를 통해서 main 함수에 있는 것을 변경시켜 주었다.
		즉 다른 함수에서 정의된 변수의 값을 바꾸었다.

		함수 정의 부분을 보면 int change_val2(int *pi)
		int형 변수를 가리키는 pi라는 이름의 포인터로 인자를 받고 있다.
		호출 하는 곳을 보면 change_val2(&i);
		즉 인자에 main 함수에서 정의된 i라는 변수의 '주소값'을 인자로 전달하고 있다.
		따라서 change_val2 함수를 호출하였을 때 pi에는 i의 주소값이 들어가게 된다.
		즉 pi는 i를 가리키게 된다.
		
	*/
	return 0;
}