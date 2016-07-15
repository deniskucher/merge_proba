#include "usertype.h"
#include "uclasses.h"
#include "uobjects.h"

_TTAKT *_takt_tc;
_TMIG *_PI12AB01;
_TMIG *_PI12AB05;
_TMIG *_PI12AB09;
void InitObjects()
{
_takt_tc = new(_TTAKT);
_PI12AB01 = new(_TMIG);
_PI12AB05 = new(_TMIG);
_PI12AB09 = new(_TMIG);
  
}
void DeleteObjects()
{
  delete(_takt_tc);
  delete(_PI12AB01);
delete(_PI12AB05);
delete(_PI12AB09);
  
}





