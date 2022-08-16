/* 매크로 함수*/
#include <stdio.h>
#define square(x) x *x

int main(int argc, char** argv) {
	printf("square(3) : %d \n", square(3 + 1)); // 7

	return 0;
}
/*
	printf("square(3) : %d \n", square(3 + 1));
	위 문장에서 우리의 의도는 4*4를 계산하는 것이였을 것이다.
	그런데 16이 아니라 전혀 엉뚱한 답인 7이 나왔다. 
	
	이 이유는 매크로는 단순히 "싹 치환해 버린다."라는 것이다

	전처리기에서 square(3+1)은 아래와 같이 변경된다.
	printf("square(3) : %d \n", 3 + 1 * 3 + 1);
	그래서 답은 7이 나오는 것이다. (연산자 우선순위에 따라서)

	이를 해결하는 방법은 단순하다
	#define square(x) x*x를 #define square(x) (x) * (x)로 바꾸면 된다.
*/