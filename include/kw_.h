/*
*	kw_ - 키움증권 OpenAPI+ C wrapper
* 
*	https://github.com/smok95/kw_
*	2021.07.10 kim,jk <d0nzs00n@gmail.com>
*/
#ifndef KIWOOM_API_C_WRAPPER_H_
#define KIWOOM_API_C_WRAPPER_H_

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <OAIdl.h>

#ifdef KW_EXPORTS
#define KW_API __declspec(dllexport)
#else
#define KW_API __declspec(dllexport)
#endif // KIWOOM_EXPORTS

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	KW_API long		kw_CommConnect();

KW_API long		kw_CommRqDataW(PCWSTR sRQName, PCWSTR sTrCode, long nPrevNext, 
	PCWSTR sScreenNo);
KW_API long		kw_CommRqDataA(PCSTR sRQName, PCSTR sTrCode, long nPrevNext, 
	PCSTR sScreenNo);

KW_API PWSTR	kw_GetLoginInfoW(PCWSTR sTag);
KW_API PSTR		kw_GetLoginInfoA(PCSTR sTag);

KW_API long		kw_SendOrderW(PCWSTR sRQName, PCWSTR sScreenNo, PCWSTR sAccNo, 
	long nOrderType, PCWSTR sCode, long nQty, long nPrice, PCWSTR sHogaGb, 
	PCWSTR sOrgOrderNo);
KW_API long		kw_SendOrderA(PCSTR sRQName, PCSTR sScreenNo, PCSTR sAccNo, 
	long nOrderType, PCSTR sCode, long nQty, long nPrice, PCSTR sHogaGb, 
	PCSTR sOrgOrderNo);

KW_API long		kw_SendOrderFOW(PCWSTR sRQName, PCWSTR sScreenNo, PCWSTR sAccNo, 
	PCWSTR sCode, long lOrdKind, PCWSTR sSlbyTp, PCWSTR sOrdTp, long lQty,
	PCWSTR sPrice, PCWSTR sOrgOrdNo);
KW_API long		kw_SendOrderFOA(PCWSTR sRQName, PCWSTR sScreenNo, PCWSTR sAccNo, 
	PCWSTR sCode, long lOrdKind, PCWSTR sSlbyTp, PCWSTR sOrdTp, long lQty,
	PCWSTR sPrice, PCWSTR sOrgOrdNo);

KW_API void		kw_SetInputValueW(PCWSTR sID, PCWSTR sValue);
KW_API void		kw_SetInputValueA(PCSTR sID, PCSTR sValue);

KW_API void		kw_DisconnectRealDataW(PCWSTR sScnNo);
KW_API void		kw_DisconnectRealDataA(PCSTR sScnNo);

KW_API long		kw_GetRepeatCntW(PCWSTR sTrCode, PCWSTR sRecordName);
KW_API long		kw_GetRepeatCntA(PCSTR sTrCode, PCSTR sRecordName);

KW_API long		kw_CommKwRqDataW(PCWSTR sArrCode, long bNext,  int nCodeCount, 
	int nTypeFlag, PCWSTR sRQName, PCWSTR sScreenNo);
KW_API long		kw_CommKwRqDataA(PCSTR sArrCode, long bNext, int nCodeCount, 
	int nTypeFlag, PCSTR sRQName, PCSTR sScreenNo);

KW_API PWSTR	kw_GetAPIModulePathW();
KW_API PSTR		kw_GetAPIModulePathA();

KW_API PWSTR	kw_GetCodeListByMarketW(PCWSTR sMarket);
KW_API PSTR		kw_GetCodeListByMarketA(PCSTR sMarket);

KW_API long		kw_GetConnectState();

KW_API PWSTR	kw_GetMasterCodeNameW(PCWSTR sTrCode);
KW_API PSTR		kw_GetMasterCodeNameA(PCSTR sTrCode);

KW_API long		kw_GetMasterListedStockCntW(PCWSTR sTrCode);
KW_API long		kw_GetMasterListedStockCntA(PCSTR sTrCode);

KW_API PWSTR	kw_GetMasterConstructionW(PCWSTR sTrCode);
KW_API PSTR		kw_GetMasterConstructionA(PCSTR sTrCode);

KW_API PWSTR	kw_GetMasterListedStockDateW(PCWSTR sTrCode);
KW_API PSTR		kw_GetMasterListedStockDateA(PCSTR sTrCode);

