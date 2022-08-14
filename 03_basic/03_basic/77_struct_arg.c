#include <stdio.h>

struct TEST {
	int age;
	int gender;
};
struct TEST3 {
	int age;
	int gender;
	char name[20];
};

int set_human(struct TEST a, int age, int gender);
int set_human2(struct TEST* a, int age, int gender);
int set_human3(struct TEST* a, int age, int gender, const char* name);
char copy_str(char* dest, const char* src);

int main() {
	struct TEST human;
	set_human(human, 10, 10);
	// printf("AGE : %d // Gender : %d ", human.age, human.gender);
	
	/*
		���������� �������ϸ� ������ ��Ÿ����.
		set_human(human, 10, 1);�� �����ϸ�
		human�� age�� gender ������� �ʱ�ȭ �� ��ó�� ���δ�.
		������ �׷��� �ʴ�.

		�ٷ� "Ư���� ������ ���� �ٸ� �Լ��� ���� �ٲٷ��� ������ �ּҰ��� �����ؾ� �Ѵ�"
		��� ���� ��Ű�� �ʾұ� �����̴�.

		�� a.age = age;�� ���� �� age�� ���� �ٲ�� ���� 
		���� main �Լ������� human�� �ƴ϶� 
		set_human �Լ��� a��� human�� ������ ����ü ������ age ����� ���� �ٲ�� �ȴ�.

		���� ���� human ����ü ������ ������� 
			���� �ʱ�ȭ ���� ���� ä ����� ����Ǿ� ������ �߻��ߴ�.

		�̸� �ذ��ϱ� ���ؼ� human ����ü ������ �ּҰ��� ���ڷ� �޴� �Լ��� ������ �Ѵ�.
	*/
	struct TEST human2;
	set_human2(&human2, 10, 1);
	printf("AGE : %d // Gender : %d ", human2.age, human2.gender);
	/*
		human�� �ּҰ��� ���ڷ� �����ϰ� �ִ�.
		���� set_human2�� ù ��° ������ a�� human�� ����Ű�� �ȴ�.
		
		������ ���� a�� ����� ����ü ������ �ƴ϶�� ���̴�.
		���� human ����ü ������ �޸� �翨 ��ġ�� ���� ���� ������ �ּҰ��� �����ϰ� ���� ���̴�.

		�ƹ�ư ���� ���� �����Ѵٸ�
		a->�� ���� a�� ����Ű�� �ִ� ����ü ������ ���, 
		�� ���� ��쿡�� human�� ����� ��Ī�� �� �ְ� �ȴ�.

		���� set_human2 �Լ� ���ο��� a-> age = age;�� �ϰ� �Ǹ�
		human�� age ����� ���� �ٲ��.

		���� ������ ���� a->age�� age�� �ٸ��ٴ� ���̴�.
		a->age�� human ����ü ������ int�� ��� age�� ��Ī�ϴ� ���̰�
		age�� �ܼ��� set_human �Լ����� ���ڷ� �޾Ƶ鿩�� int���� age�� ������ ����Ű�� ���̴�.
		�� ���� �ٸ� ���̰� ������ ��ǻ�� ���ο����� �ٸ��� ó���ʤ���.

	*/
	struct TEST3 human3;

	set_human3(&human3, 10, 1, "Lee");

	printf("AGE : %d // Gender : %d // Name : %s \n", human3.age, human3.gender, human3.name);

	return 0;
}

int set_human(struct TEST a, int age, int gender) {
	a.age = age;
	a.gender = gender;
	return 0;
}
int set_human2(struct TEST* a, int age, int gender) {
	a->age = age;
	a->gender = gender;
	return 0;
}
int set_human3(struct TEST3* a, int age, int gender, const char* name) {
	/*
		set_human3 �Լ����� name ��� ���� ���� �ʱ�ȭ���ֱ� ����
		���ڷ� char* ���� name�̶�� ���ڸ� �߰��� �ް� �ȴ�.
	*/
	a->age = age;
	a->gender = gender;
	copy_str(a->name, name);
	/*
		main�Լ��� human3 ����ü ������ name ����� �ʱ�ȭ �ϱ� ���ؼ���
		copy_str �Լ��� �̿��ؾ� �Ѵ�.

		�̸� ���ؼ��� name �迭�� �ּҰ��� 
			������ �������� ���ڿ��� �ּҰ��� �־���ϴµ�
		
		a -> name�� ���� human3 ����ü ������ name ����� �ּҰ���, name( �� ��° ���ڷ� a->name�� ���� �ٸ� ���̴�)
		�� ���� ������ �������� ���ڿ��� �ּҰ� copy_str�� ������ �� �ְ� �ȴ�.

		�ƹ�ư ���� ���� ���������� human3�� ������ ������� �ʱ�ȭ �� �� �ְ� �Ǿ���.
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