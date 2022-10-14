#define _CRT_SECURE_NO_WARNINGS		
// visual studio 2005 이상부터 'scanf', fopen' , 'strcpy' 등을 사용하면 Warning C4996 경고 발생 
// 문자열이나 파일에 관련된 버퍼나 스택등 메모리에 문제 생길 수 있음
// 경고 무시

#include <stdio.h>

long int fact(int); // 함수의 정의는 밑에 있지만, 선언하기 전에 나오더라도 괜찮다

void main() {
	int n, result;
	printf("\n 정수를 입력하세요 : ");
	scanf("%d", &n);
	result = fact(n);
	printf("\n\n %d의 팩토리얼 값은 %ld입니다.\n", n, result);
	getchar(); getchar();
}

long int fact(int n) {
	int value;
	if (n <= 1) {
		printf("\n fact(1) 함수 호출!");
		printf("\n fact(1) 값 1 반환!!");
		return 1;
	}
	else {
		printf("\n fact(%d) 함수 호출!", n);
		value = (n * fact(n - 1));
		printf("\n fact(%d) 값 %ld 반환!!", n, value);
		return value;
	}
}