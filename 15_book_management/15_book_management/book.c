#include "book.h"
#include <stdio.h>
#include <stdlib.h>

char compare(char* str1, char* str2) {
	while (*str1) {
		if (*str1 != *str2) {
			return 0; // 0 is false
		}
		str1++;
		str2++;
	}
	if (*str2 == '\0') return 1;
	return 0;
}

int register_book(BOOK* book_list, int* nth) {
	printf("책의 이름 : ");
	scanf("%s", book_list[*nth].book_name);
	printf("책의 저자 : ");
	scanf("%s", book_list[*nth].auth_name);
	printf("책의 출판사 : ");
	scanf("%s", book_list[*nth].publ_name);
	book_list[*nth].borrowed = 0;
	(*nth)++;
	return 0;
}

int search_book(BOOK* book_list, int total_num_book) {
    int user_input; /* 사용자의 입력을 받는다. */
    int i;
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
        /* i 가 0 부터 num_total_book 까지 가면서 각각의 책 제목을 사용자가 입력한
         * 검색어와 비교하고 있다. */
        for (i = 0; i < total_num_book; i++) {
            if (compare(book_list[i].book_name, user_search)) {
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }
    }
    else if (user_input == 2) {
        /* i 가 0 부터 num_total_book 까지 가면서 각각의 지은이 이름을 사용자가
         * 입력한 검색어와 비교하고 있다. */
        for (i = 0; i < total_num_book; i++) {
            if (compare(book_list[i].auth_name, user_search)) {
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }
    }
    else if (user_input == 3) {
        /* i 가 0 부터 num_total_book 까지 가면서 각각의 출판사를 사용자가 입력한
         * 검색어와 비교하고 있다. */
        for (i = 0; i < total_num_book; i++) {
            if (compare(book_list[i].publ_name, user_search)) {
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }
    }
    return 0;
}

int borrow_book(BOOK* book_list) {
    int book_num;
    printf("빌릴 책의 번호를 말해주세요 \n");
    printf("책 번호 : ");
    scanf("%d", &book_num);
    if (book_list[book_num].borrowed == 1) {
        printf("이미 대출된 책입니다! \n");
    }
    else {
        printf("책이 성공적으로 대출되었습니다. \n");
        book_list[book_num].borrowed = 1;
    }
    return 0;
}
int return_book(BOOK* book_list) {
    int num_book;
    printf("반납할 책의 번호를 써주세요 \n");
    printf("책 번호 : ");
    scanf("%d", &num_book);
    if (book_list[num_book].borrowed == 0) {
        printf("이미 반납되어 있는 상태입니다\n");
    }
    else {
        book_list[num_book].borrowed = 0;
        printf("성공적으로 반납되었습니다\n");
    }
    return 0;
}

int print_book_list(BOOK* book_list, int total_num_book) {
    FILE* fp = fopen("book_list.txt", "w");
    int i;

    if (fp == NULL) {
        printf("출력 오류 ! \n");
        return -1;
    }

    fprintf(fp, "%d\n", total_num_book);

    for (i = 0; i < total_num_book; i++) {
        fprintf(fp, "%s\n%s\n%s\n", book_list[i].book_name, book_list[i].auth_name,
            book_list[i].publ_name);
        if (book_list[i].borrowed == 0)
            fprintf(fp, "NO\n");
        else
            fprintf(fp, "YES\n");
    }

    printf("출력 완료! \n");
    fclose(fp);

    return 0;
}

/* 포인터 book_list의 값을 바꿔야 하므로 더플 포인터 형태*/
int retrieve_book_info(BOOK** book_list, int* total_num_book) {
    FILE* fp = fopen("book_list.txt", "r");
    int total_book;
    char str[10];

    if (fp == NULL) {
        printf("지정한 파일을 찾을 수 없습니다! \n");
        return -1;
    }

    /* 찾았다면 전체 책의 개수를 읽어온다. */
    fscanf(fp, "%d", &total_book);
    (*total_num_book) = total_book;

    /* 기존의 book_list 데이터를 삭제 */
    free(*book_list);
    /* 그리고 malloc으로 재할당 */
    (*book_list) = (BOOK*)malloc(sizeof(BOOK) * total_book);

    if (*book_list == NULL) {
        printf("\n ERROR \n");
        return 0;
    }

    for (int i = 0; i < total_book; i++) {
        /* book_list[i] -> book_name이 아님에 유의!! */
        fscnaf(fp, "%s", (*book_list)[i].book_name);
        fscanf(fp, "%s", (*book_list)[i].auth_name);
        fscanf(fp, "%s", (*book_list)[i].publ_name);
        fscanf(fp, "%s", str);

        if (compare(str, "YES")) {
            (*book_list)[i].borrowed = 1;
        }
        else if (compare(str, "NO")) {
            (*book_list)[i].borrowed = 0;
        }
    }
    fclose(fp);
    return 0;
}