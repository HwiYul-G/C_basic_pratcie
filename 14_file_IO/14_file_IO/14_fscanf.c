/* fscanf 이용하기 */
#include <stdio.h>

int main() {
    FILE* fp = fopen("some_data.txt", "r");
    char data[100];

    if (fp == NULL) {
        printf("파일 열기 오류! \n");
        return 0;
    }

    printf("---- 입력 받은 단어들 ---- \n");

    while (fscanf(fp, "%s", data) != EOF) {
        printf("%s \n", data);
    }
    /*
        fscanf를 통헤 fp에서 문자열을 읽어온다
        fgets는 \n이 나올 때까지 하나의 문자열로 보고 받아들이지만
        fscanf는 띄어쓰기나 탭문자들 중 어느 하나가 나올때까지 입력받으므로 파일에선
        각 단어들을 하나씩 읽어들이게 된다.
        물론 읽은 만큼 파일 위치 지정자는 이동한다.

        이때 fscanf가 더이상 새로운 데이터를 입력받을 수 없는 경우에는 
        EOF를 리턴한다.
        즉 파일에 끝에 도달하면 EOF를 리턴해 while문을 빠져나간다.
    */

    fclose(fp);

    return 0;
}
/*
    fscanf 함수는 우리가 여태 사용한 scanf 함수와 아주 유사하다.
    사실 scanf함수가 stdin에서만 입력을 받고
    fscanf는 임의의 스트림에서도 입력을 받을 수 있는 좀 더 일반화된 함수이다.

    scanf 함수의 첫 번째 인자로 입력을 받을 스트림을 써주게 된다.
    따라서 scanf(stdin, "%s", data); 와 scanf("%s", data); 는 정확히 일치하는 동작이다.

    fscanf는 사용자가 지정한 형식에 맞게 데이터를 읽어오는데
    fgets와 달리 띄어쓰기나 탭 문자들도 모두 인식하므로 각각의 단어들을 읽어오는데 요긴하게 사용할 수 있다.
*/