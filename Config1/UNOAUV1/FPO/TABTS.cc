
#include "globals.h" 
#include "TABTS.h" 

    int SMC = 0;		 //Счетчик периода мерцания
    bool PMC = false;		 //Признак мерцания
    int SMG = 0;		 //Счетчик периода мигания
    bool PMG  =false;	 	 //Признак мигания

    bool _PI12AB01PTS = false;
    bool _PI12AB05PTS = false;
    bool _PI12AB09PTS = false;
 
    bool _PI12AB01PRMC = false;
    bool _PI12AB05PRMC = false;
    bool _PI12AB09PRMC = false;
 
    bool _PI12AB01PRMG = false;
    bool _PI12AB05PRMG = false;
    bool _PI12AB09PRMG = false;
 
    bool _PI12AB01PRRP = false;
    bool _PI12AB05PRRP = false;
    bool _PI12AB09PRRP = false;
 
    int TT = 100;     //Период задачи	

  void  _TABTSS()
 {

    int TMC = 500/TT;	 //Период мерцания
    int TMG = 2000/TT;	 //Период мигания

  int n = 3;        //Кол-во  сообщений ТС 
  bool* TS[3] = {    //сообщение ТС
   &_PI12AB01TS,
   &_PI12AB05TS,
   &_PI12AB09TS
  };
  bool* DTS[3] = {    //сигнал на табло
   &_PI12AB01DTS,
   &_PI12AB05DTS,
   &_PI12AB09DTS
  };
   bool KNMC = _PI12AG03KNMC;  //кнопка мерцания 
   bool KNMG = _PI12AG05KNMG;  //кнопка мигания 
  bool* PTS[3] = {    //Признак i-го сообщения ТС
   &_PI12AB01PTS,
   &_PI12AB05PTS,
   &_PI12AB09PTS
  };
  bool* PRMC[3] = {    //Признак мерцания i-го сообщения ТС
   &_PI12AB01PTS,
   &_PI12AB05PTS,
   &_PI12AB09PTS
  };
  bool* PRMG[3] = {    //Признак мигания i-го сообщения ТС
   &_PI12AB01PTS,
   &_PI12AB05PTS,
   &_PI12AB09PTS
  };
  bool* PRR[3] = {    //Признак ровного свечения i-го сообщения ТС
   &_PI12AB01PTS,
   &_PI12AB05PTS,
   &_PI12AB09PTS
  };

int i;
 
  if (SMC++ == TMC)
  {
    SMC = 0;
    PMC = !PMC;
  }

  if (SMG++ == TMG)
  {
    SMG = 0;
    PMG = !PMG;
   }

 for (i = 0; i < n; ++i) 
  {
     if (KNMC || *PRR[i]) 
       { if (*TS[i])
            { *DTS[i]=*PRR[i]=*PTS[i]=true; }
	
          else 
		{
		 if (*PTS[i])
			{ *PRMG[i]=true; *PRR[i]=*PRMC[i]=false; *DTS[i]=PMG; }
 		  else  *PTS[i]=*DTS[i]=*PRMG[i]=*PRMC[i]=false;
		}
       }
     else
     { //1
      if (!*PRMG[i] && (*PRMC[i] || *TS[i]))
		{ *PTS[i]=*PRMC[i]=true; *PRMG[i]=*PRR[i]=false; *DTS[i]=PMC; }
	else
        { //2
         if ((!*PRMG[i] && !*PRMC[i] && !*TS[i]) || (*PRMG[i] && KNMG))
		*PTS[i]=*DTS[i]=*PRMG[i]=*PRMC[i]=false;
	  else
	    { //3
             if (*TS[i])
	        { *PTS[i]=*PRMC[i]=true; *PRMG[i]=*PRR[i]=false; *DTS[i]=PMC; }
               else
                { *PRMG[i]=true; *PRR[i]=*PRMC[i]=false; *DTS[i]=PMG; }
            } //3
	}//2

     }//1

  }
}
