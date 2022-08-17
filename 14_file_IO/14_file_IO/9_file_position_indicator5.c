/* 파일의 마지막 문자를 보기*/
#include <stdio.h>

int main() {
    FILE* fp = fopen("some_data.txt", "r");
    char data[10];
    char c;

    if (fp == NULL) {
        printf("file open error ! \n");
        return 0;
    }

    fseek(fp, -1, SEEK_END);
    /*
        위 소스에서 가장 중요한 부분은 이 부빈이다.
        파일 위치 지정자를 파일의 맨 끝에서 한 칸 왼쪽인 부분으로 옮긴다.
        왜 -1로 한 칸 옮기냐면, 맨 끝으로 옮기게 되면 
        그 부분에는 EOF(파일의 끝)을 나타내는 것이 들어 있기 때문에
        우리가 원하는 결과가 아니게 된다.

        우리가 파일에 입력한 맨 마지막 문자는 EOF 바로 왼쪽에 위치한 !가 된다.
    */
    c = fgetc(fp);
    printf("파일 마지막 문자 : %c \n", c);

    fclose(fp);
}