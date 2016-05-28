
#include <my_global.h> 
#include <mysql.h>


const char *user = "monty";
const char *password = "SENAI";
const char *host = "localhost";
const char *db = "iot";
void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s \n", mysql_error(con));
  mysql_close(con);
  exit(1);
}


int main(int argc, char **argv)
{
 MYSQL *con = mysql_init(NULL);

 if(con == NULL)
{
  fprintf(stderr, "%s \n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

// Conecta-se com o banco 
if (mysql_real_connect(con, host, user, password, db, 0, NULL, 0))
{
   finish_with_error(con);
}

/*
 //Se a tabela existir apaga-se ela 
 if(mysql_query(con, "DROP TABLE IF EXISTS node"))
{
  finish_with_error(con);
}

if(mysql_query(con, "CREATE TABLE node(ID int, value int, place char(20), ip char
(20)")
{
 finish_with_error(con);
}

*/



//Escreve algo na tabela 

if(mysql_query(con, "INSERT INTO node VALUES('teste02C', 1022, 'Cotia', '0.0.0.1')"))
{
  finish_with_error(con);
}
 printf(" %s  \n", "OK");
 mysql_close(con);
 return 0;
}
