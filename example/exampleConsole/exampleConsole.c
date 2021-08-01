#include <stdio.h>

#include "kw_.h"
#pragma comment(lib, "kw_.lib")

void OnEventConnect(long errCode);

void OnReceiveTrData(PCSTR sScrNo, PCSTR sRQName,
	PCSTR sTrCode, PCSTR sRecordName, PCSTR sPrevNext, long nDataLength,
	PCSTR sErrorCode, PCSTR sMessage, PCSTR sSplmMsg);

void OnReceiveRealData(PCSTR sRealKey, PCSTR sRealType, PCSTR sRealData);

int main()
{
	kw_Initialize(0);

	// 이벤트 핸들러 설정
	kw_SetOnEventConnect(OnEventConnect);
	kw_SetOnReceiveTrData(OnReceiveTrData);
	kw_SetOnReceiveRealData(OnReceiveRealData);

	// 로그인
	kw_CommConnect();

	kw_Wait();

	kw_Uninitialize();
    return 0;
}

void OnEventConnect(long errCode) {
	if (errCode == 0) {
		puts("연결됨");

		// 종목코드로 종목명 확인
		char* s = kw_GetMasterCodeName("005930");
		printf("종목명=%s\n", s);
		kw_FreeString(s);

		// 시세 조회
		kw_SetInputValue("종목코드", "005930");		
		long ret = kw_CommRqData("rqName1", "opt10001", 0, "scrNo1");
	}
	else {
		puts("연결 종료됨");
	
	}
}

void OnReceiveTrData(PCSTR sScrNo, PCSTR sRQName,
	PCSTR sTrCode, PCSTR sRecordName, PCSTR sPrevNext, long nDataLength,
	PCSTR sErrorCode, PCSTR sMessage, PCSTR sSplmMsg) {
	printf("TrData) %s\n", sScrNo);
}

void OnReceiveRealData(PCSTR sRealKey, PCSTR sRealType, PCSTR sRealData) {
	printf("RealData) %s\n", sRealData);
}
