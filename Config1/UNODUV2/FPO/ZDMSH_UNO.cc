
#include "globals.h" 
#include "ZDMSH.h" 

  int TM = 5;  //������ �������
  int SM = 0;	    //������� ������� �������
  bool PM = false;  //������� �������

void  _ZDMSH()
{

  int n = 1;        //���-�� �������� 
  bool* SG[1] = {    //��������� �������
   &_RQ13S01SG
  };
  bool* SGR[1] = {    //��������� ������ �������
   &_RQ13S01SGR
  };
  bool* SGM[1] = {    //��������� �������� �������
   &_RQ13S01SGM
  };
  bool* SY[1] = {    //��������� ������
   &_RQ13S01SY
  };
  bool* SYR[1] = {    //��������� ������ ������
   &_RQ13S01SYR
  };
  bool* SYM[1] = {    //��������� �������� ������
   &_RQ13S01SYM
  };
  if (SM++ == TM)
  {
    SM = 0;
    PM = !PM; 
  }
int i;
 for (i = 0; i < n; ++i) 
  {
      *SG[i] = *SGR[i];
      *SY[i] = *SYR[i];

    if (PM && *SGM[i])
       *SG[i] = true;
    if (PM && *SYM[i])
        *SY[i] = true;
   
  }
}
