#include "uclasses.h"
//__________________________________ TAF __________________________________

_TAF::_TAF()
{
  PVAPZ = false;
  RD = 0;
}

_TAF::~_TAF()
{
}

smallint _TAF::_AF(const bool SBRN, const smallint VH, const smallint TF,
  const smallint AMX)
{
     /*Тело метода*/
//такт включения 100 мс
  smallint DELTA;
  int PER;
  if (SBRN)
  {
    RD = VH;
    return RD;
  }
  else
  {
     if (!PVAPZ)
     {
        PVAPZ=true;
        RD = VH;
        return RD;
     }
     PER=VH-RD;
//////////////////////////////
  DELTA = PER > 32767? 32767 : (PER < -32767? -32767 : PER);
//////////////////////////////
     if (abs(DELTA) >= AMX)
     {
	 if (DELTA > 0)  DELTA=AMX;
           else DELTA=-AMX;
     }
        if ((TF <= (0.1*32767/100)) || (abs(DELTA)<=6))
  {
       RD = VH;
       return RD;
     }
 if (abs(smallint((DELTA*0.1/TF)*32767/100)) >1)
     {
      RD = smallint(RD+((float)DELTA*0.1/TF)*32767/100);
       return RD;
     }
     if   (DELTA>0)     RD++;
                  else  RD--;
     return RD;
  }//if (SBRN)
}  /*_TAF::_AF*/


//__________________________________ TMaxHyst __________________________________

_TMaxHyst::_TMaxHyst()
{
  old = false;
  prin = false;
}

_TMaxHyst::~_TMaxHyst()
{
}

bool _TMaxHyst::_MaxHyst(const smallint CP, const smallint Max, 
  const smallint Delta)
{
  /*Тело метода*/
   if (!prin)
    {
      prin  = true;
      old  = (CP > Max);
    }
  old = old && (CP >= (Max - Delta)) || (CP > Max);
  return old;
}  /*_TMaxHyst::_MaxHyst*/

//__________________________________ TMinHyst __________________________________

_TMinHyst::_TMinHyst()
{
  old = false;
  prin = false;
}

_TMinHyst::~_TMinHyst()
{
}

bool _TMinHyst::_MinHyst(const smallint CP, const smallint Min,
  const smallint Delta)
{   /*Тело метода*/
  if (!prin)
  {  prin = true;
     old = CP < Min;
  }
  old = old && (CP <= (Min + Delta)) || (CP < Min);
  return old;
}
    //{_TMinHyst._MinHyst}



//__________________________________ TSTrigger __________________________________

_TSTrigger::_TSTrigger()
{
  St = false;
}

_TSTrigger::~_TSTrigger()
{
}

void _TSTrigger::_STrigger(const bool S, const bool R, bool &_1, bool &_0)
{
  /*Тело метода*/
   St = St && (!R) || S;
   _1 = St;
   _0 = !St;
}  /*_TSTrigger::_STrigger*/


//__________________________________ TOnDelay __________________________________

_TOnDelay::_TOnDelay()
{
  Count = 0;
  Pd = false;
}

_TOnDelay::~_TOnDelay()
{
}

bool _TOnDelay::_OnDelay(const bool Front, const smallint T)
{
  /*Тело метода*/
   if (!Front)
   {
       Count = 0;
       Pd = false;
       return false;
   }
  else
   if ((Count < T) && (!Pd))
   {
         Count++;
         return false;
   }
   else
   {
        Pd = true;
        return true;
   }
}  /*_TOnDelay::_OnDelay*/

//__________________________________ TAVR __________________________________

_TAVR::_TAVR()
{
  RAB1_St = new _TSTrigger();
  RAB1 = false;
  RAB2 = false;
  REZ1 = false;
  RAB3 = false;
  REZ2 = false;
  REZ3 = false;
  RAB21 = false;
  RAB22 = false;
  RAB23 = false;
  RAB2_St = new _TSTrigger();
  RAB3_St = new _TSTrigger();
  ZD_OnD = new _TOnDelay();
}

_TAVR::~_TAVR()
{
}

