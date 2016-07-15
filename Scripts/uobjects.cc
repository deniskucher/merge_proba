#include "usertype.h"
#include "uclasses.h"
#include "uobjects.h"

_TTAKT *_takt_tc;
_TZDMSH *_RN21S05;
_TZDMSH *_RN21S06;
void InitObjects()
{
_takt_tc = new(_TTAKT);
_RN21S05 = new(_TZDMSH);
_RN21S06 = new(_TZDMSH);
  
}
void DeleteObjects()
{
  delete(_takt_tc);
  delete(_RN21S05);
delete(_RN21S06);
  
}



