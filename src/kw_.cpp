#include "kw_.h"

#include "kwapi.h"

#define B2W(bstr) _wcsdup(bstr)
#define B2A(bstr) _com_util::ConvertBSTRToString(bstr)
///////////////////////////////////////////////////////////////////////////////

kwapi api_;

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		return api_.create() ? TRUE : FALSE;
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

void kw_SetOnEventConnect(kw_OnEventConnect handler) {
	api_.setOnEventConnectHandler(handler);
}

void kw_SetOnReceiveTrDataW(kw_OnReceiveTrDataW handler) {
	api_.setOnReceiveTrDataHandlerW(handler);
}

void kw_SetOnReceiveTrDataA(kw_OnReceiveTrDataA handler) {
	api_.setOnReceiveTrDataHandlerA(handler);
}

void kw_SetOnReceiveRealDataW(kw_OnReceiveRealDataW handler) {
	api_.SetOnReceiveRealDataW(handler);
}

void kw_SetOnReceiveRealDataA(kw_OnReceiveRealDataA handler) {
	api_.SetOnReceiveRealDataA(handler);
}

void kw_SetOnReceiveMsgW(kw_OnReceiveMsgW handler) {
	api_.SetOnReceiveMsgW(handler);
}

void kw_SetOnReceiveMsgA(kw_OnReceiveMsgA handler) {
	api_.SetOnReceiveMsgA(handler);
}

void kw_SetOnReceiveChejanDataW(kw_OnReceiveChejanDataW handler) {
	api_.SetOnReceiveChejanDataW(handler);
}

void kw_SetOnReceiveChejanDataA(kw_OnReceiveChejanDataA handler) {
	api_.SetOnReceiveChejanDataA(handler);
}

void kw_SetOnReceiveRealConditionW(kw_OnReceiveRealConditionW handler) {
	api_.SetOnReceiveRealConditionW(handler);
}

void kw_SetOnReceiveRealConditionA(kw_OnReceiveRealConditionA handler) {
	api_.SetOnReceiveRealConditionA(handler);
}

void kw_SetOnReceiveTrConditionW(kw_OnReceiveTrConditionW handler) {
	api_.SetOnReceiveTrConditionW(handler);
}

void kw_SetOnReceiveTrConditionA(kw_OnReceiveTrConditionA handler) {
	api_.SetOnReceiveTrConditionA(handler);
}

void kw_SetOnReceiveConditionVerW(kw_OnReceiveConditionVerW handler) {
	api_.SetOnReceiveConditionVerW(handler);
}

void kw_SetOnReceiveConditionVerA(kw_OnReceiveConditionVerA handler) {
	api_.SetOnReceiveConditionVerA(handler);
}


void kw_Free(void* p) {
	p ? free(p) : void(0);
}

void kw_FreeStringW(PWSTR p) {
	kw_Free(p);
}

void kw_FreeStringA(PSTR p) {
	kw_Free(p);
}

long kw_CommConnect() {
	return api_.commConnect();
}

long kw_GetConnectState() {
	return api_.GetConnectState();
}

PWSTR kw_GetMasterCodeNameW(PCWSTR sTrCode) {
	return B2W(api_.GetMasterCodeName(sTrCode));
}

PSTR kw_GetMasterCodeNameA(PCSTR sTrCode) {
	return B2A(api_.GetMasterCodeName(sTrCode));
}

long kw_GetMasterListedStockCntW(PCWSTR sTrCode) {
	return api_.GetMasterListedStockCnt(sTrCode);
}

long kw_GetMasterListedStockCntA(PCSTR sTrCode) {
	return api_.GetMasterListedStockCnt(sTrCode);
}

PWSTR kw_GetMasterConstructionW(PCWSTR sTrCode) {
	return B2W(api_.GetMasterConstruction(sTrCode));
}

PSTR kw_GetMasterConstructionA(PCSTR sTrCode) {
	return B2A(api_.GetMasterConstruction(sTrCode));
}

PWSTR kw_GetMasterListedStockDateW(PCWSTR sTrCode) {
	return B2W(api_.GetMasterListedStockDate(sTrCode));
}

PSTR kw_GetMasterListedStockDateA(PCSTR sTrCode) {
	return B2A(api_.GetMasterListedStockDate(sTrCode));
}

PWSTR kw_GetMasterLastPriceW(PCWSTR sTrCode) {
	return B2W(api_.GetMasterLastPrice(sTrCode));
}

PSTR kw_GetMasterLastPriceA(PCSTR sTrCode) {
	return B2A(api_.GetMasterLastPrice(sTrCode));
}

