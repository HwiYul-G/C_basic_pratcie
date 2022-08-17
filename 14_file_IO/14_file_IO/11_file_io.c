#include <stdio.h>
int main() {
	FILE* fp = fopen("some_data.txt", "r+"); // "r+" : 읽기 및 쓰기 (파일이 없으면 안 열고, 존재하면 파일의 내용을 지우지 않음)
	char c;

	if (fp == NULL) {
		printf("파일 열기를 실패하였습니다! \n");
		return 0;
	}

	while ((c = fgetc(fp)) != EOF) {
		// c가 대문자일 경우
		if (65 <= c && c <= 90) {
			fseek(fp, -1, SEEK_CUR);
			fputc(c + 32, fp);
		}
		// c가 소문자일 경우
		else if (97<= c && c <=122) {
			fseek(fp, -1, SEEK_CUR);
			fputc(c - 32, fp);
		}
	}

	fclose(fp);

	return 0;
}
/*
	코드만 볼 때는 문제가 없어보인다.
	하지만 성공적으로 컴파일하면 I Am A BoY! YoU ARe A Girl 이라는 파일이
	IAAAAAAAAAAAA와 같이 괴상하게 변하고
	프로그램이 종료되지도 않아서 강제 종료 해야 했따.

	왜 이런 일이 생긴 걸까?

	ASCII표를 보면 영어 대문자의 경우 값이 65 - 90에 있으므로 위와 같이 while문을 처리한 것이 문제 없어보인다.
	예를 들어 What?이란 문자열이 있을 때 c에 W가 들어가 있따면 현재 파일 위치 지시자는 그 다음인 h를 가리키고 있다.
	따라서 w부분에 W를 쓰기 위해 파일 위치 지시자를 한 칸 뒤로 옮겨서 w를 가리키게 하고
	fputc를 통해 c + 32를 한값 ASCII코드를 보면 그 대문자에 해당하는 소문자 값을 써서
	결과적으로 what? 이된다.

	그런데 도대체 무엇이 문제일까?
	=> 12_file_io.c
*/