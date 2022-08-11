/*
	함수가 왜 중요한지 그 중요성을 절실히 느낄 수 있는 예제를 보자.
*/
/*
    #include <stdio.h>
    int main() {
      char input;

      scanf("%c", &input);

      if (48 <= input && input <= 57) {
        printf("%c 는 숫자 입니다 \n", input);
      } else {
        printf("%c 는 숫자가 아닙니다 \n", input);
      }

      return 0;
    }
*/
#include <stdio.h>
int isdigit(char c); // c가 숫자인지 아닌지 판별하는 함수
int main() {
    char input;
    scanf("%c", &input);
    if (isdigit(input)) {   // isdigit()으로 함수로 처리함으로써 무슨 일을 하는 지 더 정확히 판단할 수 있다.
        printf("%c는 숫자입니다. \n", input);
    }
    else {
        printf("%c는 숫자가 아닙니다. \n", input);
    }
    return 0;
}
int isdigit(char c) {
    if (48 <= c && c <= 57)
        return 1;
    else
        return 0;
}