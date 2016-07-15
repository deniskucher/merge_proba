<?
//Параметр: ЛБД УНО
$params = "lbd"; 
include "sintar2007.php";
?>
#ifndef globalprH
#define globalprH
#include "usertype.h"
<?
global $signals;

$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //Имя контроллера

//Выбираем дискретные сигналы  принадлежащие заданному контроллеру

$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and  (SC.TypeName='DI' or SC.TypeName='PIN' or SC.TypeName='DO'
  or SC.TypeName='KL'  or SC.TypeName='PFD')   order by SC.SigName";
$sig_d   =ibase_query($sigdb, $qry);

//Выбираем аналоговые сигналы  принадлежащие заданному контроллеру

$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and (SC.TypeName='AI'or SC.TypeName='PFA' or SC.TypeName='AO'
  or SC.TypeName='KO'  or SC.TypeName='MRI' or SC.TypeName='MRO')
  order by SC.SigName";
$sig_a   =ibase_query($sigdb, $qry);

while ($sig = ibase_fetch_object($sig_d))
    echo "extern bool _{$sig->SIGNAME};\n"; 

while ($sig = ibase_fetch_object($sig_a))
    echo "extern short _{$sig->SIGNAME};\n"; 
?>

#endif
<?
echo "\n";
