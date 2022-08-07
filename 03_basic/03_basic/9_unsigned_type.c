#include <stdio.h>

int main() {
	unsigned int b = -1;
	printf("b에 들어있는 값을 unsigned int로 해석 했을 때 값 : %u \n", b);

	b = 4294967295;
	printf("b : %u \n", b);
	b++;
	printf("b : %u \n", b);

	return 0;
}

/*
	unsigned int의 경우 음수가 없고 0 ~ 4294967295까지의 수를 표현할 수 있다.
	unsigned int 역시 int처럼 32bit를 차지한다. 
	unsigned int의 경우 int 였으면 2의 보수 표현을 통해 음수로 해석될 수를 양수라고 생각한다.

	unsigned int에 -1을 대입하면 -1은 0xFFFF FFFF로 표현되므로 가장 큰 값이  들어간다.
	%u는 unsigned 타입으로 해석하라는 의미이다.

	물론 unsigned int 상에서도 오버플로우가 발생한다. b의 최대값에 +1을 추가한다면 0이 나오게 된다.
*/