<?
//Параметры: путь к разработке, контроллер, период задачи
$params = "lbd"; 
include "sintar2007.php";
?>

#include <unistd.h>
#include <cdsface.h>
#include <cdshead.h>

#include "globals.h"
#include "SigChange.h"
#include "typeBPO.h"
<?
global $signals;
$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //Имя контроллера
//Выбираем сигналы, принадлежащие заданной ЛБД
$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and  SC.TypeName='DI'  order by SC.SigName";
$sig_di   =ibase_query($sigdb, $qry);
$sig_di_p =ibase_query($sigdb, $qry);
$sig_di_r =ibase_query($sigdb, $qry);
$sig_di_w =ibase_query($sigdb, $qry);

$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and SC.TypeName='DO'  order by SC.SigName";
$sig_do   =ibase_query($sigdb, $qry);
$sig_do_p =ibase_query($sigdb, $qry);
$sig_do_r =ibase_query($sigdb, $qry);
$sig_do_w =ibase_query($sigdb, $qry);

$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and  SC.TypeName='KL' order by SC.SigName";
$sig_kl   =ibase_query($sigdb, $qry);
$sig_kl_p =ibase_query($sigdb, $qry);
$sig_kl_r =ibase_query($sigdb, $qry);
$sig_kl_w =ibase_query($sigdb, $qry);

$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and  SC.TypeName='PIN'  order by SC.SigName";
$sig_pin   =ibase_query($sigdb, $qry);
$sig_pin_p =ibase_query($sigdb, $qry);
$sig_pin_r =ibase_query($sigdb, $qry);
$sig_pin_w =ibase_query($sigdb, $qry);

$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and  SC.TypeName='PFD' order by SC.SigName";
$sig_pfd   =ibase_query($sigdb, $qry);
$sig_pfd_p =ibase_query($sigdb, $qry);
$sig_pfd_r =ibase_query($sigdb, $qry);
$sig_pfd_w =ibase_query($sigdb, $qry);

$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and SC.TypeName='AI'  order by SC.SigName";
$sig_ai   =ibase_query($sigdb, $qry);
$sig_ai_p =ibase_query($sigdb, $qry);
$sig_ai_r =ibase_query($sigdb, $qry);
$sig_ai_w =ibase_query($sigdb, $qry);

$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and  SC.TypeName='PFA' order by SC.SigName";
$sig_pfa   =ibase_query($sigdb, $qry);
$sig_pfa_p =ibase_query($sigdb, $qry);
$sig_pfa_r =ibase_query($sigdb, $qry);
$sig_pfa_w =ibase_query($sigdb, $qry);

$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and  SC.TypeName='KO'  order by SC.SigName";
$sig_ko   =ibase_query($sigdb, $qry);
$sig_ko_p =ibase_query($sigdb, $qry);
$sig_ko_r =ibase_query($sigdb, $qry);
$sig_ko_w =ibase_query($sigdb, $qry);

$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and  SC.TypeName='AO'  order by SC.SigName";
$sig_ao   =ibase_query($sigdb, $qry);
$sig_ao_p =ibase_query($sigdb, $qry);
$sig_ao_r =ibase_query($sigdb, $qry);
$sig_ao_w =ibase_query($sigdb, $qry);

$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and  SC.TypeName='MRI'  order by SC.SigName";
$sig_mri   =ibase_query($sigdb, $qry);
$sig_mri_p =ibase_query($sigdb, $qry);
$sig_mri_r =ibase_query($sigdb, $qry);
$sig_mri_w =ibase_query($sigdb, $qry);

$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and  SC.TypeName='MRO'  order by SC.SigName";
$sig_mro   =ibase_query($sigdb, $qry);
$sig_mro_p =ibase_query($sigdb, $qry);
$sig_mro_r =ibase_query($sigdb, $qry);
$sig_mro_w =ibase_query($sigdb, $qry);

