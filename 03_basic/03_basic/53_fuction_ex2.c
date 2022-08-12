/*
	유클리도 호제법을 이용해서 N 개의 수들의 최대공약수를 구하는 함수를 만들어보세요. 
	유클리드 호제법이 무엇인지 모르신다면, 인터넷 검색을 활용하는 것을 추천합니다. (난이도 : 中上)
*/
#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n);
int main() {
	int n;
	printf("입력할 수의 개수 : ");
	scanf("%d", &n);

	int* numbers = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		printf("%d번째 수 입력 : ", i+1);
		int temp;
		scanf("%d", &temp);
		numbers[i] = temp;
	}

	int result = gcd(numbers[0], numbers[1]);
	for (int i = 1; i < n; i++) {
		result = gcd(result, numbers[i]);
	}
	printf("입력하신 %d개의 수들의 최대공약수는 %d 입니다. \n", n, result);

	free(numbers);
	return 0;
}

int gcd(int n1, int n2) {
	int m, n;
	if (n1 >= n2) {
		m = n1;
		n = n2;
	}
	else {
		m = n2;
		n = n1;
	}

	while (1) {
		int r = m % n;
		if (r == 0) {
			return n;
		}
		else {
			if (n >= r) {
				m = n;
				n = r;
			}
			else {
				m = r;
			}
		}
	}
}

/*
	유클리드 호제법은 어떠한 두 수의 최대공약수를 계산하는데 쓰이는 방법이다.
	1. 두 수를 m과 n 이라고 하자 (m>n)
	2. m을 n으로 나눈 나머지를 계산한다. m%n
	3. m%n이 0이라면 n값이 맨 처음 두 수의 최대공약수이다. (종료)
	4. m%n이 0이 아니라면, m%n과 n중 큰 것을 m, 작은 것을 n이라고 한 후 다시 1로 돌아간다.

	예를 들어서 63과 35의 최대공약수를 구한다고 하자.
	1. m =63 n = 35
	2. m%n = 63 % 35 = 28
	3. 28은 0이 아니므로 28과 35를 비교한다 35가 더 크다. 따라서 m=35 n = 28
	4. m = 35 n = 28
	5. 35 % 28 = 7
	6 7은 0이 아니므로 7과 28을 비교한다. 28이 더 크다.
	7. m = 28 n = 7
	8. m%n = 0 종료 => 맨 처음 두 수의 최대공약수 즉 63과 35의 최대공약수는 7이다.

	m = qn + r(0<=r <q), gcd(m, n) = gcd(qn+r, n) = gcd(r, n)
	유클리드 호제법은 2개의 수의 최대공약수를 찾는데만 사용했지만 이를 어떻게 n개의 수의 공통된 최대공약수를 찾는데 응용할 수 있을까?
	처음 두 수의 최대공약수를 구한다. 그리고 그 다음 수와 구한 최대강약수의 최대공약수를 구한다. 이를 쭉 반복한다.

	예를 들어서 18과 24, 40, 60의 최대공약수를 구한다고하자.
	18과 24의 최대공약수는 6이다. 그러면 이제 6과 40의 최대공약수를 계산한다. 이는 2이다.
	그러면 2와 60의 최대공약수를 계산하자. 그러면 2이다.
	따라서 이 4개의 수의 공통된 최대공약수는 2이다.
*/