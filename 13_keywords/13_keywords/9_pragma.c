/*
	#pragma once
	�Ʊ��� Weird ����ü �������� Werid �κи� �ٸ� ������Ϸλ����� ����.
	�� ��������� �̸��� werid.h�̴�.
*/
#include <stdio.h>
#include "werid.h"
int main() {
	struct Weird a;
	a.i = 3;
	printf("Weired ����ü�� a.i : %d \n", a.i);
	return 0;
}
/*
	9_pragma.c���� weird.h�� ���������Ƿ�
	weird.h�� ������ 9_pragma.c�� �״�� ����� ���̴�.
	(�� #include "weird.h" �κ��� weird.h�� �������� �ٲ���ٰ� ���� �ȴ�.)
	���� struct Weird�� ����� �� �ְ� �ǹǷ� ���� ���� ����� �߻��Ѵ�.
	
	�׷��� ���� �Ǽ��� weird.h�� 2�� �����ߴٰ� ����.
	�� #include "werid.h" #include "werid.h"�� �� ���̴�.
	�̷��� �Ǹ� error C2011 : 'Weird' : 'struct' ���� ������ 'Weird' ������ �����Ͻʽÿ�.
	��� ������ ������ �ȴ�.

	�׸��� �̰��� �Ʒ��� �� �Ͱ� ������ �ൿ�̴�.
	#include <stdio.h>
	struct Weird {
	  char arr[2];
	  int i;
	};
	struct Weird {
	  char arr[2];
	  int i;
	};

	int main() {
	  struct Weird a;
	  a.i = 3;
	  printf("Weird ����ü�� a.i : %d \n", a.i);
	  return 0;
	}

	�̸� �������� ��� �ؾ��ұ�?
	=> 10_pragma.c
*/