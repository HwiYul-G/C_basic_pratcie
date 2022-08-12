#include <stdio.h>
int read_val(const int val);
int main() {
	int a;
	scanf("%d", &a);
	read_val(a);
	return 0;
}
int read_val(const int val) {
	val = 5;	// error C2166 : l-value가 cosnt 개체를 지정합니다.
	// val을 const int로 선언했기 때문에 함수 호출 때, val 값은 인자로 전달된 값으로 초기화 되고 결코 바뀌지 않는다.
	// 상수로 인자를 받아들이는 경우 대부분 함수를 호출 해도 그 인자의 값이 변경되지 않는 경우에 자주 사용한다.
	return 0;
}