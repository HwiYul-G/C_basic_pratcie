/*
	여태까지 만든 모든 프로그램에서 변수는 HDD가 아니라 RAM에서 상주하는 데이터였다.
	즉 프로그램이 종료되어도 그렇지만 컴퓨터가 꺼지게 되면 데이터가 날아가게 되는 '휘발성 메모리'이다.

	하지만 컴퓨터에 깔려있는 대부분의 프로그램이나 문서들은 껐다 켜도 사라지지 않는다.
	왜냐하면 그 내용들이 비휘발성 저장매체 인 하드 디스크에 저장되어 있기 때문이다.

	그렇다고 해서 HDD에 아무렇게나 데이터를 보관할 수 있는 것은 아니다.
	HDD에 데이터를 보관할 땐 'file'단위로 데이터를 보관하게 된다.

	따라서 이번엔 어떻게 하면 
	파일을 만들고, 파일에 데이터를 저장하고, 파일을 읽어들일 수 있을 지 알아보자.

	사실 우리가 하드디스크에 저장되어 있는 파일들을 자유롭게 이용할 수 있다고는 하나
	이를 쓰는 과정은 매우매우 복잡하다.
	왜냐하면 파일을 새로 만든다고 쳐도, 
	하드디스크 어떤 부분에 파일을 새로 만들어야 할지, 얼마나 크게 파일을 만들 수 있는 지 등의 모든 것을 고려해야한다.

	자그마한 파일 하나를 만드는 데 이런 짓들을 하기엔 너무 지나치다.
	다행히도 이런 복잡한 일들은 컴퓨터 OS에서 알아서 해준다.

*/
#include <stdio.h>

