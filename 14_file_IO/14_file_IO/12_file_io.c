/*
	스트림 작업에서 읽기/쓰기를 변환할 때는 반드시
	fllush 함수를 호출하거나 fssek이나 rewind와 같은 함수를 호출해
	파일 위치 지정자를 다시 설정해주어야 하기 때문이다.

	따라서 위와 같이 쓰기 작업 후 다시 읽기 작업(while문에서 fputc를 통한 작업)을
	수행할 때는 fflush나 fseek 함수를 호출해야한다.

	이를 토대로 코드를 수정하면 아래와 같다.
*/
#include <stdio.h>

int main() {
    FILE* fp = fopen("some_data.txt", "r+");
    char c;

    if (fp == NULL) {
        printf("파일 열기를 실패하였습니다! \n");
        return 0;
    }

    while ((c = fgetc(fp)) != EOF) {
        /* c 가 대문자일 경우 */
        if (65 <= c && c <= 90) {
            /* 한 칸 뒤로 가서*/
            fseek(fp, -1, SEEK_CUR);
            /* 소문자로 바뀐 c 를 출력한다*/
            fputc(c + 32, fp);
            /*

            쓰기 - 읽기 모드 전환을 위해서는 무조건
            fseek 함수와 같은 파일 위치 지정자 설정 함수들을
            호출해야 한다.

            */
            fseek(fp, 0, SEEK_CUR); // fflush(fp);를 해도 된다.
        }
        /* c 가 소문자일 경우*/
        else if (97 <= c && c <= 122) {
            fseek(fp, -1, SEEK_CUR);
            fputc(c - 32, fp);
            fseek(fp, 0, SEEK_CUR);
        }
    }

    fclose(fp);
}