/* ��� ��Ʈ���� ��������*/
#include <stdio.h>
int main() {
	FILE* fp = fopen("a.txt", "w");
	fputs("Psi is an excellent C programmer", fp);
	
	fseek(fp, 0, SEEK_SET);	// ó������ ���ư���
	
	fputs("is Psi", fp); // �ٽ� fputs�� �ϴ� ���� ���� ������ ������ ���� �ʰ� ����� �ȴ�.

	fclose(fp);
	/*
		����������
		is Psi an excellent C programmer�� �����ִ�.
	
	*/
	return 0;
}