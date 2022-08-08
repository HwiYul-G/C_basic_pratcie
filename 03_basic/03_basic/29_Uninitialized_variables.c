#include <stdio.h>
int main() {
	// 초기화되지 않은 변수의 값을 출력하면 어떻게 될까?
	int arr;
	// 컴파일러는 초기화되지 않은 arr 지역 변수를 사용했다고 오류를 낸다.
	printf("니 값은 모니 : %d", arr);
	//하지만 실제로 실행을 해보면 런타임 오류가 발생한다. -> 운영체제는 초기화되지 않은 변수에 대한 접근 자체를 불허함
	
	int arr1[3];
	arr1[0] = 1;
	printf("니 값은 뭐니 : %d", arr1[1]);
	// 실행해보면 arr1[1]의 값이 정의되어 있지 않아서 이 값을 출력할 생각을 꿈도 꾸지 말라고 한다.

	int arr2[3] = { 1 };	// 컴파일러는 이를 {1,0,0} 으로 처리한다.
	printf("니 값은 뭐니 : %d\n", arr2[1]);
	// 이렇게 하면 오류도 경고도 나타나지 않는다. 그리고 0이라는 값이 출력된다.
	// 위와 같이 배열을 하면 arr[0] = 1이고 다른 정의되지 않은 값들은 -1로 초기화된다.

	return 0;
}