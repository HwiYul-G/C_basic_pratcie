
#include <stdio.h>
char copy_str(char* dest, const char* src);
struct Books {
	/* å �̸� */
	char name[30];
	/* ���� �̸� */
	char auth[30];
	/* ���ǻ� �̸� */
	char publ[30];
	/* ���� ������? */
	int borrowed;
};

int main() {
	struct Books Harry_Potter;

	copy_str(Harry_Potter.name, "Harry Potter");
	copy_str(Harry_Potter.auth, "J.K. Rolling");
	copy_str(Harry_Potter.publ, "Scholastic");
	Harry_Potter.borrowed = 0;

	printf("å �̸� : %s \n", Harry_Potter.name);
	printf("���� �̸� : %s \n", Harry_Potter.auth);
	printf("���ǻ� �̸� : %s \n", Harry_Potter.publ);

	/*
	���� ������ ���� �츮�� ���� ���� ���α׷�����
	name[100][30], borrowed[100] ���� ������ ������ �迭�� index ��ȣ�� ���� ���� ������ �־��� ����
	����ü�� �� ���� ǥ���� �� �ְ� �ȴ�.

	�׷��� borrowed ��� ���� ������ ó���� �⺻������ 0���� �����Ǿ� �ִ�.
	�׷��ٸ� ���� ���� å�� ����� ������ �Ź� borrowed = 0�� ���� �ʿ� ���� ����ü���� �ٲٸ� �ȵɱ�?

	struct Books {
		char name[30];
		char auth[30];
		char publ[30];
		int borrowed = 0;
	};
	�̷��� �ٲ㼭 ������ �ϸ� ������ �⿬�� �� �� �ִ�.

	�̷��� ������ ���� ������ �����ϴ�.
	����ü�� ���ǿ����� ������ �ʱ�ȭ �� �� ���� �����̴�. �׳� �� ��� ��ü�� �޾Ƶ鿩���Ѵ�.
	Ư�� ���� ���� �Ǽ��� �� ��� ã�⵵ ��ư� �����鵵 ������ �͸� ���� �����ؾ��Ѵ�.

*/
	
	struct Books book_list[3];
	for (int i = 0; i < 3; i++) {
		printf("å %d ���� �Է� : ");
		scanf("%s%s%s", book_list[i].name, book_list[i].auth, book_list[i].publ);
		book_list[i].borrowed = 0;
	}
	for (int i = 0; i < 3; i++) {
		printf("------------------------------- \n");
		printf("å %s �� ����\n", book_list[i].name);
		printf("���� : %s \n", book_list[i].auth);
		printf("���ǻ� : %s \n", book_list[i].publ);

		if (book_list[i].borrowed == 0) {
			printf("�� ������\n");
		}
		else {
			printf("������ \n");
		}
	}
	/*
		struct Books book_list[3];
		int arr[3]���� int�� �ϳ��� Ÿ���� ��ó��, struct Books�� �ϳ��� Ÿ������ �����ϸ� �ȴ�.
		�׷���, int arr[3]�� �ϸ� arr�� int�� ���Ұ� 3�� �����������, book_list �迭���� struct Books �� ������ 3�� ����� ����.

		�׸��� ���� for���� ����
		scanf �Լ��� book_list�� i��° ������ name, auth, publ ����� ���ڿ��� �Է¹ް� �ִ� ����� �� �� �ִ�.
		���� borrowed�� ���� 0���� �ʱ�ȭ ���ְ� �ִ�.
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
