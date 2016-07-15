<?
//Параметры: путь к разработке, контроллер, период задачи
$params = "lbd,takt"; 
include "sintar2007.php";
?>

#include "globals.h" 
#include "TABTS.h" 

    int SMC = 0;		 //Счетчик периода мерцания
    bool PMC = false;		 //Признак мерцания
    int SMG = 0;		 //Счетчик периода мигания
    bool PMG  =false;	 	 //Признак мигания

<?
global $signals;
$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //Имя контроллера
//Выбираем сигналы DO и PFD, принадлежащие заданной ЛБД
$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and (SC.TypeName='DI' or SC.TypeName='DO' or SC.TypeName='PFD')
  order by SC.SigName";
$sig_q = ibase_query($sigdb, $qry);

//для подсветки ТАБЛО ТС  4 сигнала  из БД:
$ts = array();		//сообщение сигнализации
$dts = array();		//сигнал на табло
$knmc = '';		//кнопка мерцания
$knmg = '';		//кнопка мигания
// 4 ПРИЗНАКА СООБЩЕНИЯ ТС
$pts  = array();
$prmc = array();
$prmg = array();
$prr  = array();


while ($sig = ibase_fetch_object($sig_q))
{
//echo "{$sig->SIGNAME}\n";
  
  $tsname = substr($sig->SIGNAME,0,8);

  $proto = substr($sig->SIGNAME,8);   // $proto - возвращает строку после ИМ

  if ($proto == 'TS')
   {   
   $ts[]   = $sig->SIGNAME;
   $pts[]  = str_pad($tsname, 11, 'PTS');	
   $prmc[] = str_pad($tsname, 12, 'PRMC');
   $prmg[] = str_pad($tsname, 12, 'PRMG');
   $prr[]  = str_pad($tsname, 12, 'PRR');
   }	
  elseif ($proto == 'DTS')
    $dts[] = $sig->SIGNAME;	

  elseif ($proto == 'KNMC')
    $knmc = $sig->SIGNAME;	
  elseif ($proto == 'KNMG')
    $knmg = $sig->SIGNAME;	
 	
}
$n = count($ts);

out2sig_arr($pts);
out2sig_arr($prmc);
out2sig_arr($prmg);
out2sig_arr($prr);

echo "    int TT = {$takt};     //Период задачи	\n";

?>

  void  _TABTSS()
 {

    int TMC = 500/TT;	 //Период мерцания
    int TMG = 2000/TT;	 //Период мигания

<?

echo "  int n = {$n};        //Кол-во  сообщений ТС \n";

out1sig_arr($ts, 'TS',$n, 'сообщение ТС');
out1sig_arr($dts, 'DTS',$n, 'сигнал на табло');

echo "   bool KNMC = _{$knmc};  //кнопка мерцания \n";
echo "   bool KNMG = _{$knmg};  //кнопка мигания \n";

out1sig_arr($pts, 'PTS',  $n, 'Признак i-го сообщения ТС');
out1sig_arr($pts, 'PRMC', $n, 'Признак мерцания i-го сообщения ТС');
out1sig_arr($pts, 'PRMG', $n, 'Признак мигания i-го сообщения ТС');
out1sig_arr($pts, 'PRR',  $n, 'Признак ровного свечения i-го сообщения ТС');

?>

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


