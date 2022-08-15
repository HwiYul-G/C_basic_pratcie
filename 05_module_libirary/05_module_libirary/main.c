/*
	파일을 분할하는 것만큼이나 중요한 것을 알아보자.
	바로 '다른 사람이 만들어 놓은 함수들'을 사용하는 방법이다.

	이렇게 다른 사람들이 만들어 놓은 것을 가리켜서 '라이브러리'라고 한다.
	두서관에서 책을 고르는 것처럼 C 프로그래밍에서 우리는 원하는 함수를 라이브러리에서 찾아 사용할 수 있다.
	
	이전에는 우리가 copy_str을 이용해 str1에 str2를 복사했었다.
	그리고 이를 위해 str.c에 함수의 body를 작성하고 str.h에 함수 원형을 선언해줬다.
	str.c와 main.c 각각에 str.h를 include 함으로 사용할 수 있었다.

	이렇게 모든 프로그램에서 문자열을 복사하는 일이 발생할 때마다
	str 관련된 것을 모듈화 시키기 위해 작성하면 매우 귀찮고 번거롭다.

	하지만 다행히도 사람들은 이 역하을 하는 함수를 '미리' 만들어 놓았다.

*/
#include <stdio.h>
#include <string.h>	// string.h 파일에 있는 내용을 모두 가져다 붙인다.
// string.h 파일에는 문자열을 처리하는데 관련된 함수들의 원형 모음이 있다.
/*
	이렇게 사람들이 미리 만든 하수들의 모임을 가리켜서 '라이브러리'라고 한다.
	우리가 현재 사용한 라이브러리는 string 라이브러리이다.
	
	그렇다면 stdio.h 도 라이브러리일까? 맞다.
	이는 입출력 라이브러리로 입력과 출력에 관련된 함수들을 모아놓았다.
	
*/
int main() {
	char str1[20] = { "hi" };
	char str2[20] = {"hello every1"};
	char str3[20] = { "hi" };

	// copy_str과 사용법이 정확히 동일하다
	// 문자열을 복사하고자 하는 곳의 주소값을 첫 번재 인자로, 복사가 되는 문자열의 주소값을 두 번째 인자로 준다.
	strcpy(str1, str2);

	printf("str1 : %s \n", str1);
	// ============================
	if (!strcmp(str1, str2)) {
		printf("%s and %s is equal \n", str1, str2);
	}
	else {
		printf("%s and %s is NOT equal \n", str1, str2);
	}

	if (!strcmp(str1, str3)) {
		printf("%s and %s is equal \n", str1, str3);
	}
	else {
		printf("%s and %s is NOTequal \n", str1, str3);
	}
	/*
		이번에 사용해본 함수는 strcmp 함수이다.

		이 함수는 두 문자열을 비교해서 두 문자열이 같다면 0 다르다면 0이 아닌 값을 리턴하게 되어있다.
		이 함수의 사용법도 이전에 우리가 만들었던 compare_str 함수와 동일하다.
		첫 번째와 두 번째 인자에는 비교할 문자열들의 주소를 넣어주면 된다.
	*/

	return 0;
}