KW_API PWSTR	kw_GetMasterLastPriceW(PCWSTR sTrCode);
KW_API PSTR		kw_GetMasterLastPriceA(PCSTR sTrCode);

KW_API PWSTR	kw_GetMasterStockStateW(PCWSTR sTrCode);
KW_API PSTR		kw_GetMasterStockStateA(PCSTR sTrCode);

KW_API long		kw_GetDataCountW(PCWSTR strRecordName);
KW_API long		kw_GetDataCountA(PCSTR strRecordName);

KW_API PWSTR	kw_GetOutputValueW(PCWSTR strRecordName, long nRepeatIdx, 
	long nItemIdx);
KW_API PSTR		kw_GetOutputValueA(PCSTR strRecordName, long nRepeatIdx, 
	long nItemIdx);

KW_API PWSTR	kw_GetCommDataW(PCWSTR  strTrCode, PCWSTR  strRecordName, 
	long nIndex, PCWSTR  strItemName);
KW_API PSTR		kw_GetCommDataA(PCSTR strTrCode, PCSTR strRecordName, 
	long nIndex, PCSTR strItemName);

KW_API PWSTR	kw_GetCommRealDataW(PCWSTR sTrCode, long nFid);
KW_API PSTR		kw_GetCommRealDataA(PCSTR sTrCode, long nFid);

KW_API PWSTR	kw_GetChejanDataW(long nFid);
KW_API PSTR		kw_GetChejanDataA(long nFid);

KW_API PWSTR	kw_GetThemeGroupListW(long nType);
KW_API PSTR		kw_GetThemeGroupListA(long nType);

KW_API PWSTR	kw_GetThemeGroupCodeW(PCWSTR strThemeCode);
KW_API PSTR		kw_GetThemeGroupCodeA(PCSTR strThemeCode);

KW_API PWSTR	kw_GetFutureListW();
KW_API PSTR		kw_GetFutureListA();

KW_API PWSTR	kw_GetFutureCodeByIndexW(int nIndex);
KW_API PSTR		kw_GetFutureCodeByIndexA(int nIndex);

KW_API PWSTR	kw_GetActPriceListW();
KW_API PSTR		kw_GetActPriceListA();

KW_API PWSTR	kw_GetMonthListW();
KW_API PSTR		kw_GetMonthListA();

KW_API PWSTR	kw_GetOptionCodeW(PCWSTR strActPrice, int nCp, PCWSTR strMonth);
KW_API PSTR		kw_GetOptionCodeA(PCSTR strActPrice, int nCp, PCSTR strMonth);

KW_API PWSTR	kw_GetOptionCodeByMonthW(PCWSTR sTrCode, int nCp, 
	PCWSTR strMonth);
KW_API PSTR		kw_GetOptionCodeByMonthA(PCSTR sTrCode, int nCp, 
	PCSTR strMonth);

KW_API PWSTR	kw_GetOptionCodeByActPriceW(PCWSTR sTrCode, int nCp, int nTick);
KW_API PSTR		kw_GetOptionCodeByActPriceA(PCSTR sTrCode, int nCp, int nTick);

KW_API PWSTR	kw_GetSFutureListW(PCWSTR strBaseAssetCode);
KW_API PSTR		kw_GetSFutureListA(PCSTR strBaseAssetCode);

KW_API PWSTR	kw_GetSFutureCodeByIndexW(PCWSTR strBaseAssetCode, int nIndex);
KW_API PSTR		kw_GetSFutureCodeByIndexA(PCSTR strBaseAssetCode, int nIndex);

KW_API PWSTR	kw_GetSActPriceListW(PCWSTR strBaseAssetGb);
KW_API PSTR		kw_GetSActPriceListA(PCSTR strBaseAssetGb);

KW_API PWSTR	kw_GetSMonthListW(PCWSTR strBaseAssetGb);
KW_API PSTR		kw_GetSMonthListA(PCSTR strBaseAssetGb);

KW_API PWSTR	kw_GetSOptionCodeW(PCWSTR strBaseAssetGb, PCWSTR strActPrice,
	int nCp, PCWSTR strMonth);
KW_API PSTR		kw_GetSOptionCodeA(PCSTR strBaseAssetGb, PCSTR strActPrice,
	int nCp, PCSTR strMonth);

KW_API PWSTR	kw_GetSOptionCodeByMonthW(PCWSTR strBaseAssetGb, PCWSTR sTrCode, 
	int nCp, PCWSTR strMonth);
