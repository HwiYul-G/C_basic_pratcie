#include <stdio.h>
#include <stdlib.h>
#include "book.h"

int main() {
    int user_choice;        /* ������ ������ �޴� */
    int num_total_book = 0; /* ���� å�� �� */

    BOOK* book_list;
    int i;

    printf("�������� �ִ� ���� �弭 ���� �������ּ��� : ");
    scanf("%d", &user_choice);

    book_list = (BOOK*)malloc(sizeof(BOOK) * user_choice);

    while (1) {
        printf("���� ���� ���α׷� \n");
        printf("�޴��� �����ϼ��� \n");
        printf("1. å�� ���� �߰��ϱ� \n");
        printf("2. å�� �˻��ϱ� \n");
        printf("3. å�� ������ \n");
        printf("4. å�� �ݳ��ϱ� \n");
        printf("5. ���α׷� ���� \n");
        printf("6. å���� ������ book_list.txt �� ��� \n");
        printf("7. å���� ������ book_list.txt ���� �ҷ��� \n");
        printf("8. å���� ����� ��� \n");

        printf("����� ������ : ");
        scanf("%d", &user_choice);

        if (user_choice == 1) {
            /* å�� ���� �߰��ϴ� �Լ� ȣ�� */
            register_book(book_list, &num_total_book);
        }
        else if (user_choice == 2) {
            /* å�� �˻��ϴ� �Լ� ȣ�� */
            search_book(book_list, num_total_book);
        }
        else if (user_choice == 3) {
            /* å�� ������ �Լ� ȣ�� */
            borrow_book(book_list);
        }
        else if (user_choice == 4) {
            /* å�� �ݳ��ϴ� �Լ� ȣ�� */
            return_book(book_list);
        }
        else if (user_choice == 5) {
            /* ���α׷��� �����Ѵ�. */
            break;
        }
        else if (user_choice == 6) {
            /* book_list.txt �� å���� ����� ����Ѵ�*/
            print_book_list(book_list, num_total_book);
        }
        else if (user_choice == 7) {
            /* book_list.txt ���� å���� ����� �����´�*/
            retrieve_book_info(&book_list, &num_total_book);
        }
        else if (user_choice == 8) {
            /* å���� ����� ȭ�鿡 ����Ѵ�. */
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