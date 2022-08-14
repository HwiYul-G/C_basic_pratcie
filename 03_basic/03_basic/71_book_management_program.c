/*
	���� ���� ���α׷��� �����ô�. ���α׷����� ������ ���� ��ɵ��� �����Ǿ� �־�� �մϴ�. (���̵� : ߾)
	- å�� ���� �߰��ϴ� ��� (å�� �� ������ 100 ���̶� ����. �� ��, �� å�� ������ ����, ������ �̸�, ���ǻ�� �Ѵ�)
	- å�� ������ �˻��ϸ� �� å�� ������ ���;� �Ѵ�.
	- ���� ���������� ����, ���ǻ� �˻� ����� �־�� �Ѵ�.
	- å�� ������ ���
	- å�� �ݳ��ϴ� ���

	�Ŵ��� ���α׷��� ���� ���� ���� ���α׷��� ���� ���� �޸� ü�������� ��ȹ�� ����� �ڼ��� �ʿ��ϴ�.
	�̶�, ü�������� ��ȹ�� ����� �ڼ��� ���� ��θ� �����غ��� ���̴�.
	1) �� ���α׷��� ���� �۾��� �ϴ°�?
	2) �� �۾��� �� �ʿ��� ���ΰ�?(�׷��� �ʴٸ� 1)�� ���ư���)
	3) � ȯ�濡�� ���α׷��� �۵��Ǵ°�?
	4) ���� ���� ������ ���ΰ�?

	1)�� ��� ���α׷� ��ȹ �ܰ迡�� ���� �߿��� �κ� �� �ϳ��̴�.
	���� ���� ���α׷��� "���� ���� ���α׷�"�̴�. 
	�� ���� ���� ���α׷����� ���� ������ �����ϴµ� �� �ʿ��� ����� �����Ѵ�.
	���� �� ������ �䱸�� �͵��̴�. 
	���� ���� ���� �۾����� ���� �ְ� �Ǹ� ���α׷� �뷮�� Ŀ���� �����ϴµ� �ð��� ���̵�� ���� �ʴ�.

	2)�� ��� 1)���� ���� �� �͵��� Ȯ���ϴ� �ܰ��̴�.
	�ʿ� ���� ����̰ų� �� �ʿ����� �ʰų�, �ƴϸ� �� ���α׷��� ������ �������� �ʴ� �۾����� ��� 
	�ٽ� 1������ ���ư� ������ ���ƾ��� �ʿ伺�� �ִ�.

	3) �츮���� ū ������ �ƴ����� ������ ���α׷� ���߽� ����� �߿��� �����̴�.
	�츮�� ����� ���α׷��� Windows���� �۵��� ���� �ְ� Linux�� MacOS���� �۵��� ���� �ִ�.
	�ƴϸ� TV�� �����, ��Ź�� ���� ���� ��ǰ������ �۵��� �� �ִ�.

	�츮�� �̷��� ���α׷��� �۵� ȯ�濡 ���� ���α׷��� ��� ������ �����ؾ��Ѵ�.
	���� ��� ������ ATM���� �۵��Ǵ� ���α׷��� ������ �ְ��� �켱�̾�� �Ѵ�. ���� �ӵ��� �������� ���̴�.
	iPhone���� ����Ʈ������ �۵��Ǵ� ���α׷��� ����Ʈ�� ����� ���� PC���� ���� �����Ƿ� ���α׷��� ������ ������ �������Ѵ�.
	�츮�� ���� ���� ���� ���α׷��� �׳� WIndows������ �۵��ǵ� ����ϴ�.

	4) ���α׷��� ��� ���� ������ �����ϴ� �ܰ��̴�.
	���󿡴� �� ���� ������ �ִµ� ���� �����ϴ� C������ ���� Ư���� ������ ������ �ֵ�.
	�̶����� 1,2,3 ���� ����� ������ ���� ȿ������ �� �����ؼ� ���α׷��� ������ �Ѵ�.
	���� ����� C�� �����.
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
	int user_choice; /* ������ ������ �޴�*/

	/*
		�� ���α׷��� �ʿ��� ������?
		�⺻������ å�� ����, ���ǻ� �̸�, ������ �̸��� ������ �迭�� �ʿ��ϴ�.
		�׸��� ���� �� å�� ����(���ȴ��� �ƴ���)�� ǥ���� �� �ִ� �迭�� �ʿ��ϴ�.
		���������� ���� å�� �� ������ �־�� ���߿� å�� ���� �߰��� �� �迭�� �� ��° ���Ҹ� ǥ���� ���� �� �� �ִ�.
	*/
	char book_name[100][30], auth_name[100][30], publ_name[100][30];
	int borrowed[100]; // �������� �� �ƴ��� ���� ǥ��
	int num_total_book = 0; // ���� å�� ��

	while (1) {
		printf("���� ���� ���α׷� \n");
		printf("�޴��� �����ϼ��� \n");
		printf("1. å�� ���� �߰��ϱ� \n");
		printf("2. å�� �˻��ϱ� \n");
		printf("3. å�� ������ \n");
		printf("4. å�� �ݳ��ϱ� \n");
		printf("5. ���α׷� ���� \n");

		printf("����� ������ : ");
		scanf("%d", &user_choice);
		if (user_choice == 1) {
			/* å�� ���� �߰��ϴ� �Լ� ȣ�� */
			add_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
		}
		else if (user_choice == 2) {
			/* å�� �˻��ϴ� �Լ� ȣ�� */
			search_book(book_name, auth_name, publ_name, num_total_book);
		}
		else if (user_choice == 3) {
			/* å�� ������ �Լ� ȣ�� */
			borrow_book(borrowed);
		}
		else if (user_choice == 4) {
			/* å�� �ݳ��ϴ� �Լ� ȣ�� */
			return_book(borrowed);
		}
		else if (user_choice == 5) {
			/* ���α׷��� �����Ѵ�. */
			break;
		}
	}

	return 0;
}

