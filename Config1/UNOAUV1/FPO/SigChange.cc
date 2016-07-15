
#include <unistd.h>
#include <cdsface.h>
#include <cdshead.h>

#include "globals.h"
#include "SigChange.h"
#include "typeBPO.h"
  char *pPI12AG03KNMC;
  char *pPI12AG05KNMG;
  char *pAA11AA12;
  char *pPI12AB01DTS;
  char *pPI12AB05DTS;
  char *pPI12AB09DTS;
  char *pPI12AB01TS;
  char *pPI12AB05TS;
  char *pPI12AB09TS;

  void Init_P()
 {
	////// ������� AI 
	////// ������� AO 
	////// ������� PFA 
	////// ������� KO 
	////// ������� MRI 
	////// ������� MRO 
	////// ������� DI 
  GET_REF(pPI12AG03KNMC,char,DEF_DI_BY_ID,0);
  GET_REF(pPI12AG05KNMG,char,DEF_DI_BY_ID,1);
	////// ������� DO 
  GET_REF(pAA11AA12,char,DEF_DO_BY_ID,0);
  GET_REF(pPI12AB01DTS,char,DEF_DO_BY_ID,1);
  GET_REF(pPI12AB05DTS,char,DEF_DO_BY_ID,2);
  GET_REF(pPI12AB09DTS,char,DEF_DO_BY_ID,3);
	////// ������� PFD 
  GET_REF(pPI12AB01TS,char,DEF_PFD_BY_ID,0);
  GET_REF(pPI12AB05TS,char,DEF_PFD_BY_ID,1);
  GET_REF(pPI12AB09TS,char,DEF_PFD_BY_ID,2);
	////// ������� KL 
	////// ������� PIN 
  };

  void Read_Sig()
  {
	////// ������� AI 
	////// ������� AO 
	////// ������� PFA 
	////// ������� KO 
	////// ������� MRI 
	////// ������� MRO 
	////// ������� DI 
  _PI12AG03KNMC=(bool)*pPI12AG03KNMC;
  _PI12AG05KNMG=(bool)*pPI12AG05KNMG;
	////// ������� DO 
  _AA11AA12=(bool)*pAA11AA12;
  _PI12AB01DTS=(bool)*pPI12AB01DTS;
  _PI12AB05DTS=(bool)*pPI12AB05DTS;
  _PI12AB09DTS=(bool)*pPI12AB09DTS;
	////// ������� PFD 
  _PI12AB01TS=(bool)*pPI12AB01TS;
  _PI12AB05TS=(bool)*pPI12AB05TS;
  _PI12AB09TS=(bool)*pPI12AB09TS;
	////// ������� KL 
	////// ������� PIN 
  };
  void Write_Sig()
  {
	////// ������� AI 
	////// ������� AO 
	////// ������� PFA 
	////// ������� KO 
	////// ������� MRI 
	////// ������� MRO 
	////// ������� DI 
  *pPI12AG03KNMC=(char)_PI12AG03KNMC;
  *pPI12AG05KNMG=(char)_PI12AG05KNMG;
	////// ������� DO 
  *pAA11AA12=(char)_AA11AA12;
  *pPI12AB01DTS=(char)_PI12AB01DTS;
  *pPI12AB05DTS=(char)_PI12AB05DTS;
  *pPI12AB09DTS=(char)_PI12AB09DTS;
	////// ������� PFD 
  *pPI12AB01TS=(char)_PI12AB01TS;
  *pPI12AB05TS=(char)_PI12AB05TS;
  *pPI12AB09TS=(char)_PI12AB09TS;
	////// ������� KL 
	////// ������� PIN 
  };
