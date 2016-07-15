#include "usertype.h"
#include "uclasses.h"
#include "uobjects.h"

_TTAKT *_takt_tc;
_TMIG *_PI21AC01;
_TMIG *_PI21AD03;
_TMIG *_PI21AE05;
void InitObjects()
{
_takt_tc = new(_TTAKT);
_PI21AC01 = new(_TMIG);
_PI21AD03 = new(_TMIG);
_PI21AE05 = new(_TMIG);
  
}
void DeleteObjects()
{
  delete(_takt_tc);
  delete(_PI21AC01);
delete(_PI21AD03);
delete(_PI21AE05);
  
}





