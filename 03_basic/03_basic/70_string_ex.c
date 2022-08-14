#include <stdio.h>

int str_length(char* str);
void reverse_str(char* str);
void change_case(char* str);
int isEqual_str(char* str1, char* str2);
int search_str(char* dest, char* src );

int main() {
	char str1[101];
	char str2[101];
	
	printf("전체 문장을 입력하세요 : ");
	scanf("%s", str1);
	printf("찾을 문장을 입력하세요 : ");
	scanf("%s", str2);

	int searched = search_str(str1, str2);
	if (searched == -1) {
		printf("전체 문장에 찾는 문장이 없습니다.");
	}
	else {
		printf("전체 문장에 찾는 문장이 인덱스 위치 %d 부터 시작하게 있습니다.", searched);
	}
	

	return 0;
}

int str_length(char* str) {
	int i = 0;
	while (*str) {
		i++;
	}
	return i;
}
void reverse_str(char* str) {
	// str이 '\0' 을 가리키게 함(끝으로 이동)
	int length = str_length(str);
	while (length >= 0) {
		printf("%c", str[length--]);
	}
	printf("\n");
}
void change_case(char* str) {
	while (*str) {
		if (*str >= 'a' && *str <= 'z') {
			printf("%c", *str - 32);
		}
		else if (*str > 'A' && *str <= 'Z') {
			printf("%c", *str + 32);
		}
		else {
			printf("%c", *str);
		}
		str++;
	}
	printf("\n");
}
int isEqual_str(char* str1, char* str2) {
	while (*str1) {
		if (*str1 != *str2) return 0; // 다르다
		str1++;
		str2++;
	}
	if (*str2 != '\0') return 0; // 다르다
	return 1; // 같다.
}
// dest에서 src이 있는지
int search_str(char* dest, char* src) {
	int index = 0;
	while (*dest) {
		if (*dest == *src) {
			int cnt = 0;
			while (*src) {
				dest++; 
				src++;
				// 종료 여부를 먼저 체크해야함
				if (*src == '\0') // 끝까지 가면 해당 index return 
					return index;

				if (*dest != *src) {
					// 중간에 다른 값이 나오면 원래 상태로
					dest -= cnt;
					src -= cnt;
					index -= cnt;
					break;
				}
			}
		}
		dest++;
		index++;
	}
	return -1;
}