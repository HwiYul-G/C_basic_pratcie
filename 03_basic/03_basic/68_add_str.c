#include<stdio.h>

int stradd(char* dest, char* src);

int main() {
	char str1[100] = "hello my name is ";
	char str2[] = "Psi";

	printf("��ġ�� ���� : %s \n", str1);

	stradd(str1, str2);

	printf("��ģ ���� : %s \n", str1);

	return 0;
}

int stradd(char* dest, char* src) {
	// dest�� �� �κ��� ã�´�.
	while (*dest) {
		dest++;
	}
	// while�� ���Ŀ� dest�� dest ���ڿ��� NULL���ڸ� ����Ų��.
	// ���� src�� ���ڿ����� dest�� NULL ���ڰ� �ִ� ������ �����Ѵ�.
	while (*src) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = NULL; // ���������� dest�� NULL �߰� (�ֳ��ϸ� src���� NULL�� �߰����� �ʾ����Ƿ�)
	return 1; // ��������
}