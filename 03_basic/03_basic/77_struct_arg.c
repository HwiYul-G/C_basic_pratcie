#include <stdio.h>

struct TEST {
	int age;
	int gender;
};
struct TEST3 {
	int age;
	int gender;
	char name[20];
};

int set_human(struct TEST a, int age, int gender);
int set_human2(struct TEST* a, int age, int gender);
int set_human3(struct TEST* a, int age, int gender, const char* name);
char copy_str(char* dest, const char* src);

int main() {
	struct TEST human;
	set_human(human, 10, 10);
	// printf("AGE : %d // Gender : %d ", human.age, human.gender);
	
	/*
		성공적으로 컴파일하면 오류가 나타난다.
		set_human(human, 10, 1);을 수행하면
		human의 age와 gender 멤버들이 초기화 될 것처럼 보인다.
		하지만 그렇지 않다.

		바로 "특정한 변수의 값을 다른 함수를 통해 바꾸려면 변수의 주소값을 전달해야 한다"
		라는 룲을 지키지 않았기 때문이다.

		즉 a.age = age;를 했을 때 age의 값이 바뀌는 것은 
		실제 main 함수에서의 human이 아니라 
		set_human 함수의 a라는 human과 별개의 구조체 변수의 age 멤버의 값이 바뀌게 된다.

		따라서 실제 human 구조체 변수의 멤버들은 
			전혀 초기화 되지 않은 채 출력이 실행되어 오류가 발생했다.

		이를 해결하기 위해선 human 구조체 변수의 주소값을 인자로 받는 함수를 만들어야 한다.
	*/
	struct TEST human2;
	set_human2(&human2, 10, 1);
	printf("AGE : %d // Gender : %d ", human2.age, human2.gender);
	/*
		human의 주소값을 인자로 전달하고 있다.
		따라서 set_human2의 첫 번째 인자인 a는 human을 가리키게 된다.
		
		주의할 점은 a는 절대로 구조체 변수가 아니라는 것이다.
		단지 human 구조체 변수가 메모리 사엥 위치한 곳의 시작 지점의 주소값을 보관하고 있을 뿐이다.

		아무튼 위와 같이 전달한다면
		a->을 통해 a가 가리키고 있는 구조체 변수의 멤버, 
		즉 위의 경우에는 human의 멤버를 지칭할 수 있게 된다.

		따라서 set_human2 함수 내부에서 a-> age = age;를 하게 되면
		human의 age 멤버의 값이 바뀐다.

		물론 주의할 점은 a->age와 age는 다르다는 것이다.
		a->age는 human 구조체 변수의 int형 멤버 age를 지칭하는 것이고
		age는 단순히 set_human 함수에서 인자로 받아들여진 int형의 age와 변수를 가리키는 말이다.
		이 둘은 다른 것이고 실제로 컴퓨터 내부에서도 다르게 처리ㅚㄴ다.

	*/
	struct TEST3 human3;

	set_human3(&human3, 10, 1, "Lee");

	printf("AGE : %d // Gender : %d // Name : %s \n", human3.age, human3.gender, human3.name);

	return 0;
}

int set_human(struct TEST a, int age, int gender) {
	a.age = age;
	a.gender = gender;
	return 0;
}
int set_human2(struct TEST* a, int age, int gender) {
	a->age = age;
	a->gender = gender;
	return 0;
}
int set_human3(struct TEST3* a, int age, int gender, const char* name) {
	/*
		set_human3 함수에서 name 멤버 역시 같이 초기화해주기 위해
		인자로 char* 형의 name이라는 인자를 추가로 받게 된다.
	*/
	a->age = age;
	a->gender = gender;
	copy_str(a->name, name);
	/*
		main함수의 human3 구조체 변수의 name 멤버를 초기화 하기 위해서는
		copy_str 함수를 이용해야 한다.

		이를 위해서는 name 배열의 주소값과 
			복사해 넣으려는 문자열의 주소값을 넣어야하는데
		
		a -> name을 통해 human3 구조체 변수의 name 멤버의 주소값과, name( 두 번째 인자로 a->name과 전혀 다른 것이다)
		을 통해 복사해 넣으려는 문자열의 주소값 copy_str에 전달할 수 있게 된다.

		아무튼 위를 통해 성공적으로 human3의 각각의 멤버들을 초기화 할 수 있게 되었다.
	*/

	return 0;
}
char copy_str(char* dest, const char* src) {
	while (*src) {
		*dest = *src;
		src++;
		dest++;
	}

	*dest = '\0';

	return 1;
}