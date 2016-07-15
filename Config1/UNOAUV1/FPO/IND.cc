#include "uobjects.h"
#include "globals.h"
#include "IND.h"

void _INDTC_model()
{
  bool _2PMC = false;
  bool _2PMG = false;
   
  _takt_tc->_TAKT(_2PMC,_2PMG);
  _PI12AB01->_MIG(_PI12AB01TS,_PI12AG03KNMC,_PI12AG05KNMG,_2PMC,_2PMG,_PI12AB01DTS);
  _PI12AB05->_MIG(_PI12AB05TS,_PI12AG03KNMC,_PI12AG05KNMG,_2PMC,_2PMG,_PI12AB05DTS);
  _PI12AB09->_MIG(_PI12AB09TS,_PI12AG03KNMC,_PI12AG05KNMG,_2PMC,_2PMG,_PI12AB09DTS);
}

void _IND()
{
  _INDTC_model();
}

