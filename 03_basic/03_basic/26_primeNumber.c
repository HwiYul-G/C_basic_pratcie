#include <stdio.h>

int main() {
	int guess = 5; // 우리가 소수인지 판별하고 있는 수 
	int prime[1000];

	int index = 1; // for문 변수

	prime[0] = 2;
	prime[1] = 3;
	for (;;) {
		int ok = 0; // 처음 두 소수는 특별한 경우로 취급
		for (int i = 0; i <= index; i++) {
			// guess 이하의 모든 소수들로 나눠보는 작업.
			// index 는 (배열에 저장된 소수의 개수 -1 )인데, prime[i]로 접근하므로 배열의 모든 소수들로 나눠봄
			if (guess % prime[i] != 0) {
				// 만약 guess가 prime[i]로 나눠지지 않으면 ok를 1 증가시킨다.
				ok++;
			}
			else {
				// 나눠 떨어지면 소수가 아니므로 break를 통해 for loop를 나간다.
				break;
			}
		}
		// 만일 ok가 prime 배열에 저장된 소수의 개수 즉 index+1가 같다면
		// 자기 자신 미만의 모든 소수들로도 안 나눠 떨어진다는 뜻이므로 소수이다.
		// 이때 주의해야 할 점은 1개의 수를 검사할 때마다 ok가 0으로 리셋되어야 한다. 그래야 정확한 결과를 읃을 수 있다.
		if (ok == (index + 1)) {
			index++;
			prime[index] = guess;
			printf("소수 : %d \n", prime[index]);
			if (index == 999) break;
		}
		guess += 2;
	}

	return 0;
}