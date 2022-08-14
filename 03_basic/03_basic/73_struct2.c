
#include <stdio.h>
char copy_str(char* dest, const char* src);
struct Books {
	/* 책 이름 */
	char name[30];
	/* 저자 이름 */
	char auth[30];
	/* 출판사 이름 */
	char publ[30];
	/* 빌려 졌나요? */
	int borrowed;
};

int main() {
	struct Books Harry_Potter;

	copy_str(Harry_Potter.name, "Harry Potter");
	copy_str(Harry_Potter.auth, "J.K. Rolling");
	copy_str(Harry_Potter.publ, "Scholastic");
	Harry_Potter.borrowed = 0;

	printf("책 이름 : %s \n", Harry_Potter.name);
	printf("저자 이름 : %s \n", Harry_Potter.auth);
	printf("출판사 이름 : %s \n", Harry_Potter.publ);

	/*
	위의 내용을 보면 우리가 도서 관리 프로그램에서
	name[100][30], borrowed[100] 등을 정의해 각각의 배열에 index 번호를 맞춰 따로 정의해 주었던 것을
	구조체로 한 번에 표현할 수 있게 된다.

	그런데 borrowed 멤버 값은 언제나 처음에 기본적으로 0으로 설정되어 있다.
	그렇다면 굳이 새로 책을 등록할 때마다 매번 borrowed = 0을 해줄 필요 없이 구조체에서 바꾸면 안될까?

	struct Books {
		char name[30];
		char auth[30];
		char publ[30];
		int borrowed = 0;
	};
	이렇게 바꿔서 컴파일 하면 오류의 향연을 볼 수 있다.

	이러한 오류가 나온 이유는 간단하다.
	구조체의 정의에서는 변수를 초기화 할 수 없기 때문이다. 그냥 그 사실 자체로 받아들여야한다.
	특히 위와 같은 실수를 할 경우 찾기도 어렵고 오류들도 엉뚱한 것만 나와 조심해야한다.

*/
	
	struct Books book_list[3];
	for (int i = 0; i < 3; i++) {
		printf("책 %d 정보 입력 : ");
		scanf("%s%s%s", book_list[i].name, book_list[i].auth, book_list[i].publ);
		book_list[i].borrowed = 0;
	}
	for (int i = 0; i < 3; i++) {
		printf("------------------------------- \n");
		printf("책 %s 의 정보\n", book_list[i].name);
		printf("저자 : %s \n", book_list[i].auth);
		printf("출판사 : %s \n", book_list[i].publ);

		if (book_list[i].borrowed == 0) {
			printf("안 빌려짐\n");
		}
		else {
			printf("빌려짐 \n");
		}
	}
	/*
		struct Books book_list[3];
		int arr[3]에서 int가 하나의 타입인 것처럼, struct Books도 하나의 타입으로 생각하면 된다.
		그런데, int arr[3]을 하면 arr에 int형 원소가 3개 만들어지듯이, book_list 배열에는 struct Books 형 변수가 3개 만들어 진다.

		그리고 나서 for문을 보면
		scanf 함수로 book_list의 i번째 원소의 name, auth, publ 멤버에 문자열을 입력받고 있는 모습을 볼 수 있다.
		또한 borrowed의 값도 0으로 초기화 해주고 있다.
	*/
	return 0;
}

char copy_str(char* dest, const char* src) {
	while (*src) {
		*dest = *src;
		src++;
		dest++;
	}

	*dest = '\0';

	return 1;
}
