#pragma once
#include <oleidl.h>
#include <atlcomcli.h>

#include "kw_.h"


#ifndef OVERRIDE
#define OVERRIDE override
#endif // OVERRIDE

#define KWFAIL -9999	// 키움오류코드 범위에 들어가지 않은 값으로 임의지정했음.

// tlh, tli파일 만드는 방법
//#import "C:\OpenAPI\khopenapi.ocx" no_namespace named_guids
#include "khopenapi.tlh"

#define COMAPI STDMETHODIMP
#define OVERRIDE_NOTIMPL OVERRIDE { return E_NOTIMPL; }

class kwapi;

class kwevent :public _DKHOpenAPIEvents {
public:
	kwevent(kwapi& api) :api_(api) {};
	// IUnknown
	COMAPI QueryInterface(REFIID riid, void** ppvObject) OVERRIDE;
	STDMETHODIMP_(ULONG) AddRef(void) OVERRIDE { 
		return 1; 
	}
	STDMETHODIMP_(ULONG) Release(void) OVERRIDE { 
		return 1; 
	}

	// IDispatch
	COMAPI GetTypeInfoCount(UINT* pctinfo) OVERRIDE_NOTIMPL;
	COMAPI GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo) OVERRIDE_NOTIMPL;
	COMAPI GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames,
		LCID lcid, DISPID* rgDispId) OVERRIDE_NOTIMPL;
	COMAPI Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags,
		DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo,
		UINT* puArgErr) OVERRIDE;
	DWORD& cookie() { return cookie_; }
private:
	DWORD cookie_ = 0;
	kwapi& api_;
};

