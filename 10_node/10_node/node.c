/*
	지금까지 여러가지 자료형들을 배워왔다.
	변수를 무식하게 나열하는 것을 막기 위해 배열을 이용했고,
	배열의 기능의 한계를 느껴 구조체를 만들었다.
	그리고 구조체 하나에 한 개 한개를 다루는데 한계를 느껴 구조체 배열을 이용했다.
	
	동적 할당을 함을써 사용자가 원하는 크기의 입력을 다룰 수 있게 되었다고 해도
	아직 많은 문제를 느끼고 있다.
	만일 사용자가 마음이 변해서 한 개의 입력을 더 받고 싶다면 같은 경우가 있다.
	새롭게 동적할다응ㄹ 하면 되지만 예를들어 1000개의 데이터가 있는데 1개의 추가적인 데이터를 위해
	1001개를 위한 공간을 새로 잡으면 너무 아깝다.

	이를 해결하는 것이 바로 '노드'이다.
	노드는 (데이터 |다음 노드를 가리키논 포인터) 형식으로 생겼다.

	이를 C코드로 나타내면 아래와 같다.
	struct Node{
		int dat;
		struct Node* nextNode;
	};

	즉 첫번째 노드가 다음 노드를 가리키면 다음 노드는 자신의 다음 노드를 가리키는 식으로 쭉 이어진다.
	마지막 노드는 아무것도 가리키지 않는다.
	또한 가각의 노드는 데이터를 하나씩 가지고 있다. 
	즉 나중에 데이터를 한 개 더 추가하려고 하면 마지막 노드에 새 노드를 만들어서 이어주기만 하면 된다.

	마지막 노드 이후로만 데이터를 추가할 수 있는 게 아니라 중간으로 삽입할 때도 편리하다.
	새로운 노드를 생성해서 기존 노드들과의 연결을 해주면 된다.

	이러한 사실을 바탕으로 노드를 만들어 보자.
*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* nextNode;
};
struct Node* CreateNode(int data); // Node를 생성하기'만'하는 함수
struct Node* InsertNode(struct Node* current, int data); // 어떤 노드 뒤에 새로운 노드를 생성하는 함수
void DestroyNode(struct Node* destroy, struct Node* head); // Node를 파괴하는 역할을 가지는 함수
void PrintNodeFrom(struct Node* from);

int main() {
	struct Node* Node1 = CreateNode(100);
	struct Node* Node2 = InsertNode(Node1, 200);
	struct Node* Node3 = InsertNode(Node2, 300);
	struct Node* Node4 = InsertNode(Node2, 400); // Node2 뒤에 Node4를 넣음

	PrintNodeFrom(Node1);

	return 0;
}

struct Node* CreateNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));	// node에 메모리 할당

	newNode->data = data;
	newNode->nextNode = NULL; // 가리키는 다음 노드를 NULL

	return newNode;
}
struct Node* InsertNode(struct Node* current, int data) {
	// 앞에 있는 노드의 정보 current, 새로운 노드를 위한 data
	
	// current 노드가 가리키고 있는 다음 노드가 after이다.
	struct Node* after = current->nextNode;

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->nextNode = after;

	current->nextNode = newNode;

	return newNode;
}

void DestroyNode(struct Node* destroy, struct Node* head) {
	// destroy : 파괴하고자 하는 노드, head : 첫 노드
	// 가리키고 있던 노드를 찾기 위해선 맨 처음부터 뒤져나가야함.
	
	// 다음 노드를 가리킬 포인터
	struct Node* next = head;

	// head를 파괴하려 한다면
	if (destroy == head) {
		free(destroy);
		return;
	}

	while (next)
	{
		// next node가 destroy라면 next가 destroy 앞 노드
		if (next->nextNode == destroy) {
			// 따라서 next의 다음 노드는 destroy가 아니라 destroy의 다음 노드가 된다.
			next->nextNode == destroy->nextNode;
		}
		next = next->nextNode;
	}
	free(destroy);
}
void PrintNodeFrom(struct Node* from) {
	while (from) {
		printf("노드의 데이터 : %d \n", from->data);
		from = from->nextNode;
	}
}
/*
	Node는 배열과 달리 추가/삭제/삽입이 월등히 편리하다.
	그렇다고 해서 노드가 배열보다 월등한 것은 아니다.

	왜냐하면 배열의 경우 3번째 원소에 접근하기 위해선 단순히 arr[3]으로 하면 되지만
	노드의 경우 헤드로부터 3번째 까지 일일이 '탐색'해야하기 때문이다.

	따라서 N개의 노드가 있따면 최악의 경우 N번동안 계속 찾아야하지만
	배열의 경우 특정한 상수 시간 내에 찾아갈 수 있기 때문에 이 부분에 대해선 배열이 월등이 좋다.

	또한 노드의 경우 데이터를 위한 공간 말고도 다음 노드를 가리키기 위한 8byte를 더 필요로 하기 때문에 공간적으로도 약간 손해르 본다.

	따라서 결론적으로 이야기 하자면
	추가/삭제/삽입이 자주 일어나는 경우는 노드를 사용하고 특정한 번째에 찾아가야 하는 일이 잦은 일은 배열을 사용하는 것이 이롭다.

	사실 노드 말고도 여러가지 형태의 자료구조들이 있다. (ex, 스택, 큐, 트리 등)

*/