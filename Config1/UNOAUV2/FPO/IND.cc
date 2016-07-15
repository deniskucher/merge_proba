#include "uobjects.h"
#include "globals.h"
#include "IND.h"

void _INDTC_model()
{
  bool _2PMC = false;
  bool _2PMG = false;
   
  _takt_tc->_TAKT(_2PMC,_2PMG);
  _PI21AC01->_MIG(_PI21AC01TS,_PI21AJ03KNMC,_PI21AJ05KNMG,_2PMC,_2PMG,_PI21AC01DTS);
  _PI21AD03->_MIG(_PI21AD03TS,_PI21AJ03KNMC,_PI21AJ05KNMG,_2PMC,_2PMG,_PI21AD03DTS);
  _PI21AE05->_MIG(_PI21AE05TS,_PI21AJ03KNMC,_PI21AJ05KNMG,_2PMC,_2PMG,_PI21AE05DTS);
}

void _IND()
{
  _INDTC_model();
}

