/*
	[함수 호출 관련]
	1) 함수를 호출할 때는 시간이 걸린다.

	#include <stdio.h> 
	void print_a();
	int main() {
	  int i;
	  for (i = 0; i < 10; i++) {
		print_a();
	  }
	  return 0;
	}
	void print_a() { printf("a"); }

	#include <stdio.h>
	void print_a();
	int main() {
	  print_a();
	  return 0;
	}
	void print_a() {
	  int i;
	  for (i = 0; i < 10; i++) {
		printf("a");
	  }
	}

	위의 2개의 코드 중 아래의 코드가 더 빠르게 작동한다.
	왜냐하면 함수를 호출하는 데도 꽤 많은 시간이 걸리기 때문이다.
	아무튼 위와 같이 동일한 작업을 위해 함수를 반복적으로 호출하기 보단 
	차라리 그 함수 내에서 반복적인 작업을 처리하는 것이 훨씬 더 효율적이다.

	2) 인라인(inline) 함수를 활용하자
*/
#include <stdio.h>
int max(int a, int b) {
	if (a > b) return a;
	return b;
}
__inline int imax(int a, int b) {
	if (a > b) return a;

	return b;
}
int main() {
	printf("4 와 5 중 큰 것은?", max(4, 5));
	printf("4 와 5 중 큰 것은?", imax(4, 5));
	/*
		위의 2개의 printf문 중 더 빠르게 된 것은 아래의 inline 함수를 이용한 것이다.
		위와 같이 max와 같은 단순한 작업을 함수로 만들 때는 inline 함수를 사용하는 것이 더 효율적이다.

		사실 인라인 함수는 함수가 아니다.

		반면에 max 함수는 실제로 함수의 호출 과정 부터 여러 가지 작업이 필요하다.
		그런데 정작 내부에서 수행하는 작업은 매우 단순해
		오히려 함수 내부에서 하는 작업 시간보다 호출하는데 걸리는 시간이 더 큰 배보다 배꼽이 더 큰 격이다.
		따라서 위와 같이 단순한 작업을 함수로 만들 경우 inline 함수를 하는 것이 더 좋다.
	*/
	return 0;
}
/*
	3) 인자를 전달할 때는 포인터를 이용해라
	struct big {
		int arr[1000];
		 char str[1000];
	};
	
	위와 같이 거대한 구조체가 있다고 하자.
	만일 이 구조체 변수의 arr[3] 값을 얻어오는 함수를 만들고 싶다면 어떻게 해야할까?
	
	void modify(struct big arg){} 이런 함수를 짤 수도 있다.
	하지만 이 함술르 호출할 경우 modify 함수의 arg 인자로 
	구조체 변수의 모든 데이터가 복사되야 하는데
	이는 엄청난 시간이 걸리게 된다.

	말그대로 5000 바이트나 되는 데이터의 복사를 수행해야 할 뿐더러
	modify 변수의 메모리 공간을 위한 할당도 따로 필요하기 때문이다.
	
	그렇다면 아래의 코드는 어떤가?
	void modify(struct bit *arg){}
	위 함수는 구조체 변수의 '주소값'을 얻어온다.
	이는 단순히 4 byte의 주소값 복사만 일어날 뿐 이전의 예와 같은 엄청난 복사는 일어나지 않는다.
	뿐만 아니라 동일하게 인자로 전달된 구조체 변수의 데이터들도 쉽게 읽을 수 있다.

	단순히 arg->arr[3]과 같은 방식으로!
	언제나 이점을 명심하고 되도록 인자를 전달할 때는 포인터를 자주 활용하자!

	코드 최적화와 관련되서 여기를 더 읽어보자!
	http://www.azillionmonkeys.com/qed/optimize.html
*/