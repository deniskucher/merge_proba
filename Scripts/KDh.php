<?
//Параметр: ЛБД УНО
$params = "lbd"; 
include "sintar2007.php";
?>

#ifndef KDH
#define KDH
#include "KD_Classes.h"

<?
global $signals;

$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //Имя контроллера

//Выбираем сигналы, принадлежащие заданному контроллеру

 $qry = "select * from SigCont SC, Controller C, AI K
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and SC.SigName=K.Name   and  SC.TypeName='AI' order by K.Name"; 

 $sig_ai =ibase_query($sigdb, $qry);
 $a1=$a2=$a3=0;
 
 while ($sig = ibase_fetch_object($sig_ai))
   {
     echo "  extern bool _{$sig->SIGNAME}F_1;\n";
     if  ($sig->LGR!='<null>') $a1++;
     elseif  ($sig->LGR=='2') $a2++;
     elseif  ($sig->LGR=='3') $a3++;
   }
   echo "  const short KOL_AI1=$a1;\n";
   echo "  const short KOL_AI2=($a2/2);\n";
   echo "  const short KOL_AI3=($a3/3);\n";
   
echo "\n";
?>
  extern void KD_RUN(); 
  extern void Init_KD();

#endif
<?
echo "\n";
 