KW_API PSTR		kw_GetSOptionCodeByMonthA(PCSTR strBaseAssetGb, PCSTR sTrCode,
	int nCp, PCSTR strMonth);

KW_API PWSTR	kw_GetSOptionCodeByActPriceW(PCWSTR strBaseAssetGb, 
	PCWSTR sTrCode, int nCp, int nTick);
KW_API PSTR		kw_GetSOptionCodeByActPriceA(PCSTR strBaseAssetGb, 
	PCSTR sTrCode, int nCp, int nTick);

KW_API PWSTR	kw_GetSFOBasisAssetListW();
KW_API PSTR		kw_GetSFOBasisAssetListA();

KW_API PWSTR	kw_GetOptionATMW();
KW_API PSTR		kw_GetOptionATMA();

KW_API PWSTR	kw_GetSOptionATMW(PCWSTR strBaseAssetGb);
KW_API PSTR		kw_GetSOptionATMA(PCSTR strBaseAssetGb);

KW_API PWSTR	kw_GetBranchCodeNameW();
KW_API PSTR		kw_GetBranchCodeNameA();

KW_API long		kw_SendOrderCreditW(PCWSTR sRQName, PCWSTR sScreenNo,
	PCWSTR sAccNo, long nOrderType, PCWSTR sCode, long nQty, long nPrice,
	PCWSTR sHogaGb, PCWSTR sCreditGb, PCWSTR sLoanDate, PCWSTR sOrgOrderNo);
KW_API long		kw_SendOrderCreditA(PCSTR sRQName, PCSTR sScreenNo, 
	PCSTR sAccNo, long nOrderType, PCSTR sCode, long nQty, long nPrice,
	PCSTR sHogaGb, PCSTR sCreditGb, PCSTR sLoanDate, PCSTR sOrgOrderNo);

KW_API PWSTR	kw_KOA_FunctionsW(PCWSTR sFunctionName, PCWSTR sParam);
KW_API PSTR		kw_KOA_FunctionsA(PCSTR sFunctionName, PCSTR sParam);

KW_API long		kw_SetInfoDataW(PCWSTR sInfoData);
KW_API long		kw_SetInfoDataA(PCSTR sInfoData);

KW_API long		kw_SetRealRegW(PCWSTR strScreenNo, PCWSTR strCodeList,
	PCWSTR strFidList, PCWSTR strOptType);
KW_API long		kw_SetRealRegA(PCSTR strScreenNo, PCSTR strCodeList,
	PCSTR strFidList, PCSTR strOptType);

KW_API long		kw_GetConditionLoad();

KW_API PWSTR	kw_GetConditionNameListW();
KW_API PSTR		kw_GetConditionNameListA();

KW_API long		kw_SendConditionW(PCWSTR strScrNo, PCWSTR strConditionName,
	int nIndex, int nSearch);
KW_API long		kw_SendConditionA(PCSTR strScrNo, PCSTR strConditionName,
	int nIndex, int nSearch);

KW_API void		kw_SendConditionStopW(PCWSTR strScrNo, PCWSTR strConditionName,
	int nIndex);
KW_API void		kw_SendConditionStopA(PCSTR strScrNo, PCSTR strConditionName,
	int nIndex);

KW_API VARIANT	kw_GetCommDataExW(PCWSTR strTrCode, PCWSTR strRecordName);
KW_API VARIANT	kw_GetCommDataExA(PCSTR strTrCode, PCSTR strRecordName);

KW_API void		kw_SetRealRemoveW(PCWSTR strScrNo, PCWSTR strDelCode);
KW_API void		kw_SetRealRemoveA(PCSTR strScrNo, PCSTR strDelCode);

KW_API long		kw_GetMarketTypeW(PCWSTR sTrCode);
KW_API long		kw_GetMarketTypeA(PCSTR sTrCode);

typedef void (CALLBACK* kw_OnEventConnect)(long nErrCode);

typedef void (CALLBACK* kw_OnReceiveTrDataW)(PCWSTR sScrNo, PCWSTR sRQName,
	PCWSTR sTrCode, PCWSTR sRecordName, PCWSTR sPrevNext, long nDataLength,
	PCWSTR sErrorCode, PCWSTR sMessage, PCWSTR sSplmMsg);
