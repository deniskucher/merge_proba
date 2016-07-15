
#include <unistd.h>
#include <cdsface.h>
#include <cdshead.h>

#include "globals.h"
#include "SigChange.h"
#include "typeBPO.h"
  char *pRN17D01SA1;
  char *pRN17D01SA2;
  char *pRN21S05SA1;
  char *pRN21S05SA2;
  char *pRN21S06SA1;
  char *pRN21S06SA2;
  char *pRN17D01NN;
  char *pRN17D01SGMN;
  char *pRN17D01SGP;
  char *pRN17D01SYMN;
  char *pRN17D01SYP;
  char *pRN21S05NN;
  char *pRN21S05SG;
  char *pRN21S05SO;
  char *pRN21S05SY;
  char *pRN21S05SZ;
  char *pRN21S06NN;
  char *pRN21S06SG;
  char *pRN21S06SO;
  char *pRN21S06SY;
  char *pRN21S06SZ;
  char *pRN21S05SGM;
  char *pRN21S05SGR;
  char *pRN21S05SYM;
  char *pRN21S05SYR;
  char *pRN21S06SGM;
  char *pRN21S06SGR;
  char *pRN21S06SYM;
  char *pRN21S06SYR;

  void Init_P()
 {
	////// сигналы AI 
	////// сигналы AO 
	////// сигналы PFA 
	////// сигналы KO 
	////// сигналы MRI 
	////// сигналы MRO 
	////// сигналы DI 
  GET_REF(pRN17D01SA1,char,DEF_DI_BY_ID,0);
  GET_REF(pRN17D01SA2,char,DEF_DI_BY_ID,1);
  GET_REF(pRN21S05SA1,char,DEF_DI_BY_ID,2);
  GET_REF(pRN21S05SA2,char,DEF_DI_BY_ID,3);
  GET_REF(pRN21S06SA1,char,DEF_DI_BY_ID,4);
  GET_REF(pRN21S06SA2,char,DEF_DI_BY_ID,5);
	////// сигналы DO 
  GET_REF(pRN17D01NN,char,DEF_DO_BY_ID,0);
  GET_REF(pRN17D01SGMN,char,DEF_DO_BY_ID,1);
  GET_REF(pRN17D01SGP,char,DEF_DO_BY_ID,2);
  GET_REF(pRN17D01SYMN,char,DEF_DO_BY_ID,3);
  GET_REF(pRN17D01SYP,char,DEF_DO_BY_ID,4);
  GET_REF(pRN21S05NN,char,DEF_DO_BY_ID,5);
  GET_REF(pRN21S05SG,char,DEF_DO_BY_ID,6);
  GET_REF(pRN21S05SO,char,DEF_DO_BY_ID,7);
  GET_REF(pRN21S05SY,char,DEF_DO_BY_ID,8);
  GET_REF(pRN21S05SZ,char,DEF_DO_BY_ID,9);
  GET_REF(pRN21S06NN,char,DEF_DO_BY_ID,10);
  GET_REF(pRN21S06SG,char,DEF_DO_BY_ID,11);
  GET_REF(pRN21S06SO,char,DEF_DO_BY_ID,12);
  GET_REF(pRN21S06SY,char,DEF_DO_BY_ID,13);
  GET_REF(pRN21S06SZ,char,DEF_DO_BY_ID,14);
	////// сигналы PFD 
  GET_REF(pRN21S05SGM,char,DEF_PFD_BY_ID,0);
  GET_REF(pRN21S05SGR,char,DEF_PFD_BY_ID,1);
  GET_REF(pRN21S05SYM,char,DEF_PFD_BY_ID,2);
  GET_REF(pRN21S05SYR,char,DEF_PFD_BY_ID,3);
  GET_REF(pRN21S06SGM,char,DEF_PFD_BY_ID,4);
  GET_REF(pRN21S06SGR,char,DEF_PFD_BY_ID,5);
  GET_REF(pRN21S06SYM,char,DEF_PFD_BY_ID,6);
  GET_REF(pRN21S06SYR,char,DEF_PFD_BY_ID,7);
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
  _RN17D01SA1=(bool)*pRN17D01SA1;
  _RN17D01SA2=(bool)*pRN17D01SA2;
  _RN21S05SA1=(bool)*pRN21S05SA1;
  _RN21S05SA2=(bool)*pRN21S05SA2;
  _RN21S06SA1=(bool)*pRN21S06SA1;
  _RN21S06SA2=(bool)*pRN21S06SA2;
	////// сигналы DO 
  _RN17D01NN=(bool)*pRN17D01NN;
  _RN17D01SGMN=(bool)*pRN17D01SGMN;
  _RN17D01SGP=(bool)*pRN17D01SGP;
  _RN17D01SYMN=(bool)*pRN17D01SYMN;
  _RN17D01SYP=(bool)*pRN17D01SYP;
  _RN21S05NN=(bool)*pRN21S05NN;
  _RN21S05SG=(bool)*pRN21S05SG;
  _RN21S05SO=(bool)*pRN21S05SO;
  _RN21S05SY=(bool)*pRN21S05SY;
  _RN21S05SZ=(bool)*pRN21S05SZ;
  _RN21S06NN=(bool)*pRN21S06NN;
  _RN21S06SG=(bool)*pRN21S06SG;
  _RN21S06SO=(bool)*pRN21S06SO;
  _RN21S06SY=(bool)*pRN21S06SY;
  _RN21S06SZ=(bool)*pRN21S06SZ;
	////// сигналы PFD 
  _RN21S05SGM=(bool)*pRN21S05SGM;
  _RN21S05SGR=(bool)*pRN21S05SGR;
  _RN21S05SYM=(bool)*pRN21S05SYM;
  _RN21S05SYR=(bool)*pRN21S05SYR;
  _RN21S06SGM=(bool)*pRN21S06SGM;
  _RN21S06SGR=(bool)*pRN21S06SGR;
  _RN21S06SYM=(bool)*pRN21S06SYM;
  _RN21S06SYR=(bool)*pRN21S06SYR;
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
  *pRN17D01SA1=(char)_RN17D01SA1;
  *pRN17D01SA2=(char)_RN17D01SA2;
  *pRN21S05SA1=(char)_RN21S05SA1;
  *pRN21S05SA2=(char)_RN21S05SA2;
  *pRN21S06SA1=(char)_RN21S06SA1;
  *pRN21S06SA2=(char)_RN21S06SA2;
	////// сигналы DO 
  *pRN17D01NN=(char)_RN17D01NN;
  *pRN17D01SGMN=(char)_RN17D01SGMN;
  *pRN17D01SGP=(char)_RN17D01SGP;
  *pRN17D01SYMN=(char)_RN17D01SYMN;
  *pRN17D01SYP=(char)_RN17D01SYP;
  *pRN21S05NN=(char)_RN21S05NN;
  *pRN21S05SG=(char)_RN21S05SG;
  *pRN21S05SO=(char)_RN21S05SO;
  *pRN21S05SY=(char)_RN21S05SY;
  *pRN21S05SZ=(char)_RN21S05SZ;
  *pRN21S06NN=(char)_RN21S06NN;
  *pRN21S06SG=(char)_RN21S06SG;
  *pRN21S06SO=(char)_RN21S06SO;
  *pRN21S06SY=(char)_RN21S06SY;
  *pRN21S06SZ=(char)_RN21S06SZ;
	////// сигналы PFD 
  *pRN21S05SGM=(char)_RN21S05SGM;
  *pRN21S05SGR=(char)_RN21S05SGR;
  *pRN21S05SYM=(char)_RN21S05SYM;
  *pRN21S05SYR=(char)_RN21S05SYR;
  *pRN21S06SGM=(char)_RN21S06SGM;
  *pRN21S06SGR=(char)_RN21S06SGR;
  *pRN21S06SYM=(char)_RN21S06SYM;
  *pRN21S06SYR=(char)_RN21S06SYR;
	////// сигналы KL 
	////// сигналы PIN 
  };
