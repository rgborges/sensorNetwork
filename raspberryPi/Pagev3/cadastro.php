<?php 
$host = "mysql.hostinger.com.br";
$db   = "banco";
$user = "user";
$pass = "pass";
$con = mysqli_connect($host, $user, $pass) or trigger_error(mysqli_error(),E_USER_ERROR); 
mysqli_select_db($con, $db);
$dimmer	= $_POST ["dimmer"]; //variavel do dimmer
$query = sprintf("INSERT INTO `tabela` (`coluna`) VALUES '$dimmer'"); //acertar query sql
$dados = mysqli_query($con, $query) or die(mysqli_error($con));?>