PWSTR kw_GetMasterStockStateW(PCWSTR sTrCode) {
	return B2W(api_.GetMasterStockState(sTrCode));
}

PSTR kw_GetMasterStockStateA(PCSTR sTrCode) {
	return B2A(api_.GetMasterStockState(sTrCode));
}

long kw_GetDataCountW(PCWSTR strRecordName) {
	return api_.GetDataCount(strRecordName);
}
long kw_GetDataCountA(PCSTR strRecordName) {
	return api_.GetDataCount(strRecordName);
}

PWSTR kw_GetOutputValueW(PCWSTR strRecordName, long nRepeatIdx,
	long nItemIdx) {
	return B2W(api_.GetOutputValue(strRecordName, nRepeatIdx, nItemIdx));
}

PSTR kw_GetOutputValueA(PCSTR strRecordName, long nRepeatIdx,
	long nItemIdx) {
	return B2A(api_.GetOutputValue(strRecordName, nRepeatIdx, nItemIdx));
}

PWSTR kw_GetCommDataW(PCWSTR strTrCode, PCWSTR strRecordName,
	long nIndex, PCWSTR strItemName) {
	return B2W(api_.GetCommData(strTrCode, strRecordName, nIndex, strItemName));
}

PSTR kw_GetCommDataA(PCSTR strTrCode, PCSTR strRecordName,
	long nIndex, PCSTR strItemName) {
	return B2A(api_.GetCommData(strTrCode, strRecordName, nIndex, strItemName));
}

PWSTR kw_GetCommRealDataW(PCWSTR sTrCode, long nFid) {
	return B2W(api_.GetCommRealData(sTrCode, nFid));
}

PSTR kw_GetCommRealDataA(PCSTR sTrCode, long nFid) {
	return B2A(api_.GetCommRealData(sTrCode, nFid));
}

PWSTR kw_GetChejanDataW(long nFid) {
	return B2W(api_.GetChejanData(nFid));
}

PSTR kw_GetChejanDataA(long nFid) {
	return B2A(api_.GetChejanData(nFid));
}


PWSTR kw_GetAPIModulePathW() {
	return B2W(api_.GetAPIModulePath());
}

PSTR kw_GetAPIModulePathA() {
	return B2A(api_.GetAPIModulePath());
}

PWSTR kw_GetCodeListByMarketW(PCWSTR sMarket) {
	return B2W(api_.GetCodeListByMarket(sMarket));
}

PSTR kw_GetCodeListByMarketA(PCSTR sMarket) {
	return B2A(api_.GetCodeListByMarket(sMarket));
}


PWSTR kw_GetFutureListW() {
	return B2W(api_.GetFutureList());
}
PSTR kw_GetFutureListA() {
	return B2A(api_.GetFutureList());
}

PWSTR kw_GetActPriceListW() {
	return B2W(api_.GetActPriceList());
}

PSTR kw_GetActPriceListA() {
	return B2A(api_.GetActPriceList());
}

PWSTR kw_GetMonthListW() {
	return B2W(api_.GetMonthList());
}

PSTR kw_GetMonthListA() {
	return B2A(api_.GetMonthList());
}

PWSTR kw_GetOptionCodeW(PCWSTR strActPrice, int nCp,
	PCWSTR strMonth) {
	return B2W(api_.GetOptionCode(strActPrice, nCp, strMonth));
}

PSTR kw_GetOptionCodeA(PCSTR strActPrice, int nCp, PCSTR strMonth) {
	return B2A(api_.GetOptionCode(strActPrice, nCp, strMonth));
}

PWSTR kw_GetOptionCodeByMonthW(PCWSTR sTrCode, int nCp,
	PCWSTR strMonth) {
	return B2W(api_.GetOptionCodeByMonth(sTrCode, nCp, strMonth));
}

PSTR kw_GetOptionCodeByMonthA(PCSTR sTrCode, int nCp,
	PCSTR strMonth) {
	return B2A(api_.GetOptionCodeByMonth(sTrCode, nCp, strMonth));
}

PWSTR kw_GetOptionCodeByActPriceW(PCWSTR sTrCode, int nCp,
	int nTick) {
	return B2W(api_.GetOptionCodeByActPrice(sTrCode, nCp, nTick));
}

PSTR kw_GetOptionCodeByActPriceA(PCSTR sTrCode, int nCp, int nTick) {
	return B2A(api_.GetOptionCodeByActPrice(sTrCode, nCp, nTick));
}

