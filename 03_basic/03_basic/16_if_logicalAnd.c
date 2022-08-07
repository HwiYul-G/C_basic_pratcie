#include <stdio.h>

int main() {
	int a;
	printf("아무 숫자나 입력하세요 : ");
	scanf("%d", &a);

	if (a >= 10)
		if (a < 20)
			printf(" %d는 10 이상, 2 미만인 수 입니다. \n", a);

	// 위는 아래와 같이 논리곱 연산자 &&으로 줄여 사용할 수 있다.
	int a;
	printf("아무 숫자나 입력하세요 : ");
	scanf("%d", &a);

	if (a >= 10 && a < 20) {
		printf(" %d 는 10 이상, 20 미만인 수 입니다. \n", a);
	}
	// & : bit연산의 AND - > 정확한 비트 AND 연산 수행
	// && : 논리곱인 AND 연산 -> 참(1)인지 거짓(0)인지

	int a = 31, b = 15;
	printf("a & b = %d\n", a & b); // 15
	printf("a && b = %d\n", a && b); //1 

	// 0 외의 값은 어차피 1이므로 &나 &&나 비슷해보인다.
	// 하지만 SCE(Short Circuit Evaluation) 때문에 논리식 사이엔 &&이 바람직하다.
	int height = 175, weight = 90;
	if (height >= 180 && weight >= 90) {}
	// height가 180 미만이므로 뒤으 weight >=90을 검사하지 않고 거짓 처리를 한다.
	// 즉 쓸대없는 연산을 줄이게 되는 이런 방시을 SCE라고 한다.


	// 마찬가지로 논리 OR ||도 있다.
	int height, weight;
	printf("당신의 키와 몸무게를 각각 입력해 주세요 : ");
	scanf("%d %d", &height, &weight);
	
	// 두 조건 식 중 적어도 하나가 참이면 무조건 if block 안을 실행하게 해준다.
	if (height >= 190 || weight >= 100) {
		printf("당신은 '거구' 입니다. \n");
	}
	// !은 NOT 연산자이다. 0이 아닌 값을 0으로 변환해주는 특성을 이용해서 어떤 변수의 값이 0이 아닌지를 판별하기 위해 
	//if(!p){// p가 0일때만 수행} 이런 로직을 쓰기도 한다.
	if (!(height >= 190 || weight >= 100)) {
		printf("당신은 거구가 아닙니다. \n");
	}

	return 0;
}