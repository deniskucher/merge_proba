<?
//Параметр: 
$params = "Proj"; 
include "sintar2007.php";
?>

#include "globalpr.h"

<?
$Types = array(8 => 'float', 'short', 'int', 'unsigned short', 'unsigned char', 'bool'); 
//Выбираем переменные из программного проекта
$projdb = ibase_connect($Proj);
$qry = "select OBJECTNAME, VARVALUE, TYPEID from OBJECT  
  where (CATEGORY = 1) and (TYPEID < 14) and (VARVALUE != '') and (VARVALUE is not NULL)
  and (PROJECTID is NULL)  order by OBJECTNAME";
$proj_q = ibase_query($projdb, $qry);
while ($sig = ibase_fetch_object($proj_q))
   echo "  {$Types[$sig->TYPEID]} _{$sig->OBJECTNAME} = {$sig->VARVALUE};\n";
?>
<?
echo "\n";
