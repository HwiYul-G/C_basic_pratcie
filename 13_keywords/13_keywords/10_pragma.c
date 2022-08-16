
#include <stdio.h>
#include "werid.h"
int main() {
	struct Weird a;
	a.i = 3;
	printf("Weird 구조체의 a.i : %d \n", a.i);
	return 0;
}
/*
	우선 왜 오류가 나지 않았는지 살펴보자.
	우리가 전처리기라고 한다면 맨 처음에 첫 번재 #include "weird.h"를 만났을 때
	WEIRD_H가 정의되어 있지 않으므로 #ifndef가 참이 되어
	#define WEIRD_H가 수행되어 WEIRD_H라는 것이 정의된다.
	
	또한 헤더파일의 내용도 10_pragma.c에 그대로 복사된다.
	그 후 실수로 weird.h를 다시 한번 include 했을 때는
	이미 WEIRD_H가 정의되어 있는 상태이므로
	#ifndef WEIRD_H가 거짓이 되어 #endif로 넘어가버려 10_pragma.c에 그 내용이 복사되지 않는다.

	이렇게 하면 헤더 파일의 내용이 중복으로 포함되는 것을 막을 수 있다.
	(이미 많이 하는 방식이다.)
	하지만 #pragma를 이용해서 더 ㄷ순하게 할 수 있는데

	// weird.h 파일에 아래와 같이 하면 된다.
	#pragma once
	struct Weird {
		char arr[2];
		int i;
	};

	이렇게 하고 컴파일해도 잘 나온다.
	#pragma once라는 명령어는 컴파일러로 하여금 이 파일이 오직 딱 한 번만 include 될 수 있다는 것을 말해준다.
	이는 위에서 #ifndef를 이용해 복잡하게 하였던 작업들을 단순하게 한 문장으로 끝낼 수 있게 해준다.

	또한 #pragma once의 장점으로 #ifndef를 이용하는 것보다 컴파일 시간을 절약할 수 있다는 점이다.
	#ifndef를 이용하게 되면 include 하였을 때 전처리기가 직접 헤더파일을 열어 보아서
	과연 WEIRD_H가 정의되었나 정의되지 않았나 확인해 보아야 하는데,
	pragma once를 이용하면 한 번 include 되었다면 헤더 파일을 다시 열어보지도 않기 때문에 컴파일 시간이 절약되는 효과가 나타난다.

	다만 #pragma 관련 키워드들이 컴파일러 종속적이여서
	어떤 컴파일러에서는 #pragma once가 지원되지 않을 수도 있다.
	따라서 무슨 컴파일러를 사용하는지 보고 #pragma once를 지원한다면 되도록 이것을 사용하는 것이 도움된다.
*/