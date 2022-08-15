/*
	89_before_module.c에서 모듈화를 하는 것
	compare 함수는 상당히 다른 일을 하고 있어서 main 함수와 같은 파일에 둘 필요가 없다.

*/
#include "str.h"

char compare(char* str1, char* str2) {
	while (*str1) {
		if (*str1 != *str2) {
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str2 == '\0') return 1;
	return 0;
}