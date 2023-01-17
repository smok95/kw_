#include <stdio.h>
#include "example_TrRealRecv.h"
#include "example_sendCondition.h"

int main()
{
	int input = 0;
	puts("=========================");
	puts("1. 시세 조회 예제 실행");
	puts("2. 조건검색 예제 실행");
	puts("=========================");
	puts("번호를 입력해주세요!");
	scanf("\n%d", &input);

	switch (input)
	{
	case 1:	return example_trRealRecv();
	case 2:	return example_sendCondition();
	}

	return 0;
}
