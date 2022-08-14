#include <stdio.h>

int main() {
	char str[] = "sentence";
	char* pstr = "sentence";

	printf("str : %s \n", str);
	printf("pstr : %s \n", pstr);
	/*
		char* pstr = "sentence";�� ���� �̻��ϰ� ��������.
		sentence�� ���ڿ��̰�, � ������ �ּҰ��� �ƴϴ�.
		pstr�� char���� ����Ű�� �������̹Ƿ� char�� ������ �ּӹ��� �����Ѵ�.

		�׷��� �츮�� "sentence"�� Ư���� �ּҰ�ó�� ����ϰ� �ִ�.
		�׷���, "sentence"��� ���ڿ��� �ּҰ��� �´�.
		�׷��ٸ� ������ �ּҰ��ΰ�? �ٷ� "sentence"��� ���ڿ��� ����� �ּҰ�(�����ּҰ�)�̴�.

		�ϱ��� �ʴ� �ٸ�
		printf("%d \n", "sentence");�� �����غ���.
	*/
	printf("%d \n", "sentence");
	// ������ Ư���� ���� ��µ��� �� �� �ִ�. �׷��ٸ� �� "sentence"�� ����ü �����ϱ�?

	char str2[] = "hello";
	char* pstr2 = "goodbye";

	str2[1] = 'a';
	pstr2[1] = 'a';
	/*
		���� �ڵ带 �����غ��� ���������� ������ �߾ ���� �� ������ ����.
		
		�켱 pstr2[1] = 'a';�� �ּ�ó���� �� �����غ��� ����� ������� �� �� �ִ�.
		�� pstr2[1] = 'a';�� ������ ���̴�.
		�� ������ �߻��� ���ϱ�? 
		
		���� ���� �������� pstr�� ���� �б⸸ ���� ��(printf�Լ��� ���� �������� �ʴ´�.)
		���������� ����Ǿ�����, �Ʒ����� pstr2[1] = 'a'; �� ���� pstr2�� ���� �����Ͽ��� �� ������ ��µ� ���� ����
		��ġ ���ó�� ��ǻ�Ϳ��� ���� �����ϵ��� ������� �ʴ� �� ����.
	*/

	/*
		literal(���ͷ�)
		���α׷��� ���� literal�̶� �ҽ� �ڵ�󿡼� '������ ��'�� ������ ���� ���´´�.
		Ư�� C����� ��� ū ����ǥ(")�� ���� �͵��� ���ڿ� ���ͷ�(string literal)�̶�� �θ���.

		char *pstr = "goodbye";
		printf("why so serious?");
		scanf("%c", str[0]);

		�׷��ٸ� ���� 3���� ���忡�� ���ڿ� ���ͷ��� �����ΰ�?
		�ٷ� goodbye, why so serious, %c ��ΰ� ���ͷ��̴�.

		��ǻ�ʹ� �̷��� ���ͷ����� ���� ��Ƽ� �����Ѵ�. 
		�� ���α׷��� �����ϸ� �޸� ���� Ư���� ���� ���ͷ����� �޸��� �����Ǿ� �ִ� ������ �����.

		���� char *pstr = "goodbye"�� �����ϰ� �Ǹ� 
		��ǻ�ʹ� "goodbye"�� ���� �ּҰ��� �����ͼ� pstr�� ���� �ض� ��� �ǹ��� �۾��� �����Ѵ�.
		���� pstr�� "goodbye"��� ���ͷ��� ����Ű�� printf("%s", pstr)�� ���� �� goodbye�� ���������� ����� �� �ְ� �ȴ�.

		�׷��� �Ʊ� ���ߴ� ��ó�� ���ͷ��� ������ "�ҽ� �ڵ� �󿡼� ������ ���� ������ �͵�"�̴�.
		�� ���� ���α׷� �Ⱦ� �߿����� ���ͷ��� ���� ����� ����Ǽ��� �ȵȴٴ� ���̴�.

		�Ʊ ���ߵ��� ���� hello��� ���ͷ��� ���� �Ǽ��� hi�� �����ߴٸ� 
		����ڴ� �и��� str�� hello��� ���� ������� ���������� hi�� ���� �Ǿ� ū ������ �߱��� �� �ִ�.

		���� ���ͷ��� �����Ǵ� ���� '���� �б⸸ ������ ��'�� �ȴ�. 
		���� �� ���� �Ժη� �����Ϸ��� �õ��ϸ� �ٷ� ���α׷��� �������� �ȴ�.

		�׷��� ������ �츮�� char str[] = "hello";�� �ߴٸ� str�� hello�� ����
		printf("why so serious");�� �ߴٸ� ȭ�鿡 why so serious�� ��µ� ���̶�� ������ �� �ִٴ� ���̴�.
		�ֳ��ϸ� �� ��� ���ڿ����� string literal�̶�� �̸� �Ͽ� �޸� ���� Ư���� �������� ��ȣ�ް� �ֱ� �����̴�.

		// == �߰� ���� ==
		���α׷��� ����Ǿ �޸𸮿� �ε�Ǹ� 5������ ����(text segment, data segment, bsssegment, heap, stac)�� �����Ѵ�.
		�̶� text segment�� ���α׷� �ڵ�� ���, ���ͷ� ���� ���ǵȴ�.
		�ֳ��ϸ� text segment�� �ִ� ������� only read �̱� �����̴�.
		���� �� ����� �����Ϸ� ������ ���� os ȯ�濡 ���� �ٸ� �� �ִ�.
		// ====

		char *pstr2 = "goodbye";
		pstr2[1] = 'a';
		�ٽ� ���� �ڵ带 ����.
		goodbye�� ���ڿ� �����̹Ƿ� text segment ������ ����ȴ�. �׸��� �� ���� ���� �б� �����ϹǷ�
		���⸦ �õ��� �� ������ �հ� �ȴ�.

		�ݸ鿡 printf("pstr2 : %s \n, pstr2);�� ���� read���� �����ϴ� �۾��� �� ����ȴ�.

		�׷��ٸ� �Ʒ� �ڵ�� ���?
		char str[] = "hello";
		��� ���� hello�� ���ͷ��̶�� �θ��� �ָ��ϴ�. �ֳ��ϸ� �迭�� ���Ǵ� �����Ϸ��� ���� �Ʒ��� ���� �ؼ��Ǳ� �����̴�.
		char str[] = {'h', 'e','l', 'l', 'o', '\0'};
		�̴� �׳� str�̶�� �迭�� hello��� ���ڿ��� �����ϰ� �� ���̴�.
		�׸��� ���� �迭�� text segment�� �ƴ϶� stack�̶�� �޸� ������ ������ ������ ���ǵȴ�.
		���� str ���� ���ڿ��� ������ �����ϴ�.

		!! ������ VS2017 �̻󿡼��� literal�� char*�� ����ų �� ����.
		�ݵ�� const char*�� �����Ѿ��ϸ� ���п� ���ͷ��� �����ϴ� ������ ���� ������ �ܿ��� ���� �� �ִ�.
		


		
	*/

	return 0;
}