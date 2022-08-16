/*
	���ݱ��� �������� �ڷ������� ����Դ�.
	������ �����ϰ� �����ϴ� ���� ���� ���� �迭�� �̿��߰�,
	�迭�� ����� �Ѱ踦 ���� ����ü�� �������.
	�׸��� ����ü �ϳ��� �� �� �Ѱ��� �ٷ�µ� �Ѱ踦 ���� ����ü �迭�� �̿��ߴ�.
	
	���� �Ҵ��� ������ ����ڰ� ���ϴ� ũ���� �Է��� �ٷ� �� �ְ� �Ǿ��ٰ� �ص�
	���� ���� ������ ������ �ִ�.
	���� ����ڰ� ������ ���ؼ� �� ���� �Է��� �� �ް� �ʹٸ� ���� ��찡 �ִ�.
	���Ӱ� �����Ҵ����� �ϸ� ������ ������� 1000���� �����Ͱ� �ִµ� 1���� �߰����� �����͸� ����
	1001���� ���� ������ ���� ������ �ʹ� �Ʊ���.

	�̸� �ذ��ϴ� ���� �ٷ� '���'�̴�.
	���� (������ |���� ��带 ����Ű�� ������) �������� �����.

	�̸� C�ڵ�� ��Ÿ���� �Ʒ��� ����.
	struct Node{
		int dat;
		struct Node* nextNode;
	};

	�� ù��° ��尡 ���� ��带 ����Ű�� ���� ���� �ڽ��� ���� ��带 ����Ű�� ������ �� �̾�����.
	������ ���� �ƹ��͵� ����Ű�� �ʴ´�.
	���� ������ ���� �����͸� �ϳ��� ������ �ִ�. 
	�� ���߿� �����͸� �� �� �� �߰��Ϸ��� �ϸ� ������ ��忡 �� ��带 ���� �̾��ֱ⸸ �ϸ� �ȴ�.

	������ ��� ���ķθ� �����͸� �߰��� �� �ִ� �� �ƴ϶� �߰����� ������ ���� ���ϴ�.
	���ο� ��带 �����ؼ� ���� ������� ������ ���ָ� �ȴ�.

	�̷��� ����� �������� ��带 ����� ����.
*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* nextNode;
};
struct Node* CreateNode(int data); // Node�� �����ϱ�'��'�ϴ� �Լ�
struct Node* InsertNode(struct Node* current, int data); // � ��� �ڿ� ���ο� ��带 �����ϴ� �Լ�
void DestroyNode(struct Node* destroy, struct Node* head); // Node�� �ı��ϴ� ������ ������ �Լ�
void PrintNodeFrom(struct Node* from);

int main() {
	struct Node* Node1 = CreateNode(100);
	struct Node* Node2 = InsertNode(Node1, 200);
	struct Node* Node3 = InsertNode(Node2, 300);
	struct Node* Node4 = InsertNode(Node2, 400); // Node2 �ڿ� Node4�� ����

	PrintNodeFrom(Node1);

	return 0;
}

struct Node* CreateNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));	// node�� �޸� �Ҵ�

	newNode->data = data;
	newNode->nextNode = NULL; // ����Ű�� ���� ��带 NULL

	return newNode;
}
struct Node* InsertNode(struct Node* current, int data) {
	// �տ� �ִ� ����� ���� current, ���ο� ��带 ���� data
	
	// current ��尡 ����Ű�� �ִ� ���� ��尡 after�̴�.
	struct Node* after = current->nextNode;

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->nextNode = after;

	current->nextNode = newNode;

	return newNode;
}

void DestroyNode(struct Node* destroy, struct Node* head) {
	// destroy : �ı��ϰ��� �ϴ� ���, head : ù ���
	// ����Ű�� �ִ� ��带 ã�� ���ؼ� �� ó������ ������������.
	
	// ���� ��带 ����ų ������
	struct Node* next = head;

	// head�� �ı��Ϸ� �Ѵٸ�
	if (destroy == head) {
		free(destroy);
		return;
	}

	while (next)
	{
		// next node�� destroy��� next�� destroy �� ���
		if (next->nextNode == destroy) {
			// ���� next�� ���� ���� destroy�� �ƴ϶� destroy�� ���� ��尡 �ȴ�.
			next->nextNode == destroy->nextNode;
		}
		next = next->nextNode;
	}
	free(destroy);
}
void PrintNodeFrom(struct Node* from) {
	while (from) {
		printf("����� ������ : %d \n", from->data);
		from = from->nextNode;
	}
}
/*
	Node�� �迭�� �޸� �߰�/����/������ ������ ���ϴ�.
	�׷��ٰ� �ؼ� ��尡 �迭���� ������ ���� �ƴϴ�.

	�ֳ��ϸ� �迭�� ��� 3��° ���ҿ� �����ϱ� ���ؼ� �ܼ��� arr[3]���� �ϸ� ������
	����� ��� ���κ��� 3��° ���� ������ 'Ž��'�ؾ��ϱ� �����̴�.

	���� N���� ��尡 �ֵ��� �־��� ��� N������ ��� ã�ƾ�������
	�迭�� ��� Ư���� ��� �ð� ���� ã�ư� �� �ֱ� ������ �� �κп� ���ؼ� �迭�� ������ ����.

	���� ����� ��� �����͸� ���� ���� ���� ���� ��带 ����Ű�� ���� 8byte�� �� �ʿ�� �ϱ� ������ ���������ε� �ణ ���ظ� ����.

	���� ��������� �̾߱� ���ڸ�
	�߰�/����/������ ���� �Ͼ�� ���� ��带 ����ϰ� Ư���� ��°�� ã�ư��� �ϴ� ���� ���� ���� �迭�� ����ϴ� ���� �̷Ӵ�.

	��� ��� ���� �������� ������ �ڷᱸ������ �ִ�. (ex, ����, ť, Ʈ�� ��)

*/