/* 한 글자씩 입력받기 */
#include <stdio.h>

int main() {
	FILE* fp = fopen("a.txt", "r");
	char c;

	while ((c = fgetc(fp)) != EOF) {
		/*
			fgetc는 fp에서 문자 하나를 얻어온다.
			즉 한 문자씩 읽어들인다.

			이때 문자열의 맨 마지막이 NULL문자를 나타내는 것처럼
			파일의 맨 마지막에는 EOF라고 End Of File을 나타내는 값인 -1이 들어가 있다.

			실제로 EOF의 원형을 찾아봐도
			#define EOF (-1)
			로 -1로 선언되어 있다.
			
			따라서 우리는 c가 EOF인지 아닌지 비교함을 통해 파일의 끝까지 입력을 받았는지 안받았는지
			알 수 있다.
			이와 같은 방식을 통해 파일의 크기를 알아내는 프로그램도 만들 수 있다.
			=> 4_get_filesize
		*/
		printf("%c", c);
	}
	fclose(fp);

	return 0;
}