/*
	��Ʈ�� �۾����� �б�/���⸦ ��ȯ�� ���� �ݵ��
	fllush �Լ��� ȣ���ϰų� fssek�̳� rewind�� ���� �Լ��� ȣ����
	���� ��ġ �����ڸ� �ٽ� �������־�� �ϱ� �����̴�.

	���� ���� ���� ���� �۾� �� �ٽ� �б� �۾�(while������ fputc�� ���� �۾�)��
	������ ���� fflush�� fseek �Լ��� ȣ���ؾ��Ѵ�.

	�̸� ���� �ڵ带 �����ϸ� �Ʒ��� ����.
*/
#include <stdio.h>

int main() {
    FILE* fp = fopen("some_data.txt", "r+");
    char c;

    if (fp == NULL) {
        printf("���� ���⸦ �����Ͽ����ϴ�! \n");
        return 0;
    }

    while ((c = fgetc(fp)) != EOF) {
        /* c �� �빮���� ��� */
        if (65 <= c && c <= 90) {
            /* �� ĭ �ڷ� ����*/
            fseek(fp, -1, SEEK_CUR);
            /* �ҹ��ڷ� �ٲ� c �� ����Ѵ�*/
            fputc(c + 32, fp);
            /*

            ���� - �б� ��� ��ȯ�� ���ؼ��� ������
            fseek �Լ��� ���� ���� ��ġ ������ ���� �Լ�����
            ȣ���ؾ� �Ѵ�.

            */
            fseek(fp, 0, SEEK_CUR); // fflush(fp);�� �ص� �ȴ�.
        }
        /* c �� �ҹ����� ���*/
        else if (97 <= c && c <= 122) {
            fseek(fp, -1, SEEK_CUR);
            fputc(c - 32, fp);
            fseek(fp, 0, SEEK_CUR);
        }
    }

    fclose(fp);
}