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
	printf("å�� �̸� : ");
	scanf("%s", book_list[*nth].book_name);
	printf("å�� ���� : ");
	scanf("%s", book_list[*nth].auth_name);
	printf("å�� ���ǻ� : ");
	scanf("%s", book_list[*nth].publ_name);
	book_list[*nth].borrowed = 0;
	(*nth)++;
	return 0;
}

int search_book(BOOK* book_list, int total_num_book) {
    int user_input; /* ������� �Է��� �޴´�. */
    int i;
    char user_search[30];
    printf("��� ������ �˻� �� ���ΰ���? \n");
    printf("1. å ���� �˻� \n");
    printf("2. ������ �˻� \n");
    printf("3. ���ǻ� �˻� \n");
    scanf("%d", &user_input);
    printf("�˻��� �ܾ �Է����ּ��� : ");
    scanf("%s", user_search);
    printf("�˻� ��� \n");
    if (user_input == 1) {
        /* i �� 0 ���� num_total_book ���� ���鼭 ������ å ������ ����ڰ� �Է���
         * �˻���� ���ϰ� �ִ�. */
        for (i = 0; i < total_num_book; i++) {
            if (compare(book_list[i].book_name, user_search)) {
                printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }
    }
    else if (user_input == 2) {
        /* i �� 0 ���� num_total_book ���� ���鼭 ������ ������ �̸��� ����ڰ�
         * �Է��� �˻���� ���ϰ� �ִ�. */
        for (i = 0; i < total_num_book; i++) {
            if (compare(book_list[i].auth_name, user_search)) {
                printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }
    }
    else if (user_input == 3) {
        /* i �� 0 ���� num_total_book ���� ���鼭 ������ ���ǻ縦 ����ڰ� �Է���
         * �˻���� ���ϰ� �ִ�. */
        for (i = 0; i < total_num_book; i++) {
            if (compare(book_list[i].publ_name, user_search)) {
                printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }
    }
    return 0;
}

int borrow_book(BOOK* book_list) {
    int book_num;
    printf("���� å�� ��ȣ�� �����ּ��� \n");
    printf("å ��ȣ : ");
    scanf("%d", &book_num);
    if (book_list[book_num].borrowed == 1) {
        printf("�̹� ����� å�Դϴ�! \n");
    }
    else {
        printf("å�� ���������� ����Ǿ����ϴ�. \n");
        book_list[book_num].borrowed = 1;
    }
    return 0;
}
int return_book(BOOK* book_list) {
    int num_book;
    printf("�ݳ��� å�� ��ȣ�� ���ּ��� \n");
    printf("å ��ȣ : ");
    scanf("%d", &num_book);
    if (book_list[num_book].borrowed == 0) {
        printf("�̹� �ݳ��Ǿ� �ִ� �����Դϴ�\n");
    }
    else {
        book_list[num_book].borrowed = 0;
        printf("���������� �ݳ��Ǿ����ϴ�\n");
    }
    return 0;
}

int print_book_list(BOOK* book_list, int total_num_book) {
    FILE* fp = fopen("book_list.txt", "w");
    int i;

    if (fp == NULL) {
        printf("��� ���� ! \n");
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

    printf("��� �Ϸ�! \n");
    fclose(fp);

    return 0;
}

/* ������ book_list�� ���� �ٲ�� �ϹǷ� ���� ������ ����*/
int retrieve_book_info(BOOK** book_list, int* total_num_book) {
    FILE* fp = fopen("book_list.txt", "r");
    int total_book;
    char str[10];

    if (fp == NULL) {
        printf("������ ������ ã�� �� �����ϴ�! \n");
        return -1;
    }

    /* ã�Ҵٸ� ��ü å�� ������ �о�´�. */
    fscanf(fp, "%d", &total_book);
    (*total_num_book) = total_book;

    /* ������ book_list �����͸� ���� */
    free(*book_list);
    /* �׸��� malloc���� ���Ҵ� */
    (*book_list) = (BOOK*)malloc(sizeof(BOOK) * total_book);

    if (*book_list == NULL) {
        printf("\n ERROR \n");
        return 0;
    }

    for (int i = 0; i < total_book; i++) {
        /* book_list[i] -> book_name�� �ƴԿ� ����!! */
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