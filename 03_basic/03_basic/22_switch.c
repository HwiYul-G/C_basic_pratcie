
#include <stdio.h>
int main() {
    int input;

    printf("마이펫 \n");
    printf("무엇을 하실 것인지 입력하세요 \n");
    printf("1. 밥주기 \n");
    printf("2. 씻기기 \n");
    printf("3. 재우기 \n");

    scanf("%d", &input);

    if (input == 1) {
        printf("아이 맛있어 \n");
    }
    else if (input == 2) {
        printf("아이 시원해 \n");
    }
    else if (input == 3) {
        printf("zzz \n");
    }
    else {
        printf("무슨 명령인지 못 알아 듣겠어. 왈왈 \n");
    }

    // 위와 같이 동일한 변수 input에 대해 비교문이 반복되는 경우 깔끔하게 switch 문을 적용시킬 수 있다.
    /*
        switch(변수){
            case 값1:
                break;
                ....
        }
        변수 부분에는 값1, 값2 ... 들과 비교할 변수가 들어가게 된다.
        아래 예제의 경우 input을 1과 2와 3과 비교해야 했으므로 변수 부분에는 input이 들어가게 된다.
        이때, switch 문에 사용될 변수는 반드시 "정수 데이터를 보관하는 변수"여야 한다.
        즉 char, short, int, long 중 하나여야한다.
        만약 flaot, double 이라면 컴파일 오류가 발생하게 된다.

        변수 == 값1 일때 가장 맨 위의 case 명령이 실행되고, 변수 == 값2 이면 두 번째 case가 실행된다. 
        그리고 각자 실행후 break;를 통해 swtich를 빠져나가게 된다.

        만약 변수 == 값2이면 case 값1은 실행되지 않고 case값 2만 실행되고 break를 통해 switch를 나간다.

        주의할 점으로 '값'에 위치하는 것들은 무조건 '상수'여야한다.
        만약 '값'부분에 상수가 아닌 '변수'들이 오가되면 오류가 발생하게 된다.
        그 이유는 switch문의 내부적인 처리 방법 때문이다.

        마지막으로 default는 if문의 else와 같은 역할을 한다. 이도 저도 아닌 것들의 case가 된다.
        
        또한, 각 case 마다 break;를 꼭 넣어줘야한다. 만약 break가 빠지면 어떤 일이 발생하는 지 직접 해보라.

    */
    switch (input) {
    case 1:
        printf("아이 맛있어 \n");
        break;

    case 2:
        printf("아이 시원해 \n");
        break;

    case 3:
        printf("zzz \n");
        break;

    default:
        printf("무슨 명령인지 못 알아 듣겠어. 왈왈 \n");
        break;
    }

    // case의 값으로는 상수만 된다면서?
    char input;

    printf("(소문자) 알파벳 읽기\n");
    printf("알파벳 : ");

    scanf("%c", &input);

    switch (input) {
    case 'a':
        printf("에이 \n");
        break;

    case 'b':
        printf("비 \n");
        break;

    case 'c':
        printf("씨 \n");
        break;

    default:
        printf("죄송해요.. 머리가 나빠서 못 읽어요  \n");
        break;
    }
    // 컴퓨터는 문자와 숫자를 구분하지 못한다. 컴퓨터는 문자를 모두 숫자로 처리한 뒤 우리에게 보여줄 때만 문자로 보여주는 것이다.
    // 따라서, 문자 = 정수라고 생각해도 무방하다.
    return 0;
}
/*
    switch와 if - else의 차이점은 무엇인가?
    내부적으로 이 차이를 정확히 이해하려면 '어셈블리어'에 대한 이해가 필요핟.

    switch(input){
    case 1: break;
    case 2: break;
    case 3: break;
    default: break;
    }

    if(input == 1){
    }else if(input == 2){
    }else if(input == 3){
    }else{
    }

    if문의 경우 각 경우마다 값들을 비교한다. 위의 경우 값을 3번 비교한다. if 1번 else if 2번이고 else는 비굥벗이 자동 처리되는 것이기 때문이다.
    즉, if 문을 이용하면 각 case의 경우 비교하게 되므로 최악의 경우 모든 case에 대해 값을 비교하는 어셈블리의 CMP 연산을 시행하게 된다.

    그런데 switch문은 내부적으로 jump table이라는 것을 생성한다.
    이때 jump table의 크기는 case의 값들에 따라 달라지는데, 예를 들어 어떤 switch문의 경우 case 1: ~calse 10: 까지 있다고 하자.
    그러면 jumptable에는 0부터 9까지의 값이 들어간다.

    여기소 우리는 왜 case 값: 할 때, '값' 부분에 변수가 위치하면 안되는 지 알게 된다.
    점프 테이블은 프로그램 초기에 작성되므로 switch문이 실행되기 전에 jump table이 작성되게 된다.
    따라서 '값' 부분에 변수가 들어가게 되면 jump table에 무엇이 올지 알 수 없으므로 변수를 사용하면 안된다.

    이 값들은 무엇을 의미하냐면 각 case 별로 명령들이 위치한 곳의 주소를 가리킨다.
    예를 들어서 1인 지점으로 점프하게 되면 case 1: block의 명령어들이 수행된다.
    이제 변수의 값에 따라 변수가 3이라면 점프 테이블의 3번째 원소를 찾아서 그 값에 해당하는 곳으로 점프하게 된다.

    (실제로 switch 문이 처리되는 과정은 더 복잡하다)

    결론적으로 switch문이 효과적으로 처리되기 위해서는 case의 '값'들의 크기가 그다지 크지 않아야 하고, 
    '값'들이 순차적으로 정렬되어 있고,
    그 '값'끼리 차이가 크지 않다면 최고로 효율적인 switch문을 이용할 수 있게 된다.

*/