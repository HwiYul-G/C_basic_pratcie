#include <stdio.h>

/*
	continue문은 break문과 비슷하지만 하는 일은 완전히 다르다.
	continume는 break와 달리 for문을 빠져나가는 것이 아니라 그냥 pass 해준다.

	break는 아래의 모든 내용을 무시하고 loop를 빠져나가는데 continue는 다시 조건 점검부로 점프한다.

*/

// 5의 배수를 제외한 숫자 출력
int main() {
	for (int i = 0; i < 100; i++) {
		if (i % 5 == 0) continue;
		printf("%d ", i);
	}

	return 0;
}