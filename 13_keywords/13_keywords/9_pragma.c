/*
	#pragma once
	아까의 Weird 구조체 예제에서 Werid 부분만 다른 헤더파일로빼놓아 보자.
	이 헤더파일의 이름은 werid.h이다.
*/
#include <stdio.h>
#include "werid.h"
int main() {
	struct Weird a;
	a.i = 3;
	printf("Weired 구조체의 a.i : %d \n", a.i);
	return 0;
}
/*
	9_pragma.c에서 weird.h를 포함했으므로
	weird.h의 내용이 9_pragma.c로 그대로 복사된 셈이다.
	(즉 #include "weird.h" 부분이 weird.h의 내용으로 바뀌었다고 봐도 된다.)
	따라서 struct Weird를 사용할 수 있게 되므로 위와 같은 결과가 발생한다.
	
	그런데 만일 실수로 weird.h를 2번 포함했다고 하자.
	즉 #include "werid.h" #include "werid.h"를 한 것이다.
	이렇게 되면 error C2011 : 'Weird' : 'struct' 형식 재정의 'Weird' 선언을 참조하십시오.
	라는 오류를 만나게 된다.

	그리고 이것은 아래와 같 것과 동일한 행동이다.
	#include <stdio.h>
	struct Weird {
	  char arr[2];
	  int i;
	};
	struct Weird {
	  char arr[2];
	  int i;
	};

	int main() {
	  struct Weird a;
	  a.i = 3;
	  printf("Weird 구조체의 a.i : %d \n", a.i);
	  return 0;
	}

	이를 막으려면 어떻게 해야할까?
	=> 10_pragma.c
*/