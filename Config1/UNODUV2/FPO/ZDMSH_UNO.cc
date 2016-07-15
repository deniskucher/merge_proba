
#include "globals.h" 
#include "ZDMSH.h" 

  int TM = 5;  //Период мигания
  int SM = 0;	    //Счетчик периода мигания
  bool PM = false;  //Признак мигания

void  _ZDMSH()
{

  int n = 1;        //Кол-во задвижек 
  bool* SG[1] = {    //Подсветка зеленым
   &_RQ13S01SG
  };
  bool* SGR[1] = {    //Подсветка ровным зеленым
   &_RQ13S01SGR
  };
  bool* SGM[1] = {    //Подсветка мигающим зеленым
   &_RQ13S01SGM
  };
  bool* SY[1] = {    //Подсветка желтым
   &_RQ13S01SY
  };
  bool* SYR[1] = {    //Подсветка ровным желтым
   &_RQ13S01SYR
  };
  bool* SYM[1] = {    //Подсветка мигающим желтым
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
