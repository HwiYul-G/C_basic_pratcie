#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	double celsius; // ���� �µ�

	printf("���� �µ��� ȭ�� �µ��� �ٲ��ִ� ���α׷� �Դϴ�. \n");
	printf("���� �µ��� �Է��� �ּ��� : ");
	scanf("%lf", &celsius); // ���� �µ��� �Է¹޴´�.

	printf("���� %f ���� ȭ���� %f �� �Դϴ�. \n", celsius, 9 * celsius / 5 + 32);


	char ch; // ����
	
	short sh; //����
	int i;
	long lo;
	
	float fl; //�Ǽ�
	double du;

	// �ѱ��� 2byte �̻��� �����ϹǷ� �ִ� 1byte�� �����ϴ� char�� ������ �ѱ��� ġ�� ������ ��  
	// = > ���� �޸� �̻� �����͸� ����־� �߻��ϴ� ���� �����÷ο�
	printf("char �� ���� �Է� : ");
	scnaf("%c", &ch);

	printf("short �� ���� �Է� : ");
	scanf("%hd", &sh);
	printf("int �� ���� �Է� : ");
	scanf("%d", &i);
	printf("long �� ���� �Է� : ");
	scanf("%ld", &lo);

	printf("float �� ���� �Է� : ");
	scanf("%f", &fl);
	printf("double �� ���� �Է� : ");
	scanf("%lf", &du);

	printf("char : %c, short : %d, int : %d ", ch, sh, i);
	printf("long : %ld, float : %f, double : %f \n", lo, fl, du);

	return 0;
}

// scanf ��� scanf_s�� ����϶�� ����ϴ� �� �̴�
// scanf�� �������� ũ�⸦ Ȯ������ �ʾƼ� ���� �����÷ο�(�Է¹޴� �������� ũ�Ⱑ �غ�� �������� ū ����)�� �߻��� �� �ֱ� �����̴�.

/*
	printf : ȭ�鿡 ����� ������ִ� �Լ� // scanf : ȭ��(Ű����)�� ���� ����� �޾Ƶ��̴� �Է� �Լ�
	scanf�� � �Է��� �ϱ���� ��� ��ٸ���. ����, �Է��� �� �� ���͸� �����߸� �Է����� ó���ȴ�.
	printf���� �� ������ ����� ���� (%d, %f, %c .. )�� �������� �ٸ��� �ϴ� ��ó�� scanf�� �� ������ Ÿ�Ը��� �Է¹޴� ������ �޸��ؾ� �Ѵ�.

	printf�� double�̳� float ��� %f�� ����Ѵ�.
	������ scanf�� double ���� ������ �Է¹������� %lf�� �ؾ��ϰ� float�� %f�� �ؾ��Ѵ�. 
*/