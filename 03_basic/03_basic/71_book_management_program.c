/*
	도서 관리 프로그램을 만들어봅시다. 프로그램에는 다음과 같은 기능들이 구현되어 있어야 합니다. (난이도 : 上)
	- 책을 새로 추가하는 기능 (책의 총 개수는 100 권이라 하자. 이 때, 각 책의 정보는 제목, 저자의 이름, 출판사로 한다)
	- 책의 제목을 검색하면 그 책의 정보가 나와야 한다.
	- 위와 마찬가지로 저자, 출판사 검색 기능이 있어야 한다.
	- 책을 빌리는 기능
	- 책을 반납하는 기능

	거대한 프로그램을 만들 때는 작은 프로그램을 만들 때와 달리 체계적으로 계획을 세우는 자세가 필요하다.
	이때, 체계적으로 계획을 세우는 자세란 다음 모두를 생각해보는 것이다.
	1) 이 프로그램은 무슨 작업을 하는가?
	2) 이 작업이 꼭 필요한 것인가?(그렇지 않다면 1)로 돌아간다)
	3) 어떤 환경에서 프로그램이 작동되는가?
	4) 무슨 언어로 개발할 것인가?

	1)의 경우 프로그램 계획 단계에서 가장 중요한 부분 중 하나이다.
	현재 만들 프로그램은 "도서 관리 프로그램"이다. 
	이 도서 관리 프로그램에는 정말 도서를 관리하는데 꼭 필요한 기능이 들어가야한다.
	예를 들어서 과제로 요구된 것들이다. 
	만일 쓸데 없는 작업들을 많이 넣게 되면 프로그램 용량도 커지고 개발하는데 시간도 많이들어 좋지 않다.

	2)의 경우 1)에서 내가 한 것들을 확인하는 단계이다.
	필요 없는 기능이거나 꼭 필요하지 않거나, 아니면 이 프로그램의 목적과 부합하지 않는 작업들의 경우 
	다시 1번으로 돌아가 생각해 보아야할 필요성이 있다.

	3) 우리에게 큰 문제가 아니지만 실제로 프로그램 개발시 상당히 중요한 역할이다.
	우리가 만드는 프로그램은 Windows에서 작동될 수도 있고 Linux나 MacOS에서 작동될 수도 있다.
	아니면 TV나 냉장고, 세탁기 같은 가전 제품에서도 작동될 수 있다.

	우리는 이러한 프로그램의 작동 환경에 맞춰 프로그램을 어떻게 만들지 고민해야한다.
	예를 들어 은행의 ATM에서 작동되는 프로그램은 보안이 최고로 우선이어야 한다. 비교적 속도가 느리더라도 말이다.
	iPhone같은 스마트폰에서 작동되는 프로그램은 스마트폰 사양이 보통 PC보다 좋지 않으므로 프로그램을 가볍고 빠르게 만들어야한다.
	우리가 만들 도서 관리 프로그램은 그냥 WIndows에서만 작동되도 충분하다.

	4) 프로그램을 어떠한 언어로 만들지 결정하는 단계이다.
	세상에는 수 많은 언어들이 있는데 현재 공부하는 C말고도 각각 특성을 가지는 언어들이 있따.
	이때마다 1,2,3 번을 충분히 고려해 가장 효율적인 언어를 선택해서 프로그램을 만들어야 한다.
	물론 현재는 C로 만든다.
*/
#include <stdio.h>

int add_book(char(*book_name)[30], char(*auth_name)[30],
	char(*publ_name)[30], int* borrowed, int* num_total_book);
int search_book(char(*book_name)[30], char(*auth_name)[30],
	char(*publ_name)[30], int num_total_book);
int borrow_book(int* borrowed);
int return_book(int* borrowed);
int compare(char* str1, char* str2);

