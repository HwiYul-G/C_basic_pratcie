/*
	���� ����ü ������ ������ �� �Ʒ��� ���� �ۼ��ߴ�.
	struct Anomynous Var, Var2;

	�׷��� ����ü ������ �����ϴ� ���ٸ� ����� �ִ�.
*/
#include <stdio.h>
char copy_str(char* dest, char* src);
int Print_Obj_Status(struct obj OBJ);

struct obj {
	/*
		�⺻������ �츮�� �ϴ� ��ó��
		struct obj��� ����ü�� �����߰� ����� �Ʒ��� �ִ�.
		�׷��� �Ʒ� �ִ� Ball�� �����ΰ�?

		�̴� �ٷ� struct obj���� Ball�̶� ����ü ������ �����϶�� ���̴�.
		�̷ν� main �Լ����� struct obj Ball; �̶�� �� ���� �Ⱦ��� �� �� �ִ�.

		��� main �Լ����� struct obj Ball; �̶�� �� �Ͱ� �����ϴ�.
	*/
	char name[20];
	int x, y;
} Ball;

int main() {
	Ball.x = 3;
	Ball.y = 4;
	copy_str(Ball.name, "RED BALL");

	Print_Obj_Status(Ball);
	return 0;
}

char copy_str(char* dest, char* src) {
	while (*src) {
		*dest = *src;
		src++;
		dest++;
	}

	*dest = '\0';

	return 1;
}
int Print_Obj_Status(struct obj OBJ) {
	printf("Location of %s \n", OBJ.name);
	printf("( %d, %d ) \n", OBJ.x, OBJ.y);
	return 0;
}