PWSTR kw_GetSFutureListW(PCWSTR strBaseAssetCode) {
	return B2W(api_.GetSFutureList(strBaseAssetCode));
}

PSTR kw_GetSFutureListA(PCSTR strBaseAssetCode) {
	return B2A(api_.GetSFutureList(strBaseAssetCode));
}

PWSTR kw_GetSFutureCodeByIndexW(PCWSTR strBaseAssetCode, 
	int nIndex) {
	return B2W(api_.GetSFutureCodeByIndex(strBaseAssetCode, nIndex));
}
PSTR kw_GetSFutureCodeByIndexA(PCSTR strBaseAssetCode, int nIndex) {
	return B2A(api_.GetSFutureCodeByIndex(strBaseAssetCode, nIndex));
}

PWSTR kw_GetSActPriceListW(PCWSTR strBaseAssetGb) {
	return B2W(api_.GetSActPriceList(strBaseAssetGb));
}

PSTR kw_GetSActPriceListA(PCSTR strBaseAssetGb) {
	return B2A(api_.GetSActPriceList(strBaseAssetGb));
}

PWSTR kw_GetSMonthListW(PCWSTR strBaseAssetGb) {
	return B2W(api_.GetSMonthList(strBaseAssetGb));
}

PSTR kw_GetSMonthListA(PCSTR strBaseAssetGb) {
	return B2A(api_.GetSMonthList(strBaseAssetGb));
}

PWSTR kw_GetSOptionCodeW(PCWSTR strBaseAssetGb, PCWSTR strActPrice, int nCp,
	PCWSTR strMonth) {
	return B2W(api_.GetSOptionCode(strBaseAssetGb, strActPrice, nCp, strMonth));
}

PSTR kw_GetSOptionCodeA(PCSTR strBaseAssetGb, PCSTR strActPrice, int nCp,
	PCSTR strMonth) {
	return B2A(api_.GetSOptionCode(strBaseAssetGb, strActPrice, nCp, strMonth));
}

PWSTR kw_GetSOptionCodeByMonthW(PCWSTR strBaseAssetGb, PCWSTR sTrCode, int nCp, 
	PCWSTR strMonth) {
	return B2W(api_.GetSOptionCodeByMonth(strBaseAssetGb, sTrCode, nCp, strMonth));
}
PSTR kw_GetSOptionCodeByMonthA(PCSTR strBaseAssetGb, PCSTR sTrCode, int nCp,
	PCSTR strMonth) {
	return B2A(api_.GetSOptionCodeByMonth(strBaseAssetGb, sTrCode, nCp, strMonth));
}

PWSTR kw_GetSOptionCodeByActPriceW(PCWSTR strBaseAssetGb, PCWSTR sTrCode,
	int nCp, int nTick) {
	return B2W(api_.GetSOptionCodeByActPrice(strBaseAssetGb, sTrCode, nCp, 
		nTick));
}

PSTR kw_GetSOptionCodeByActPriceA(PCSTR strBaseAssetGb, PCSTR sTrCode, int nCp,
	int nTick) {
	return B2A(api_.GetSOptionCodeByActPrice(strBaseAssetGb, sTrCode, nCp,
		nTick));
}

PWSTR kw_GetFutureCodeByIndexW(int nIndex) {
	return B2W(api_.GetFutureCodeByIndex(nIndex));
}
PSTR kw_GetFutureCodeByIndexA(int nIndex) {
	return B2A(api_.GetFutureCodeByIndex(nIndex));
}

PWSTR kw_GetThemeGroupListW(long nType) {
	return B2W(api_.GetThemeGroupList(nType));
}

PSTR kw_GetThemeGroupListA(long nType) {
	return B2A(api_.GetThemeGroupList(nType));
}

PWSTR kw_GetThemeGroupCodeW(PCWSTR strThemeCode) {
	return B2W(api_.GetThemeGroupCode(strThemeCode));
}

PSTR kw_GetThemeGroupCodeA(PCSTR strThemeCode) {
	return B2A(api_.GetThemeGroupCode(strThemeCode));
}

PWSTR kw_GetSFOBasisAssetListW() {
	return B2W(api_.GetSFOBasisAssetList());
}

PSTR kw_GetSFOBasisAssetListA() {
	return B2A(api_.GetSFOBasisAssetList());
}

PWSTR kw_GetOptionATMW() {
	return B2W(api_.GetOptionATM());
}
PSTR kw_GetOptionATMA() {
	return B2A(api_.GetOptionATM());
}

