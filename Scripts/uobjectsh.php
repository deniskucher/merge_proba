<?
//��������: ��� ���
$params = "lbd"; 
include "sintar2007.php";
?>
#ifndef uObjectH
#define uObjectH
#include "usertype.h"
#include "uclasses.h"

<?
global $signals, $OldConsName, $SigName;

$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //��� �����������
$OldConsName = '?';
$DTS = $KNMC = $KNMG = ''; 

//�������� ������� DI, DO � PFD, ������������� �������� ���
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
    //IfNewConsole(7);   //3-'DTS',4-���������� ������
    $DTS = $SigName;
    $CellName = substr($SigName,0,strlen($SigName)-3); 
    $TS = $CellName.'TS';	//������� ������� TS � �� �� ������������ - ���� ������	
  echo "extern _TMIG *_{$CellName};\n";
  }
  
 
}
?>

extern _TTAKT *_takt_tc;

extern void InitObjects();
extern void DeleteObjects();

#endif


