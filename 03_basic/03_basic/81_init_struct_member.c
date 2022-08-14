#include <stdio.h>
int Print_Status(struct HUMAN human);
struct HUMAN {
	int age;
	int height;
	int weight;
	int gender;
	// 아래와 같은 방식으로도 초기화 가능하ㅏ.
} Adam2 = { 31,182, 75, 9 }, Eve2 = {27, 166, 48, 1};

int main() {
	/*
		구조체의 멤버를 {}를 통해 쉽게 초기화 할 수 있다.
		순차적으로 적용된다.
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