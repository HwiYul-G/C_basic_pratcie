#include <stdio.h>
#include <string.h>

int main() {
	char str[50] = "I love Chewing C hahaha";

	printf("%s \n", str);	// I love Chewing C hahaha
	printf("memmove ���� \n");
	memmove(str + 23, str + 17, 6);
	printf("%s \n", str);	// I love Chewing C hahahahahaha
	printf("%d \n", str[29]); // �������� 29�� NULL�� �Ǿ�����? => ����ȴ�.
	/*
		memmove(str + 23, str + 17, 6);
		�� �Լ��� ��� str + 17���� 6���� ���ڸ� str+23�� �Ű��.
		�� hahaha�� ���ۺκп��� 6���� ������ hahaha�� str�� �� ������ �κп� ������ �־��ٴ� ���̴�.

		memmove �Լ��� ������ memcpy�� �ϴ� ���� ���� ����غ�������
		��� memcpy�� �޸�, �޸� ������ ���ĵ� �ȴ�.

		���� ��쵵 str�� �����ϴ� �κ��� �������� ���������� �����ϰ� �Ǿ���.
		���п� ���߿� memmove �Լ��� ���� ���� ����ϰ� �� ���̴�.
	*/
	return 0;
}