#include "KD_Classes.h"
#include <math.h>
#include <stdlib.h>

short Delay_1m = 0;
short tKD1 = 5;
short tKD23 = 5;
bool _0 = false;

//__________________________________ TKD2 __________________________________

_TKD2::_TKD2(smallint _1n4)
{	
  n4 = _1n4;
  PROTKL = false;
  PRKRZ= false;
  pMask_ZRK = &_0;
}

_TKD2::~_TKD2()
{
}

void _TKD2::_KD2(const smallint P1R, const smallint P2R, const bool OTKLKD,
  const bool KRZ, const smallint DEL, const bool NKD11,
  const bool NKD12, const bool SBRN, smallint &PTR, bool &PTF,
  smallint &ZZ)
{
  /*Тело метода*/
  // byte D1,D2;

if (*pMask_ZRK)  n4=0;//09_11_2012
  
if (OTKLKD)
{  //  Отказа Нет, Показания датчика равны Значению замещения
  if (!PROTKL)
 {
  PTF= false;
  ZZ = PTR;
  n4= 0;
  PROTKL = true;
  }
  PTR= ZZ;
}
else
{
    //  ОПРЕДЕЛЕНИЕ ОТКАЗА ДАТЧИКА
  if (PRKRZ)
  {
  	PRKRZ= false;
  	PTF= false;
  }
  else if (SBRN) PTF= false;
  if ( KRZ)
  {	
  	PRKRZ= true;
    PTF= true;
  }   
  if (NKD11 || NKD12) n4= 0;
  if ( NKD11 &&  NKD12)
     PTF= true;
  else  if (!(NKD11 || NKD12)) 
   {
    if (abs( P1R -  P2R) >  DEL)
    {
     if (n4 >= tKD23) PTF= true;
      else n4++;
	
    }
    else  n4= 0;
    }
    //  ОПРЕДЕЛЕНИЕ РАБОЧЕГО ЗНАЧЕНИЯ

    PTR = !( NKD11 ^ NKD12)? ((P1R >>1) + (P2R >>1)): (NKD11? P2R : P1R);
 
   PROTKL = false;
   }

}  /*_TKD2::_KD2*/

//__________________________________ TKD3 __________________________________

_TKD3::_TKD3(byte _1n1, byte _2n2, byte _3n3, byte _4n4, byte _5nk)
{
  n1 = _1n1;
  n2 = _2n2;
  n3 = _3n3;
  n4 = _4n4;
  nk = _5nk;
  PROTKL = false;
  PRKRZ= false;
  pMask_ZRK = &_0;
}

_TKD3::~_TKD3()
{
}

void _TKD3::_KD3(const smallint P1R, const smallint P2R, const smallint P3R,
  const bool OTKLKD, const bool KRZ, const smallint DEL,
  const bool SBRN, const bool NKD11, const bool NKD12, const bool NKD13,
  smallint &PTR, bool &PTF, bool &NKD31, bool &NKD32, bool &NKD33,
  smallint &ZZ, bool KRS1, bool KRS2, bool KRS3)

