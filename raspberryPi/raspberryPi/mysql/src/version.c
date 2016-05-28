#include <my_global.h>
#include <mysql.h>


int main(int argc, char **atgv)
{
  printf("Versao MySQL Client : %s \n", mysql_get_client_info());

 return 0;
}