class kwapi :
	public IOleClientSite,	
	public IOleInPlaceSite,
	public IStorage
{
public:
	kwapi();
	virtual ~kwapi();

	bool create();
	void destroy();

	void setOnEventConnectHandler(kw_OnEventConnect handler) {
		onEventConnect_ = handler;
	}

	void setOnReceiveTrDataHandlerW(kw_OnReceiveTrDataW handler) {
		onReceiveTrDataW_ = handler;
	}

	void setOnReceiveTrDataHandlerA(kw_OnReceiveTrDataA handler) {
		onReceiveTrDataA_ = handler;
	}

	void SetOnReceiveRealDataW(kw_OnReceiveRealDataW handler) {
		onReceiveRealDataW_ = handler;
	}

	void SetOnReceiveRealDataA(kw_OnReceiveRealDataA handler) {
		onReceiveRealDataA_ = handler;
	}

	void SetOnReceiveMsgW(kw_OnReceiveMsgW handler) {
		onReceiveMsgW_ = handler;
	}

	void SetOnReceiveMsgA(kw_OnReceiveMsgA handler) {
		onReceiveMsgA_ = handler;
	}

	void SetOnReceiveChejanDataW(kw_OnReceiveChejanDataW handler) {
		onReceiveChejanDataW_ = handler;
	}

	void SetOnReceiveChejanDataA(kw_OnReceiveChejanDataA handler) {
		onReceiveChejanDataA_ = handler;
	}

	void SetOnReceiveRealConditionA(kw_OnReceiveRealConditionA handler) {
		onReceiveRealConditionA_ = handler;
	}

	void SetOnReceiveRealConditionW(kw_OnReceiveRealConditionW handler) {
		onReceiveRealConditionW_ = handler;
	}

	void SetOnReceiveTrConditionW(kw_OnReceiveTrConditionW handler) {
		onReceiveTrConditionW_ = handler;
	}

	void SetOnReceiveTrConditionA(kw_OnReceiveTrConditionA handler) {
		onReceiveTrConditionA_ = handler;
	}

	void SetOnReceiveConditionVerW(kw_OnReceiveConditionVerW handler) {
		onReceiveConditionVerW_ = handler;
	}

	void SetOnReceiveConditionVerA(kw_OnReceiveConditionVerA handler) {
		onReceiveConditionVerA_ = handler;
	}


	long commConnect();
	void Disconnect();
		
	inline long CommRqData(_bstr_t sRQName, _bstr_t sTrCode, long nPrevNext,
		_bstr_t sScreenNo) {
		return v ? v->CommRqData(sRQName, sTrCode, nPrevNext, sScreenNo) : KWFAIL;
	}
		
	inline _bstr_t GetLoginInfo(_bstr_t sTag) {
		return v ? v->GetLoginInfo(sTag) : _bstr_t();
	}
	
	inline long SendOrder(_bstr_t sRQName, _bstr_t sScreenNo, _bstr_t sAccNo,
		long nOrderType, _bstr_t sCode, long nQty, long nPrice,
		_bstr_t sHogaGb, _bstr_t sOrgOrderNo) {
		return v ? v->SendOrder(sRQName, sScreenNo, sAccNo, nOrderType, sCode,
			nQty, nPrice, sHogaGb, sOrgOrderNo) : KWFAIL;
	}

	inline long SendOrderFO(_bstr_t sRQName, _bstr_t sScreenNo,
		_bstr_t sAccNo, _bstr_t sCode, long lOrdKind, _bstr_t sSlbyTp,
		_bstr_t sOrdTp, long lQty, _bstr_t sPrice, _bstr_t sOrgOrdNo) {
		return v ? v->SendOrderFO(sRQName, sScreenNo, sAccNo, sCode, lOrdKind,
			sSlbyTp, sOrdTp, lQty, sPrice, sOrgOrdNo) : KWFAIL;
	}

	inline void SetInputValue(_bstr_t sID, _bstr_t sValue) {
		v ? v->SetInputValue(sID, sValue) : 0;
	}

	inline void DisconnectRealData(_bstr_t sScnNo) {
		v ? v->DisconnectRealData(sScnNo) : 0;
	}

	inline long GetRepeatCnt(_bstr_t sTrCode, _bstr_t sRecordName) {
		return v ? v->GetRepeatCnt(sTrCode, sRecordName) : 0;
	}

	inline long CommKwRqData(_bstr_t sArrCode, long bNext, int nCodeCount,
		int nTypeFlag, _bstr_t sRQName, _bstr_t sScreenNo) {
		return v ? v->CommKwRqData(sArrCode, bNext, nCodeCount, nTypeFlag, 
			sRQName, sScreenNo) : KWFAIL;
	}

	inline _bstr_t GetAPIModulePath() {
		return v ? v->GetAPIModulePath() : _bstr_t();
	}
	
	inline _bstr_t GetCodeListByMarket(_bstr_t sMarket) {
		return v ? v->GetCodeListByMarket(sMarket) : _bstr_t();
	}

	inline long GetConnectState() {
		return v ? v->GetConnectState() : 0;
	}
	
	inline _bstr_t GetMasterCodeName(_bstr_t sTrCode) {
		return v ? v->GetMasterCodeName(sTrCode) : _bstr_t();
	}
	
	inline long GetMasterListedStockCnt(_bstr_t sTrCode) {
		return v ? v->GetMasterListedStockCnt(sTrCode) : 0;
	}
	
	inline _bstr_t GetMasterConstruction(_bstr_t sTrCode) {
		return v ? v->GetMasterConstruction(sTrCode) : _bstr_t();
	}
	
	inline _bstr_t GetMasterListedStockDate(_bstr_t sTrCode) {
		return v ? v->GetMasterListedStockDate(sTrCode) : _bstr_t();
	}
	
	inline _bstr_t GetMasterLastPrice(_bstr_t sTrCode) {
		return v ? v->GetMasterLastPrice(sTrCode) : _bstr_t();
	}

	inline _bstr_t GetMasterStockState(_bstr_t sTrCode) {
		return v ? v->GetMasterStockState(sTrCode) : _bstr_t();
	}

	inline long GetDataCount(_bstr_t strRecordName) {
		return v ? v->GetDataCount(strRecordName) : 0;
	}

	inline _bstr_t GetOutputValue(_bstr_t strRecordName, long nRepeatIdx,
		long nItemIdx) {
		return v ? v->GetOutputValue(strRecordName, nRepeatIdx, nItemIdx) : 
			_bstr_t();
	}

	inline _bstr_t GetCommData(_bstr_t strTrCode, _bstr_t strRecordName,
		long nIndex, _bstr_t strItemName) {
		return v ? v->GetCommData(strTrCode, strRecordName, nIndex, 
			strItemName) : _bstr_t();
	}

	inline _bstr_t GetCommRealData(_bstr_t sTrCode, long nFid) {
		return v ? v->GetCommRealData(sTrCode, nFid) : _bstr_t();
	}
	
	inline _bstr_t GetChejanData(long nFid) {
		return v ? v->GetChejanData(nFid) : _bstr_t();
	}

	inline _bstr_t GetThemeGroupList(long nType) {
		return v ? v->GetThemeGroupList(nType) : _bstr_t();
	}
	
	inline _bstr_t GetThemeGroupCode(_bstr_t strThemeCode) {
		return v ? v->GetThemeGroupCode(strThemeCode) : _bstr_t();
	}
	
	inline _bstr_t GetFutureList() {
		return v ? v->GetFutureList() : _bstr_t();
	}
	
	inline _bstr_t GetFutureCodeByIndex(int nIndex) {
		return v ? v->GetFutureCodeByIndex(nIndex) : _bstr_t();
	}

	inline _bstr_t GetActPriceList() {
		return v ? v->GetActPriceList() : _bstr_t();
	}
	
	inline _bstr_t GetMonthList() {
		return v ? v->GetMonthList() : _bstr_t();
	}

	inline _bstr_t GetOptionCode(_bstr_t strActPrice, int nCp,
		_bstr_t strMonth) {
		return v ? v->GetOptionCode(strActPrice, nCp, strMonth) : _bstr_t();
	}

	inline _bstr_t GetOptionCodeByMonth(_bstr_t sTrCode, int nCp,
		_bstr_t strMonth) {
		return v ? v->GetOptionCodeByMonth(sTrCode, nCp, strMonth) : _bstr_t();
	}

	inline _bstr_t GetOptionCodeByActPrice(_bstr_t sTrCode, int nCp, 
		int nTick) {
		return v ? v->GetOptionCodeByActPrice(sTrCode, nCp, nTick) : _bstr_t();
	}

	inline _bstr_t GetSFutureList(_bstr_t strBaseAssetCode) {
		return v ? v->GetSFutureList(strBaseAssetCode) : _bstr_t();
	}
	
	inline _bstr_t GetSFutureCodeByIndex(_bstr_t strBaseAssetCode, int nIndex) {
		return v ? v->GetSFutureCodeByIndex(strBaseAssetCode, nIndex) : _bstr_t();
	}
	
	inline _bstr_t GetSActPriceList(_bstr_t strBaseAssetGb) {
		return v ? v->GetSActPriceList(strBaseAssetGb) : _bstr_t();
	}

	inline _bstr_t GetSMonthList(_bstr_t strBaseAssetGb) {
		return v ? v->GetSMonthList(strBaseAssetGb) : _bstr_t();
	}

	inline _bstr_t GetSOptionCode(_bstr_t strBaseAssetGb, _bstr_t strActPrice,
		int nCp, _bstr_t strMonth) {
		return v ? v->GetSOptionCode(strBaseAssetGb, strActPrice, nCp, 
			strMonth) : _bstr_t();
	}

	inline _bstr_t GetSOptionCodeByMonth(_bstr_t strBaseAssetGb,
		_bstr_t sTrCode, int nCp, _bstr_t strMonth) {
		return v ? v->GetSOptionCodeByMonth(strBaseAssetGb, sTrCode, nCp, 
			strMonth) : _bstr_t();
	}
	
	inline _bstr_t GetSOptionCodeByActPrice(_bstr_t strBaseAssetGb,
		_bstr_t sTrCode, int nCp, int nTick) {
		return v ? v->GetSOptionCodeByActPrice(strBaseAssetGb, sTrCode, nCp, 
			nTick) : _bstr_t();
	}

	inline _bstr_t GetSFOBasisAssetList() {
		return v ? v->GetSFOBasisAssetList() : _bstr_t();
	}
	
	inline _bstr_t GetOptionATM() {
		return v ? v->GetOptionATM() : _bstr_t();
	}
	
	inline _bstr_t GetSOptionATM(_bstr_t strBaseAssetGb) {
		return v ? v->GetSOptionATM(strBaseAssetGb) : _bstr_t();
	}
	
	inline _bstr_t GetBranchCodeName() {
		return v ? v->GetBranchCodeName() : _bstr_t();
	}

	inline long SendOrderCredit(_bstr_t sRQName, _bstr_t sScreenNo,
		_bstr_t sAccNo, long nOrderType, _bstr_t sCode, long nQty, long nPrice,
		_bstr_t sHogaGb, _bstr_t sCreditGb, _bstr_t sLoanDate,
		_bstr_t sOrgOrderNo) {
		return v ? v->SendOrderCredit(sRQName, sScreenNo, sAccNo, nOrderType, 
			sCode, nQty, nPrice, sHogaGb, sCreditGb, sLoanDate, sOrgOrderNo) 
			: KWFAIL;
	}

	inline _bstr_t KOA_Functions(_bstr_t sFunctionName, _bstr_t sParam) {
		return v ? v->KOA_Functions(sFunctionName, sParam) : _bstr_t();
	}

	inline long SetInfoData(_bstr_t sInfoData) {
		return v ? v->SetInfoData(sInfoData) : KWFAIL;
	}

	inline long SetRealReg(_bstr_t strScreenNo, _bstr_t strCodeList,
		_bstr_t strFidList, _bstr_t strOptType) {
		return v ? v->SetRealReg(strScreenNo, strCodeList, strFidList, 
			strOptType) : KWFAIL;
	}

	inline long GetConditionLoad() {
		return v ? v->GetConditionLoad() : KWFAIL;
	}

	inline _bstr_t GetConditionNameList() {
		return v ? v->GetConditionNameList() : _bstr_t();
	}
	
	inline long SendCondition(_bstr_t strScrNo, _bstr_t strConditionName,
		int nIndex, int nSearch) {
		return v ? v->SendCondition(strScrNo, strConditionName, nIndex, 
			nSearch) : KWFAIL;
	}

	inline void SendConditionStop(_bstr_t strScrNo, _bstr_t strConditionName,
		int nIndex) {
		v ? v->SendConditionStop(strScrNo, strConditionName, nIndex) : 0;
	}

	inline VARIANT GetCommDataEx(_bstr_t strTrCode, _bstr_t strRecordName) {
		_variant_t vtNull;
		return v ? v->GetCommDataEx(strTrCode, strRecordName) : vtNull;
	}

	inline void SetRealRemove(_bstr_t strScrNo, _bstr_t strDelCode) {
		v ? v->SetRealRemove(strScrNo, strDelCode) : 0;
	}
	
	inline long GetMarketType(_bstr_t sTrCode) {
		return v ? v->GetMarketType(sTrCode) : KWFAIL;
	}

	// IUnknown
	COMAPI QueryInterface(REFIID riid, void** ppvObject) OVERRIDE;
	STDMETHODIMP_(ULONG) AddRef(void) OVERRIDE;
	STDMETHODIMP_(ULONG) Release(void) OVERRIDE;

	// IOleClientSite
	COMAPI SaveObject(void) OVERRIDE_NOTIMPL;
	COMAPI GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, IMoniker** ppmk) OVERRIDE;
	COMAPI GetContainer(IOleContainer** ppContainer) OVERRIDE;
	COMAPI ShowObject(void) OVERRIDE;
	COMAPI OnShowWindow(BOOL fShow) OVERRIDE;
	COMAPI RequestNewObjectLayout(void) OVERRIDE_NOTIMPL;

	// IOleWindow
	COMAPI GetWindow(HWND* phwnd) OVERRIDE;
	COMAPI ContextSensitiveHelp(BOOL fEnterMode) OVERRIDE_NOTIMPL;

	// IOleInPlaceSite
	COMAPI CanInPlaceActivate(void) OVERRIDE;
	COMAPI OnInPlaceActivate(void) OVERRIDE_NOTIMPL;
	COMAPI OnUIActivate(void) OVERRIDE_NOTIMPL;
	COMAPI GetWindowContext(IOleInPlaceFrame** ppFrame,
		IOleInPlaceUIWindow** ppDoc, LPRECT lprcPosRect, LPRECT lprcClipRect,
		LPOLEINPLACEFRAMEINFO lpFrameInfo) OVERRIDE_NOTIMPL;
	COMAPI Scroll(SIZE scrollExtant) OVERRIDE_NOTIMPL;
	COMAPI OnUIDeactivate(BOOL fUndoable) OVERRIDE_NOTIMPL;
	COMAPI OnInPlaceDeactivate(void) OVERRIDE_NOTIMPL;
	COMAPI DiscardUndoState(void) OVERRIDE_NOTIMPL;
	COMAPI DeactivateAndUndo(void) OVERRIDE_NOTIMPL;
	COMAPI OnPosRectChange(LPCRECT lprcPosRect) OVERRIDE_NOTIMPL;
	
	// IStorage
	COMAPI CreateStream(const OLECHAR* pwcsName, DWORD grfMode,
		DWORD reserved1, DWORD reserved2, IStream** ppstm) OVERRIDE_NOTIMPL;
	COMAPI OpenStream(const OLECHAR* pwcsName, void* reserved1,
		DWORD grfMode, DWORD reserved2, IStream** ppstm) OVERRIDE_NOTIMPL;
	COMAPI CreateStorage(const OLECHAR* pwcsName, DWORD grfMode,
		DWORD reserved1, DWORD reserved2, IStorage** ppstg) OVERRIDE_NOTIMPL;
	COMAPI OpenStorage(const OLECHAR* pwcsName, IStorage* pstgPriority,
		DWORD grfMode, SNB snbExclude, DWORD reserved, IStorage** ppstg)
		OVERRIDE_NOTIMPL;
	COMAPI CopyTo(DWORD ciidExclude, const IID* rgiidExclude,
		SNB snbExclude, IStorage* pstgDest) OVERRIDE_NOTIMPL;
	COMAPI MoveElementTo(const OLECHAR* pwcsName, IStorage* pstgDest,
		const OLECHAR* pwcsNewName, DWORD grfFlags) OVERRIDE_NOTIMPL;
	COMAPI Commit(DWORD grfCommitFlags) OVERRIDE_NOTIMPL;
	COMAPI Revert(void) OVERRIDE_NOTIMPL;
	COMAPI EnumElements(DWORD reserved1, void* reserved2,
		DWORD reserved3, IEnumSTATSTG** ppenum) OVERRIDE_NOTIMPL;
	COMAPI DestroyElement(const OLECHAR* pwcsName) OVERRIDE_NOTIMPL;
	COMAPI RenameElement(const OLECHAR* pwcsOldName, const OLECHAR* pwcsNewName) 
		OVERRIDE_NOTIMPL;
	COMAPI SetElementTimes(const OLECHAR* pwcsName, const FILETIME* pctime, 
		const FILETIME* patime, const FILETIME* pmtime) OVERRIDE_NOTIMPL;
	COMAPI SetClass(REFCLSID clsid) OVERRIDE;
	COMAPI SetStateBits(DWORD grfStateBits, DWORD grfMask) OVERRIDE_NOTIMPL;
	COMAPI Stat(STATSTG* pstatstg, DWORD grfStatFlag) OVERRIDE_NOTIMPL;

	HRESULT onInvoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags,
		DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo,
		UINT* puArgErr);

	void SetUseUtf8(bool bUse) { useUtf8_ = bUse; }

	inline bool IsUseUtf8() { return useUtf8_; }

	inline char* bstrToString(BSTR bstr) {
		if (useUtf8_) {
			const UINT len = SysStringLen(bstr);
			if (len == 0) {
				return _strdup("");
			}
			const int sizeNeeded = WideCharToMultiByte(CP_UTF8, 0, bstr, len,
				nullptr, 0, nullptr, nullptr);
			char* utf8 = (char*)calloc(sizeNeeded, sizeNeeded);
			WideCharToMultiByte(CP_UTF8, 0, bstr, len, utf8, sizeNeeded, nullptr,
				nullptr);
			return utf8;
		}
		else {
			return _com_util::ConvertBSTRToString(bstr);
		}
	}

	void waitMessageLoop();
