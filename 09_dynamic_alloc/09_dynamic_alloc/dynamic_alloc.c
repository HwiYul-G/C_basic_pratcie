/*
	우리가 배열을 정할 때 그 크기는 언제나 '컴파일 시간에 확정' 되어 있어야 한다.
	즉 컴파일러가 배열의 크기를 추측할 필요 엇이 명확하게 나타나 있어야 한다.
	하지만 이는 정말 고역스러운 일이다.
	예를 들어 우리가 컴퓨터로부터 학생들의 수학 점수를 입력 받아 평균을 내는 프로그램을 만든다고 해보자.

	각 학급마다 학생들의 수가 모두 다르기 때문에 배열의 크기를 명확하게 정할 수 없게 된다.
	따라서 보통 이 경우 배열을 '충분히 크게' 잡게 된다. 그리고 이렇게 하면 메모리가 낭비되는 경우가 허다하다.

	컴퓨터에서 낭비란 곧 비효율적인 프로그램을 의미하는 것이다.
	이렇게 쓸데 없이 낭비되는 자원을 막기 위해 '학생 수'를 입력 받고 그 학생 수만큼 배열의 크기를 지정하면 얼마나 좋을까?
	
	"동적 메모리 할당"이라는 방법을 통해 이러한 일을 할 수 있다.
	이것은 말 그대로 동적으로 메모리를 할당한다.
	여기서 동적이란 말은 딱 정해진 것이 아니라 가변적으로 변할 수 있다는 말이다.
	또한 메모리를 할당한다는 이야기는 
	역시 우리가 배열을 정의하면 
	배열에 맞는 메모리의 특정한 공간이 배열을 나타나는 것처럼 
		메모리의 특정한 부분을 사용할 수 있게 된다.
	참고적으로 할당되지 않는 메모리는 절대 사용할 수 없다.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv) {
	int SizeOfArray;
	int* arr;

	printf("만들고 싶은 배열의 원소 수 : ");
	scanf("%d", &SizeOfArray);

	arr = (int*)malloc(sizeof(int) * SizeOfArray);
	// int arr[SizeOfArray]와 동일한 작업을 한 크기의 배열 생성

	free(arr);

	return 0;
}
/*
	arr = (int*)malloc(sizeof(int) * SizeOfArray);
	이 부분이 우리가 원하는 작업을 해주는 역할을 한다.
	이 함수의 이름은 malloc이며 memory allocation의 약자이다.

	이 함수는 <stdlib.h>에 정의되어 있기 때문에 #include <stdlib.h>를 추가해줘야한다.

	이 함수는 인자로 전달된 크기의 바이트 수만큼 메모리 공간을 만든다.
	즉 메모리 공간을 할당하게 된다. 
	
	우리가 원소의 개수가 SizeOfArray인 int형 배열을 만들기 위해서는
	당연히 (int의 크기)* (SizeOfArray)가 된다.
	이때 int 타입의 크기를 정호가히 알기 위해서 sizeof 키워드를 사용하게 된다.
	sizeof는 이 타입의 크기를 알려준다. 따라서 sizeof(int)*SizeOfArray를 인자로 주면 된다.

	이 함수가 리턴하는 것은 자신이 할당한 메모리의 시작 주소를 리턴하게 된다.
	이 때, 리턴형이 (void*)형 이므로 우리는 이를 (int*)으로 형변환 하여 arr에 넣어주기만 하면 된다.

	그리고 마지막에 free는 우리가 할당받은 다 쓰고 난 후에 메모리 영역을 다시 컴퓨터에게 돌려주는 역하을 한다.
	이를 해제(free)한다고 한다.
	이 free를 제대로 하지 않으면 사용하지도 않는 메모리가 쓸데없이 자리를 차지하게 된다.

	이렇게 free를 제대로 하지 않아 발생하는 문제를 메모리 누스(memory leak)이라고 한다.

*/