#include <stdio.h>

#include "kw_.h"
#pragma comment(lib, "kw_.lib")

void OnEventConnect(long errCode) {
    if (errCode == 0) {
        puts("로그인 성공");
        
        // 종목코드로 종목명 확인
		char* s = kw_GetMasterCodeName("005930");
        printf("종목명=%s\n", s);

        kw_SetInputValue("종목코드", "005930");
        long ret = kw_CommRqData("jktest", "opt10001", 0, "jktestscr");
        printf("ret1=%d\n", ret);

		kw_SetInputValue("종목코드", "000660");
		ret = kw_CommRqData("jktes2t", "opt10001", 0, "jktestscr2");
        printf("ret2=%d\n", ret);
		kw_FreeString(s);
    }
    else {
        puts("로그인 실패");
        kw_Disconnect();
    }
}

void OnReceiveTrData(PCSTR sScrNo, PCSTR sRQName,
    PCSTR sTrCode, PCSTR sRecordName, PCSTR sPrevNext, long nDataLength,
    PCSTR sErrorCode, PCSTR sMessage, PCSTR sSplmMsg) {
    printf("%s) scrNo=%s, rqName=%s, trCode=%s\n", __FUNCTION__, sScrNo, 
        sRQName, sTrCode);
}


void OnErceiveRealData(PCSTR sRealKey,
	PCSTR sRealType, PCSTR sRealData) {
    printf("%s) %s\n",__FUNCTION__, sRealData);
}

int main()
{
	// 이벤트 핸들러 설정
    kw_SetOnEventConnect(OnEventConnect);
    kw_SetOnReceiveTrData(OnReceiveTrData);
    kw_SetOnReceiveRealData(OnErceiveRealData);
	
	// 로그인
    kw_CommConnect();
    
    //kw_Wait();

    while (1) {
        Sleep(100);
    }
    return 0;
}