while ($sig = ibase_fetch_object($sig_ai))
 {
    echo "  int *p{$sig->SIGNAME};\n";
}
while ($sig = ibase_fetch_object($sig_ao))
 {
    echo "  int *p{$sig->SIGNAME};\n";
}
while ($sig = ibase_fetch_object($sig_pfa))
 {
    echo "  int *p{$sig->SIGNAME};\n";
}
while ($sig = ibase_fetch_object($sig_ko))
 {
    echo "  int *p{$sig->SIGNAME};\n";
}
while ($sig = ibase_fetch_object($sig_mri))
 {
    echo "  int *p{$sig->SIGNAME};\n";
}
while ($sig = ibase_fetch_object($sig_mro))
 {
    echo "  int *p{$sig->SIGNAME};\n";
}
 while ($sig = ibase_fetch_object($sig_di))
 {
/*	if((substr($sig->SIGNAME,-4) == 'KNMC')
  or (substr($sig->SIGNAME,-4) == 'KNMG'))*/
       echo "  char *p{$sig->SIGNAME};\n";
}
 while ($sig = ibase_fetch_object($sig_do))
 {
//	if ((substr($sig->SIGNAME,-3) == 'DTS'))
       echo "  char *p{$sig->SIGNAME};\n";
}
 while ($sig = ibase_fetch_object($sig_pfd))
 {
//	if(substr($sig->SIGNAME,-2) == 'TS')
       echo "  char *p{$sig->SIGNAME};\n";
 }
 while ($sig = ibase_fetch_object($sig_kl))
 {
    echo "  char *p{$sig->SIGNAME};\n";
}
while ($sig = ibase_fetch_object($sig_pin))
 {
    echo "  char *p{$sig->SIGNAME};\n";
}

 ?>

  void Init_P()
 {
<?
$n=0; 
echo "	////// сигналы AI \n";
 while ($sig = ibase_fetch_object($sig_ai_p))
  {
  echo "  GET_REF(p{$sig->SIGNAME},int,DEF_AI_BY_ID,{$n});\n";
  $n++;
  }
  $n=0; 
  echo "	////// сигналы AO \n";
 while ($sig = ibase_fetch_object($sig_ao_p))
  {
  echo "  GET_REF(p{$sig->SIGNAME},int,DEF_AO_BY_ID,{$n});\n";
  $n++;
  }
  $n=0; 
  echo "	////// сигналы PFA \n";
 while ($sig = ibase_fetch_object($sig_pfa_p))
  {
  echo "  GET_REF(p{$sig->SIGNAME},int,DEF_PFA_BY_ID,{$n});\n";
  $n++;
  }
  $n=0; 
  echo "	////// сигналы KO \n";
 while ($sig = ibase_fetch_object($sig_ko_p))
  {
  echo "  GET_REF(p{$sig->SIGNAME},int,DEF_KO_BY_ID,{$n});\n";
  $n++;
  }
  $n=0; 
  echo "	////// сигналы MRI \n";
 while ($sig = ibase_fetch_object($sig_mri_p))
  {
  echo "  GET_REF(p{$sig->SIGNAME},int,DEF_MRI_BY_ID,{$n});\n";
  $n++;
  }
  $n=0; 
  echo "	////// сигналы MRO \n";
 while ($sig = ibase_fetch_object($sig_mro_p))
  {
  echo "  GET_REF(p{$sig->SIGNAME},int,DEF_MRO_BY_ID,{$n});\n";
  $n++;
  }
 $n=0; 
 echo "	////// сигналы DI \n";
 while ($sig = ibase_fetch_object($sig_di_p))
  {
 // if((substr($sig->SIGNAME,-4) == 'KNMC')
 // or (substr($sig->SIGNAME,-4) == 'KNMG'))
  echo "  GET_REF(p{$sig->SIGNAME},char,DEF_DI_BY_ID,{$n});\n";
  $n++;
  }
 $n=0; 
 echo "	////// сигналы DO \n";
 while ($sig = ibase_fetch_object($sig_do_p))
  {
  //if ((substr($sig->SIGNAME,-3) == 'DTS'))
  echo "  GET_REF(p{$sig->SIGNAME},char,DEF_DO_BY_ID,{$n});\n";
  $n++;
  }
 $n=0; 
 echo "	////// сигналы PFD \n";
 while ($sig = ibase_fetch_object($sig_pfd_p))
  {
 // if(substr($sig->SIGNAME,-2) == 'TS')
  echo "  GET_REF(p{$sig->SIGNAME},char,DEF_PFD_BY_ID,{$n});\n";
  $n++;
  }
  $n=0; 
  echo "	////// сигналы KL \n";
 while ($sig = ibase_fetch_object($sig_kl_p))
  {
  echo "  GET_REF(p{$sig->SIGNAME},char,DEF_KL_BY_ID,{$n});\n";
  $n++;
  }
  $n=0; 
  echo "	////// сигналы PIN \n";
 while ($sig = ibase_fetch_object($sig_pin_p))
  {
  echo "  GET_REF(p{$sig->SIGNAME},char,DEF_PIN_BY_ID,{$n});\n";
  $n++;
  }
 ?>
  };

  void Read_Sig()
  {
<?
echo "	////// сигналы AI \n";
  while ($sig = ibase_fetch_object($sig_ai_r))
    {
    echo "  _{$sig->SIGNAME}=(short)*p{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы AO \n";
  while ($sig = ibase_fetch_object($sig_ao_r))
    {
    echo "  _{$sig->SIGNAME}=(short)*p{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы PFA \n";
  while ($sig = ibase_fetch_object($sig_pfa_r))
    {
    echo "  _{$sig->SIGNAME}=(short)*p{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы KO \n";
  while ($sig = ibase_fetch_object($sig_ko_r))
    {
    echo "  _{$sig->SIGNAME}=(short)*p{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы MRI \n";
  while ($sig = ibase_fetch_object($sig_mri_r))
    {
    echo "  _{$sig->SIGNAME}=(short)*p{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы MRO \n";
  while ($sig = ibase_fetch_object($sig_mro_r))
    {
    echo "  _{$sig->SIGNAME}=(short)*p{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы DI \n";
  while ($sig = ibase_fetch_object($sig_di_r))
    {
	/*if((substr($sig->SIGNAME,-4) == 'KNMC')
  or (substr($sig->SIGNAME,-4) == 'KNMG'))*/
       echo "  _{$sig->SIGNAME}=(bool)*p{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы DO \n";
  while ($sig = ibase_fetch_object($sig_do_r))
    {
    echo "  _{$sig->SIGNAME}=(bool)*p{$sig->SIGNAME};\n";
	}
  echo "	////// сигналы PFD \n";
  while ($sig = ibase_fetch_object($sig_pfd_r))
    {
    echo "  _{$sig->SIGNAME}=(bool)*p{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы KL \n";
  while ($sig = ibase_fetch_object($sig_kl_r))
    {
    echo "  _{$sig->SIGNAME}=(bool)*p{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы PIN \n";
  while ($sig = ibase_fetch_object($sig_pin_r))
    {
    echo "  _{$sig->SIGNAME}=(bool)*p{$sig->SIGNAME};\n";
	}

?>
  };
  void Write_Sig()
  {
<?
	echo "	////// сигналы AI \n";
	while ($sig = ibase_fetch_object($sig_ai_w))
    {
    echo "  *p{$sig->SIGNAME}=(int)_{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы AO \n";
	while ($sig = ibase_fetch_object($sig_ao_w))
    {
    echo "  *p{$sig->SIGNAME}=(int)_{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы PFA \n";
	while ($sig = ibase_fetch_object($sig_pfa_w))
    {
    echo "  *p{$sig->SIGNAME}=(int)_{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы KO \n";
	while ($sig = ibase_fetch_object($sig_ko_w))
    {
    echo "  *p{$sig->SIGNAME}=(int)_{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы MRI \n";
	while ($sig = ibase_fetch_object($sig_mri_w))
    {
    echo "  *p{$sig->SIGNAME}=(int)_{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы MRO \n";
	while ($sig = ibase_fetch_object($sig_mro_w))
    {
    echo "  *p{$sig->SIGNAME}=(int)_{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы DI \n";
	while ($sig = ibase_fetch_object($sig_di_w))
    {
    echo "  *p{$sig->SIGNAME}=(char)_{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы DO \n";
	while ($sig = ibase_fetch_object($sig_do_w))
    {
    echo "  *p{$sig->SIGNAME}=(char)_{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы PFD \n";
	while ($sig = ibase_fetch_object($sig_pfd_w))
    {
	echo "  *p{$sig->SIGNAME}=(char)_{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы KL \n";
	while ($sig = ibase_fetch_object($sig_kl_w))
    {
    echo "  *p{$sig->SIGNAME}=(char)_{$sig->SIGNAME};\n";
	}
	echo "	////// сигналы PIN \n";
	while ($sig = ibase_fetch_object($sig_pin_w))
    {
    echo "  *p{$sig->SIGNAME}=(char)_{$sig->SIGNAME};\n";
	}
?>
  };
