#include <stdio.h>
struct employee {
	int age;
	int salary;
};
struct company {
	struct employee data;
	char name[10];
	/*
		�Ǵٸ� ����ü ������ ����� ���� ����ü
		����ü�� ����ڰ� ������ �Ǵٸ� ��(type)�̱� ������ �̰��� ������ ���� �翬�ϴ�.

		����ü ���� int�� char�� ���� �ϳ��� ���̴�.
		�츮�� ���� ���� �̸��� struct employee��� ���̰�
		�� �� data��� (����ü) ������ �����ߴ�.

		int a�� ������ ������ ���̴�.
	*/
};
int main() {
	struct company Kim;

	Kim.data.age = 31;
	Kim.data.salary = 3000000;
	/*
		����鿡 ���� ������ ��
		'.'�������� �켱 ������ ���ʺ����̹Ƿ�
		Kim.data�� �ؼ��� �� Kim.data�� .age�� �ؼ��ȴ�

		�ٽø��� Kim�� data ����� age ����� ���� ����.
	*/

	printf("Kim's age : %d \n", Kim.data.age);
	printf("Kim's salary : %d$/year \n", Kim.data.salary);

	return 0;
}