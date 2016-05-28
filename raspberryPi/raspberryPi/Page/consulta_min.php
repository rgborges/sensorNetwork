<?php 
// definições de host, database, usuário e senha
$host = "mysql.hostinger.com.br";
$db   = "u765779207_simu";
$user = "u765779207_root";
$pass = "simuroot";
// conecta ao banco de dados
$con = mysqli_connect($host, $user, $pass) or trigger_error(mysqli_error(),E_USER_ERROR); 
// seleciona a base de dados em que vamos trabalhar
mysqli_select_db($con, $db);
// cria a instrução SQL que vai selecionar os dados
$query = sprintf("SELECT id, name, local, valor FROM dispositivos");
// executa a query
$dados = mysqli_query($con, $query) or die(mysqli_error($con));
// transforma os dados em um array
$linha = mysqli_fetch_assoc($dados);
// calcula quantos dados retornaram
$total = mysqli_num_rows($dados);?>

<head><link href="static/css/visual.css" rel="stylesheet"></head>
<table class="sensor_table">
    <tr>
        <td class="table_header">Vari&aacute;vel Mensurada</td>
        <td class="table_header">Valor</td>
        <td class="table_header">Localiza&ccedil;&atilde;o</td>
        <td class="table_header">IP</td>
        <td class="table_header">Rede</td>
    </tr> 
    <?php

    if($total >= 0) 
    {
        do {
            ?> 
            <tr>
                <td>
                    <?=$linha['id']?>
                </td> 
                <td>
                    <?=$linha['name']?>
                </td>
                <td>
                    <?=$linha['local']?>
                </td>
                <td>
                    <?=$linha['valor']?>
                </td>
                <td>
                    <?="nada"?></td>
                </tr>
                <?php     }while($linha = mysqli_fetch_assoc($dados));?>
                <? } ?>
            </table>

            <?php header("Content-type: text/html; charset=utf-8");
            mysqli_free_result($dados);
            ?>
