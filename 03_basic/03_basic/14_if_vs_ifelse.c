/* if �� if- else if �� ����*/
#include <stdio.h>
int main() {
    int num;

    printf("�ƹ� ���ڳ� �Է��� ������ : ");
    scanf("%d", &num);

    if (num == 7) {
        printf("a ����� ���� 7 �̱���!\n"); // ���⸸ �����
    }
    else if (num == 7) {
        printf("b ����� ���� 7 �̱���! \n");
    }

    // ��
    if (num == 7) { 
        printf("c ����� ���� 7 �̱���!\n");
    }
    if (num == 7) {
        printf("d ����� ���� 7 �̱���! \n");
    }

    return 0;
}
/*
    else ���� ���� ������ '���� if���� ���� �ƴ� ��' ����ȴٴ� ����� �⺻���� ��� �ִ�.
    ���� if-else if �� ���� if�� ture�̸� else if�� ������� �ʴ´�.

    �ݸ� if�� if�� ���� ����� ���� �Ѵ� ����ȴ�.
*/