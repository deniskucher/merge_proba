<?
//���������: ���� � ����������, ����������, ������ ������
$params = "lbd"; 
include "sintar2007.php";
?>

#include "globals.h" 
#include "ZDMSH.h" 

  int TM = 5;  //������ �������
  int SM = 0;	    //������� ������� �������
  bool PM = false;  //������� �������

void  _ZDMSH()
{

<?
global $signals;
$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //��� �����������
//�������� ������� DO � PFD, ������������� �������� ���
$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and (SC.TypeName='DO' or SC.TypeName='PFD')
  order by SC.SigName";
$sig_q = ibase_query($sigdb, $qry);

//����� �������� ����������� 6 �������� ��������� �� �������� ���������:
$sg = array();
$sgr = array();
$sgm = array();
$sy = array();
$syr = array();
$sym = array();

while ($sig = ibase_fetch_object($sig_q))
{
//echo "{$sig->SIGNAME}\n";
   
  $proto = substr($sig->SIGNAME,7);   // $proto - ���������� ������ ����� ��

  if ($proto == 'SG') 
    $sg[] = $sig->SIGNAME;	
  elseif ($proto == 'SGR')
    $sgr[] = $sig->SIGNAME;	
  elseif ($proto == 'SGM')
    $sgm[] = $sig->SIGNAME;	
  elseif ($proto == 'SY')
    $sy[] = $sig->SIGNAME;	
  elseif ($proto == 'SYR')
    $syr[] = $sig->SIGNAME;	
  elseif ($proto == 'SYM')
    $sym[] = $sig->SIGNAME;	
}
$n = count($sgr);
echo "  int n = {$n};        //���-�� �������� \n";
out1sig_arr($sg, 'SG',  $n, '��������� �������');
out1sig_arr($sgr,'SGR', $n, '��������� ������ �������');
out1sig_arr($sgm,'SGM', $n, '��������� �������� �������');
out1sig_arr($sy, 'SY',  $n, '��������� ������');
out1sig_arr($syr,'SYR', $n, '��������� ������ ������');
out1sig_arr($sym,'SYM', $n, '��������� �������� ������');
?>
  if (SM++ == TM)
  {
    SM = 0;
    PM = !PM; 
  }
int i;
 for (i = 0; i < n; ++i) 
  {
      *SG[i] = *SGR[i];
      *SY[i] = *SYR[i];

    if (PM && *SGM[i])
       *SG[i] = true;
    if (PM && *SYM[i])
        *SY[i] = true;
   
  }
}
