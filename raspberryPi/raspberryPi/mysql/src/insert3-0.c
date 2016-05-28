#include <my_global.h>
#include <mysql.h>

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

int main(int argc, char **argv)
{
  MYSQL *con = mysql_init(NULL);
  
  if (con == NULL) 

  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }  

  if (mysql_real_connect(con, "localhost", "monty", "SENAI", 
          "iot", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    
  
  if (mysql_query(con, "DROP TABLE IF EXISTS node")) {
      finish_with_error(con);
  }
  
  if (mysql_query(con, "CREATE TABLE node(id TEXT,value INT,ip TEXT,place TEXT)")) {      
      finish_with_error(con);
  }
  
  if (mysql_query(con, "INSERT INTO node VALUES('teste02C',1023,'0.0.0.1', 'Sao Paulo')")) {
      finish_with_error(con);
  }
  /*
  if (mysql_query(con, "INSERT INTO Cars VALUES(2,'Mercedes',57127)")) {
      finish_with_error(con);
  }
  
  if (mysql_query(con, "INSERT INTO Cars VALUES(3,'Skoda',9000)")) {
      finish_with_error(con);
  }
  
  if (mysql_query(con, "INSERT INTO Cars VALUES(4,'Volvo',29000)")) {
      finish_with_error(con);
  }
  
  if (mysql_query(con, "INSERT INTO Cars VALUES(5,'Bentley',350000)")) {
      finish_with_error(con);
  }
  
  if (mysql_query(con, "INSERT INTO Cars VALUES(6,'Citroen',21000)")) {
      finish_with_error(con);
  }
  
  if (mysql_query(con, "INSERT INTO Cars VALUES(7,'Hummer',41400)")) {
      finish_with_error(con);
  }
  
  if (mysql_query(con, "INSERT INTO Cars VALUES(8,'Volkswagen',21600)")) {
      finish_with_error(con);
  }
*/
  mysql_close(con);
  exit(0);
}
