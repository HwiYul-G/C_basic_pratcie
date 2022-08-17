#include <stdio.h>
#include <stdlib.h>
#include "book.h"

int main() {
    int user_choice;        /* 유저가 선택한 메뉴 */
    int num_total_book = 0; /* 현재 책의 수 */

    BOOK* book_list;
    int i;

    printf("도서관의 최대 보관 장서 수를 설정해주세요 : ");
    scanf("%d", &user_choice);

    book_list = (BOOK*)malloc(sizeof(BOOK) * user_choice);

    while (1) {
        printf("도서 관리 프로그램 \n");
        printf("메뉴를 선택하세요 \n");
        printf("1. 책을 새로 추가하기 \n");
        printf("2. 책을 검색하기 \n");
        printf("3. 책을 빌리기 \n");
        printf("4. 책을 반납하기 \n");
        printf("5. 프로그램 종료 \n");
        printf("6. 책들의 내용을 book_list.txt 에 출력 \n");
        printf("7. 책들의 내용을 book_list.txt 에서 불러옴 \n");
        printf("8. 책들의 목록을 출력 \n");

        printf("당신의 선택은 : ");
        scanf("%d", &user_choice);

        if (user_choice == 1) {
            /* 책을 새로 추가하는 함수 호출 */
            register_book(book_list, &num_total_book);
        }
        else if (user_choice == 2) {
            /* 책을 검색하는 함수 호출 */
            search_book(book_list, num_total_book);
        }
        else if (user_choice == 3) {
            /* 책을 빌리는 함수 호출 */
            borrow_book(book_list);
        }
        else if (user_choice == 4) {
            /* 책을 반납하는 함수 호출 */
            return_book(book_list);
        }
        else if (user_choice == 5) {
            /* 프로그램을 종료한다. */
            break;
        }
        else if (user_choice == 6) {
            /* book_list.txt 에 책들의 목록을 출력한다*/
            print_book_list(book_list, num_total_book);
        }
        else if (user_choice == 7) {
            /* book_list.txt 에서 책들의 목록을 가져온다*/
            retrieve_book_info(&book_list, &num_total_book);
        }
        else if (user_choice == 8) {
            /* 책들의 목록을 화면에 출력한다. */
            for (i = 0; i < num_total_book; i++) {
                printf("%s // %s // %s // ", book_list[i].book_name,
                    book_list[i].auth_name, book_list[i].publ_name);
                if (book_list[i].borrowed == 0)
                    printf("NO\n");
                else
                    printf("YES\n");
            }
        }
    }

    free(book_list);
    return 0;
}