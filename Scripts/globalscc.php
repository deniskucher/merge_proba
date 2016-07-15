<?
//��������: ��� ���
$params = "lbd"; 
include "sintar2007.php";
?>
#include "usertype.h"
#include "globals.h"
<?
global $signals;
$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //��� �����������

//�������� ������� DI, DO � PFD, ������������� �������� ���
$qry = "select SC.SigName, SC.TypeName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID
  and  (SC.TypeName='AI' or  SC.TypeName='AO' or  SC.TypeName='PFA'
  or  SC.TypeName='AO'
    or  SC.TypeName='MRI' or  SC.TypeName='MRO')
  order by SC.SigName"; 
$sig_as = ibase_query($sigdb, $qry);

//�������� ������� KO, ������������� �������� ���
$qry = "select K.BASEVAL, SC.SigName, SC.TypeName, \"MAX\" as MX, \"MIN\" as MN from SigCont SC, Controller C, KO K
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and SC.SigName=K.Name
  and  SC.TypeName='KO' order by K.BASEVAL"; 
$sig_ko = ibase_query($sigdb, $qry);
//�������� ���������� ������� ������������� �������� ���
$qry = "select SC.SigName, SC.TypeName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID
  and  (SC.TypeName='DI' or  SC.TypeName='DO' or  SC.TypeName='PFD'
  or  SC.TypeName='PIN')
  order by SC.SigName"; 
$sig_ds = ibase_query($sigdb, $qry);
//�������� ������� KL, ������������� �������� ���
$qry = "select K.BASEVAL, SC.SigName, SC.TypeName from SigCont SC, Controller C, KL K
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and SC.SigName=K.Name
  and  SC.TypeName='KL' order by K.BASEVAL"; 
$sig_kl = ibase_query($sigdb, $qry);
echo "	////// ������� ���������� \n";
while ($sig = ibase_fetch_object($sig_as))
	{ 
	echo "short _{$sig->SIGNAME} = 0;\n"; 
	}
echo "	////// ������� �� \n";
while ($sig = ibase_fetch_object($sig_ko))
    {
    $Val =  round(($sig->BASEVAL*32767)/($sig->MX-$sig->MN));   
    echo "short _{$sig->SIGNAME} = $Val;\n"; 
    }
echo "	////// ������� ���������� \n";
while ($sig = ibase_fetch_object($sig_ds))
	{ 
    echo "bool _{$sig->SIGNAME} = false;\n"; 
	}
echo "	////// ������� KL \n";
while ($sig = ibase_fetch_object($sig_kl))
	{
    $Baseval = $sig->BASEVAL;
    if($Baseval == '1')
		{
		echo "bool _{$sig->SIGNAME} = true;\n"; 
		 }
		 else
		 {
		 echo "bool _{$sig->SIGNAME} = false;\n";
		}
	}
?>

