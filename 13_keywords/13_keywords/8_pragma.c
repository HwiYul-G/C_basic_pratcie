#include <stdio.h>
/* ��ó���� ��ɿ��� ; �� ������ �ʴ´�! */
#pragma pack(1)
struct Weird {
	char arr[2];
	int i;
};
int main() {
	struct Weird a;
	printf("size of a : %d \n", sizeof(a));	// 6
	return 0;
}
/*
	pragma Ű���带 ����ϴ� �����Ѵ�� 6���� �� ���´�.
	#pragma pack(1) �� MS�迭�� �����Ϸ��鿡�� ��ȿ�� �����ε�,
	����ü�� 1byte ������ �����϶�� ���̴�.

	�� ����ü�� ũ�Ⱑ 1�� ����� �ǰ� �϶�� ���̴�. 1�ܿ��� 2,4,8,16 ���� �� �� �ִ�.
	���� �⺻��, �� ���� ���� ���� �����ϱ� ���ؼ��� #pragma pack(4)�� �ϸ� �ȴ�.

	9_pragma.c���� �̾
*/