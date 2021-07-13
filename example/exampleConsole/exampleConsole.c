#include <stdio.h>

#include "kw_.h"
#pragma comment(lib, "kw_.lib")

void CALLBACK OnEventConnect(long errCode) {
    if (errCode == 0) {
        puts("로그인 성공");
        
        // 종목코드로 종목명 확인
		char* s = kw_GetMasterCodeName("005930");
        printf("종목명=%s\n", s);
		kw_FreeString(s);
    }
    else {
        puts("로그인 실패");
        exit(0);
    }
}

int main()
{
	// 이벤트 핸들러 설정
    kw_SetOnEventConnect(OnEventConnect);
	
	// 로그인
    kw_CommConnect();
    
    kw_Wait();
    return 0;
}
