/* ���Ͽ��� 'this'�� 'that'���� �ٲٱ� */
#include <stdio.h>
#include <string.h>

int main() {
	FILE* fp = fopen("some_data.txt", "r+"); // �б� �� ���Ⱑ ������ ����(���� ������ �����ؾ���)
	char data[100];

	if (fp == NULL) {
		printf("���� ���� ���� \n");
		return 0;
	}

	while (fscnaf(fp, "%s", data) != EOF) {
		if (strcmp(data, "this") == 0) {
			fseek(fp, -(long)strlen("this"), SEEK_CUR);
			fputs("that", fp);

			fflush(fp);// fputs �۾� �� fscnaf�� �ϱ⸦ �ϹǷ� fflush�� ����ؾ��Ѵ�.
		}
	}

	fclose(fp);
	return 0;
}