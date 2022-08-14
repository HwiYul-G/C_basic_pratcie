#include <stdio.h>

int str_length(char* str);
void reverse_str(char* str);
void change_case(char* str);
int isEqual_str(char* str1, char* str2);
int search_str(char* dest, char* src );

int main() {
	char str1[101];
	char str2[101];
	
	printf("��ü ������ �Է��ϼ��� : ");
	scanf("%s", str1);
	printf("ã�� ������ �Է��ϼ��� : ");
	scanf("%s", str2);

	int searched = search_str(str1, str2);
	if (searched == -1) {
		printf("��ü ���忡 ã�� ������ �����ϴ�.");
	}
	else {
		printf("��ü ���忡 ã�� ������ �ε��� ��ġ %d ���� �����ϰ� �ֽ��ϴ�.", searched);
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
	// str�� '\0' �� ����Ű�� ��(������ �̵�)
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
		if (*str1 != *str2) return 0; // �ٸ���
		str1++;
		str2++;
	}
	if (*str2 != '\0') return 0; // �ٸ���
	return 1; // ����.
}
// dest���� src�� �ִ���
int search_str(char* dest, char* src) {
	int index = 0;
	while (*dest) {
		if (*dest == *src) {
			int cnt = 0;
			while (*src) {
				dest++; 
				src++;
				// ���� ���θ� ���� üũ�ؾ���
				if (*src == '\0') // ������ ���� �ش� index return 
					return index;

				if (*dest != *src) {
					// �߰��� �ٸ� ���� ������ ���� ���·�
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