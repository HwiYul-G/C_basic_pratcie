#include <stdio.h>
/*
	for(초기식;조건식;증가식){}에서
	아래의 for문은 초기식, 조건식, 증감식이 모두 없다.
	for문은 얼마나 실행되어야 할까?

	for문의 조건식이 명시되지 않는다면 항상 '참'이라 인식되므로
	for문은 언제나 참이 된다. 따라서 무한히 중괄호 속의 내용을 실행한다.

	만약 for(;;){
		printf("a");
	}
	
	를 실행하게 하면 무한히 for의 scope를 실행시킨다. (프로그램 자체가 강제 종료되기 전까지)

	하지만 아래의 실행 시키는 것은 무한 루프에 빠지지 않는다. 이는 break 덕분이다.
	break가 for문을 탈출시킨다.

*/

int main() {
	int usranswer;
	
	printf("컴퓨터가 생각한 숫자를 맞춰 보세요! \n");

	for (;;) {
		scanf("%d", &usranswer);
		if (usranswer == 3) {
			printf("정답! \n");
			break;
		}
		else {
			printf("땡! \n");
		}
	}
	return 0;
}