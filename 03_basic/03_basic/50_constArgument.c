#include <stdio.h>
int read_val(const int val);
int main() {
	int a;
	scanf("%d", &a);
	read_val(a);
	return 0;
}
int read_val(const int val) {
	val = 5;	// error C2166 : l-value�� cosnt ��ü�� �����մϴ�.
	// val�� const int�� �����߱� ������ �Լ� ȣ�� ��, val ���� ���ڷ� ���޵� ������ �ʱ�ȭ �ǰ� ���� �ٲ��� �ʴ´�.
	// ����� ���ڸ� �޾Ƶ��̴� ��� ��κ� �Լ��� ȣ�� �ص� �� ������ ���� ������� �ʴ� ��쿡 ���� ����Ѵ�.
	return 0;
}