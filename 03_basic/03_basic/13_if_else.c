/* ������ �ڵ� */
#include <stdio.h>
int main() {
    int num;

    printf("�ƹ� ���ڳ� �Է��� ������ : ");
    scanf("%d", &num);

    if (num == 7) {
        printf("����� ���� 7 �̱���!\n");
    }
    else {
        if (num == 4) {
            printf("������ ���� 4 �ΰ��� ;;; \n");
        }
        else {
            if (num == 1) {
                printf("ù ��° ����!! \n");
            }
            else {
                if (num == 2) {
                    printf("�� ���ڴ� �ٷ� �ι�° ���� \n");
                }
                else {
                    // ......(����)......
                }
            }
        }
    }

    // else if�� �̿��� �Ʒ��� ���� �ٲ� �� �ִ�.

    int num;

    printf("�ƹ� ���ڳ� �Է��� ������ : ");
    scanf("%d", &num);

    if (num == 7) {
        printf("����� ���� 7 �̱���!\n");
    }
    else if (num == 4) {
        printf("������ ���� 4 �ΰ��� ;;; \n");
    }
    else {
        printf("�׳� ����� ���� %d \n", num);
    }



    return 0;
}