PWSTR kw_GetSOptionATMW(PCWSTR strBaseAssetGb) {
	return B2W(api_.GetSOptionATM(strBaseAssetGb));
}

PSTR kw_GetSOptionATMA(PCSTR strBaseAssetGb) {
	return B2A(api_.GetSOptionATM(strBaseAssetGb));
}

PWSTR kw_GetBranchCodeNameW() {
	return B2W(api_.GetBranchCodeName());
}

PSTR kw_GetBranchCodeNameA() {
	return B2A(api_.GetBranchCodeName());
}

long kw_SendOrderCreditW(PCWSTR sRQName, PCWSTR sScreenNo, PCWSTR sAccNo,
	long nOrderType, PCWSTR sCode, long nQty, long nPrice, PCWSTR sHogaGb,
	PCWSTR sCreditGb, PCWSTR sLoanDate, PCWSTR sOrgOrderNo) {
	return api_.SendOrderCredit(sRQName, sScreenNo, sAccNo, nOrderType, sCode, 
		nQty, nPrice, sHogaGb, sCreditGb, sLoanDate, sOrgOrderNo);
}

long kw_SendOrderCreditA(PCSTR sRQName, PCSTR sScreenNo, PCSTR sAccNo,
	long nOrderType, PCSTR sCode, long nQty, long nPrice, PCSTR sHogaGb,
	PCSTR sCreditGb, PCSTR sLoanDate, PCSTR sOrgOrderNo) {
	return api_.SendOrderCredit(sRQName, sScreenNo, sAccNo, nOrderType, sCode,
		nQty, nPrice, sHogaGb, sCreditGb, sLoanDate, sOrgOrderNo);
}

PWSTR kw_KOA_FunctionsW(PCWSTR sFunctionName, PCWSTR sParam) {
	return B2W(api_.KOA_Functions(sFunctionName, sParam));
}

PSTR kw_KOA_FunctionsA(PCSTR sFunctionName, PCSTR sParam) {
	return B2A(api_.KOA_Functions(sFunctionName, sParam));
}

long kw_SetInfoDataW(PCWSTR sInfoData) {
	return api_.SetInfoData(sInfoData);
}

long kw_SetInfoDataA(PCSTR sInfoData) {
	return api_.SetInfoData(sInfoData);
}

long kw_SetRealRegW(PCWSTR strScreenNo, PCWSTR strCodeList, PCWSTR strFidList,
	PCWSTR strOptType) {
	return api_.SetRealReg(strScreenNo, strCodeList, strFidList, strOptType);
}

long kw_SetRealRegA(PCSTR strScreenNo, PCSTR strCodeList, PCSTR strFidList,
	PCSTR strOptType) {
	return api_.SetRealReg(strScreenNo, strCodeList, strFidList, strOptType);
}

long kw_GetConditionLoad() {
	return api_.GetConditionLoad();
}

PWSTR kw_GetConditionNameListW() {
	return B2W(api_.GetConditionNameList());
}

PSTR kw_GetConditionNameListA() {
	return B2A(api_.GetConditionNameList());
}

long kw_SendConditionW(PCWSTR strScrNo, PCWSTR strConditionName, int nIndex,
	int nSearch) {
	return api_.SendCondition(strScrNo, strConditionName, nIndex, nSearch);
}

long kw_SendConditionA(PCSTR strScrNo, PCSTR strConditionName, int nIndex,
	int nSearch) {
	return api_.SendCondition(strScrNo, strConditionName, nIndex, nSearch);
}

void kw_SendConditionStopW(PCWSTR strScrNo, PCWSTR strConditionName,
	int nIndex) {
	return api_.SendConditionStop(strScrNo, strConditionName, nIndex);
}

void kw_SendConditionStopA(PCSTR strScrNo, PCSTR strConditionName, int nIndex) {
	return api_.SendConditionStop(strScrNo, strConditionName, nIndex);
}

VARIANT	kw_GetCommDataExW(PCWSTR strTrCode, PCWSTR strRecordName) {
	return api_.GetCommDataEx(strTrCode, strRecordName);
}
VARIANT	kw_GetCommDataExA(PCSTR strTrCode, PCSTR strRecordName) {
	return api_.GetCommDataEx(strTrCode, strRecordName);
}

void kw_SetRealRemoveW(PCWSTR strScrNo, PCWSTR strDelCode) {
	api_.SetRealRemove(strScrNo, strDelCode);
}

void kw_SetRealRemoveA(PCSTR strScrNo, PCSTR strDelCode) {
	api_.SetRealRemove(strScrNo, strDelCode);
}

