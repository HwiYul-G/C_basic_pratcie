/*
	N �������� M �������� ��ȯ�ϴ� ���α׷��� ��������. (���̵� : ��)
	N, M�� ��� 36�����̴�.
	�ֳ��ϸ� ���� �̿�� 1,2,3 ... A, B... �� �̿��ϴµ� ���ĺ��� 26���̹Ƿ� 36�������� ��Ÿ�� �� �ֱ� �����̴�.
*/
#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	��� �ڷκ��� ���� �������� ���� �������� ��Ȱ�� �� �Է¹���(N, M �Է�)
	
	N������ ���� �Է¹���
	
	�� ���� �� �ڸ��� ������ int �迭 ���� ����. �̶� ���� �������� ����
	���� �� 16�������� 7AE�� �Է¹޾Ҵٸ� digit[0] = 14, digit[1] = 10, digit[2] = 7�� ������ �ȴ�.
	�ùٸ��� ���� ���ڰ� �ԷµǸ� �����Ѵ�. (���� ��� 2�����ε� 3�̶� ���� �̿�� ����)

	�� ���� �������� ��ȯ�Ѵ�. (NtoDec �Լ� ���� ���)

	�� �������� �ٽ� M ������ ���� ��ȯ�Ѵ�. (DectoM �Լ� ���� ���)
*/