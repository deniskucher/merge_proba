
#include "globals.h" 
#include "ZDMSH.h" 

  int TT = 100;     //������ ������	
  int TM = 500/TT;  //������ �������
  int SM = 0;	    //������� ������� �������
  bool PM = false;  //������� �������

void  _ZDMSH()
{

  int n = 2;        //���-�� �������� 
  bool* SG[2] = {    //��������� �������
   &_RN21S05SG,
   &_RN21S06SG
  };
  bool* SGR[2] = {    //��������� ������ �������
   &_RN21S05SGR,
   &_RN21S06SGR
  };
  bool* SGM[2] = {    //��������� �������� �������
   &_RN21S05SGM,
   &_RN21S06SGM
  };
  bool* SY[2] = {    //��������� ������
   &_RN21S05SY,
   &_RN21S06SY
  };
  bool* SYR[2] = {    //��������� ������ ������
   &_RN21S05SYR,
   &_RN21S06SYR
  };
  bool* SYM[2] = {    //��������� �������� ������
   &_RN21S05SYM,
   &_RN21S06SYM
  };
  if (SM++ == TM)
  {
    SM = 0;
    PM = !PM; 
  }
int i;
  for (i = 0; i < n; ++i) 
  {
    if (PM)
    {
      *SG[i] = *SGM[i];
      *SY[i] = *SYM[i];
    }
    else
    {
      *SG[i] = *SGR[i];
      *SY[i] = *SYR[i];
    }
  }
}