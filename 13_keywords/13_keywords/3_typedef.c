/* ������ ���� ���α׷�
    #include <stdio.h>
    int main() {
        int input;
        int a, b;

        while (1) {
            printf("--- ���� --- \n");
            printf("1. ���� \n");
            printf("2. ���� \n");
            printf("3. ���� \n");

            scanf("%d", &input);

            if (input == 1) {
                printf("�� �� : ");
                scanf("%d%d", &a, &b);
                printf("%d �� %d �� �� : %d \n", a, b, a + b);
            }
            else if (input == 2) {
                printf("�� �� : ");
                scanf("%d%d", &a, &b);
                printf("%d �� %d �� �� : %d \n", a, b, a - b);
            }
            else
                break;
        }

        return 0;
    }
*/

/*
    �Ʒ��� ���α׷��� ���� ���⿡ �̿��Ѵٰ� ����.
    �׷��� �츮�� �� ���α׷��� ����� ����� ��Ÿ���Ե� CPU���� 32bit ���� ������ �� �� ����.
    ���� 16bit ���ϸ� ������ �� �ִٰ� ����.

    �׷��ٸ� �� ���⿡�� int���� ����ϴ� ���� �Ұ����ϰ� short�� char���� �����鸸 �����ؾ��Ѵ�.
    �׷��� ���� ���α׷��ε� �ٸ� ������ ���⿡�� int���� ��밡���ϴٰ� ����.
    �׷��ٸ� �� �ڵ带 �ٽ� �� �ٲ�����Ѵ�.
    �̴� �ſ� ���ŷο� ���̰� �̸� ���ػ� �Ʒ��� ���� �ڵ带 �ٲ㺸��.
*/
/* ���� �ҽ� �ڵ� */
#include <stdio.h>
typedef int CAL_TYPE;
int main() {
    CAL_TYPE input;
    CAL_TYPE a, b;

    while (1) {
        printf("--- ���� --- \n");
        printf("1. ���� \n");
        printf("2. ���� \n");
        printf("3. ���� \n");

        scanf("%d", &input);

        if (input == 1) {
            printf("�� �� : ");
            scanf("%d%d", &a, &b);
            printf("%d �� %d �� �� : %d \n", a, b, a + b);
        }
        else if (input == 2) {
            printf("�� �� : ");
            scanf("%d%d", &a, &b);
            printf("%d �� %d �� �� : %d \n", a, b, a - b);
        }
        else
            break;
    }

    return 0;
}
/*
    ������ �ҽ��ڵ� ���� �� ����ȴ�.
    �ٸ� �ٲ� ���� ������ Ÿ���� CAL_TYPE�̶�� �� ���̴�.
    �׸��� ������ typedef�� ���� CAL_TYPE�� int���� ���ٰ� �����ߴ�.
     ���� �� �ҽ��ڵ带 short�� char�� �Ǵ� ���⿡ �����Ű���� ��� �ؾ� �ұ�?
     �������� ��� ������ Ÿ���� ���δ� �����ؾ� ������
     ������ typedef���� CAL_TYPE�� ���� short�� char�� ������ �ٲ������ �ȴ�.
*/
