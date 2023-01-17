#include <stdio.h>

#include "kw_.h"
#pragma comment(lib, "kw_.lib")

void OnEventConnect(long errCode);
void OnReceiveTrCondition(PCSTR sScrNo,
	PCSTR strCodeList, PCSTR strConditionName, int nIndex, int nNext);
void OnReceiveConditionVer(long lRet, PCSTR sMsg);
void OnReceiveRealCondition(PCSTR sTrCode, PCSTR strType, PCSTR strConditionName, 
	PCSTR strConditionIndex);

int example_sendCondition() {
	kw_Initialize(0);

	// 이벤트 핸들러 설정
	kw_SetOnEventConnect(OnEventConnect);
	kw_SetOnReceiveTrCondition(OnReceiveTrCondition);
	kw_SetOnReceiveConditionVer(OnReceiveConditionVer);
	kw_SetOnReceiveRealCondition(OnReceiveRealCondition);

	// 로그인
	kw_CommConnect();

	kw_Wait();

	kw_Uninitialize();
	return 0;
}

void OnEventConnect(long errCode) {
	if (errCode == 0) {
		puts("연결됨");

		// 조건검색
		// SendConditon 호출전에 반드시 GetConditionLoad가 최초 1회 호출되어 야 함.
		long ret = kw_GetConditionLoad();
		printf("kw_GetConditionLoad=%d\n", ret);

		// 조건검색명 목록 조회
		char* names = kw_GetConditionNameList();
		printf("ConditionNameList=%s\n", names);
		kw_FreeString(names);
	}
	else {
		puts("연결 종료됨");

	}
}


void OnReceiveTrCondition(PCSTR sScrNo,
	PCSTR strCodeList, PCSTR strConditionName, int nIndex, int nNext) {
	printf("OnReceiveTrCondition) scrNo=%s, conditionName=%s, index=%d, codelist=%s\n", 
		sScrNo, strConditionName, nIndex, strCodeList);
}

void OnReceiveConditionVer(long lRet, PCSTR sMsg) {
	printf("OnReceiveConditionVer) %s\n", sMsg);

	// 화면번호
	char* strScrNo = "testScr1";
	// 조건식 이름 (GetConditionNameList참고)
	char* strConditionName = "조건식1";
	// 조건식 인덱스(GetConditionNameList참고)
	int nIndex = 5;
	// 조회구분(0:일반조회, 1:실시간조회, 2:연속조회)
	int nSearch = 1; 	
	long ret = kw_SendCondition(strScrNo, strConditionName, nIndex, nSearch);
	printf("SendCondition=%d\n", ret);
}

void OnReceiveRealCondition(PCSTR sTrCode, PCSTR strType, PCSTR strConditionName,
	PCSTR strConditionIndex) {
	printf("OnReceiveRealCondition) trCode=%s, type=%s, conditionName=%s, conditionIndex=%s\n", 
		sTrCode, strType, strConditionName, strConditionIndex);
}