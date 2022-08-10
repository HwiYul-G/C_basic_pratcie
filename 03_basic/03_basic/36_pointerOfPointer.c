/*
	int **p;
	위는 포인터의 포인터로, int를가리키는 포인터를 가리키는 포인터이다.
	
*/
#include <stdio.h>

int main() {
	int a;
	int* pa;
	int** ppa;

	pa = &a;
	ppa = &pa;	// pa의 주소값이 들어간다.

	a = 3;

	// === 같은 행에 있는 값들이 모두 같다. ===
	// pa가 a를 가리키고 있으므로 *pa를 하면 a를 지칭하는 것이 되어 a의 값을 출력한다.
	// **ppa는 어떨까? 이를 다시 써보면 *(*ppa)가 되고 *ppa는 pa를 지칭하는 것이기에 *pa가 되서 결국 a의 값이 출력된다.
	printf("a : %d // *pa : %d // **ppa : %d \n", a, *pa, **ppa);
	// *ppa도 ppa가 pa를 가리키고 있으므로 *ppa를 하면 pa를 지칭하는 것이된다. 따라서 pa의 값 즉 &a의 값이 출력된다.
	printf("&a : %p // pa : %p // *ppa : %p \n", &a, pa, *ppa);	
	// pa가 a를 가리키고 있으므로 pa에는 a의 주소값이 들어간다. 따라서 &a와 pa는 같은 값이 된다.
	printf("&pa : %p // ppa : %p \n", &pa, ppa);


	

	return 0;
}