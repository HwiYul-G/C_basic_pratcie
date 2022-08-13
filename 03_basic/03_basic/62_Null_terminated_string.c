/*
	���ڿ��� ����� string�̶�� �ϴµ�, ������ �ǹ̴� ���̴�.
	�׷��� ���ڿ��� string�̶� �θ��� ������ ���� ���ڿ��� ��ó�� ���ڵ��� �޸��� ������ ���̱� �����̴�.
	
	��ǻ�ʹ� ���ڿ��� ��ó�� �޸��� ������ �����Ѵ�. �� ���ڵ��� ���� char�迭�� �����Ѵ�.

	char s[5];
	s[0] = 'H', s[1] = 'e', s[2] = 'l', s[3] ='l', s[4] = 'o'
	���������� �޸𸮿� ����� ���� �� ���ڿ� �ش��ϴ� '�ƽ�Ű ��'�̴�. 
	�̸� ���ڷ� �����ϴ���, ���ڷ� �����ϴ��Ĵ� ���α׷����� �����̴�.

	���� ���� ���ڿ� s�� �������� ��
	���� �츮�� char �迭 s�� ����� ���ڵ��� ȭ�鿡 ����Ѵٰ� ����. 
	���� ���� ��� "s�� ���ڿ��� �����, �� ���ڴ� 3���� ���ھ�"��� ��������ϴ� �������� �����.
	�� ������ ���� �� �� ����.

	���ڿ��� ���״�� ���ڵ��� �ϳ��� ���ļ� �ٴϴ� ���̹Ƿ�(���� �츮�� s�� ���ڿ��� �̿��Ѵٰ� �ϸ� ù ��¥ H�� �̿��� ���� �ƴϱ⿡)
	���ڿ��� �̿��� ������ ���ڿ��� ���̸� �˾ƾ��ϴ� ������ ���� �߻��Ѵ�.

	���� C�����ڵ���
	char s[6];
	s[0] = 'H', s[1] = 'e', s[2] = 'l', s[3] ='l', s[4] = 'o', s[5] = 0
	ó�� ����ϴ� ����� �����Ҵ�.

	�� ���ڿ��� ���� ��������� ���ڿ��̿����ϴ�.��� �˷��ִ� ���� ���ڸ� ���� ���̴�.
	�� ���� ���ڴ� �ƽ�ũ ���� 0�̰�, '\0'�̶���� ��Ÿ����. ���� ���� '0'�� �򰥸��� �ȵȴ�.
	���� 0�� �ƽ�Ű �ڵ� ���� 0�� �ƴ϶� 48�̴�.
	����, �� ���� ���ڸ� �����Ѽ� ��(Null)�̶�� �θ���.

	�� ���ڰ� �� ������ �־�� �ϱ� ������ 3���ڶ�� �ص� �迭�� 4ĭ�� �ʿ��ϴ�.
	�̷��� �� ���Ṯ�ڸ� ��������� ���ڿ��� ���� ���� ���� �� �ִ� ������ �����.
	���ڿ� s�� ������� �̰� 3���ڷ� �Ǿ��־� ��� ���� �ʿ� ���� s���ڿ��� ������� ��� ���ص�
	��ǻ�Ͱ� �˾Ƽ� null�� ���� ������ ����ؾ��� �ϰ� �Ѵ�.
*/
#include <stdio.h>

int main() {
	// �� 3������ ��� ������ null �̴�.
	char null_1 = '\0';
	char null_2 = 0;
	char null_3 = (char)NULL; // ��� �빮�ڷ� ����ؾ� �Ѵ�

	char not_null = '0'; // �̰��� ���� '0'�� �ƽ�Ű�ڵ� 48�̴�.

	printf("NULL�� ����(�ƽ�Ű)�� : %d, %d, %d \n", null_1, null_2, null_3);// 0 0 0
	printf("'0'�� ����(�ƽ�)�� : %d \n", not_null); // 48
	// ���� ������ ���� �츮�� ���ڿ��� ���������� ���� ���ڷ� NULL�̳� '\0'�̳� ���� 0�� �ƴ� 0�̶� �� ��ü�� ����� �� ������ �˾Ҵ�.
	/*
		������ �� �Ʒ��� ���� ����� ������ ��쵵 �ִ�.
		warning C4047 : '�ʱ�ȭ ��' : 'char'�� ���� ���� ������ 'void *'��(��) �ٸ��ϴ�.
		��ټ��� �汸�� �߿��� ������ ������ ���⼭�� ����� ���� �߿����� �ʱ� ������ ������� �ʾƵ� �ȴ�.
	*/

	//�Ʒ� ������ ���� ���ڿ��� �� Ȯ���� ��������.
	char sentence_1[4] = { 'P', 's', 'i', '\0' };
	char sentence_2[4] = { 'P', 's', 'i', 0 };
	char sentence_3[4] = { 'P', 's', 'i', (char)NULL };
	// ���� ����ǥ�� �迭�� �ϳ��ϳ� ������ ���ڿ��� �����ϴ� ���� ���ŷο� ���̴�.
	// ���� �Ʒ��� ���� ""�� ���� �����ָ� �˾Ƽ� ���ڷ� �־��ش�. �̶� NULL���ڴ� �ڿ� �ڵ����� �߰��Ǵ� ���� ū����ǥ �ȿ� ������ �ʿ�� ����.
	// ���� �ϴ� �Ǽ��� "Psi"�� �����س��� �迭�� ũ�⸦ 3���� ��� ��찡 �ֱ� �����̴�. �׷��� sentence�� ���� NULL�� ���� �ʾ�
	// sentence�� ���ڿ��� ����϶�� ���� �� NULL�� ���� ������ �𸣹Ƿ� ������ �ʴ� �޸� ������ �аԵǴ� ������ �߻��Ѵ�.
	// �ݵ�� NULL�� ���� ���� �ϳ��� �� �߰��ؾ��Ѵ�.
	char sentence_4[4] = { "Psi" };	

	printf("sentence_1 : %s \n", sentence_1);  // %s �� ���ؼ� ���ڿ��� ����Ѵ�.
	printf("sentence_2 : %s \n", sentence_2);
	printf("sentence_3 : %s \n", sentence_3);
	printf("sentence_4 : %s \n", sentence_4);

	//======= ������ ���� ���� ==========
	char word[30] = { "long sentence" };
	char* str = word; // &word[0]

	printf("%s \n", str);// str�� ����Ű�� ���� ���ڿ��� ���(��, ���� ���� ������ ���)

	// ====== ���ڿ� �ٲٱ� =======
	char word2[] = { "long sentence" }; // ������ ������ �����ϴ� �κ��� ��ĭ���� �� ���� �����Ϸ��� �˾Ƽ� ������ ������ ���� ��ĭ�� ä���� ��.

	printf("���� ���� : %s \n", word2);

	word2[0] = 'a';
	word2[1] = 'b';
	word2[2] = 'c';
	word2[3] = 'd';

	printf("���� ���� : %s \n", word2);



	return 0;
}