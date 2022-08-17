/* 파일에서 'this'를 'that'으로 바꾸기 */
#include <stdio.h>
#include <string.h>

int main() {
	FILE* fp = fopen("some_data.txt", "r+"); // 읽기 및 쓰기가 가능한 형식(기존 파일이 존재해야함)
	char data[100];

	if (fp == NULL) {
		printf("파일 열기 오류 \n");
		return 0;
	}

	while (fscnaf(fp, "%s", data) != EOF) {
		if (strcmp(data, "this") == 0) {
			fseek(fp, -(long)strlen("this"), SEEK_CUR);
			fputs("that", fp);

			fflush(fp);// fputs 작업 후 fscnaf로 일기를 하므로 fflush를 사용해야한다.
		}
	}

	fclose(fp);
	return 0;
}