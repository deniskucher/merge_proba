
#include <unistd.h>
#include <cdsface.h>
#include <cdshead.h>

#include "globals.h"
#include "SigChange.h"
#include "typeBPO.h"
  char *pRN17D02SA1;
  char *pRN17D02SA2;
  char *pRN17D03SA1;
  char *pRN17D03SA2;
  char *pRQ13S01SA1;
  char *pRQ13S01SA2;
  char *pRN17D02NN;
  char *pRN17D02SGMN;
  char *pRN17D02SGP;
  char *pRN17D02SYMN;
  char *pRN17D02SYP;
  char *pRN17D03NN;
  char *pRN17D03SGMN;
  char *pRN17D03SGP;
  char *pRN17D03SYMN;
  char *pRN17D03SYP;
  char *pRQ13S01NN;
  char *pRQ13S01SG;
  char *pRQ13S01SO;
  char *pRQ13S01SY;
  char *pRQ13S01SZ;
  char *pRQ13S01SGM;
  char *pRQ13S01SGR;
  char *pRQ13S01SYM;
  char *pRQ13S01SYR;

  void Init_P()
 {
	////// сигналы AI 
	////// сигналы AO 
	////// сигналы PFA 
	////// сигналы KO 
	////// сигналы MRI 
	////// сигналы MRO 
	////// сигналы DI 
  GET_REF(pRN17D02SA1,char,DEF_DI_BY_ID,0);
  GET_REF(pRN17D02SA2,char,DEF_DI_BY_ID,1);
  GET_REF(pRN17D03SA1,char,DEF_DI_BY_ID,2);
  GET_REF(pRN17D03SA2,char,DEF_DI_BY_ID,3);
  GET_REF(pRQ13S01SA1,char,DEF_DI_BY_ID,4);
  GET_REF(pRQ13S01SA2,char,DEF_DI_BY_ID,5);
	////// сигналы DO 
  GET_REF(pRN17D02NN,char,DEF_DO_BY_ID,0);
  GET_REF(pRN17D02SGMN,char,DEF_DO_BY_ID,1);
  GET_REF(pRN17D02SGP,char,DEF_DO_BY_ID,2);
  GET_REF(pRN17D02SYMN,char,DEF_DO_BY_ID,3);
  GET_REF(pRN17D02SYP,char,DEF_DO_BY_ID,4);
  GET_REF(pRN17D03NN,char,DEF_DO_BY_ID,5);
  GET_REF(pRN17D03SGMN,char,DEF_DO_BY_ID,6);
  GET_REF(pRN17D03SGP,char,DEF_DO_BY_ID,7);
  GET_REF(pRN17D03SYMN,char,DEF_DO_BY_ID,8);
  GET_REF(pRN17D03SYP,char,DEF_DO_BY_ID,9);
  GET_REF(pRQ13S01NN,char,DEF_DO_BY_ID,10);
  GET_REF(pRQ13S01SG,char,DEF_DO_BY_ID,11);
  GET_REF(pRQ13S01SO,char,DEF_DO_BY_ID,12);
  GET_REF(pRQ13S01SY,char,DEF_DO_BY_ID,13);
  GET_REF(pRQ13S01SZ,char,DEF_DO_BY_ID,14);
	////// сигналы PFD 
  GET_REF(pRQ13S01SGM,char,DEF_PFD_BY_ID,0);
  GET_REF(pRQ13S01SGR,char,DEF_PFD_BY_ID,1);
  GET_REF(pRQ13S01SYM,char,DEF_PFD_BY_ID,2);
  GET_REF(pRQ13S01SYR,char,DEF_PFD_BY_ID,3);
	////// сигналы KL 
	////// сигналы PIN 
  };

  void Read_Sig()
  {
	////// сигналы AI 
	////// сигналы AO 
	////// сигналы PFA 
	////// сигналы KO 
	////// сигналы MRI 
	////// сигналы MRO 
	////// сигналы DI 
  _RN17D02SA1=(bool)*pRN17D02SA1;
  _RN17D02SA2=(bool)*pRN17D02SA2;
  _RN17D03SA1=(bool)*pRN17D03SA1;
  _RN17D03SA2=(bool)*pRN17D03SA2;
  _RQ13S01SA1=(bool)*pRQ13S01SA1;
  _RQ13S01SA2=(bool)*pRQ13S01SA2;
	////// сигналы DO 
  _RN17D02NN=(bool)*pRN17D02NN;
  _RN17D02SGMN=(bool)*pRN17D02SGMN;
  _RN17D02SGP=(bool)*pRN17D02SGP;
  _RN17D02SYMN=(bool)*pRN17D02SYMN;
  _RN17D02SYP=(bool)*pRN17D02SYP;
  _RN17D03NN=(bool)*pRN17D03NN;
  _RN17D03SGMN=(bool)*pRN17D03SGMN;
  _RN17D03SGP=(bool)*pRN17D03SGP;
  _RN17D03SYMN=(bool)*pRN17D03SYMN;
  _RN17D03SYP=(bool)*pRN17D03SYP;
  _RQ13S01NN=(bool)*pRQ13S01NN;
  _RQ13S01SG=(bool)*pRQ13S01SG;
  _RQ13S01SO=(bool)*pRQ13S01SO;
  _RQ13S01SY=(bool)*pRQ13S01SY;
  _RQ13S01SZ=(bool)*pRQ13S01SZ;
	////// сигналы PFD 
  _RQ13S01SGM=(bool)*pRQ13S01SGM;
  _RQ13S01SGR=(bool)*pRQ13S01SGR;
  _RQ13S01SYM=(bool)*pRQ13S01SYM;
  _RQ13S01SYR=(bool)*pRQ13S01SYR;
	////// сигналы KL 
	////// сигналы PIN 
  };
  void Write_Sig()
  {
	////// сигналы AI 
	////// сигналы AO 
	////// сигналы PFA 
	////// сигналы KO 
	////// сигналы MRI 
	////// сигналы MRO 
	////// сигналы DI 
  *pRN17D02SA1=(char)_RN17D02SA1;
  *pRN17D02SA2=(char)_RN17D02SA2;
  *pRN17D03SA1=(char)_RN17D03SA1;
  *pRN17D03SA2=(char)_RN17D03SA2;
  *pRQ13S01SA1=(char)_RQ13S01SA1;
  *pRQ13S01SA2=(char)_RQ13S01SA2;
	////// сигналы DO 
  *pRN17D02NN=(char)_RN17D02NN;
  *pRN17D02SGMN=(char)_RN17D02SGMN;
  *pRN17D02SGP=(char)_RN17D02SGP;
  *pRN17D02SYMN=(char)_RN17D02SYMN;
  *pRN17D02SYP=(char)_RN17D02SYP;
  *pRN17D03NN=(char)_RN17D03NN;
  *pRN17D03SGMN=(char)_RN17D03SGMN;
  *pRN17D03SGP=(char)_RN17D03SGP;
  *pRN17D03SYMN=(char)_RN17D03SYMN;
  *pRN17D03SYP=(char)_RN17D03SYP;
  *pRQ13S01NN=(char)_RQ13S01NN;
  *pRQ13S01SG=(char)_RQ13S01SG;
  *pRQ13S01SO=(char)_RQ13S01SO;
  *pRQ13S01SY=(char)_RQ13S01SY;
  *pRQ13S01SZ=(char)_RQ13S01SZ;
	////// сигналы PFD 
  *pRQ13S01SGM=(char)_RQ13S01SGM;
  *pRQ13S01SGR=(char)_RQ13S01SGR;
  *pRQ13S01SYM=(char)_RQ13S01SYM;
  *pRQ13S01SYR=(char)_RQ13S01SYR;
	////// сигналы KL 
	////// сигналы PIN 
  };
