<?
//���������: ���� � ����������, ����������, ������ ������
$params = "lbd,takt"; 
include "sintar2007.php";
?>

#include "globals.h" 
#include "TABTS.h" 

    int SMC = 0;		 //������� ������� ��������
    bool PMC = false;		 //������� ��������
    int SMG = 0;		 //������� ������� �������
    bool PMG  =false;	 	 //������� �������

<?
global $signals;
$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //��� �����������
//�������� ������� DO � PFD, ������������� �������� ���
$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and (SC.TypeName='DI' or SC.TypeName='DO' or SC.TypeName='PFD')
  order by SC.SigName";
$sig_q = ibase_query($sigdb, $qry);

//��� ��������� ����� ��  4 �������  �� ��:
$ts = array();		//��������� ������������
$dts = array();		//������ �� �����
$knmc = '';		//������ ��������
$knmg = '';		//������ �������
// 4 �������� ��������� ��
$pts  = array();
$prmc = array();
$prmg = array();
$prr  = array();


while ($sig = ibase_fetch_object($sig_q))
{
//echo "{$sig->SIGNAME}\n";
  
  $tsname = substr($sig->SIGNAME,0,8);

  $proto = substr($sig->SIGNAME,8);   // $proto - ���������� ������ ����� ��

  if ($proto == 'TS')
   {   
   $ts[]   = $sig->SIGNAME;
   $pts[]  = str_pad($tsname, 11, 'PTS');	
   $prmc[] = str_pad($tsname, 12, 'PRMC');
   $prmg[] = str_pad($tsname, 12, 'PRMG');
   $prr[]  = str_pad($tsname, 12, 'PRR');
   }	
  elseif ($proto == 'DTS')
    $dts[] = $sig->SIGNAME;	

  elseif ($proto == 'KNMC')
    $knmc = $sig->SIGNAME;	
  elseif ($proto == 'KNMG')
    $knmg = $sig->SIGNAME;	
 	
}
$n = count($ts);

out2sig_arr($pts);
out2sig_arr($prmc);
out2sig_arr($prmg);
out2sig_arr($prr);

echo "    int TT = {$takt};     //������ ������	\n";

?>

  void  _TABTSS()
 {

    int TMC = 500/TT;	 //������ ��������
    int TMG = 2000/TT;	 //������ �������

<?

echo "  int n = {$n};        //���-��  ��������� �� \n";

out1sig_arr($ts, 'TS',$n, '��������� ��');
out1sig_arr($dts, 'DTS',$n, '������ �� �����');

echo "   bool KNMC = _{$knmc};  //������ �������� \n";
echo "   bool KNMG = _{$knmg};  //������ ������� \n";

out1sig_arr($pts, 'PTS',  $n, '������� i-�� ��������� ��');
out1sig_arr($pts, 'PRMC', $n, '������� �������� i-�� ��������� ��');
out1sig_arr($pts, 'PRMG', $n, '������� ������� i-�� ��������� ��');
out1sig_arr($pts, 'PRR',  $n, '������� ������� �������� i-�� ��������� ��');

?>

int i;
 
  if (SMC++ == TMC)
  {
    SMC = 0;
    PMC = !PMC;
  }

  if (SMG++ == TMG)
  {
    SMG = 0;
    PMG = !PMG;
   }

 for (i = 0; i < n; ++i) 
  {
     if (KNMC || *PRR[i]) 
       { if (*TS[i])
            { *DTS[i]=*PRR[i]=*PTS[i]=true; }
	
          else 
		{
		 if (*PTS[i])
			{ *PRMG[i]=true; *PRR[i]=*PRMC[i]=false; *DTS[i]=PMG; }
 		  else  *PTS[i]=*DTS[i]=*PRMG[i]=*PRMC[i]=false;
		}
       }
     else
     { //1
      if (!*PRMG[i] && (*PRMC[i] || *TS[i]))
		{ *PTS[i]=*PRMC[i]=true; *PRMG[i]=*PRR[i]=false; *DTS[i]=PMC; }
	else
        { //2
         if ((!*PRMG[i] && !*PRMC[i] && !*TS[i]) || (*PRMG[i] && KNMG))
		*PTS[i]=*DTS[i]=*PRMG[i]=*PRMC[i]=false;
	  else
	    { //3
             if (*TS[i])
	        { *PTS[i]=*PRMC[i]=true; *PRMG[i]=*PRR[i]=false; *DTS[i]=PMC; }
               else
                { *PRMG[i]=true; *PRR[i]=*PRMC[i]=false; *DTS[i]=PMG; }
            } //3
	}//2

     }//1

  }
}


