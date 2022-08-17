/* ������ ������ ���ڸ� ����*/
#include <stdio.h>

int main() {
    FILE* fp = fopen("some_data.txt", "r");
    char data[10];
    char c;

    if (fp == NULL) {
        printf("file open error ! \n");
        return 0;
    }

    fseek(fp, -1, SEEK_END);
    /*
        �� �ҽ����� ���� �߿��� �κ��� �� �κ��̴�.
        ���� ��ġ �����ڸ� ������ �� ������ �� ĭ ������ �κ����� �ű��.
        �� -1�� �� ĭ �ű�ĸ�, �� ������ �ű�� �Ǹ� 
        �� �κп��� EOF(������ ��)�� ��Ÿ���� ���� ��� �ֱ� ������
        �츮�� ���ϴ� ����� �ƴϰ� �ȴ�.

        �츮�� ���Ͽ� �Է��� �� ������ ���ڴ� EOF �ٷ� ���ʿ� ��ġ�� !�� �ȴ�.
    */
    c = fgetc(fp);
    printf("���� ������ ���� : %c \n", c);

    fclose(fp);
}