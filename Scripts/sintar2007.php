<?php

define('DEVELOPMENT_FILE_NAME', 'development.xml');
define('CONFIG_DB','config.ib');
define('SIGNAL_DB','signals.ib');

function parse_args()
{
	global $argv,$development_path,$params;
	if (!isset($params))
		$params = array();
	if (is_string($params))
	{
		$params = explode(',',$params);
		foreach ($params as $k=>$v)
		{
			$params[$k] = trim($v);
			if ($params[$k]=="")
				unset($params[$k]);
		}
	}
	else if (!is_array($params))
		die('Parameters expected as `$params=array("param",...);` or `$params="param,..."`');
	$args = $argv;
	array_shift($args);
	if (count($args) != count($params)+1)
	{
		$err = "USAGE: php ".$argv[0].' -- "<path to development>" ["<script parameters>"...]'."\n<params>\n";
		foreach ($params as $param)
			$err .= "$param\n";
		$err .= "</params>\n";
		die($err);
	}
	$development_path = array_shift($args);
	foreach ($params as $param)
		$GLOBALS[strtolower($param)] = $GLOBALS[$param] = array_shift($args);
}

function read_development_file()
{
	global $development,$development_path,$projects,$signaldbs,$config,$signals,$projects_i,$signaldbs_i;
	$development = simplexml_load_file($development_path.DEVELOPMENT_FILE_NAME);
	$projects_i = $signaldbs_i = $projects = $signaldbs = array();
	$config = $development_path.CONFIG_DB;
	$signals = $development_path.SIGNAL_DB;
	foreach ($development->Projects->Project as $proj)
	{
		$name = xml_decode((string)$proj['name']);
		$projects_i[strtolower($name)] = $projects[$name] = $development_path.$name.'.ib';
	}
	foreach ($development->SignalDBs->SignalDB as $db)
	{
		$name = xml_decode((string)$db['name']);
		$signaldbs_i[strtolower($name)] = $signaldbs[$name] = $development_path.$name.'.ib';
	}
}

function get_db_path($name)
{
	global $projects_i,$signaldbs_i,$config;
	if (strpos($name,':')!==FALSE)
		return $name;
	$name = strtolower(trim($name));
	if (substr($name,-3)=='.ib')
		$name = substr($name,-3);
	if ($name=='config'||$name=='configuration')
		$name = $config;
	else if (isset($projects_i[$name]))
		return $projects_i[$name];
	else if (isset($signaldbs_i[$name]))
		return $signaldbs_i[$name];
	else if (isset($signaldbs_i['db_'.$name]))
		return $signaldbs_i['db_'.$name];
	else
		return FALSE;
}

function xml_decode($str)
{
	return iconv('utf-8','windows-1251',$str);
}

// Database abstraction layer

function db_handle_error()
{
	$msg = ibase_errmsg();
	if (defined('IGNORE_DB_ERRORS') && IGNORE_DB_ERRORS)
		echo "Interbase error: $msg\n";
	else
		die("Interbase error: $msg\n");
}

function db_connect($path)
{
	$lnk = ibase_connect($path, 'SYSDBA', 'masterkey'); // Если указывать кодировку - фигня получается :(
	if ($lnk === FALSE)
		db_handle_error();
	return $lnk;
}

function db_open($name)
{
	$path = get_db_path($name);
	if ($path === FALSE)
		die("Ошибка: не удалось распознать имя проекта или БД сигналов $name\n");
	return db_connect($path);
}

function db_close($link)
{
	if (ibase_close($link)===FALSE)
		db_handle_error();
}

function db_query()
{
	if (is_resource(func_get_arg(0)))
	{
		$r = func_get_arg(0);
		$text = func_get_arg(1);
		$q = ibase_query($r,$text);
	}
	else
		$q = ibase_query(func_get_arg(0));
	if ($q === FALSE)
		db_handle_error();
	return $q;
}

function db_free_result($q)
{
	if (ibase_free_result($q)===FALSE)
		db_handle_error();
}

function db_fetch_assoc($q)
{
	$res = ibase_fetch_assoc($q, IBASE_TEXT);
	if ($res === FALSE)
		return $res;
	foreach ($res as $field=>$val)
		$res[strtolower($field)]=$val;
	return $res;
}

function db_fetch_row($q)
{
	return ibase_fetch_row($q, IBASE_TEXT);
}

function db_fetch($q)
{
	$res = db_fetch_assoc($q);
	if ($res!==FALSE)
		$res=(object)$res;
	return $res;
}

function db_query_first()
{
	if (is_resource(func_get_arg(0)))
	{
		$r = func_get_arg(0);
		$text = func_get_arg(1);
		$q = db_query($r,$text);
	}
	else
		$q = db_query(func_get_arg(0));
	if ($q === FALSE)
		return $q;
	$res = db_fetch($q);
	db_free_result($q);
}

function db_query_all()
{
	if (is_resource(func_get_arg(0)))
	{
		$r = func_get_arg(0);
		$text = func_get_arg(1);
		$q = db_query($r,$text);
		if (func_num_args()>=3)
			$idfield = func_get_arg(2);
	}
	else
	{
		$q = db_query(func_get_arg(0));
		if (func_num_args()>=2)
			$idfield = func_get_arg(1);
	}
	if ($q === FALSE)
		return $q;
	$res = array();
	while ($record = db_fetch($q))
	{
		if (isset($idfield)&&$idfield)
			$res[$record->$idfield] = $record;
		else
			$res[] = $record;
	}
	db_free_result($q);
	return $res;
}

function out1sig_arr($arr, $proto,$n, $comment)
{
  echo "  bool* {$proto}[{$n}] = {    //{$comment}\n";
  $i = 0;
  foreach ($arr as $value)
  {
    if ($i++ > 0)
      echo ",\n";
    echo "   &_{$value}";
  } 
  echo "\n  };\n"; 		
}	

function out2sig_arr($arr)
{
  
  $i = 0;
  foreach ($arr as $value)
  {
    if ($i++ > 0)
      echo "\n";
      echo "    bool _{$value} = false;";
    
  } 
   echo "\n \n"; 		
}	


parse_args();
read_development_file();

?>