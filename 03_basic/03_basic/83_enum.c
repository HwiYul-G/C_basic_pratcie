/*
	프로그래밍을 하다 보면 각 데이터에 수를 대응시키는 경우가 많다.
	예를 들어, 사람을 처리할 때 남자는 0 여자는 1을 대응시켜서 처리하거나
	색을 나타날 때 빨강에는 0, 흰색에는 1 등을 대응시켜서 나타내게 된다.

	이렇게 수를 대응시켜서 처리할 때에는 아래와 같이 헷갈리는 경우가 발생한다.
	if(human.gender == 0) // 사람의 성별이 0일 때

	남자는 0 여자는 1임을 확실하게 기억하고 있다면
	상관이 없겠지만 기억하지 못하게 된다면 성에 대해 
		무엇을 대응시켰는지 다시 찾아봐야되는 번거로운 일이 발생한다.

	하지만 아래와 같이
	if(human.gender == MALE)
	이렇게 한다면 확실히 알아 듣기 쉽다.

	하지만 이 문제를 위해 MALE 이라는 상수를 설정해야되고
	이 때문에 메모리가 낭비된다.
	이는 프로그래머의 입장에서 난감하다.

	C에서는 이를 열거형(Enum)을 도입해서 말끔하게 해결한다.
*/
#include <stdio.h>
// enum을 나타내기 위해선 enum{};을 하고 그 안에 작성해주면 된다.
// 그러면 컴파일러는 열거형에 나타나 있는 각 원소에 0부터 차례로 정수값을 매겨준다.
// 즉 RED = 0, BLUE = 1, ... , BLACK = 3;처럼
// 사실 == 0으로 비교하는 것과 의미는 정확히 동일하지만 프로그래머가 읽을 땐 큰 차이가 있다.
// 위와 같이 한다고 해서 실질적으로 RED라는 변수가 메모리에 정해진 것은 아니다.
// 컴파일 시에는 컴파일러는 RED는 모두 0으로 바꾸고 BLUE는 모두 1로 바꾸는 등의 변환 작업을 하게 된다.
enum {RED, BLUE, WHITE, BLACK};
// enum {A = 3, B, O, AB}; // A = 3, B = 4, O = 5, AB = 6이 된다.
enum {A =3, B, O = 3, AB}; // B와 AB 가 둘다 4가 된다.
// 참고로 열거형에서는 언제나 '정수값'이여야만 한다.
int main() {
	int palette = RED;
	switch (palette)
	{
		case RED:
			printf("palette : RED \n");
			break;
		case BLUE:
			printf("palette : BLUE \n");
			break;
		case WHITE:
			printf("palette : WHITE \n");
			break;
		case BLACK:
			printf("palette : BLACK \n");
			break;
	}

	return 0;
}