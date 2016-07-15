
#include <unistd.h>
#include <cdsface.h>
#include <cdshead.h>

#include "globals.h"
#include "SigChange.h"
#include "typeBPO.h"
  char *pPI21AJ03KNMC;
  char *pPI21AJ05KNMG;
  char *pPI21AC01DTS;
  char *pPI21AD03DTS;
  char *pPI21AE05DTS;
  char *pPI21AC01TS;
  char *pPI21AD03TS;
  char *pPI21AE05TS;

  void Init_P()
 {
	////// ������� AI 
	////// ������� AO 
	////// ������� PFA 
	////// ������� KO 
	////// ������� MRI 
	////// ������� MRO 
	////// ������� DI 
  GET_REF(pPI21AJ03KNMC,char,DEF_DI_BY_ID,0);
  GET_REF(pPI21AJ05KNMG,char,DEF_DI_BY_ID,1);
	////// ������� DO 
  GET_REF(pPI21AC01DTS,char,DEF_DO_BY_ID,0);
  GET_REF(pPI21AD03DTS,char,DEF_DO_BY_ID,1);
  GET_REF(pPI21AE05DTS,char,DEF_DO_BY_ID,2);
	////// ������� PFD 
  GET_REF(pPI21AC01TS,char,DEF_PFD_BY_ID,0);
  GET_REF(pPI21AD03TS,char,DEF_PFD_BY_ID,1);
  GET_REF(pPI21AE05TS,char,DEF_PFD_BY_ID,2);
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
  _PI21AJ03KNMC=(bool)*pPI21AJ03KNMC;
  _PI21AJ05KNMG=(bool)*pPI21AJ05KNMG;
	////// ������� DO 
  _PI21AC01DTS=(bool)*pPI21AC01DTS;
  _PI21AD03DTS=(bool)*pPI21AD03DTS;
  _PI21AE05DTS=(bool)*pPI21AE05DTS;
	////// ������� PFD 
  _PI21AC01TS=(bool)*pPI21AC01TS;
  _PI21AD03TS=(bool)*pPI21AD03TS;
  _PI21AE05TS=(bool)*pPI21AE05TS;
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
  *pPI21AJ03KNMC=(char)_PI21AJ03KNMC;
  *pPI21AJ05KNMG=(char)_PI21AJ05KNMG;
	////// ������� DO 
  *pPI21AC01DTS=(char)_PI21AC01DTS;
  *pPI21AD03DTS=(char)_PI21AD03DTS;
  *pPI21AE05DTS=(char)_PI21AE05DTS;
	////// ������� PFD 
  *pPI21AC01TS=(char)_PI21AC01TS;
  *pPI21AD03TS=(char)_PI21AD03TS;
  *pPI21AE05TS=(char)_PI21AE05TS;
	////// ������� KL 
	////// ������� PIN 
  };