long kw_GetMarketTypeW(PCWSTR sTrCode) {
	return api_.GetMarketType(sTrCode);
}

long kw_GetMarketTypeA(PCSTR sTrCode) {
	return api_.GetMarketType(sTrCode);
}


long kw_CommRqDataW(PCWSTR sRQName, PCWSTR sTrCode,
	long nPrevNext, PCWSTR sScreenNo) {
	return api_.CommRqData(sRQName, sTrCode, nPrevNext, sScreenNo);
}

long kw_CommRqDataA(PCSTR sRQName, PCSTR sTrCode,
	long nPrevNext, PCSTR sScreenNo) {
	return api_.CommRqData(sRQName, sTrCode, nPrevNext, sScreenNo);
}

PWSTR kw_GetLoginInfoW(PCWSTR sTag) {
	return B2W(api_.GetLoginInfo(sTag));
}

PSTR kw_GetLoginInfoA(PCSTR sTag) {
	return B2A(api_.GetLoginInfo(sTag));
}

long kw_SendOrderW(PCWSTR sRQName, PCWSTR sScreenNo,
	PCWSTR sAccNo, long nOrderType, PCWSTR sCode, long nQty,
	long nPrice, PCWSTR sHogaGb, PCWSTR sOrgOrderNo) {
	return api_.SendOrder(sRQName, sScreenNo, sAccNo, nOrderType, sCode, nQty,
		nPrice, sHogaGb, sOrgOrderNo);
}

long kw_SendOrderA(PCSTR sRQName, PCSTR sScreenNo,
	PCSTR sAccNo, long nOrderType, PCSTR sCode, long nQty,
	long nPrice, PCSTR sHogaGb, PCSTR sOrgOrderNo) {
	return api_.SendOrder(sRQName, sScreenNo, sAccNo, nOrderType, sCode, nQty, 
		nPrice, sHogaGb, sOrgOrderNo);
}


long kw_SendOrderFOW(PCWSTR sRQName, PCWSTR sScreenNo,
	PCWSTR sAccNo, PCWSTR sCode, long lOrdKind,
	PCWSTR sSlbyTp, PCWSTR sOrdTp, long lQty,
	PCWSTR sPrice, PCWSTR sOrgOrdNo) {
	return api_.SendOrderFO(sRQName, sScreenNo, sAccNo, sCode, lOrdKind,
		sSlbyTp, sOrdTp, lQty, sPrice, sOrgOrdNo);
}

long kw_SendOrderFOA(PCWSTR sRQName, PCWSTR sScreenNo,
	PCWSTR sAccNo, PCWSTR sCode, long lOrdKind,
	PCWSTR sSlbyTp, PCWSTR sOrdTp, long lQty,
	PCWSTR sPrice, PCWSTR sOrgOrdNo) {
	return api_.SendOrderFO(sRQName, sScreenNo, sAccNo, sCode, lOrdKind, 
		sSlbyTp, sOrdTp, lQty, sPrice, sOrgOrdNo);
}

void kw_SetInputValueW(PCWSTR sID, PCWSTR sValue) {
	api_.SetInputValue(sID, sValue);
}

void kw_SetInputValueA(PCSTR sID, PCSTR sValue) {
	api_.SetInputValue(sID, sValue);
}

void kw_DisconnectRealDataW(PCWSTR sScnNo) {
	api_.DisconnectRealData(sScnNo);
}

void kw_DisconnectRealDataA(PCSTR sScnNo) {
	api_.DisconnectRealData(sScnNo);
}

long kw_GetRepeatCntW(PCWSTR sTrCode, PCWSTR sRecordName) {
	return api_.GetRepeatCnt(sTrCode, sRecordName);
}

long kw_GetRepeatCntA(PCSTR sTrCode, PCSTR sRecordName) {
	return api_.GetRepeatCnt(sTrCode, sRecordName);
}

long kw_CommKwRqDataW(PCWSTR sArrCode, long bNext, int nCodeCount,
	int nTypeFlag, PCWSTR sRQName, PCWSTR sScreenNo) {
	return api_.CommKwRqData(sArrCode, bNext, nCodeCount, nTypeFlag, sRQName,
		sScreenNo);
}

long kw_CommKwRqDataA(PCSTR sArrCode, long bNext, int nCodeCount,
	int nTypeFlag, PCSTR sRQName, PCSTR sScreenNo) {
	return api_.CommKwRqData(sArrCode, bNext, nCodeCount, nTypeFlag, sRQName, 
		sScreenNo);
}


void kw_Wait() {
	MSG msg;
	if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
