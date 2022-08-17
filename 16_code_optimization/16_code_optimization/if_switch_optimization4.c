/*
	if 및 switch문 관련
	1) if문을 2의 배수로 쪼개기
	2) 순차적 비교에서는 switch 문을 사용해라
	3) 룩업 테이블(look 'up table, LUT)을 사용할 수 있으면 사용해라.
*/
#include <stdio.h>
char* Condition_String1(int condition);
int main() {
	// 1) if문을 2의 배수로 쪼개기
	int i;
	scanf("%d", &i);
	if (i == 1) {
	}
	else if (i == 2) {
	}
	else if (i == 3) {
	}
	else if (i == 4) {
	}
	else if (i == 5) {
	}
	else if (i == 6) {
	}
	else if (i == 7) {
	}
	else if (i == 8) {
	}
	/*
		물론 위와 같은 명령들은 switch문을 이용하는 것이 훨씬 바람직하다.
		위의 경우 if문에서는 최악의 경우 최대 8번의 비교작업을 해야하므로 엄청난 낭비이다.

		하지만 아래와 같이 if문을 아래와 같이 구성하게 된다면 어떨가?
		아래와 같이 if문을 쪼개는 것을
		Binary Breakdown이라고 한다.
		즉 이진의 형태로 쪼갠 것이다.
		이럴 경우 i가 1에서 8까지 어떠한 값을 가지더라도 3번만의 비교로 값을 알아낼 수 있다.
		참고로 이전의 if문의 형태로 평균적으로 4번의 비교가 필요했다.
	*/
	if (i <= 4) {
		if (i <= 2) {
			if (i == 1) {
				/* i is 1 */
			}
			else {
				/* i must be 2 */
			}
		}
		else {
			if (i == 3) {
				/* i is 3 */
			}
			else {
				/* i must be 4 */
			}
		}
	}
	else {
		if (i <= 6) {
			if (i == 5) {
				/* i is 5 */
			}
			else {
				/* i must be 6 */
			}
		}
		else {
			if (i == 7) {
				/* i is 7 */
			}
			else {
				/* i must be 8 */
			}
		}
	}

	// 2) 순차적 비교에서는 switch 문을 사용해라
	/*
		대부분의 현대 컴파일러들은 이 작업을 알아서 최적화 해준다.
		사실 위의 if 문 에제에서는
		즉 위와 같이 순차적인 정수 값을 비교하는 경우에는 
		switch문을 사용하는 것이 매우 요긴하다.

		즉 아래와 같은 코드가 훨씬 더 효율적이다.
	*/
	switch (i) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	}

	/*
		3) 룩업테이블(LUT)을 사용할 수 있으면 사용해라
		룩업 테이블이란, 원론적으로 설명하면 특정 데이터에서 다른 데이터로 변환할 때
		사용 되는 테이블이라 할 수 있다.
		말만 들으면 조금 어려운데 사실 컴퓨터에서 매우 자주 사용되고 있다.

		예를 들어 컴퓨터에서 3D 처리를 할 때
		많은 수의 sine이나 cosine 연산들이 들어가게 된다.
		이 때 sin 값 계산은 꽤 오랜 시간 걸리는 계산이다.
		그런데 sin 1 값이 필요할 때마다 계산을 하게 되면 아주 시간 낭비가 심하다.
		이를 ㅁ가기 위해 프로그램 실행 초기에 sin1부터 sin90 까지 미리 계산해 둔 뒤,,,
		표로 만들어 버리면 나중에 sin1 값이 필요하면 단순히 표에서 1 번째 값을 찾으면 되니까 편하다.

		이렇게 만들어 놓은 테이블을 LUK라고 한다.
		즉 필요한 데이터를 쉽게 찾을 수 있도록 미리 만들어 놓은 표이다.

		예를 들어 char* Condition_String1(int condition)의 함수와 같은 경우 사용할 수 있다.
		char* Condition_String1(int condition)과
		char* Condition_String2(int condition)를 보라.

		char* Conditio_string2(int condition)이 lookUpTable을 통해 훨씬 짧고 프로그램의 크기도 줄어들게 할 수 있다.
	*/
	return 0;
}

char* Condition_String1(int condition) {
	switch (condition) {
	case 0:
		return "EQ";
	case 1:
		return "NE";
	case 2:
		return "CS";
	case 3:
		return "CC";
	case 4:
		return "MI";
	case 5:
		return "PL";
	case 6:
		return "VS";
	case 7:
		return "VC";
	case 8:
		return "HI";
	case 9:
		return "LS";
	case 10:
		return "GE";
	case 11:
		return "LT";
	case 12:
		return "GT";
	case 13:
		return "LE";
	case 14:
		return "";
	default:
		return 0;
	}
}
char* Condition_String2(int condition) {
	if ((unsigned)condition >= 15) {
		return 0;
	}
	char* table[] = { "EQ", "NE", "CS", "CC", "MI", "PL", "VS",
					 "VC", "HI", "LS", "GE", "LT", "GT", "LE" };
	return table[condition];
}