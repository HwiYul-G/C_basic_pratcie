/*
	�Լ��� �� �߿����� �� �߿伺�� ������ ���� �� �ִ� ������ ����.
*/
/*
    #include <stdio.h>
    int main() {
      char input;

      scanf("%c", &input);

      if (48 <= input && input <= 57) {
        printf("%c �� ���� �Դϴ� \n", input);
      } else {
        printf("%c �� ���ڰ� �ƴմϴ� \n", input);
      }

      return 0;
    }
*/
#include <stdio.h>
int isdigit(char c); // c�� �������� �ƴ��� �Ǻ��ϴ� �Լ�
int main() {
    char input;
    scanf("%c", &input);
    if (isdigit(input)) {   // isdigit()���� �Լ��� ó�������ν� ���� ���� �ϴ� �� �� ��Ȯ�� �Ǵ��� �� �ִ�.
        printf("%c�� �����Դϴ�. \n", input);
    }
    else {
        printf("%c�� ���ڰ� �ƴմϴ�. \n", input);
    }
    return 0;
}
int isdigit(char c) {
    if (48 <= c && c <= 57)
        return 1;
    else
        return 0;
}