int add_book(char(*book_name)[30], char(*auth_name)[30],
	char(*publ_name)[30], int* borrowed, int* num_total_book) {
	printf("�߰��� å�� ���� : ");
	scanf("%s", book_name[*num_total_book]);

	printf("�߰��� å�� ���� : ");
	scanf("%s", auth_name[*num_total_book]);

	printf("�߰��� å�� ���ǻ� : ");
	scanf("%s", publ_name[*num_total_book]);

	borrowed[*num_total_book] = 0; // �������� ����
	printf("�߰� �Ϸ� ! \n");
	(*num_total_book)++;
	
	return 0;
}

int search_book(char(*book_name)[30], char(*auth_name)[30],
	char(*publ_name)[30], int num_total_book) {
	/*
		�츮�� ���� ���� ���α׷����� ���� '�˻�'����� �츮�� �˰� �ִ� �˻� ��ɰ� ��¦ �ٸ���.
		�츮�� �ϴ��� ���� �˻� ����� ���ڿ��� ����ϰų� ���¸� �����ص� �˻� ����� ��Ÿ������
		�츮�� ���� �˻� ����� ���ڿ��� ������ ���� �� ��Ÿ����.

		���� ������Ʈ�� �� �κе� �����ؼ� �ϵ��� ����.
	*/
	int user_input;
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
		for (int i = 0; i < num_total_book; i++) {
			if (compare(book_name[i], user_search)) {
				printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s \n", i,
					book_name[i], auth_name[i], publ_name[i]);
			}
		}
	}
	else if (user_input == 2) {
		for (int i = 0; i < num_total_book; i++) {
			if (compare(auth_name[i], user_search)) {
				printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s \n", i,
					book_name[i], auth_name[i], publ_name[i]);
			}
		}
	}
	else if (user_input == 3) {
		for (i = 0; i < num_total_book; i++) {
			if (compare(publ_name[i], user_search)) {
				printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s \n", i,
					book_name[i], auth_name[i], publ_name[i]);
			}
		}
	}

	return 0;
}

int borrow_book(int* borrowed) {
	/* ����ڷ� ���� å��ȣ�� ���� ����*/
	int book_num;

	printf("���� å�� ��ȣ�� �����ּ��� \n");
	printf("å ��ȣ : ");
	scanf("%d", &book_num);

	if (borrowed[book_num] == 1) {
		printf("�̹� ����� å�Դϴ�! \n");
	}
	else {
		printf("å�� ���������� ����Ǿ����ϴ�. \n");
		borrowed[book_num] = 1;
	}

	return 0;
}

int return_book(int* borrowed) {
	/* �ݳ��� å�� ��ȣ */
	int num_book;

	printf("�ݳ��� å�� ��ȣ�� ���ּ��� \n");
	printf("å ��ȣ : ");
	scanf("%d", &num_book);

	if (borrowed[num_book] == 0) {
		printf("�̹� �ݳ��Ǿ� �ִ� �����Դϴ�\n");
	}
	else {
		borrowed[num_book] = 0;
		printf("���������� �ݳ��Ǿ����ϴ�\n");
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