void _TAVR::_AVR(smallint P, bool PF, smallint PMX1, smallint PMX2, smallint PMN, bool N1RAB, bool N2RAB, 
  bool N3RAB, bool VKL1, bool OTKL1, bool VKL2, bool OTKL2, bool VKL3, bool OTKL3, bool ZDZAK, smallint TVOTKL, 
  bool N1AO, bool N2AO, bool N3AO, bool &N1A01, bool &N1A02, bool &N2A01, bool &N2A02, bool &N3A01, bool 
  &N3A02, bool &PBMX1, bool &PBMX2, bool &PNMN12)
{
  bool _43_R = false;
  bool _41_R = false;
  bool _61_R = false;
  bool _42_R = false;
  bool _62_R = false;
  bool _40_R = false;
  bool _60_R = false;
  bool _53_R = false;
  bool _54_R = false;
  bool _67_R = false;
  bool _56_R = false;
  bool _1_1 = false;
  bool _1_0 = false;
  bool _51_R = false;
  bool _52_R = false;
  bool _66_R = false;
  bool _0_1 = false;
  bool _0_0 = false;
  bool _55_R = false;
  bool _68_R = false;
  bool _2_1 = false;
  bool _2_0 = false;
  bool _73_R = false;
  bool _74_R = false;
  bool _79_R = false;
  bool _75_R = false;
  bool _76_R = false;
  bool _80_R = false;
  bool _77_R = false;
  bool _78_R = false;
  bool _81_R = false;
  bool _47_R = false;
  bool _48_R = false;
  bool _49_R = false;
  bool _50_R = false;
  bool _63_R = false;
  bool _82_R = false;
  bool _64_R = false;
  bool _83_R = false;
  bool _65_R = false;
  bool _44_R = false;
  bool _57_R = false;
  bool _45_R = false;
  bool _58_R = false;
  bool _46_R = false;
  bool _59_R = false;
  bool _69_R = false;
  bool _72_R = false;
  bool _84_R = false;
  bool _91_R = false;
  bool _88_R = false;
  bool _89_R = false;
  bool _70_R = false;
  bool _90_R = false;
  bool _93_R = false;
  bool _85_R = false;
  bool _86_R = false;
  bool _71_R = false;
  bool _87_R = false;
  bool _92_R = false;
  bool _3Out = false;
  bool _94_R = false;
  bool _95_R = false;
  bool _96_R = false;

  _43_R = RAB1 || RAB2 || RAB3;
  _41_R = ! RAB2;
  _61_R = _43_R && _41_R && N2RAB;
  RAB22 = _61_R;
  _42_R = ! RAB3;
  _62_R = _43_R && _42_R && N3RAB;
  RAB23 = _62_R;
  _40_R = ! RAB1;
  _60_R = _43_R && _40_R && N1RAB;
  RAB21 = _60_R;
  _53_R = ! N1RAB;
  _54_R = ! N3RAB;
  _67_R = N2RAB && _53_R && _54_R;
  _56_R = ! N2RAB;
  RAB2_St->_STrigger(_67_R,_56_R,_1_1,_1_0);
  RAB2 = _1_1;
  _51_R = ! N2RAB;
  _52_R = ! N3RAB;
  _66_R = N1RAB && _51_R && _52_R;
  RAB1_St->_STrigger(_66_R,_53_R,_0_1,_0_0);
  RAB1 = _0_1;
  _55_R = ! N1RAB;
  _68_R = N3RAB && _55_R && _56_R;
  RAB3_St->_STrigger(_68_R,_54_R,_2_1,_2_0);
  RAB3 = _2_1;
  _73_R = ! RAB1;
  _74_R = ! RAB21;
  _79_R = _73_R && _74_R;
  REZ1 = _79_R;
  _75_R = ! RAB2;
  _76_R = ! RAB22;
  _80_R = _75_R && _76_R;
  REZ2 = _80_R;
  _77_R = ! RAB3;
  _78_R = ! RAB23;
  _81_R = _77_R && _78_R;
  REZ3 = _81_R;
  _47_R = P > PMX1;
  PBMX1 = _47_R;
  _48_R = P > PMX2;
  PBMX2 = _48_R;
  _49_R = P < PMN;
  PNMN12 = _49_R;
  _50_R = ! PF;
  _63_R = _47_R && _50_R;
  _82_R = _63_R && RAB1 && OTKL1;
  _64_R = _48_R && _50_R;
  _83_R = OTKL1 && RAB21 && _64_R;
  _65_R = _49_R && _50_R;
  _44_R = RAB1 || RAB21;
  _57_R = N1AO && _44_R;
  _45_R = RAB2 || RAB22;
  _58_R = N2AO && _45_R;
  _46_R = RAB3 || RAB23;
  _59_R = N3AO && _46_R;
  _69_R = _57_R || _58_R || _59_R;
  _72_R = _65_R || _69_R;
  _84_R = OTKL1 && REZ1 && _72_R;
  _91_R = _82_R || _83_R || _84_R;
  N1A01 = _91_R;
  _88_R = _63_R && RAB3 && OTKL3;
  _89_R = OTKL3 && RAB23 && _64_R;
  _70_R = _65_R || _69_R;
  _90_R = OTKL3 && REZ3 && _70_R;
  _93_R = _88_R || _89_R || _90_R;
  N3A01 = _93_R;
  _85_R = _63_R && RAB2 && OTKL2;
  _86_R = OTKL2 && RAB22 && _64_R;
  _71_R = _65_R || _69_R;
  _87_R = OTKL2 && REZ2 && _71_R;
  _92_R = _85_R || _86_R || _87_R;
  N2A01 = _92_R;
  _3Out = ZD_OnD->_OnDelay(ZDZAK,TVOTKL);
  _94_R = _3Out && VKL1;
  N1A02 = _94_R;
  _95_R = _3Out && VKL2;
  N2A02 = _95_R;
  _96_R = _3Out && VKL3;
  N3A02 = _96_R;
}