typedef void (CALLBACK* kw_OnReceiveTrDataA)(PCSTR sScrNo, PCSTR sRQName,
	PCSTR sTrCode, PCSTR sRecordName, PCSTR sPrevNext, long nDataLength,
	PCSTR sErrorCode, PCSTR sMessage, PCSTR sSplmMsg);

typedef void (CALLBACK* kw_OnReceiveRealDataW)(PCWSTR sRealKey,
	PCWSTR sRealType, PCWSTR sRealData);
typedef void (CALLBACK* kw_OnReceiveRealDataA)(PCSTR sRealKey,
	PCSTR sRealType, PCSTR sRealData);

typedef void (CALLBACK* kw_OnReceiveMsgW)(PCWSTR sScrNo, PCWSTR sRQName,
	PCWSTR sTrCode, PCWSTR sMsg);
typedef void (CALLBACK* kw_OnReceiveMsgA)(PCSTR sScrNo, PCSTR sRQName,
	PCSTR sTrCode, PCSTR sMsg);

typedef void (CALLBACK* kw_OnReceiveChejanDataW)(PCWSTR sGubun, long nItemCnt,
	PCWSTR sFIdList);
typedef void (CALLBACK* kw_OnReceiveChejanDataA)(PCSTR sGubun, long nItemCnt,
	PCSTR sFIdList);

typedef void (CALLBACK* kw_OnReceiveRealConditionW)(PCWSTR sTrCode,
	PCWSTR strType, PCWSTR strConditionName, PCWSTR strConditionIndex);
typedef void (CALLBACK* kw_OnReceiveRealConditionA)(PCSTR sTrCode,
	PCSTR strType, PCSTR strConditionName, PCSTR strConditionIndex);

typedef void (CALLBACK* kw_OnReceiveTrConditionW)(PCWSTR sScrNo,
	PCWSTR strCodeList, PCWSTR strConditionName, int nIndex, int nNext);
typedef void (CALLBACK* kw_OnReceiveTrConditionA)(PCSTR sScrNo,
	PCSTR strCodeList, PCSTR strConditionName, int nIndex, int nNext);

typedef void (CALLBACK* kw_OnReceiveConditionVerW)(long lRet, PCWSTR sMsg);
typedef void (CALLBACK* kw_OnReceiveConditionVerA)(long lRet, PCSTR sMsg);

KW_API void kw_SetOnEventConnect(kw_OnEventConnect handler);

KW_API void kw_SetOnReceiveTrDataW(kw_OnReceiveTrDataW handler);
KW_API void kw_SetOnReceiveTrDataA(kw_OnReceiveTrDataA handler);

KW_API void kw_SetOnReceiveRealDataW(kw_OnReceiveRealDataW handler);
KW_API void kw_SetOnReceiveRealDataA(kw_OnReceiveRealDataA handler);

KW_API void kw_SetOnReceiveMsgW(kw_OnReceiveMsgW handler);
KW_API void kw_SetOnReceiveMsgA(kw_OnReceiveMsgA handler);

KW_API void kw_SetOnReceiveChejanDataW(kw_OnReceiveChejanDataW handler);
KW_API void kw_SetOnReceiveChejanDataA(kw_OnReceiveChejanDataA handler);

KW_API void kw_SetOnReceiveRealConditionW(kw_OnReceiveRealConditionW handler);
KW_API void kw_SetOnReceiveRealConditionA(kw_OnReceiveRealConditionA handler);

KW_API void kw_SetOnReceiveTrConditionW(kw_OnReceiveTrConditionW handler);
KW_API void kw_SetOnReceiveTrConditionA(kw_OnReceiveTrConditionA handler);

KW_API void kw_SetOnReceiveConditionVerW(kw_OnReceiveConditionVerW handler);
KW_API void kw_SetOnReceiveConditionVerA(kw_OnReceiveConditionVerA handler);

KW_API void kw_Wait();
KW_API void kw_Free(void* p);
KW_API void kw_FreeStringW(PWSTR p);
KW_API void kw_FreeStringA(PSTR p);

