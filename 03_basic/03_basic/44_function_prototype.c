/*
	[�Լ��� ����]
	���� �Լ��� ����ϸ鼭 �Լ����� ��� main �Լ� ������ ���ǵǰ� �־���.
	�׷��� �� ���Ǹ� main ���� �Ʒ����� �Ѵٸ� ��� �ɱ�?

	(��� ��κ��� ������� ��� main �Լ��� ���� ���� ���� ������ �Լ����� main �Լ� �ڿ� ���ǵǰ� �Ѵ�.)
	
	���� ���,
	#include <stdio.h>
	int main(){
		int i =3, j = 5;
		swap(&i, &j);
		return 0;
	}
	int swap(int *a, int*b){
		int tmp = *a;
		*a = *b;
		*b = tmp;
		return 0;
	}
	���� ���� �� ��� ������ �ϰ� �Ǹ� �Ʒ��� ���� ����� ���.
	warning C4013 : 'swap'��(��) ���ǵ��� �ʾѽ��ϴ�. extern�� int���� ��ȯ�ϴ� ������ �����Ѵ�.
	
	�����ϰ� �����ϸ� �� ����ȴ�. �׷��ٸ� �ƹ� ���� ���� ���ϱ�?
	��� �Լ��� ������ �� ����ϸ� ������ �߻����� �ʴ´�.
	������ ����� ��������� ���α׷����ϴٰ� �Ǽ��� ������ ������ �����ϰ� ���ų� �ùٸ��� �ʴ� Ÿ���� ������ ����ϴ� ���� ���� �߻��Ѵ�.
	���� ���α׷� �ÿ��� Ư���� ���� ���� �Լ��� �̿��ϱ� �����̴�.

	���� ���� ���¿��� �Լ��� �Ǽ��� �����ؼ� swap(&i)�� �ϰ� ������ �ϸ�
	������ ����� �������� ���� Ư���� ���ڸ� �����ߴٴ� ���� ������ �ʴ´�.
	
	�׸��� �����ϸ� �����Ͻ� �ƹ� ���� �޽����� �����µ� ������ ����.
	�����Ϸ��� ���� ���ڸ� ��� �����ߴ��� ���� ǥ�������� �ʾƼ� ������ ã�� ������� �� �ۿ� ����.

	swap�Լ��� ȣ�� �κ��� swap(&i, j); �� �����ص� ������ ����.
	�����͸� �����ؾ��ϴµ� �������� �����ؼ� ������ b�� �޸��� �ùٸ��� ���� ������ �����߱� �����̴�.
	�����Ϸ��� �̷��� �Ǽ��� �ϳ��� ���� ���ϰ� �ִ�.

	C���� �Լ��� ����(prototype)�� �̿��� �̸� �ذ��ϰ� ���ش�.
*/

#include <stdio.h>
int swap(int* a, int* b);	// �Լ��� ����(prototype)
int main() {
	int i, j;
	i = 3;
	j = 5;

	printf("SWAP ���� : i : %d, j : %d \n", i, j);
	swap(&i, &j);
	printf("SWAP ���� : i : %d, j : %d \n", i, j);

	return 0;
}

int swap(int* a, int* b) {
	int temp = *a;

	*a = *b;
	*b = temp;

	return 0;
}
/*
	�ҽ��ڵ带 ���� �� ���� �� ���� �߰��� ���� �� �� �ִ�. �װ��� '�Լ��� ����'�̴�.
	�̴� �Լ��� ���� �κ��� �� �� �� ���� �ͻ��̴�. (������ ���� �Լ��� �������� ���ǿʹ� �޸� �ڿ�;�� ���� �ٴ� ���̴�.)
	�׷���, �� ������ �����Ϸ����� ���� ���� ����� �˷��ش�.
	"�� �ҽ��ڵ忡 �̷��� �Լ��� ���ǵǾ� ������ �� ����� �����Ϸ���!" ��� �����ִ� ���̴�.

	�� �����Ϸ����� �� �ҽ��ڵ忡 ���Ǵ� �Լ��� ���� ������ �����ϴ� ���̴�.
	�ٽ� ���� ���� ���α׷����� ���� �ݿ����� ���� �����̴�. �׷����� �츮�� �ռ� �Ͽ��� �Ǽ����� ���� �ʵ��� �����ش�.
	����, ���� ���� �Լ��� ������ ������ ���¿��� ���ڸ� &i �ϳ��� ��������.
	�� swap(&i);�� �����غ���.

	�׷� �����Ͻ� error C2198 : 'swap' : ȣ�⿡ �Ű� ������ �ʹ� �����ϴ�. ��� ����� ������.

	�Լ��� ������ ���� ���� �ʾ��� ���� ����(�Ű� ����)�� �ϳ� �ٿ��� 
	�ƹ��� ���� �ʴ� �����Ϸ��� ������ �����ϰ� ���� ���� ���� ��Ȯ�� ��ġ�� ���� ��� �߸��ߴ��� ��Ƴ���.
	�̰��� ������ ������ �ٷ� �����Ϸ����� ���� ���� �Լ��� �̿��� ������ �Լ��� ������ ���� �̾߱� �߱� �����̴�.

	swap(&i, &j)�� swap (&i, j)�� �ٲ� ���
	warning C4047: '�Լ�' : 'int *'�� ���� ���� ������ 'int'��(��) �ٸ��ϴ�.
	warning C4024: 'swap' : ���� �� ���� �Ű� ���� 2�� ������ ���� �ٸ��ϴ�.
	��� ����� ���.
*/