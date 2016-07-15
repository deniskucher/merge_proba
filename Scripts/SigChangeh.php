<?
//Параметр: ЛБД УНО
$params = "lbd"; 
include "sintar2007.php";
?>
#ifndef SigChangeH
#define SigChangeH

<?
global $signals;

$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //Имя контроллера

//Выбираем сигналы DI, DO и PFD, принадлежащие заданной ЛБД
$qry = "select SC.SigName, SC.TypeName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID
  and  (SC.TypeName='AI' or  SC.TypeName='AO' or  SC.TypeName='PFA'
  or  SC.TypeName='AO' or  SC.TypeName='KO'
    or  SC.TypeName='MRI' or  SC.TypeName='MRO')
  order by SC.SigName"; 
$sig_as = ibase_query($sigdb, $qry);
$qry = "select SC.SigName, SC.TypeName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID
  and  (SC.TypeName='DI' or  SC.TypeName='DO' or  SC.TypeName='PFD'
  or  SC.TypeName='PIN' or  SC.TypeName='KL')
  order by SC.SigName"; 
$sig_ds = ibase_query($sigdb, $qry);
while ($sig = ibase_fetch_object($sig_as))
{
 echo "extern int *p{$sig->SIGNAME};\n"; 
}
while ($sig = ibase_fetch_object($sig_ds))
{
 echo "extern char *p{$sig->SIGNAME};\n"; 
}
?>
extern void Read_Sig();
extern void Write_Sig();
extern void Init_P();
#endif
