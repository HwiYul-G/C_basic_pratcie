/*
	[산술 연산 관련]
	1) 부동 소수점(float, double)은 되도록 사용하지 말자.
	부동 소수점 수는 그 구조가 매우 복잡하다.
	정수 자료형(int, short ..)의 경우 단순히 2진수를 나타낸 것에 불과하지만
	부동 소수점은 그 수의 특정한 규격이 정해진 것이기 때문에 복잡하다.

	따라서 부동 소수점 수를 가지고 하는 연산 자체도 매우 느릴 수 밖에 없다.
	꼭 부동 소수점 연산은 오직 반드시 필요할 때만 사용해야한다.

	여기서 반드시 필요할 때 라면 소수점 몇 째 자리까지 정밀도를 요구할 때나
	매우 큰 수를 다룰 때 이다.
	만일 소수점 둘째 자리나 첫 째 자리 정도의 정밀도를 요구한다면 단순히 그 수에 x10, x100을 해서
	정수 자료형으로 다루는 것이 오히려 좋다.

	2-1) 나눗셈을 피해라1

	int inc_second(int second) { return (++second) % 60; } // 초를 증가시키는 함수
	초의 범위는 0부터 59이므로 1 증가시킨 뒤에 만일 60을 넘었을 때를 대비해 위와 같이 60으로 나눈 나머지를 구해야한다.
	그런데 여기서 문제는 나눗셈은 매우매우 느린 연산이다.

	다른 덧셈, 뺄셈에 비해 몇 배 가까이 느리기 때문에 엄청난 시간 손해가 있다.
	만약 우리가 second가 60보다 커질 일이 없다는 것을 알고 있다면 굳이 60으로 나눌 필요 없이
	if 문으로 60일 때만 0을 리턴해주면 된다.
	왜냐하면 if문은 나눗셈보다 훨씬 빠르게 처리되기 때문이다.

	int inc_second(int second) {
		++second;
		if (second >= 60) return 0;
		return second;
	}
	따라서 위와 같이 하면 훨씬 시간을 아낄 수 있다.

	한 가지 짚고 넘어갈 점은 위 코드에서 분기문(if)를 도입하였다는 점이다.
	때로는 분기문이 프로그램 속도를 저하시킬 수 있다.

	왜냐하면 CPU의 경우 명령어 실행 속도를 향상시키기 위해 파이프라이닝이라는 작업을 수행한다.
	쉽게 말하자면, 다음에 실행될 명령어를 이전 명령어 실행이 채 끝나기 전에 미리 실행시키는 것과 비슷하다.

	문제는 분기문이 있을 경우 다음에 실행할 명령어가 무엇인지 모른다.
	위의 경우 second >= 60 이면 0을 리턴하는 명령을 수행해야하고 아니면 return second;를 수행해야한다.

	그렇다면 CPU가 second>=60 이 끝날 때까지 기다릴까? 아니다.
	이전에 추세를 보아서 대충 참일지 거짓일지 예측한 다음에 다음에 올 명령어를 실행하게 된다.
	이렇게 분기문을 예측하는 것을 분기 예측(branch predicition)이라 한다.

	예측이 맞았다면 기분좋게 진행할 수 있지만,
	그렇지 않다면 여태한 작업을 모두 버리고 원래 수행했어야할 명령어를 다시 실행한다.
	Intel Skylake CPU의 경우 해당 패널티가 20cycle 정도 된다.

	참고로 정수 나눗셈 연산(DIV)의 경우 10cycler 정도 필요하고 덧셈의 경우 1cycler 정도에 끝난다.
	(즉 나눗셈이 덧셈보다 10배 느리다.)

	* Cycle : 쉽게 생각하면 CPU에서 한 가지 작업을 수행하는 데 걸리는 시간 단위.
			만일 CPU가 4Ghz라면 1초에 40억 cycler 어치 연산을 수행할 수 있다.

	따라서 만약 분기 예측 정확도를 50%이상으로 할 수만 있다면 위와 같이 코드를 바꿨을 때 효율적으로 최적화 했다고 할 수 있다.
	다행이도 CPU의 분기 예측기는 꽤나 똑똑해서, 이전의 분기 결과 추세를 바탕으로 예측하게 된다.
	우리의 inc_second는 대부분의 경우 second>=60이 참일 일 없기 때문에
	(확률상 1/60이다) 분기 예측 확률이 꽤 높을 것이다.

	물론 실제 프로그램에서 inc_second가 어떻게 사용되는 지는 아무도 모른다.
	따라서 반드시 테스트를 통해 실제 향상이 있는 지 확인해보는 것이 좋다.

	2-2) 나눗셈을 피하라2
	대부분의 현대 컴파일러들은 이 작업을 알아서 최적화 해 준다.
	앞서 말했듯 나눗셈은 시간이 매우매우 오래 걸리는 작업이다. 
	그런데 놀랍게도 2의 멱수들(2,4,8,16,32)로 나눌 때는 나눗셈을 하지 않고도 간단히 처리할 수 있는 방법이 있다.
	바로 shift 연산을 수행한느 것이다. 
	shift 연산은 컴퓨터 연산 중에서도 가장 빠른 연산이므로 이를 잘 활용하면 시간을 엄청나게 절약할 수 있다.

	2의 멱수들을 이진수로 표현해보면 1, 10, 100, 1000 등이 될 것이다.
	우리가 만일 10진수로 생각할 때 7865를 100으로 나누면 몫이 얼마가 될까?
	우리는 별로 고민하지 않고 78이라고 말할 수 있다.
	왜냐하면 단순히 끝의 두 자리를 버리면 되기 때문이다.
	2진수도 마찬가지이다. 11101010을 1000으로 나눈 몫은 얼마일까?
	이는 단순히 마지막 3자리를 버리면 되므로 11101이 된다.

	이 아이디어를 이용하면 1000(이진수)으로 나눌 땐 수를 오른쪽으로 3칸 쉬프트 해버리면 된다.
	즉 오른쪽으로 3칸 밀어버리는 것이다.

	아래 예제는 32로 나누는 것이다.
	32는 2의 5승이므로 오른쪽으로 5칸 쉬프트 하면 된다.
	#include <stdio.h>
	int main(){
		int i;
		printf("정수를 입력하세요 : ");
		scanf("%d", &i);

		printf("%d를 32로 나누면 : %d \n", i, i/32);
		printf("%d를 5로 칸 오른쪽으로  shift하면 : %d\n", i, i>>5);

		return 0;
	}

	3-1) bit 연산 활용하기
	비트연산 OR, AND, XOR 등등은 컴퓨터에서 가장 빠르게 실행되는 연산들이다.
	비트 연산은 다음과 같이 여러가지 정보를 하나의 변수에 포함하는데 자주 사용된다.
	예를 들어 우리가 하나의 사람에 대한 여러가지 상태에 관한 정보를 나타내는 변수를 만든다고 하자.

	구조체를 배웠기에 아래와 같이 만들 것이다.
	struct HUMAN {
		int is_Alive;
		int is_Walking;
		int is_Running;
		int is_Jumping;
		int is_Sleeping;
		int is_Eating;
	};

	이는 상당한 메모리 낭비가 된다. 6가지 정보를 나타내는데 6*4*8 = 192개의 bit나 소모했기 때문이다.
	물론 이를 char로 빠구면 되지 않나 싶을 수 있지만 결국은 같은 이야기이다.

	굳이 하나의 정보를 한 개의 비트에 대응시켜 사용할 수 있는데.
	이를 각각의 변수에 모두 대응시켜 사용한 것이 문제이다.
	하지만 비트 연산을 잘 이요하면 이를 해결할 수 있다.

	아래의 경우를 보자.
*/
#include <stdio.h>
/*
	define을 이용해 여러 개의 변수에 값을 대응시킴.
	한 가지 특징은 각 데이터에는 오직 1개의 비트만 1이고 나머지는 모두 0이다.
*/
#define ALIVE 0x1      // 2 진수로 1
#define WALKING 0x2    // 2 진수로 10
#define RUNNING 0x4    // 2 진수로 100
#define JUMPING 0x8    // 2 진수로 1000
#define SLEEPING 0x10  // 2 진수로 10000
#define EATING 0x20    // 2 진수로 100000
int main() {
	/*
		define으로 변수에 값을 대응 시키고
		아래의 my_status에 OR 연산을 주게 되면 각 데이터들이 나타내는 자리만 1이되거 나머지 모든 자리는 0이 됨
		따라서 int my_status = 0b...0100011이 된다.
		이제 이를 이용해 if문에서도 쉽게 사용할 수 있는데 
		단순히 유무를 파악하고자할 때는 데이터와 AND 연산을 시키면 된다.

		예를 들어 WALKING 중인지 아닌지 파악하기 위해
		WALKING과 AND 연산을 시켜보면 만일 내가 WALKING 중이였다면
		AND 연산시 나머지 부분은 모두 0이고, WALKINg에 해당하는 자리수만 1이 될 것이여서
		if문에서 참으로 판단된다. 
		(if문은 0이 아닌 모든 값을 참으로 생각한다),
		내가 walking 중이 아니였다면 나머지부분은 모두 0이고 
		WALKING에 해당하는 자리수조차 0이 될 것이므로 
		0이 되어서 if문에서 거짓으로 판단된다.

	*/
	int my_status = ALIVE | WALKING | EATING;

	if (my_status & ALIVE) {
		printf("I am ALIVE!! \n");
	}
	if (my_status & WALKING) {
		printf("I am WALKING!! \n");
	}
	if (my_status & RUNNING) {
		printf("I am RUNNING!! \n");
	}
	if (my_status & JUMPING) {
		printf("I am JUMPING!! \n");
	}
	if (my_status & SLEEPING) {
		printf("I am SLEEPING!! \n");
	}
	if (my_status & EATING) {
		printf("I am EATING!! \n");
	}

	/*
		3-2) 비트 연산 활용하기 2
		비트 연산을 가장 많이 활용하는 예로 홀수/짝수 판별이 있다.

		우리는 여태 짝홀 판별을
		i%2 == 0이면 짝수,
		i%2 == 1이면 홀수 (!=1  등)으로
		이러한 방식으로 만들었다.

		그런데 앞서 말한 것처럼 나눗셈 연산은 매우 느리다.
		하지만 놀랍게도 AND 연산 한 번으로 이를 해결할 수 있다.
	*/
	int a;
	scanf("%d", &a);
	/*
		어떤 정수가 홀수라면 2진수로 나타냈을 때
		맨 마지막 자리가 1이어야 한다.
		이를 이용해서 단순히 어떤 정수의 맨 마지막 비트가 1인지만 확인하면 된다.
		근데 위에서 강조했듯 맨 마지막 비트가 1인지 확인하려면
		맨 마지막 비트만 1인 수(즉 1)과 AND 하면 된다. 
	*/
	if (a & 1) {
		printf("%d는 홀수 입니다. \n", a);
	}
	else {
		printf("%d는 짝수 입니다. \n", a);
	}
	return 0;
}
/*
	비트 연산에 관련해서 아래 내용을 기억하면 된다.
	1) 어떠한 정수의 특정 자리를 1로 만들고 싶다면
		그 자리는 1이고 나머지는 0인 수와 OR 하면 된다.
	2) 어떠한 정수의 특정 자리가 1인지를 검사하고 싶다면
		그 자리만 1이고 나머지는 0인 수와 AND하면 된다.
*/