#include <stdio.h>
__inline int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int main(int argc, char**argv) {
	printf("3과 2중 최대값은 : %d \n", max(3, 2));
	return 0;
}

/*
	컴파일러는 max(3,2)라는 문장을 보고 max 함수 내부 코드로 max(3,2)를 대체할 수 있을 지 생각한다.

	만일 이를 max 함수를 호출하고 리턴받는 형태 보다,
	직접 작업하는 비용이 더 작다고 생각할 때는 이를 치환하게 된다.
	하지만, 이 비용이 더 크다면(코드 길이가 더 길어짐) inline 키워드를 무시하게 된다.

	다행이도 이 max 함수의 경우 간단히 치환할 수 있는데, 아마 컴파일러는 이 함수의 내용을
	printf("%d 과 %d 중 최대값은 : %d \n", 3, 2, 3 > 2 ? 3 : 2);
	(컴파일러가 컴파일을 수행할 때 실제로 저 코드로 바꿔서 컴파일 하진 않는다. 
		코드가 컴파일된 결과가 위 코드가 컴파일된 결과와 같다는 뜻)

	여태까지 인라인 함수와 매크로 함수를 살펴 보았는데
	많은 사람들이 매크로 함수보단 인라인 함수를 사용하도록 권장하고 있다.
	이 때문에 원래는 C표준에 없었던 인라인 함수가 C99라는 새로운 C 표준에 포함되었다.
	
	또한 인라인 함순느 매크로와 달리 단순 치환을 하는 것이 아니라
	진짜 함수처럼 동작하므로 훨씬 구현하기 쉽고 편리하다.
	디버깅 역시 인라인 함수가 편하다.
*/