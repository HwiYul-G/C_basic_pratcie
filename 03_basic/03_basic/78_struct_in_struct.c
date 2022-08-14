#include <stdio.h>
struct employee {
	int age;
	int salary;
};
struct company {
	struct employee data;
	char name[10];
	/*
		또다른 구조체 변수를 멤버로 가진 구조체
		구조체는 사용자가 정의한 또다른 형(type)이기 때문에 이것이 가능한 것은 당연하다.

		구조체 역시 int나 char와 같은 하나의 형이다.
		우리가 만든 형은 이름이 struct employee라는 것이고
		그 중 data라는 (구조체) 변수를 생성했다.

		int a와 완전히 동일한 일이다.
	*/
};
int main() {
	struct company Kim;

	Kim.data.age = 31;
	Kim.data.salary = 3000000;
	/*
		멤버들에 값을 대입할 때
		'.'연산자의 우선 순위는 왼쪽부터이므로
		Kim.data가 해석된 후 Kim.data의 .age가 해석된다

		다시말해 Kim의 data 멤버의 age 멤버에 값이 들어간다.
	*/

	printf("Kim's age : %d \n", Kim.data.age);
	printf("Kim's salary : %d$/year \n", Kim.data.salary);

	return 0;
}