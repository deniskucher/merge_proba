<?
//Параметр: ЛБД УНО
$params = "lbd"; 
include "sintar2007.php";
?>

#include "KD.h"
#include "globals.h"

<?
global $signals;

$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //Имя контроллера

//Выбираем сигналы, принадлежащие заданному контроллеру

$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID and (SC.TypeName='AI')
  order by SC.SigName";
$sig_ai   =ibase_query($sigdb, $qry);

 while ($sig = ibase_fetch_object($sig_ai))
       echo "  bool _{$sig->SIGNAME}F_1;\n";
?>

_TKD1 *pAI1[KOL_AI1+1]; // +1 worked in case KOL_AI count = 0 
_TKD2 *pAI2[KOL_AI2+1];
_TKD3 *pAI3[KOL_AI3+1];

void Init_KD()
{
 short i;
 for (i=0;i <= KOL_AI1;i++) 
 pAI1[i] = new _TKD1(0,0,0,0,0,0,0,0,0,0,0,0,0); 
 for (i=0;i <= KOL_AI2;i++) 
 pAI2[i] = new _TKD2(0); 
 for (i=0;i <= KOL_AI3;i++) 
 pAI3[i] = new _TKD3(0,0,0,0,0); 
   i=0;
<?
$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID and (SC.TypeName='PFD')
  order by SC.SigName";
$sig_pfd   =ibase_query($sigdb, $qry);
 while ($sig = ibase_fetch_object($sig_pfd))
    {
     if (strpos($sig->SIGNAME,'ZMX') or strpos($sig->SIGNAME, 'ZMN')
      or strpos($sig->SIGNAME,'ZDV') or strpos($sig->SIGNAME, 'ZRK'))
       echo "  pAI1[i]->pMask _{$sig->SIGNAME}= &_{$sig->SIGNAME};\n";
   }

?>

void KD_RUN()
{
 short i;
 i=0;
 if (Delay_1m<600) Delay_1m++;
<?
 $qry = "select * from SigCont SC, Controller C, AI K
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and SC.SigName=K.Name   and  SC.TypeName='AI' order by K.Name"; 

 $sig_ain1 =ibase_query($sigdb, $qry);
 $sig_ain2 =ibase_query($sigdb, $qry);
 $sig_ain3 =ibase_query($sigdb, $qry);

 while ($sig = ibase_fetch_object($sig_ain1))
 {
  if  ($sig->CHANLCOUNT== '0' or $sig->CHANLCOUNT== '1')
   echo "  pAI1[i]->_KD1(_{$sig->SIGNAME}, _{$sig->SIGNAME}OKD, _{$sig->SIGNAME}KRS,
       _{$sig->SIGNAME}K1N, _{$sig->SIGNAME}K1N, _{$sig->SIGNAME}DV, _{$sig->SIGNAME}MN,
       _{$sig->SIGNAME}MX, _{$sig->SIGNAME}ZZ, _{$sig->SIGNAME}SBRN, _{$sig->SIGNAME}R,
       _{$sig->SIGNAME}F, _{$sig->SIGNAME}F_1);  i++;\n";
   elseif  ($sig->CHANLCOUNT== '2')   
   echo "  pAI1[i]->_KD1(_{$sig->SIGNAME}, _{$sig->SIGNAME}OKD, _{$sig->SIGNAME}KRS,
       _{$sig->SIGNAME}K1N, _{$sig->SIGNAME}K2N, _{$sig->SIGNAME}DV, _{$sig->SIGNAME}MN,
       _{$sig->SIGNAME}MX, _{$sig->SIGNAME}ZZ, _{$sig->SIGNAME}SBRN, _{$sig->SIGNAME}R,
       _{$sig->SIGNAME}F, _{$sig->SIGNAME}F_1);  i++;\n";        
    
  }     
echo " i=0;\n";

$i = 0;
$zam='<null>';
  while ($sig = ibase_fetch_object($sig_ain2))
   {
    if  ($i ==0 and $sig->LGR== '2' and $sig->ZAMER!= '<null>')
       {
        $zam=$sig->ZAMER;
        $A1=$sig->SIGNAME;
        $i++;
       }

    elseif  ($i ==1 and $sig->LGR== '2' and $sig->ZAMER == $zam)
       {
        $A2=$sig->SIGNAME;
        echo "  pAI1[i]->_KD2(_{$A1}R, _{$A2}R,_{$sig->ZAMER}OKD, _{$sig->ZAMER}KRS,
       _{$sig->ZAMER}DEL, _{$sig->ZAMER}ZZ, _{$A1}F, _{$A2}F, _{$sig->ZAMER}SBRN,
       _{$sig->ZAMER}R, _{$sig->ZAMER}F, _{$sig->ZAMER}ZZ);  i++;\n";
        $i =0;
        $zam='<null>';
       }
   }
echo " i=0;\n";
  
$i = 0;
$zam='<null>';

while ($sig = ibase_fetch_object($sig_ain3))
   {
         if  ($i ==0 and $sig->LGR== '3' and $sig->ZAMER!= '<null>')
       {
        $zam=$sig->ZAMER;
        $A1=$sig->SIGNAME;
        $i++;
       }

    elseif  ($i ==1 and $sig->LGR== '3' and  $sig->ZAMER == $zam)
       {
        $A2=$sig->SIGNAME;
        $i++;
       }
    elseif  ($i ==2 and $sig->LGR== '3' and  $sig->ZAMER == $zam)
       {
        $A3=$sig->SIGNAME;
       echo "  pAI1[i]->_KD3(_{$A1}R, _{$A2}R, _{$A3}R, _{$sig->ZAMER}OKD, _{$sig->ZAMER}KRS,
       _{$sig->ZAMER}DEL, _{$sig->ZAMER}ZZ, _{$sig->ZAMER}SBRN, _{$A1}F_1, _{$A2}F_1, _{$A3}F_1,
       _{$sig->ZAMER}R, _{$sig->ZAMER}F, _{$A1}F, _{$A2}F, _{$A3}F, _{$sig->ZAMER}ZZ,
       _{$A1}KRS, _{$A2}KRS, _{$A3}KRS);  i++;\n";
       $i =0; $zam='<null>';
       }
    
  }  
echo "};\n";
?>
 
