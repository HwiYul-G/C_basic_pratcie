/* fssek 함수 예제*/
#include <stdio.h>

int main() {
	FILE* fp = fopen("some_data.txt", "r");	// There is some data in this FILE!!!!
	char data[10];
	char c;

	if (fp == NULL) {
		printf("file open error ! \n");
		return 0;
	}

	fgets(data, 5, fp);	
	/*
		fgets 함수를 사용해서 fp로부터 입력받는다.
		이 때, 문자열 형태로 입력을 받는데 입력을 받을 때
		\n이 나올 때 까지 입력받거나 (두번째 인자의 크기 -1)만틈 입력받을 때까지 입력을 받는다.
		위의 경우 \n이 나오기 전에 4byte만큼 입력을 받으므로 
		data에는 Ther이란 내용의 문자열이 들어간다.

		왜 1만큼 뺀 크기로 입력을 받냐면
		data에 문자열을 구성하기 위해 맨 뒤는 언제나 NULL 문자를 위한 자리를 만들어주어야 하기 때문이다.

		이렇게 입력을 받게 된다면 파일 위치 지정다는 e를 가리키게 된다.
	*/
	printf("입력 받은 데이터 : %s \n", data);

	c = fgetc(fp);	// fp에서 문자를 받아옴 (e가 들어가고) 옆으로 옮겨서 ' '(띄어쓰기)를 가리키게 될것.
	// 띄어쓰기도 ASCII 값이 대응되어 있는 엄연한 문자이다.
	printf("그 다음에 입력 받은 문자 : %c \n", c); // e

	fseek(fp, -1, SEEK_CUR);
	/*
		SEEK_CUR은 현재 파일의 위치지정자의 위치를 나타낸다.
		두 번째 인자로 -1을 전달했으니 왼쪽으로 1만큼 옮기란느 것이다.

		즉 현재 파일 위치지정자의 위치에서 왼쪽으로 -1만큼 다시 옮겼으니
		파일 위치지정자가 이전의 'e'를 가리키게 된다.
	*/

	c = fgetc(fp); // e를 얻어오고, ' '를 가리킨다.
	printf("그렇다면 무슨 문자가? : %c \n", c); // e가 나올 것이다.

	fclose(fp);
	return 0;
}