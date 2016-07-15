#ifndef KD_ClassesH
#define KD_ClassesH
#include "usertype.h"

extern short Delay_1m;

//__________________________________ TKD2 __________________________________

class _TKD2
{
public:
  smallint n4;  //Счетчик отказа по DEL
  bool PRKRZ;
  bool PROTKL;
  bool *pMask_ZRK;
  _TKD2(smallint _1n4);
  ~_TKD2();
  void _KD2(const smallint P1R, const smallint P2R, const bool OTKLKD,
  const bool KRZ, const smallint DEL, const bool NKD11,
  const bool NKD12, const bool SBRN, smallint &PTR, bool &PTF,
  smallint &ZZ);
//  void MaskFault();
};
//__________________________________ TKD3 __________________________________

class _TKD3
{
public:
  byte n1;  //Счетчик отказа по DEL 1 датч
  byte n2;  //Счетчик отказа по DEL 2 датч.
  byte n3;  //Счетчик отказа по DEL 3 датч.
  byte n4;  //Счетчик отказа по DEL оставшихся двух
  byte nk;
  bool PRKRZ;
  bool *pMask_ZRK;
   bool PROTKL;
  _TKD3(byte _1n1, byte _2n2, byte _3n3, byte _4n4, byte _5nk);
  ~_TKD3();
  void _KD3(const smallint P1R, const smallint P2R, const smallint P3R,
  const bool OTKLKD, const bool KRZ, const smallint DEL,
  const bool SBRN, const bool NKD11, const bool NKD12, const bool NKD13,
  smallint &PTR, bool &PTF, bool &NKD31, bool &NKD32, bool &NKD33,
  smallint &ZZ, bool KRS1, bool KRS2, bool KRS3);
  void MaskFault();
};
//__________________________________ TKD1 __________________________________

class _TKD1
{
public:
  smallint P_z[10];
  smallint nDV;  //Счетчик выдержки отказа датчика по DV
  smallint nMX;  //Счетчик выдержки отказа датчика по MX,MN
  smallint TCKD1;  //Счетчик тактов
  bool PRKRS;
  bool PRDV;
bool NKD;
bool NKN;
   bool PROTKL;
  bool  *pMask_ZMX,*pMask_ZMN,*pMask_ZDV; // ьрёъш эр яЁшўшэ√ юЄърчют 
  _TKD1(smallint _1_0, smallint _2_1, smallint _3_2, smallint _4_3, smallint _5_4, 
    smallint _6_5, smallint _7_6, smallint _8_7, smallint _9_8, smallint _10_9, smallint 
    _11nDV, smallint _12nMX, smallint _13TCKD1);
  ~_TKD1();
  void _KD1(const smallint P, const bool OTKLKD, const bool KRS,
  const bool NTSKN1, const bool NTSKN2, const smallint DV, const smallint MN,
  const smallint MX, const bool SBRN, smallint &PR,
  bool &NKD1, smallint &ZZR, bool &NKD1_1);
//  void MaskFault();
};
#endif
