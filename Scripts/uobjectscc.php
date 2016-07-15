<?
//Параметр: ЛБД УНО
$params = "lbd"; 
include "sintar2007.php";
?>
#include "usertype.h"
#include "uclasses.h"
#include "uobjects.h"

_TTAKT *_takt_tc;
<?
global $signals, $OldConsName, $SigName;

$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //Имя контроллера
$OldConsName = '?';
$DTS = $KNMC = $KNMG = ''; 

//Выбираем сигналы DI, DO и PFD, принадлежащие заданной ЛБД
$qry = "select SC.SigName, SC.TypeName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  order by SC.TypeName, SC.SigName";
$sig_q = ibase_query($sigdb, $qry);
while ($sig = ibase_fetch_object($sig_q))
{
  $SigName = $sig->SIGNAME;
  $TypeName = $sig->TYPENAME;
  //echo " {$SigName} ({$TypeName})\n";
  if (($TypeName == 'DO') and (substr($SigName,-3) == 'DTS'))
  {
    //IfNewConsole(7);   //3-'DTS',4-координаты ячейки
    $DTS = $SigName;
    $CellName = substr($SigName,0,strlen($SigName)-3); 
    $TS = $CellName.'TS';	//Наличие сигнала TS в БД не контролируем - одна ячейка	
  echo "_TMIG *_{$CellName};\n";
  }
   
}
?>
void InitObjects()
{
_takt_tc = new(_TTAKT);
<? global $signals, $OldConsName, $SigName;

$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //Имя контроллера
$OldConsName = '?';
$DTS = $KNMC = $KNMG = ''; 

//Выбираем сигналы DI, DO и PFD, принадлежащие заданной ЛБД
$qry = "select SC.SigName, SC.TypeName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  order by SC.TypeName, SC.SigName";
$sig_q = ibase_query($sigdb, $qry);
while ($sig = ibase_fetch_object($sig_q))
{
  $SigName = $sig->SIGNAME;
  $TypeName = $sig->TYPENAME;
  //echo " {$SigName} ({$TypeName})\n";
  if (($TypeName == 'DO') and (substr($SigName,-3) == 'DTS'))
  {
    //IfNewConsole(7);   //3-'DTS',4-координаты ячейки
    $DTS = $SigName;
    $CellName = substr($SigName,0,strlen($SigName)-3); 
    $TS = $CellName.'TS';	//Наличие сигнала TS в БД не контролируем - одна ячейка	
  echo "_{$CellName} = new(_TMIG);\n";
  }
   
}
?>
  
}
void DeleteObjects()
{
  delete(_takt_tc);
  <?global $signals, $OldConsName, $SigName;

$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //Имя контроллера
$OldConsName = '?';
$DTS = $KNMC = $KNMG = ''; 

//Выбираем сигналы DI, DO и PFD, принадлежащие заданной ЛБД
$qry = "select SC.SigName, SC.TypeName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  order by SC.TypeName, SC.SigName";
$sig_q = ibase_query($sigdb, $qry);
while ($sig = ibase_fetch_object($sig_q))
{
  $SigName = $sig->SIGNAME;
  $TypeName = $sig->TYPENAME;
  //echo " {$SigName} ({$TypeName})\n";
  if (($TypeName == 'DO') and (substr($SigName,-3) == 'DTS'))
  {
    //IfNewConsole(7);   //3-'DTS',4-координаты ячейки
    $DTS = $SigName;
    $CellName = substr($SigName,0,strlen($SigName)-3); 
    $TS = $CellName.'TS';	//Наличие сигнала TS в БД не контролируем - одна ячейка	
  echo "delete(_{$CellName});\n";
  }
   
}
?>
  
}





