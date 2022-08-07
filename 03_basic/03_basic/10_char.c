/*
	- 문자를 저장하는 변수
	- scanf의 사용
	- 섭씨 -> 화씨 환산 

	char				1byte	signed : -128 to 127 / unsigned : 0 to 255
	short int(short)	2bytes	signed : -32768 to 32767 / unsigned : 0 to 65535
	int					4bytes	signed : -2147483648 to 2147483647 / unsigned : 0 to 4294967295
	long int(long)		4bytes	signed : -2147483648 to 2147483647 / unsigned : 0 to 4294967295
	bool				1byte	true / false
	float				4bytes	+/- 3.4e +/- 38 (~ 7 digits)
	double				8bytes	+/- 1.7e +/- 308 ( ~ 15 digits)
	long double			8bytes	+/- 1.7e +/- 308 (~15 digits)
*/

#include <stdio.h>
int main() {
	char a;
	a = 'a';

	printf("a의 값과 들어 있는 문자는? 값 : %d, 문자 : %c \n", a, a); // 97, a

	return 0;
}

/*
	만약 a = 'a'가 아니라 a = a라면 C컴파일러는 a가 변수 a라고 착각해 a라는 변수의 값을 a라는 변수에 대입하는 문장으로 인식한다.
	따라서 a에는 아무런 값이 들어있지 않은 NULL값(쓰레기 값)이 되어 a라는 문자를 출력했을 때 이상한 값이 나온다.

	%d는 a의 값을 정수인 10진수 숫자로 출력하라는 것이고 %c는 a의 값을 문자로 출력하라는 것이다.
	이때, 각 문자마다 대응되는 숫자를 ASCII 코드라는 것으로 정의했다. 
	ASCII코드는 8bit 데이터를 이용해 여러 문자에 번호를 붙인 것이다.
	과거에는 7bit만으로 충분히 문자를 정할 수 있다고 생각했지만 부족해서 1bit를 추가한 Extended ASCII Code가 되었다.

	그러나 256개가 된 것으론 또 충분하지 못하다.
	왜냐면 한글만 해도 자모은 24개로 구성되는데 한 글자당 최대 초성/중성/종성을 모두 표현해야 한다.
	또한 더욱 심각한 것은 한자같은 표의문자의 경우 수만 개가 넘는 한자 데이터를 가지고 있어야하는데 이를 256개 안에 다 표현하는 것은 불가능하다.

	따라러 더 많은 종류의 문자를 표현해야 한다는 필요성이 있다.
	그래ㅓ Unicode라는 새로운 형식의 문자 체계를 도입하게 된다.
	유니코드는 한 문자를 1 to 4 bytes까지 다양한 길이로 처리한다. 이는 기존 아스키 코드 체계를 유지하면서 새로운 문자들을 추가하기 위함이다.
*/