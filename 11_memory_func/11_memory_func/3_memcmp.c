/* memcmp 함수 
    
    memcmp 함수는 이름에서도 충분히 짐작이 되듯 2 개의 메모리 공간을 서로 비교하는 함수이다.
    memcmp 함수는 메모리의 두 부분을 원하는 만큼 비교한다.
    이 때 같다면 0, 다르다면 결과에 따라 0이 아닌 값을 리턴하게 된다.

*/

#include <stdio.h>
#include <string.h>

int main() {
    int arr[10] = { 1, 2, 3, 4, 5 };
    int arr2[10] = { 1, 2, 3, 4, 5 };

    // arr과 arr2를 비교해서 처음 5개의 byte가 같다면 0을 리턴한다
    // 주의할 점은 5개의 원소가 아니라 5byte라는 점이다.
    // 만일 arr1과 arr2 전체를 비교하고 싶다면 3번째 인자로 sizeof(int)*5를 넣어주어야한다.
    if (memcmp(arr, arr2, 5) == 0)
        printf("arr 과 arr2 는 일치! \n");
    else
        printf("arr 과 arr2 는 일치 안함 \n");

    return 0