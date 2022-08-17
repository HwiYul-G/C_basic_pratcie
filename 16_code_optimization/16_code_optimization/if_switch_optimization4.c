/*
	if �� switch�� ����
	1) if���� 2�� ����� �ɰ���
	2) ������ �񱳿����� switch ���� ����ض�
	3) ��� ���̺�(look 'up table, LUT)�� ����� �� ������ ����ض�.
*/
#include <stdio.h>
char* Condition_String1(int condition);
int main() {
	// 1) if���� 2�� ����� �ɰ���
	int i;
	scanf("%d", &i);
	if (i == 1) {
	}
	else if (i == 2) {
	}
	else if (i == 3) {
	}
	else if (i == 4) {
	}
	else if (i == 5) {
	}
	else if (i == 6) {
	}
	else if (i == 7) {
	}
	else if (i == 8) {
	}
	/*
		���� ���� ���� ��ɵ��� switch���� �̿��ϴ� ���� �ξ� �ٶ����ϴ�.
		���� ��� if�������� �־��� ��� �ִ� 8���� ���۾��� �ؾ��ϹǷ� ��û�� �����̴�.

		������ �Ʒ��� ���� if���� �Ʒ��� ���� �����ϰ� �ȴٸ� ���?
		�Ʒ��� ���� if���� �ɰ��� ����
		Binary Breakdown�̶�� �Ѵ�.
		�� ������ ���·� �ɰ� ���̴�.
		�̷� ��� i�� 1���� 8���� ��� ���� �������� 3������ �񱳷� ���� �˾Ƴ� �� �ִ�.
		����� ������ if���� ���·� ��������� 4���� �񱳰� �ʿ��ߴ�.
	*/
	if (i <= 4) {
		if (i <= 2) {
			if (i == 1) {
				/* i is 1 */
			}
			else {
				/* i must be 2 */
			}
		}
		else {
			if (i == 3) {
				/* i is 3 */
			}
			else {
				/* i must be 4 */
			}
		}
	}
	else {
		if (i <= 6) {
			if (i == 5) {
				/* i is 5 */
			}
			else {
				/* i must be 6 */
			}
		}
		else {
			if (i == 7) {
				/* i is 7 */
			}
			else {
				/* i must be 8 */
			}
		}
	}

	// 2) ������ �񱳿����� switch ���� ����ض�
	/*
		��κ��� ���� �����Ϸ����� �� �۾��� �˾Ƽ� ����ȭ ���ش�.
		��� ���� if �� ����������
		�� ���� ���� �������� ���� ���� ���ϴ� ��쿡�� 
		switch���� ����ϴ� ���� �ſ� ����ϴ�.

		�� �Ʒ��� ���� �ڵ尡 �ξ� �� ȿ�����̴�.
	*/
	switch (i) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	}

	/*
		3) ������̺�(LUT)�� ����� �� ������ ����ض�
		��� ���̺��̶�, ���������� �����ϸ� Ư�� �����Ϳ��� �ٸ� �����ͷ� ��ȯ�� ��
		��� �Ǵ� ���̺��̶� �� �� �ִ�.
		���� ������ ���� ���� ��� ��ǻ�Ϳ��� �ſ� ���� ���ǰ� �ִ�.

		���� ��� ��ǻ�Ϳ��� 3D ó���� �� ��
		���� ���� sine�̳� cosine ������� ���� �ȴ�.
		�� �� sin �� ����� �� ���� �ð� �ɸ��� ����̴�.
		�׷��� sin 1 ���� �ʿ��� ������ ����� �ϰ� �Ǹ� ���� �ð� ���� ���ϴ�.
		�̸� ������ ���� ���α׷� ���� �ʱ⿡ sin1���� sin90 ���� �̸� ����� �� ��,,,
		ǥ�� ����� ������ ���߿� sin1 ���� �ʿ��ϸ� �ܼ��� ǥ���� 1 ��° ���� ã���� �Ǵϱ� ���ϴ�.

		�̷��� ����� ���� ���̺��� LUK��� �Ѵ�.
		�� �ʿ��� �����͸� ���� ã�� �� �ֵ��� �̸� ����� ���� ǥ�̴�.

		���� ��� char* Condition_String1(int condition)�� �Լ��� ���� ��� ����� �� �ִ�.
		char* Condition_String1(int condition)��
		char* Condition_String2(int condition)�� ����.

		char* Conditio_string2(int condition)�� lookUpTable�� ���� �ξ� ª�� ���α׷��� ũ�⵵ �پ��� �� �� �ִ�.
	*/
	return 0;
}

char* Condition_String1(int condition) {
	switch (condition) {
	case 0:
		return "EQ";
	case 1:
		return "NE";
	case 2:
		return "CS";
	case 3:
		return "CC";
	case 4:
		return "MI";
	case 5:
		return "PL";
	case 6:
		return "VS";
	case 7:
		return "VC";
	case 8:
		return "HI";
	case 9:
		return "LS";
	case 10:
		return "GE";
	case 11:
		return "LT";
	case 12:
		return "GT";
	case 13:
		return "LE";
	case 14:
		return "";
	default:
		return 0;
	}
}
char* Condition_String2(int condition) {
	if ((unsigned)condition >= 15) {
		return 0;
	}
	char* table[] = { "EQ", "NE", "CS", "CC", "MI", "PL", "VS",
					 "VC", "HI", "LS", "GE", "LT", "GT", "LE" };
	return table[condition];
}