int main() {
	/*
		fopen 함수는 바로 위에서 말한 OS가 알아서 해준느 부분을 처리한다.
		fopen 함수는 우리가 지정한 파일 a.txt와 소통할 수 있도록 '스트림'을 만들어 준다.
	*/
	FILE* fp;
	fp = fopen("a.text", "w");
	/*
		위의 코드 fopen 함수는 만든 스트림을 가리키는 포인터를 리턴한다.
		스트림에 관한 정보는 FILE이라는 구조체에 들어가 있다.

		이제 우리는 fp를 가지고 파일을 이용할 수 있게 된다.
		그런데 우리는 fopen에서 2번째 인자로 "w"를 전달했는데
		이는 이 파일에 오직 write만 하겠다는 의미이다.

		즉 스트림인데도 출력 스트림만 만든 것이다.
		파일에 쓴느 것은 프로그램 관점에서 출력이므로 출력 스트림
		읽는 것은 입력 받는 것이므로 입력 스트림이다.
		출력 스트림을 만들었다는 것은 즉 쉽게 말하면 일방 통행 도로를 만든 것이다.

		이렇게 출력만 하게 된다면 당연히 파일에 write만 할 수 있따.
		파일에서 데이터를 read하는 작업은 불가능하다.

		읽는 것은 나중에 생각하기로 하고 write만 생각해보자.

		우선 fopen에서 "w"를 인자로 전달했을 때 특징이
		1) 첫 번째 인자로 전달된 이름의 파일이 존재하지 않는다면 
				아무 내용이 없는 새 파일을 만들거나
			동일한 이름의 파일이 존재한다면 그 내용을 다 지워버리게 된다.
		
		참고로 a.txt로 그냥 파일의 이름을 전달한다면 오직 '소스파일과 동일한 경로에 있는 파일들'을 찾게 된다.
		만일 다른 폴더에 있는 a.txt를 찾고 싶다면 그 경로를 넣어주면 된다.

		예를 들어 C드라이브의 BBB라는 폴더의 a.txt 라는 파일을 원한다면
		fp = fopen("C:\\BBB\\a.txt","w");
		를 하면 된다.
		이때 \\을 쓰는 이유는 \을 하나만 쓰면 escape character라고 생각해서 이상한 문자가 되므로
		\\을 통해 \을 나타내야 한다.

		아무튼 우리의 a.txt의 경우 원래 존재하지 않았을 것이므로 
		fopen에서 a.txt를 "w"로 여는 순간 새로운 파일이 만들어진다.
	*/

	if (fp == NULL) {
		/*
			파일이 어떠한 이유에서라든지 열지 못한 경우 fopen 함수는 NULL을 리턴한다.
			fopen이 실패하는 경우는 그리 많지 않으므로 이 부분을 생략하는 경우가 가끔 있다.
			그런데 만일 fopen이 실패했는데 검사하지 않는다면 소스 뒷 부분에서 어떤 문제가 발생할지 모른다.
			따라서 실패하는 경우가 드물더라도 이렇게 항상 검사를 하자.
		*/
		printf("Write Error!! \n");
		return 0;
	}

	/*
		파일을 열고나서 fputs라는 훌륭한 함수로 파일에 기록할 수 있다.
		1번째 인자로 파일에 기록할 문자열을 전달하고
		2번째 인자로 어떤 스트림을 택할지 그 포인터를 써주면 된다.

		우리는 우리가 위에서 열은 파일 스트림을 택할 것이므로 fp를 써주면 된다.
		
		재미있는 사실은 표준 스트림들은 이미 이름이 정해져있는데 
		앞서 말했듯 stdout은 컴퓨터의 모니터에 해당하는 표준 출력 스트림이다.
		즉 2번째 인자로 stdout을 전달하면 우리 콘솔 화면에 그 문자열이 뜬다.

		fputs("Hello World!!! \n", stdout);
		위 문장을 실행하면 콘솔에 Hello World!!!가 찍힌다.
	*/
	fputs("Hello World!! \n", fp);

	/*
		마지막으로 fclose를 통해 연결되었던 스트림을 닫아주어야 한다.
		만약 fclose로 스트림을 닫지 않는다면, 스트림이 계속 살아있어서
		이 파일은 계속 쓰기 상태로 남아있다.
		이는 프로그램이 종료되기 전까지 이 상태로 계속 남아있어서
		마치 동적 메모리 할당에서 free로 메모리를 반환해 주어야 하는 것처럼 스트림도 닫아 주어야 합니다.

		흥미로운 사실은 fclose로 표준 스트림도 닫아 버릴 수 있다.
		예를 들어 fclose(stdout);을 할 수 있다
		이러면 이후에 printf를 해도 아무것도 출력되지 않는다. 
	*/
	fclose(fp);

	return 0;
}
/*
	스트림(Stream)

	우리가 printf 함수를 이용할 때 어떠한 작업이 컴퓨터에서 내부적으로 처리되는 지 생각해보자.
	1) 먼저 출력할 문자열을 구성해야한다.
	2) 그리고 이를 모니터에 전달해서 출력하라는 명령을 내려야 한다.

	과연 이것이 쉬운일일까? 모니터에 명령을 내리기 위해서는 모니터를 만든 회사마다
	그 방식이 다를 것이고 어떠한 명령을 내려야 하는지도 다를 것이다.
	하지만 우리는 이를 printf라는 함수 하나로 이 모든 것을 했다.
	
	그 이유는 바로 'stream'에 있다.
	스트림은 이 두 개의 완전히 다른 장치들을 이어주는 '파이프'이다.
	이러한 스트림은 우리가 직접 구현해야 되는 것이 아니라 OS가 스스로 처리해주는 것이다.

	만일 우리가 모니터와 잇는 스트림을 이용한다면 OS는 모니터에 맞는 명령을 내릴 것이고,
	키보드와 잇는 스트림을 이용한다면 OS가 키보드에 맞는 명령을 알아서 내릴 것이다.
	프로그래머 입장에서는 걱정할 것이 전혀 없다.

	따라서 우리가 만일 모니터에 A를 출력하고 싶다면
	단순히 스트림에 A를 넣으면 된다.
	왜냐하면 이렇게 스트림으로 전달된 문자 A는 OS에 의해 알아서 모니터에 명령을 내려서 A를 출력하면 된다.
	마찬가지로 키보드에서 문자를 받고 싶다면 스트림을 타고 무슨 문자가 오는 지에만 관심가지면 된다.
	왜냐하면 우리가 키보드에서 무언가 입력했다면 OS에서 알아서 잘 해석을 한 다음
	우리가 이해할 수 있는 데이터로 만들어서 스트림에 전달하기 때문이다.

	// 조금 수준 높은 설명
		스트림을 정확히 표현하면 '추상화된 장치(abstract devices)'라고 말할 수 있다.
		왜냐하면 여러가지 주변 장치들(모니터, 키보드, 하드디스크 등)을 추상화 시켜서
		사용자가 마치 동일한 장치에 접근한 것처럼 사용할 수 있게 만들었기 때문이다.
		어떤 모습으로 장치들을 추상화 시켰냐면 스트림은 마치 책장과 같이 만들었다.
		책장에 책을 끼우거나 빼는 것처럼 데이터를 순차적으로 쭉 나열해서 
		데이터의 끝까지 차례대로 읽어들일 수 있도록 만들었다.
	// 수준 높은 설명 끝

	그런데 사실 생각해보면 우리는 위에서 말한 두 예인 모니터와 키보드에 대한 스트림을 한번도 만든 적이 없다.
	파일을 이용할 때는 파일에 대한 스트림을 fopen으로 만든다고 했었는데..
	사실 모니터와 키보드에 대한 스트림은 표준 스트림(standard stream)이라 해서 프로그램이 실행될 때 자동으로 생성된다.

	모니터에 대한 스트림은 stdout이고, 키보드에 대한 스트림은 stdin이다.
	그 외에 stderr이라는 표준 오류 스트림이란 것이 있는데 stdout과 거의 동일하다. (단지 오류를 출력하는 것일 뿐)
*/