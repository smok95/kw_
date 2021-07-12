# kw_ : C Wrapper for 키움증권 OpenAPI+ 

kw_는 키움증권API를 조금 더 쉽게 사용할 수 있도록 만든 라이브러리로
COM(ActiveX) 지식이나 MFC연동이 필요하지 않습니다.



## 필수환경
키움api를 사용하려면 키움 open API+(https://www.kiwoom.com/h/customer/download/VOpenApiInfoView) 서비스 사용신청 및 API모듈을 설치하셔야 합니다.

또한 모의투자의 경우에는 별도 신청(https://www.kiwoom.com/h/mock/ordinary/VMockTotalMHOMEView) 을 하셔야 합니다.
(* 모의투자기간이 제한되어 있어 투자기간이 종료되면 다시 신청하셔야 합니다.)


## 키움API 개발가이드 문서
https://download.kiwoom.com/web/openapi/kiwoom_openapi_plus_devguide_ver_1.5.pdf

## 예제
```c#include <stdio.h>

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
  }
}

int main()
{
  // 이벤트 핸들러 설정
  kw_SetOnEventConnect(OnEventConnect);

  // 로그인
  kw_CommConnect();

  while (TRUE) {
    kw_Wait();
  }
    
  return 0;
}
```

## 사용방법
- 키움API 함수명 앞에 모두 `kw_`를 붙여서 호출
- 리턴값이 문자열인 경우 `kw_Free` 또는 `kw_FreeString`로 메모리해제 
- 이벤트는 `kw_Set이벤트명`을 사용하여 이벤트 핸들러 지정

