#include <stdio.h>
/*
	slave가 함수임을 알려주는 () 안에 int master_money가 쓰여있다. 
	이는 "나를 호출하는 코드로부터 어떤 값을 master_money라는 int형 변수에 인자(혹은 매개변수)로 받아들이겠다."라는 것을 의미한다.

	우선 '인자'가 무엇인지 보자.
	slave와 main 함수는 전혀 별개의 함수이므로 slave는 main함수 안의 변수를 사용할 수 없고 그 역으로도 마찬가지이다.

	하지만, 인자(argument) 혹은 매개변수(parameter)라고 부르는 것을 이용하면 이러한 일을 가능하게 한다.
	인자는 직관적으로 봐도 알 수 있듯이 slave 함수 내에 선언되어 있는 변수이다.
	이 때, 인자는 함수를 정의할 때의 ()안에 나타나게 된다.

	아래의 경우 slave 함수는 int형의 master_money라는 변수를 인자로 가지고 있다.
	이제 이 함수를 어떤 함수에서 호출한다ㅗ 하자. 그러면 이 함수 호출시 인자에 적당한 값을 넣어줘야 한다.
	slave(500); 이러한 방식으로
	위의 말은 slave 함수를 호출할 때, slave 함수 안에서 정의된 master_money라는 변수에 500이라는 값을 전달하겠다!라는 의미이다.

	결론적으로
		함수의 인자는 '호출한 것과, 함수를 서로 연결해 주는 통신 수단'이라고 말할 수 있다.
	이러한 연유에서 수학적 용어로 틀린 표현이지만 C에선 '매개 변수'라고 한다.
*/

// 2) 그러면 slave함수는 body를 수행하게 된다.
int slave(int master_money) {
	master_money += 10000;
	return master_money;
}

// 과연 이건 될까?
int slave2(int my_money) {
	my_money += 10000;
	return my_money;
}


int main() {
	int my_money = 100000;
	// 1) slave 함수를 호출하는 호출자(caller)의 코드를 살펴보자.
	// printf에서 맨 뒤에 %d에 들어갈 값으로 slave(my_money)가 반환하는 값을 넣었다.
	// slave(my_money)가 반환하는 값을 먼저 넣기 위해선 slave 함수를 호출해야하는데
	// 이 때 my_money의 값이 slave 함수의 인자로 넘어간다.
	// 이제 2)로 가자
	printf("2009.12.12 재산 : $%d \n", slave(my_money));

	printf("slave2를 이용한 재산 : %d \n", slave2(my_money)); // 110000
	printf("my_money : %d", my_money); // 100000
	/*
		왜 slave2(my_money)로 인해 반환된 my_money값과
		그냥 부른 my_money의 값이 다를까?

		slave2 함수 호출시 main 함수 내부에 선언된 my_money의 값을 slave 함수의 변수인 my_money에 전달하고 있다.
		즉, 값 함수 내부에 선언된 my_money들은 이름은 같지만 '서로 다른 변수'이고, 메모리 상의 '다른 위치'를 점유하고 있다.
		즉 우리가 보기에 두 변수는 동일한 것으로 보여도 컴퓨터가 보기엔 두 변수는 서로 다른 것이다.

		두 번째로 주목할 점은 '값'이 전달된다는 점이다.
		slave함수를 호출할 때 slave 함수의 my_money 인자에는 '값'이 전달된다.
		즉, main 함수의 my_money의 100000 이라는 값이 slave 함수의 my_mone라는 인자에 저장되어 들어간다.

		따라서 slave 함수에서 my_money의 값을 아무리 지지고 볶아도 main 함수의 my_money 변수에는 전혀 영향을 주지 않는다.

		왜냐하면 slave 함수의 my_money 변수는 단지 main 함수의 my_money와 같은 값을 가진 채로 초기화된 메모리 상의 또다른 변수이기 때문이다.

		이것은 마치 int a = b; b++; 이라고 했는데 a의 값이 b와 같이 1증가함을 바라는 것과 같다.
		아무튼 결과적으로 main 함수의 두번째 printf에서 main 함수의 my_money 출력시엔 변화하지 않은 100000이 출력된다.

		그렇다면 우리가 다른 함수의 변수 값을 수정하고자 하는 함수를 만들고 싶다면 어떻게 해야할까?
		앞에서 배운 내용을 생각해보면 "각 함수의 세계는 너무나 배타적이여서 각 함수는 서로 무슨 변수가 있었는지 모른다.
		사실 정확히 ㅁ라하자면 각 함수의 형태(리턴형, 함수 이름, 인자들의 형)을 제외하고는 서로에 대해 아는 것이 없다."

		그럼 우리는 다른 함수에서 정의된 변수 값을 수정하는 함수는 작성할 수 없을까?
		아니다! 포인터를 이용하면 된다.
	*/

	return 0;
}