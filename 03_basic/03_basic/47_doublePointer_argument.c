/*
	� �Լ��� Ư���� Ÿ���� ����/�迭�� ���� �ٲٷ��� 
	�Լ��� ���ڴ� �ݵ�� Ÿ���� ����Ű�� ������ ���� �̿��ؾ��Ѵ�.
*/
#include <stdio.h>

int pswap(int** ppa, int** ppb);
int main() {
	int a, b;
	int* pa, * pb;

	pa = &a;
	pb = &b;

	printf("pa �� ����Ű�� ������ �ּҰ� : %p \n", pa);	//0x7ffc5ffd7520 
	printf("pa �� �ּҰ� : %p \n \n", &pa);	// 0x7ffc5ffd7528 
	printf("pb �� ����Ű�� ������ �ּҰ� : %p \n", pb);	// 0x7ffc5ffd7524 
	printf("pb �� �ּҰ� : %p \n", &pb);	// 0x7ffc5ffd7530

	printf(" ------------- ȣ�� -------------- \n");
	pswap(&pa, &pb);
	printf(" ------------- ȣ�ⳡ -------------- \n");

	printf("pa �� ����Ű�� ������ �ּҰ� : %p \n", pa);	// 0x7ffc5ffd7524 
	printf("pa �� �ּҰ� : %p \n \n", &pa);	// 0x7ffc5ffd7528
	printf("pb �� ����Ű�� ������ �ּҰ� : %p \n", pb);	// 0x7ffc5ffd7520
	printf("pb �� �ּҰ� : %p \n", &pb);	// 0x7ffc5ffd7530

	return 0;
}

int pswap(int** ppa, int** ppb) {
	int* temp = *ppa;

	printf("ppa�� ����Ű�� ������ �ּҰ� : %p \n", ppa);// 0x7ffc5ffd7528
	printf("ppb�� ����Ű�� ������ �ּҰ� : %p \n", ppb);	// 0x7ffc5ffd7530 

	*ppa = *ppb;
	*ppb = temp;
	
	return 0;
}