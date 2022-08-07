#include <stdio.h>

int main() {
	int i;
	printf("입력하고 싶은 숫자를 입력하세요 : ");
	scnaf("%d", &i);

	if (i == 7) {
		printf("당신은 행운의 숫자 7을 입력했습니다.");
	}

	double a, b;
	printf("나누고 싶은 두 정수를 입력하세요 : ");
	scanf("%lf %lf", &a, &b);

	if (b == 0) {
		printf("0으로 나눌 수 없습니다. \n");
		return 0; // return 0;을 하면서 프로그램이 종료됨(아래의 내용이 실행되지 않음)
	}
	printf("%f를 %f로 나눈 결과는 : %f \n", a, b, a / b); // double/ double을 제수를 0으로 해서 나누면 inf를 내뿜음

	int score;
	printf("당신의 수학 점수를 입력하세요 : ");
	scanf("%d", &score);
	if (score >= 90) {
		printf("당신은 합격입니다! \n");
	}
	if (score < 90) {
		printf("당신은 불합격 입니다. \n");
	}

	return 0;
}
// if문의 조건이 거짓인가 거짓이 아닌가에 따라 실행의 유무를 판별함
// 0은 거짓, 0외의 숫자는 참을 나타냄 => if(0)이라고 하면 if의 block은 실행되지 않는다.