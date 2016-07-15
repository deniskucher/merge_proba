<?
//Параметр: ЛБД УНО
$params = "lbd"; 
include "sintar2007.php";
?>
#ifndef globalsH
#define globalsH
#include "usertype.h"
<?
global $signals;

$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //Имя контроллера

//Выбираем аналоговые сигналы принадлежащие заданной ЛБД
$qry = "select SC.SigName, SC.TypeName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID
  and  (SC.TypeName='AI' or  SC.TypeName='AO' or  SC.TypeName='PFA'
  or  SC.TypeName='AO' or  SC.TypeName='KO'
    or  SC.TypeName='MRI' or  SC.TypeName='MRO')
  order by SC.SigName"; 
$sig_as = ibase_query($sigdb, $qry);
//Выбираем дискретные сигналы, принадлежащие заданной ЛБД
$qry = "select SC.SigName, SC.TypeName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID
  and  (SC.TypeName='DI' or  SC.TypeName='DO' or  SC.TypeName='PFD'
   or  SC.TypeName='KL' or  SC.TypeName='PIN')
  order by SC.SigName"; 
$sig_ds = ibase_query($sigdb, $qry);
echo "	////// сигналы аналоговые \n";
while ($sig = ibase_fetch_object($sig_as))
	{
	echo "extern short _{$sig->SIGNAME};\n"; 
	}
echo "	////// сигналы дискретные \n";
while ($sig = ibase_fetch_object($sig_ds))
	{
    echo "extern bool _{$sig->SIGNAME};\n"; 
	}
?>

#endif
<?
echo "\n";