#include <stdio.h>
#include <string.h>

int main() {
	char str[50] = "I love Chewing C hahaha";

	printf("%s \n", str);	// I love Chewing C hahaha
	printf("memmove 이후 \n");
	memmove(str + 23, str + 17, 6);
	printf("%s \n", str);	// I love Chewing C hahahahahaha
	printf("%d \n", str[29]); // 마지막에 29가 NULL로 되었을까? => 저장된다.
	/*
		memmove(str + 23, str + 17, 6);
		이 함수의 경우 str + 17에서 6개의 문자를 str+23에 옮겼다.
		즉 hahaha의 시작부분에서 6개의 문자인 hahaha를 str의 맨 마지막 부분에 복사해 넣었다는 뜻이다.

		memmove 함수의 장점은 memcpy와 하는 일이 많이 비슷해보이지만
		사실 memcpy와 달리, 메모리 공간이 겹쳐도 된다.

		위의 경우도 str과 복사하는 부분이 겹쳤지만 성공적으로 수행하게 되었다.
		덕분에 나중에 memmove 함수를 아주 많이 사용하게 될 것이다.
	*/
	return 0;
}