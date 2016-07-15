<?
//Параметр: ЛБД УНО
$params = "lbd"; 
include "sintar2007.php";
?>
#include "uobjects.h"
#include "globals.h"
#include "IND.h"

<?
/*
Выборка сигналов: из заданного ЛБД УНО
Сигналы индикационной ячейки: TS(PFD) и DTS(DO)
Сигналы KNMС, KNMG (DI) - по одному на пульт: одинаковы для всех инд. ячеек этого пульта
Имя объекта = имя ячейки (имя пульта + координаты), например, PI12AB05.
*/
?>
void _INDTC_model()
{
  bool _2PMC = false;
  bool _2PMG = false;
   
  _takt_tc->_TAKT(_2PMC,_2PMG);
<?
global $signals, $OldConsName, $Sigs, $KNMC, $KNMG;
$Sigs = array();
$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //Имя контроллера
$OldConsName = '?';
$DTS = $KNMC = $KNMG = ''; 

//Выбираем сигналы DI, DO и PFD, принадлежащие заданной ЛБД
$qry = "select SC.SigName, SC.TypeName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  order by SC.SigName";
$sig_q = ibase_query($sigdb, $qry);
while ($sig = ibase_fetch_object($sig_q))
{
  $SigName = $sig->SIGNAME;
  $TypeName = $sig->TYPENAME;
  //echo " {$SigName} ({$TypeName})\n";
  if (($TypeName == 'DO') and (substr($SigName,-3) == 'DTS'))
  {
    if (NewConsole($SigName, 7))   //3-'DTS',4-координаты ячейки
      OutputConsole();
    $Sigs[] = $SigName;
  }
  elseif (($TypeName == 'DI') and (substr($SigName,-4) == 'KNMC'))
  {
    if (NewConsole($SigName, 8))
      OutputConsole();
    $KNMC = $SigName;
  }  
  elseif (($TypeName == 'DI') and (substr($SigName,-4) == 'KNMG'))
  {
    if (NewConsole($SigName, 8))
      OutputConsole();
    $KNMG = $SigName;
  }  
}
OutputConsole();   //Последний пульт
?>
<?
function NewConsole($SigName, $TailLen)
{
  global $OldConsName;
  $ConsName = substr($SigName, 0, strlen($SigName)-$TailLen);	
  $Res = ($OldConsName != $ConsName);
  if ($Res)
    $OldConsName = $ConsName;
  return $Res;  
}

function OutputConsole()
{
  global $Sigs, $KNMC, $KNMG; 
  foreach ($Sigs as $SigName) 
  {
    $DTS = $SigName;
    $CellName = substr($SigName, 0, strlen($SigName)-3); 
    $TS = $CellName.'TS';	//Наличие сигнала TS в БД не контролируем - одна ячейка	
    echo "  _{$CellName}->_MIG(_{$TS},_{$KNMC},_{$KNMG},_2PMC,_2PMG,_{$DTS});\n";
  }
  array_splice($Sigs, 0);   
  $KNMC = $KNMG = '';
}
?>
}

void _IND()
{
  _INDTC_model();
}

