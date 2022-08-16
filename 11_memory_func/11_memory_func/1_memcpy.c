/*
	�޸𸮿� ���õ� C ǥ�� ���̺귯������ �⺻���� �����Ǵ� �͵鿡 ���� �Ӷ���.
	�ϴ� �޸𸮸� ���������� ������ ��ٰ� ���� �� �ִ� �Լ�����
		memmove, memcpy, memcmp, memset ���� �ִ�.
	�츮�� ���⼭ ��ǥ���� 3���� �Լ��� memmove, memcpy, memcmp�� �˾ƺ���.

	�� �Լ��� ��� string.h�� ���ǵǾ� �ִ�.
*/

#include<stdio.h>
#include<string.h>

int main() {
	char str[50] = "I love Chewing C hahaha";
	char str2[50];
	char str3[50];

	// strlen�Լ��� ���ڿ� ���̸� �������ִ� �Լ���
	// strlen("abc");�� �ϸ� 3�� ���ϵȴ�. �̶� �������� NULL ���ڴ� ���� �����Ƿ� + 1�� ���Ѹ�ŭ �����ؾ��Ѵ�(NULL����)
	memcpy(str2, str, strlen(str) + 1); // str�κ��� strlen(str)+1��ŭ�� ���ڸ� str2�� �����ض�
	memcpy(str3, "hello", 6);

	printf("%s \n", str); // I love Chewing C hahaha 
	printf("%s \n", str2); // I love Chewing C hahaha 
	printf("%s \n", str3); // hello
	/*
		memcpy�� �޸��� Ư���� �κ����κ��� �󸶱����� �κ��� �ٸ� �޸� �������� �������ִ� �Լ��̴�.
		���� ���� ���ڿ��� �����ϴµ� ���� �� �ִ�.

		���� ���ڿ� ���縦 ���������� �ϴ� �Լ��� strcpy�̴�.
		������ ���� ���� memcpy�� ����ϴ� �͵� ������ �ʴ�.
	*/

	return 0;
}