int main() {
	int user_choice; /* 유저가 선택한 메뉴*/

	/*
		이 프로그램에 필요한 변수는?
		기본적으로 책의 제목, 출판사 이름, 저자의 이름을 저장할 배열이 필요하다.
		그리고 현재 이 책의 상태(빌렸는지 아닌지)를 표시할 수 있는 배열도 필요하다.
		마지막으로 현재 책의 총 개수가 있어야 나중에 책을 새로 추가할 때 배열의 몇 번째 원소를 표시할 지를 알 수 있다.
	*/
	char book_name[100][30], auth_name[100][30], publ_name[100][30];
	int borrowed[100]; // 빌려졌는 지 아닌지 상태 표시
	int num_total_book = 0; // 현재 책의 수

	while (1) {
		printf("도서 관리 프로그램 \n");
		printf("메뉴를 선택하세요 \n");
		printf("1. 책을 새로 추가하기 \n");
		printf("2. 책을 검색하기 \n");
		printf("3. 책을 빌리기 \n");
		printf("4. 책을 반납하기 \n");
		printf("5. 프로그램 종료 \n");

		printf("당신의 선택은 : ");
		scanf("%d", &user_choice);
		if (user_choice == 1) {
			/* 책을 새로 추가하는 함수 호출 */
			add_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
		}
		else if (user_choice == 2) {
			/* 책을 검색하는 함수 호출 */
			search_book(book_name, auth_name, publ_name, num_total_book);
		}
		else if (user_choice == 3) {
			/* 책을 빌리는 함수 호출 */
			borrow_book(borrowed);
		}
		else if (user_choice == 4) {
			/* 책을 반납하는 함수 호출 */
			return_book(borrowed);
		}
		else if (user_choice == 5) {
			/* 프로그램을 종료한다. */
			break;
		}
	}

	return 0;
}

int add_book(char(*book_name)[30], char(*auth_name)[30],
	char(*publ_name)[30], int* borrowed, int* num_total_book) {
	printf("추가할 책의 제목 : ");
	scanf("%s", book_name[*num_total_book]);

	printf("추가할 책의 저자 : ");
	scanf("%s", auth_name[*num_total_book]);

	printf("추가할 책의 출판사 : ");
	scanf("%s", publ_name[*num_total_book]);

	borrowed[*num_total_book] = 0; // 빌려지지 않음
	printf("추가 완료 ! \n");
	(*num_total_book)++;
	
	return 0;
}

int search_book(char(*book_name)[30], char(*auth_name)[30],
	char(*publ_name)[30], int num_total_book) {
	/*
		우리가 도서 관리 프로그램에서 만들 '검색'기능은 우리가 알고 있는 검색 기능과 살짝 다르다.
		우리가 하느히 쓰는 검색 기능은 문자열이 비슷하거나 형태를 포함해도 검색 결과에 나타나지만
		우리가 만든 검색 기능은 문자열이 완전히 같을 때 나타난다.

		추후 업데이트시 이 부분도 고려해서 하도록 하자.
	*/
	int user_input;
	char user_search[30];

	printf("어느 것으로 검색 할 것인가요? \n");
	printf("1. 책 제목 검색 \n");
	printf("2. 지은이 검색 \n");
	printf("3. 출판사 검색 \n");
	scanf("%d", &user_input);

	printf("검색할 단어를 입력해주세요 : ");
	scanf("%s", user_search);

	printf("검색 결과 \n");

	if (user_input == 1) {
		for (int i = 0; i < num_total_book; i++) {
			if (compare(book_name[i], user_search)) {
				printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i,
					book_name[i], auth_name[i], publ_name[i]);
			}
		}
	}
	else if (user_input == 2) {
		for (int i = 0; i < num_total_book; i++) {
			if (compare(auth_name[i], user_search)) {
				printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i,
					book_name[i], auth_name[i], publ_name[i]);
			}
		}
	}
	else if (user_input == 3) {
		for (i = 0; i < num_total_book; i++) {
			if (compare(publ_name[i], user_search)) {
				printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i,
					book_name[i], auth_name[i], publ_name[i]);
			}
		}
	}

	return 0;
}

int borrow_book(int* borrowed) {
	/* 사용자로 부터 책번호를 받을 변수*/
	int book_num;

	printf("빌릴 책의 번호를 말해주세요 \n");
	printf("책 번호 : ");
	scanf("%d", &book_num);

	if (borrowed[book_num] == 1) {
		printf("이미 대출된 책입니다! \n");
	}
	else {
		printf("책이 성공적으로 대출되었습니다. \n");
		borrowed[book_num] = 1;
	}

	return 0;
}

int return_book(int* borrowed) {
	/* 반납할 책의 번호 */
	int num_book;

	printf("반납할 책의 번호를 써주세요 \n");
	printf("책 번호 : ");
	scanf("%d", &num_book);

	if (borrowed[num_book] == 0) {
		printf("이미 반납되어 있는 상태입니다\n");
	}
	else {
		borrowed[num_book] = 0;
		printf("성공적으로 반납되었습니다\n");
	}

	return 0;
}

int compare(char* str1, char* str2) {
	while (*str1) {
		if (*str1 != *str2) {
			return 0;
		}

		str1++;
		str2++;
	}

	if (*str2 == '\0') return 1;

	return 0;
}