#ifndef uclassesH
#define uclassesH
#include "usertype.h"


//__________________________________ TINDMN __________________________________

class _TINDMN
{
public:
  smallint SM;
  bool PM;
  bool PRSY;
  bool PRSG;
  _TINDMN();
  ~_TINDMN();
  void _INDMN(const bool SYR, const bool SGR, const bool SYM,
  const bool SGM, bool &SY, bool &SG);
};
//__________________________________ TMIG __________________________________

class _TMIG
{
public:
  bool PRR;
  bool PRMG;
  bool PRMC;
  bool PTS;
  _TMIG();
  ~_TMIG();
  void _MIG(const bool TS, const bool KNMC, const bool KNMG, const bool PMC,
  const bool PMG, bool &DTS);
};
//__________________________________ TTAKT __________________________________

class _TTAKT
{
public:
  smallint SMC;
  smallint SMG;
  bool PRMC;
  bool PRMG;
  _TTAKT();
  ~_TTAKT();
  void _TAKT(bool &PMC, bool &PMG);
};
#endif
