#include <stdio.h>

int main() {
	char words[30];	// null���� �����ϰ� �ִ� 29�ڱ��� ���� �迭 ����

	printf("30 �� �̳��� ���ڿ��� �Է����ּ���! : ");
	scanf("%s", words);	//�Է¹޴� ������ %s�� ���ڿ��� �Է¹���, words��� �迭 �̸� ��ü�� �̹� �迭�� ����Ű�� ������ �̹Ƿ� �ּҰ��� �����ϰ� �ִ�.
	// ���⼭ what is your name�� �Է��ϸ�

	printf("���ڿ� : %s \n", words);	// ����� what�� �ȴ�.

	/*
		scanf�� ���Ͱ� ������ �Է��� �����ϴµ� �� what�κи� �Է��� �Ǿ�����?
		=> �̾ �н�!

	*/

	// �����غ��� 1
	const char* str = "abcdefghi"; // char c_str[] ={"abcdefghi"};�� �ƴϿ��� �� �ȴ�.
	printf("%s", str); 
	/* char c_str[] = {}; �� �ѰͰ� cosnt char* str = ""; ���� �� ���� ��������
		const char*�� ������ ���ڰ� ��������� �����Ǿ� ������ �Ұ����ϴ�.
	*/

	// �����غ���2
	char str_a[] = "abc";
	char str_b[] = "abc";

	if (str_a == str_b) {
		/* �� �κ��� ������� �ʴ´�.*/
		printf("str_a�� str_b�� ����.");
	}
	/*
		���� �ȵǴ� ������ �迭 ��ü�� ȣ���ϸ� �迭�� ���� ���� �ƴ� �迭�� �ּҸ� ȣ���ϴµ�
		str_a�� str_b�� ��ġ�� �޸� �ּҰ� �ٸ��� �����̴�.

		�̸� �ذ��ϱ� ���ؼ� �� ���� �����־���Ѵ�.
		�̸� ���� int isEqual(char*a, char*b)�̶� �Լ��� ������ �־���.
	*/


	return 0;
}

int isEqual(char* a, char* b) {
	while (*a || *b) { // �� ���� NULL�� ������
		if (*a++ != *b++) return 0;
	}
	return 1;
}