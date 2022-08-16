/*
	����ü ���� '����ڰ� ���� �ϳ��� ������ Ÿ��'�̴�.
	�ٽ� ���� ����ü�� intó�� ����� �� �ִٴ� ���̴�.
	���� ����ü �迭�� malloc�� �̿��� ������ ���� ���� ���� �̻��� ���� ����.
*/
#include <stdio.h>
#include <stdlib.h>

struct Something {
	int a, b;
};

int main() {
	struct Something* arr; // struct Something�� ����Ű�� ������
	int size, i;

	printf("���Ͻô� ����ü �迭�� ũ�� : ");
	scnaf("%d", &size);

	/*
		malloc�� �̿��� arr�� ���� ������ �Ҵ��� �ش�.
		�̿� �ʿ��� ũ��� �翬�� sizeof(struct Somthing_*size) �̴�.

		���� sizeof ��� ����ü�� ���� ũ�⸦ ����ؼ� ���ϴ� ��� ������ �߻��Ѵ�.
		���� ��� Something ����ü�� ��� 1���� 8byte�� �����Ѵٰ� �� �� �ִµ� ��� �׷��� ���� ���� �ִ�.

		���� �� ���� �� Ư��������,
		���� ��� ����ü�� ũ�Ⱑ 10byte�� ��� ��ǻ�Ͱ� '���� ���� ���(double world boundary)'�� ��������
		�ӵ��� ����Ű�� ��찡 �ִ�.
		�� ��� ����ü�� ũ��� 12byte�� ���ֵ� �� �ִ�.
		=> ������ sizeof�� ����ؾ� �Ѵٴ� ���� ���!
	*/
	arr = (struct Something*)malloc(sizeof(struct Something) * size);

	for (i = 0; i < size; i++) {
		printf("arr[%d].a : ", i);
		scnaf("%d", &arr[i].a);
		printf("arr[%d].b : ", i);
		scanf("%d", &arr[i].b);
	}

	for (i = 0; i < size; i++) {
		printf("arr[%d].a : %d, arr[%d].b : %d \n", i, arr[i].a, i, arr[i].b);
	}
	free(arr);

	return 0;
}