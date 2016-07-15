#include "uclasses.h"
//__________________________________ TINDMN __________________________________

_TINDMN::_TINDMN()
{
  SM = 0;
  PM = false;
  PRSY = false;
  PRSG = false;
}

_TINDMN::~_TINDMN()
{
}

void _TINDMN::_INDMN(const bool SYR, const bool SGR, const bool SYM,
  const bool SGM, bool &SY, bool &SG)
{
if(SM>10){
	SM=0;
	if(PM) PM=false;
	else
	PM=true;
	 }
else
SM++;
 if(SGR) PRSG = true;
 else PRSG = false;
 if(SYR) PRSY = true;
 else PRSY = false;
 if(PM) {
	 if(SGM) PRSG = true;
	 if(SYM) PRSY = true;
	 }
 SY = PRSY;
 SG = PRSG;

  /*Тело метода*/
}  /*_TINDMN::_INDMN*/

//__________________________________ TMIG __________________________________

_TMIG::_TMIG()
{
  PRR = false;
  PRMG = false;
  PRMC = false;
  PTS = false;
}

_TMIG::~_TMIG()
{
}

void _TMIG::_MIG(const bool TS, const bool KNMC, const bool KNMG, const bool PMC,
  const bool PMG, bool &DTS)
{
  /*Тело метода*/
  if(!KNMC){
		if(PRR) goto l1;
		//else {
			if(PRMG){
				if(KNMG) {
			l2:	DTS=PRMG=PRMC=PTS=false;
				goto KON;
				}
				else
					if(TS) goto MC;
					else goto MG;
			}
			//else {
			if(PRMC){
		MC: PTS = PRMC = true;
			PRMG=PRR=DTS=false;
			if(PMC) DTS = true;
			goto KON;
			}
			else{
			if(TS) goto MC;
			goto l2;

			}
	}
	else {
l1:	if(TS) PTS=DTS=PRR=true;
	else{
		if(PTS){
	MG: PRMG=true;
		PRR=PRMC=DTS=false;
		if(PMG) DTS = true;
			}
		goto KON;
		}
	}
KON: return;
}  /*_TMIG::_MIG*/

//__________________________________ TTAKT __________________________________

_TTAKT::_TTAKT()
{
  SMC = 0;
  SMG = 0;
  PRMC = false;
  PRMG = false;
}

_TTAKT::~_TTAKT()
{
}

void _TTAKT::_TAKT(bool &PMC, bool &PMG)
{
  /*Тело метода*/
  if(SMC>5) {
  	SMC = 0;
  	if(PRMC)
  	PRMC = false;
  	else
  	PRMC = true;
             }
   else
   SMC++;
   if(SMG>20) {
  	SMG = 0;
  	if(PRMG)
  	PRMG = false;
  	else
  	PRMG = true;
             }
   else
   SMG++;
  PMC = PRMC;
  PMG = PRMG;
}  /*_TTAKT::_TAKT*/

