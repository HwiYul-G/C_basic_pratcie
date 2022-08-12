#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	double celsius; // 섭씨 온도

	printf("섭씨 온도를 화씨 온도를 바꿔주는 프로그램 입니다. \n");
	printf("섭씨 온도를 입력해 주세요 : ");
	scanf("%lf", &celsius); // 섭씨 온도를 입력받는다.

	printf("섭씨 %f 도는 화씨로 %f 도 입니다. \n", celsius, 9 * celsius / 5 + 32);


	char ch; // 문자
	
	short sh; //정수
	int i;
	long lo;
	
	float fl; //실수
	double du;

	// 한글은 2byte 이상을 차지하므로 최대 1byte를 차지하는 char형 변수에 한글을 치면 오류가 남  
	// = > 허용된 메모리 이상에 데이터를 집어넣어 발생하는 버퍼 오버플로우
	printf("char 형 변수 입력 : ");
	scnaf("%c", &ch);

	printf("short 형 변수 입력 : ");
	scanf("%hd", &sh);
	printf("int 형 변수 입력 : ");
	scanf("%d", &i);
	printf("long 형 변수 입력 : ");
	scanf("%ld", &lo);

	printf("float 형 변수 입력 : ");
	scanf("%f", &fl);
	printf("double 형 변수 입력 : ");
	scanf("%lf", &du);

	printf("char : %c, short : %d, int : %d ", ch, sh, i);
	printf("long : %ld, float : %f, double : %f \n", lo, fl, du);

	return 0;
}

// scanf 대신 scanf_s를 사용하라고 경고하는 데 이는
// scanf가 데이터의 크기를 확인하지 않아서 버퍼 오버플로우(입력받는 데이터의 크기가 준비된 공간보다 큰 문제)가 발생할 수 있기 때문이다.

/*
	printf : 화면에 결과를 출력해주는 함수 // scanf : 화면(키보드)로 부터 결과를 받아들이는 입력 함수
	scanf는 어떤 입력을 하기까지 계속 기다린다. 또한, 입력을 할 때 엔터를 눌러야만 입력으로 처리된다.
	printf에서 각 변수를 출력할 포맷 (%d, %f, %c .. )을 변수마다 다르게 하는 것처럼 scanf도 각 변수의 타입마다 입력받는 포멧을 달리해야 한다.

	printf는 double이나 float 모두 %f로 출력한다.
	하지만 scanf는 double 형의 변수를 입력받으려면 %lf로 해야하고 float은 %f로 해야한다. 
*/