private:
	kwevent event_;
	ULONG refCount_ = 0;
	CComPtr<IOleObject> oleObj_;
	CComPtr<IConnectionPoint> connectPoint_;
	bool oleInitialized_ = false;
	bool useUtf8_ = false;
	_DKHOpenAPIPtr v;
	HWND hControlWnd_ = nullptr;

	kw_OnEventConnect onEventConnect_ = nullptr;

	kw_OnReceiveTrDataW onReceiveTrDataW_ = nullptr;
	kw_OnReceiveTrDataA onReceiveTrDataA_ = nullptr;

	kw_OnReceiveRealDataW onReceiveRealDataW_ = nullptr;
	kw_OnReceiveRealDataA onReceiveRealDataA_ = nullptr;

	kw_OnReceiveMsgW onReceiveMsgW_ = nullptr;
	kw_OnReceiveMsgA onReceiveMsgA_ = nullptr;

	kw_OnReceiveChejanDataA onReceiveChejanDataA_ = nullptr;
	kw_OnReceiveChejanDataW onReceiveChejanDataW_ = nullptr;

	kw_OnReceiveRealConditionW onReceiveRealConditionW_ = nullptr;
	kw_OnReceiveRealConditionA onReceiveRealConditionA_ = nullptr;

	kw_OnReceiveTrConditionW onReceiveTrConditionW_ = nullptr;
	kw_OnReceiveTrConditionA onReceiveTrConditionA_ = nullptr;

	kw_OnReceiveConditionVerW onReceiveConditionVerW_ = nullptr;
	kw_OnReceiveConditionVerA onReceiveConditionVerA_ = nullptr;
};

