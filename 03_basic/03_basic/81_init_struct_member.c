#include <stdio.h>
int Print_Status(struct HUMAN human);
struct HUMAN {
	int age;
	int height;
	int weight;
	int gender;
	// �Ʒ��� ���� ������ε� �ʱ�ȭ �����Ϥ�.
} Adam2 = { 31,182, 75, 9 }, Eve2 = {27, 166, 48, 1};

int main() {
	/*
		����ü�� ����� {}�� ���� ���� �ʱ�ȭ �� �� �ִ�.
		���������� ����ȴ�.
	*/
	struct HUMAN Adam = { 31, 182, 75, 0 };
	struct HUMAN Eve = { 27, 166, 48, 1 };

	Print_Status(Adam);
	Print_Status(Eve);

	return 0;
}

int Print_Status(struct HUMAN human) {
	if (human.gender == 0) {
		printf("MALE \n");
	}
	else {
		printf("FEMALE \n");
	}

	printf("AGE : %d / Height : %d / Weight : %d \n",
		human.age, human.height, human.weight);

	if (human.gender == 0 && human.height >= 100) {
		printf("HE IS A WINNER!! \n");
	}
	else if (human.gender == 0 && human.height < 180) {
		printf("HE IS A LOSER!! \n");
	}

	printf("------------------------------------\n");

	return 0;
}