#ifdef _UNICODE
#define kw_SetOnReceiveConditionVer kw_SetOnReceiveConditionVerW
#define kw_OnReceiveConditionVer kw_OnReceiveConditionVerW
#define kw_SetOnReceiveRealCondition kw_SetOnReceiveRealConditionW
#define kw_OnReceiveRealCondition kw_OnReceiveRealConditionW
#define kw_SetOnReceiveChejanData kw_SetOnReceiveChejanDataW
#define kw_OnReceiveChejanData kw_OnReceiveChejanDataW
#define kw_GetCommDataEx kw_GetCommDataExW
#define kw_GetMarketType kw_GetMarketTypeW
#define kw_SetRealRemove kw_SetRealRemoveW
#define kw_SendConditionStop kw_SendConditionStopW
#define kw_SendCondition kw_SendConditionW
#define kw_GetConditionNameList kw_GetConditionNameListW
#define kw_SetRealReg kw_SetRealRegW
#define kw_SetInfoData kw_SetInfoDataW
#define kw_KOA_Functions kw_KOA_FunctionsW
#define kw_SendOrderCredit kw_SendOrderCreditW
#define kw_GetSOptionCodeByActPrice kw_GetSOptionCodeByActPriceW
#define kw_GetSOptionCodeByMonth kw_GetSOptionCodeByMonthW
#define kw_GetSMonthList kw_GetSMonthListW
#define kw_GetSActPriceList kw_GetSActPriceListW
#define kw_GetSFutureCodeByIndex kw_GetSFutureCodeByIndexW
#define kw_GetSFutureList kw_GetSFutureListW
#define kw_GetOptionCodeByActPrice kw_GetOptionCodeByActPriceW
#define kw_GetOptionCodeByMonth kw_GetOptionCodeByMonthW
#define kw_GetOptionCode kw_GetOptionCodeW
#define kw_CommKwRqData kw_CommKwRqDataW
#define kw_GetRepeatCnt kw_GetRepeatCntW
#define kw_DisconnectRealData kw_DisconnectRealDataW
#define kw_SetInputValue kw_SetInputValueW
#define kw_SendOrderFO kw_SendOrderFOW
#define kw_SendOrder kw_SendOrderW
#define kw_SetOnReceiveMsg kw_SetOnReceiveMsgW
#define kw_OnReceiveMsg kw_OnReceiveMsgW
#define kw_GetChejanData kw_GetChejanDataW
#define kw_OnReceiveRealData kw_OnReceiveRealDataW
#define kw_SetOnReceiveRealData kw_SetOnReceiveRealDataW
#define kw_GetCommRealData kw_GetCommRealDataW
#define kw_GetCommData kw_GetCommDataW
#define kw_GetOutputValue kw_GetOutputValueW
#define kw_GetDataCount kw_GetDataCountW
#define kw_GetMasterStockState kw_GetMasterStockStateW
#define kw_GetMasterLastPrice kw_GetMasterLastPriceW
#define kw_GetMasterListedStockDate kw_GetMasterListedStockDateW
#define kw_GetMasterConstruction kw_GetMasterConstructionW
#define kw_GetMasterListedStockCnt kw_GetMasterListedStockCntW
#define kw_GetMasterCodeName kw_GetMasterCodeNameW
#define kw_GetCodeListByMarket kw_GetCodeListByMarketW
#define kw_GetLoginInfo kw_GetLoginInfoW
#define kw_OnReceiveTrData kw_OnReceiveTrDataW
#define kw_SetOnReceiveTrData kw_SetOnReceiveTrDataW
#define kw_CommRqData kw_CommRqDataW
#define kw_GetBranchCodeName kw_GetBranchCodeNameW
#define kw_GetSOptionATM kw_GetSOptionATMW
#define kw_GetOptionATM kw_GetOptionATMW
#define kw_GetAPIModulePath kw_GetAPIModulePathW
#define kw_GetFutureList kw_GetFutureListW
#define kw_FreeString kw_FreeStringW
#define kw_GetActPriceList kw_GetActPriceListW
#define kw_GetMonthList kw_GetMonthListW
#define kw_GetFutureCodeByIndex kw_GetFutureCodeByIndexW
#define kw_GetThemeGroupList kw_GetThemeGroupListW
#define kw_GetThemeGroupCode kw_GetThemeGroupCodeW
#define kw_GetSFOBasisAssetList kw_GetSFOBasisAssetListW
#define kw_SetOnReceiveTrCondition kw_SetOnReceiveTrConditionW
#define kw_OnReceiveTrCondition kw_OnReceiveTrConditionW
#else
#define kw_SetOnReceiveConditionVer kw_SetOnReceiveConditionVerA
#define kw_OnReceiveConditionVer kw_OnReceiveConditionVerA
#define kw_SetOnReceiveRealCondition kw_SetOnReceiveRealConditionA
#define kw_OnReceiveRealCondition kw_OnReceiveRealConditionA
#define kw_SetOnReceiveChejanData kw_SetOnReceiveChejanDataA
#define kw_OnReceiveChejanData kw_OnReceiveChejanDataA
#define kw_GetCommDataEx kw_GetCommDataExA
#define kw_GetMarketType kw_GetMarketTypeA
#define kw_SetRealRemove kw_SetRealRemoveA
#define kw_SendConditionStop kw_SendConditionStopA
#define kw_SendCondition kw_SendConditionA
#define kw_GetConditionNameList kw_GetConditionNameListA
#define kw_SetRealReg kw_SetRealRegA
#define kw_SetInfoData kw_SetInfoDataA
#define kw_KOA_Functions kw_KOA_FunctionsA
#define kw_SendOrderCredit kw_SendOrderCreditA
#define kw_GetSOptionCodeByActPrice kw_GetSOptionCodeByActPriceA
#define kw_GetSOptionCodeByMonth kw_GetSOptionCodeByMonthA
#define kw_GetSMonthList kw_GetSMonthListA
#define kw_GetSActPriceList kw_GetSActPriceListA
#define kw_GetSFutureCodeByIndex kw_GetSFutureCodeByIndexA
#define kw_GetSFutureList kw_GetSFutureListA
#define kw_GetOptionCodeByActPrice kw_GetOptionCodeByActPriceA
#define kw_GetOptionCodeByMonth kw_GetOptionCodeByMonthA
#define kw_GetOptionCode kw_GetOptionCodeA
#define kw_CommKwRqData kw_CommKwRqDataA
#define kw_GetRepeatCnt kw_GetRepeatCntA
#define kw_DisconnectRealData kw_DisconnectRealDataA
#define kw_SetInputValue kw_SetInputValueA
#define kw_SendOrderFO kw_SendOrderFOA
#define kw_SendOrder kw_SendOrderA
#define kw_SetOnReceiveMsg kw_SetOnReceiveMsgA
#define kw_OnReceiveMsg kw_OnReceiveMsgA
#define kw_GetChejanData kw_GetChejanDataA
#define kw_OnReceiveRealData kw_OnReceiveRealDataA
#define kw_SetOnReceiveRealData kw_SetOnReceiveRealDataA
#define kw_GetCommRealData kw_GetCommRealDataA
#define kw_GetCommData kw_GetCommDataA
#define kw_GetOutputValue kw_GetOutputValueA
#define kw_GetDataCount kw_GetDataCountA
#define kw_GetMasterStockState kw_GetMasterStockStateA
#define kw_GetMasterLastPrice kw_GetMasterLastPriceA
#define kw_GetMasterListedStockDate kw_GetMasterListedStockDateA
#define kw_GetMasterConstruction kw_GetMasterConstructionA
#define kw_GetMasterListedStockCnt kw_GetMasterListedStockCntA
#define kw_GetMasterCodeName kw_GetMasterCodeNameA
#define kw_GetCodeListByMarket kw_GetCodeListByMarketA
#define kw_GetLoginInfo kw_GetLoginInfoA
#define kw_OnReceiveTrData kw_OnReceiveTrDataA
#define kw_SetOnReceiveTrData kw_SetOnReceiveTrDataA
#define kw_CommRqData kw_CommRqDataA
#define kw_GetBranchCodeName kw_GetBranchCodeNameA
#define kw_GetSOptionATM kw_GetSOptionATMA
#define kw_GetOptionATM kw_GetOptionATMA
#define kw_GetSFOBasisAssetList kw_GetSFOBasisAssetListA
#define kw_GetAPIModulePath kw_GetAPIModulePathA
#define kw_GetFutureList kw_GetFutureListA
#define kw_FreeString kw_FreeStringA
#define kw_GetActPriceList kw_GetActPriceListA
#define kw_GetMonthList kw_GetMonthListA
#define kw_GetFutureCodeByIndex kw_GetFutureCodeByIndexA
#define kw_GetThemeGroupList kw_GetThemeGroupListA
#define kw_GetThemeGroupCode kw_GetThemeGroupCodeA
#define kw_SetOnReceiveTrCondition kw_SetOnReceiveTrConditionA
#define kw_OnReceiveTrCondition kw_OnReceiveTrConditionA
#endif

#ifdef __cplusplus
}
#endif // __cplusplus


#endif // KIWOOM_API_C_WRAPPER_H_