{
  /*Тело метода*/
char n,FlagP;
int SR,DP1,DP2,DP3,P1,P2;

NKD31=NKD11;
NKD32=NKD12;
NKD33=NKD13;

if (*pMask_ZRK) n1=n2=n3=n4=0;

if (OTKLKD)
{
  //  Отказа Нет, Показания датчика равны Значению замещения
  if (!PROTKL)
  {
  PTF= false;
  ZZ = PTR;
  NKD31= false;
  NKD32= false;
  NKD33= false;
  n1=0;
  n2=0;
  n3=0;
  n4=0;
  PROTKL = true;
  }
  PTR= ZZ;
}
else
{
    //  ОПРЕДЕЛЕНИЕ ОТКАЗА ДАТЧИКА
  if (PRKRZ)
  {
  	PRKRZ= false;
  	PTF= false; 
  }		  
  else if (SBRN) PTF= false;
  n=0;
  nk=0;
  if (NKD11)
  {
    n++;
    if (KRS1) nk++;
  }  
  if (NKD12)
  {
    n+=2;
    if (KRS2) nk+=2;
  }  
  if (NKD13)
  {
    n+=4;
    if (KRS3) nk+=4;
  }  
  // Выбор среднего значения
//  SR = Center(P1R,P2R,P3R);
 SR =P1R < P2R? (P2R < P3R? P2R: (P1R < P3R? P3R : P1R)) : (P1R < P3R? P1R: (P2R < P3R? P3R : P2R));
  if (n==0)  // нет браков из предыд. процедур и по отклонению от среднего
  {
    DP1= SR-P1R;
    DP2= SR-P2R;
    DP3= SR-P3R;
    // Формирование неисправностей датчиков
    if ((abs(DP1) > DEL)&&(DEL != 32767)) 
    {
      if (n1 > tKD23)
      {
       NKD31 =true;
       n++;
      }
       else n1++;	
    }
    else n1= 0;

    if ((abs(DP2) > DEL)&&(DEL !=32767))
    {
      if (n2 > tKD23)
      {
       NKD32 =true;
       n+=2;
      }
      else n2++;	
    }
    else n2=0;

    if ((abs(DP3) > DEL)&&(DEL != 32767))
    {
      if (n3 > tKD23)
      {
       NKD33 =true;
       n+=4;
      }
      else n3++;
    }
    else n3=0;
    if ((n==3) || (n==5) || (n==6))  PTF=true;
    PTR=SR;
	goto B3; 
  }
  else 
  {
m1: FlagP=1;  // C
    switch (n)
    {
    case 1:
      P1=P2R;
      P2=P3R;
      FlagP=0;
      break;

    case 2:
      P1=P1R;
      P2=P3R;
      FlagP=0;
      break;

    case 4:
      P1=P1R;
      P2=P2R;
      FlagP=0;
      break;

    default:
    if (nk==0) goto MPTR;	
      if (n==3) PTR=P3R;
      else if (n==5) PTR=P2R;
           else if (n==6) PTR=P1R; 
                else
                {
MPTR:  			  PTR= SR;
      			  PTF= true;
                  goto MZZR;
				}
    }

    if (!FlagP)
    {
      if (abs(P1-P2) > (DEL*1.5))
      {
        if (n4 > tKD23)
        {
         PTF= true;
         PTR= SR;
	 goto MZZR;
        }
        else n4++;
      }
      else n4 = 0;
    
    PTR= (P1 >>1)+(P2 >> 1);
   
    }   /*FLAGP=0*/
  }
B3:
  if (KRZ)   
  {
  	PRKRZ= true;
  	PTF= true;
  }	

MZZR:
  PROTKL = false;   // Значение замещения равно показанию датчика
 
 }    /*OTLKD=0*/
  }  /*_TKD3::_KD3*/

//__________________________________ TKD1 __________________________________

_TKD1::_TKD1(smallint _1_0, smallint _2_1, smallint _3_2, smallint _4_3, smallint _5_4, 
  smallint _6_5, smallint _7_6, smallint _8_7, smallint _9_8, smallint _10_9, smallint 
  _11nDV, smallint _12nMX, smallint _13TCKD1)
{
  P_z[0] = _1_0;
  P_z[1] = _2_1;
  P_z[2] = _3_2;
  P_z[3] = _4_3;
  P_z[4] = _5_4;
  P_z[5] = _6_5;
  P_z[6] = _7_6;
  P_z[7] = _8_7;
  P_z[8] = _9_8;
  P_z[9] = _10_9;
  nDV = _11nDV;
  nMX = _12nMX;
  TCKD1 = _13TCKD1;
//  PROTKL = false;
  PRKRS = false;
pMask_ZMX = pMask_ZMN = pMask_ZDV = &_0;
}

_TKD1::~_TKD1()
{
}

void _TKD1::_KD1(const smallint P, const bool OTKLKD, const bool KRS,
  const bool NTSKN1, const bool NTSKN2, const smallint DV, const smallint MN,
  const smallint MX, const bool SBRN, smallint &PR,
  bool &NKD1, smallint &ZZ, bool &NKD1_1)
{
  /*Тело метода*/
  if (OTKLKD)
{
   if (!PROTKL)	
   {
	  NKD1_1= false;
	  ZZ =P;
	  nDV= 0;
	  nMX= 0;
	  PROTKL =true ;
   }
   PR = ZZ;
  goto aaa;
}
if (NTSKN1 && NTSKN2 && (Delay_1m > 100))
  goto bbb;

if (KRS)
{
  PRKRS= true;
//  nMX= 0;
//  nDV= 0;	
  goto bbb;
}  

if (PRKRS) 
{
  PRKRS= false;
  NKD1_1= false;	
}	
else if (SBRN) NKD1_1= false;

if ( !*pMask_ZDV &&(abs(P-P_z[TCKD1])>DV)&&(Delay_1m==600)&&(DV != 32767))
{
  if (nDV < 5)
   {
    nDV++; 
	PRDV= true;
    goto ffff;
   }
  else goto bbb;
}

nDV= 0;
PRDV= false;
ffff: if ( !*pMask_ZMN && ((P < MN) && (MN != 0)) || !*pMask_ZMX && (P > MX))
	{
	  if (nMX < tKD1)
	    {
	     nMX++; 
	     goto aaa;
	    }
	  else goto bbb;
	}

nMX=0;
goto ccc;

bbb:   // выход - Значение замещения
    NKD1_1= true;
ccc:
	if (!PRDV)
	{
		PR= P;
		PROTKL = false;
	}	
aaa:
	P_z[TCKD1]= P; // Предыдущее показание датчика
	 TCKD1++;
	 if (TCKD1 > 9) TCKD1 = 0;
	 NKD1= NKD1_1;
}  /*_TKD1::_KD1*/

