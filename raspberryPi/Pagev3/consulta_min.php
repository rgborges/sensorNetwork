
<?php 
// definine  host, database, usuario e senha
//$host = "mysql.hostinger.com.br";
//$db   = "u765779207_simu";
//$user = "u765779207_root";
//$pass = "simuroot";
$host = "localhost";
$dbs = "iot";
$user = "monty";
$pass = "SENAI";
//Conecta-se ao banco
$db = new mysqli($host, $user, $pass, $dbs);
//Verifica conexão
if(mysqli_connect_errno())
{
  die('Não foi possível se conectar ao banco['.$db->connect_error.']');

}

$result = $db->query('SELECT * from iot.node;');
echo '<head><link href="static/css/visual.css" rel="stylesheet"></head>';
echo '<TABLE BORDER="3" class="sensor_table">';
echo PHP_EOL;

while($func = $result->fetch_row())
{
 echo'<TR>';
 foreach($func as $i => $value)
{
  echo '<TD>'.$value.'</TD>';
}
echo '</TR>';
}
echo'</TABLE>';
$result->close();

?>
