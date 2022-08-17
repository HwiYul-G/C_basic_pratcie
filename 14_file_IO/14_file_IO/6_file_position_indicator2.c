/* 출력 스트림도 마찬가지*/
#include <stdio.h>
int main() {
	FILE* fp = fopen("a.txt", "w");
	fputs("Psi is an excellent C programmer", fp);
	
	fseek(fp, 0, SEEK_SET);	// 처음으로 돌아가서
	
	fputs("is Psi", fp); // 다시 fputs를 하니 파일 앞의 내용이 끼워져 들어가지 않고 덮어쓰기 된다.

	fclose(fp);
	/*
		최종적으로
		is Psi an excellent C programmer가 적혀있다.
	
	*/
	return 0;
}