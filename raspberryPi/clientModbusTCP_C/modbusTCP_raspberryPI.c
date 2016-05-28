/*
Cliente modbus TCP IP utilizando a biblioteca libmodbus no Raspberry Pi modelo 1
escrito por Rafael Borges Batista .

email: rafael.eng.auto@gmail.com

Dependências:

libmodbus 
modbus-dev 
gcc


comando de compilação via terminal

gcc programa.c -o objeto pkg-config --cflags ---libs libmodbus`

*/

#include <modbus.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


const char *ip = "192.168.1.104";
const char *port = "502";
int main(int argc, char **argv)
{
    modbus_t *mb;
    uint16_t tab_reg[32];
    int rc;
    int i;
    
    mb = modbus_new_tcp(ip, port);
    
    
        if(mb == NULL)
        {
            fprintf(stderr, "Nao foi possivel alocar libmodbus \n");
            return -1;
        }
        if(modbus_connect(mb) == -1)
        {
            fprintf(stderr, "Falha na conexao \n");
            modbus_free(mb);
            return -1;
        }
        
        //Lê 5 registradores a partir do endereço 0
         rc == modbus_read_registers(mb, 0, 5, tab_reg);
         
         if(rc == -1)
         {
             printf("error \n");
             modbus_free(mb);
             return -1;
         }
         
 for(i = 0; i < rc; i++)
 {
     printf("reg[%d] = %d (0x%X) \n", i, tab_reg[i], tab_reg[i]);
 }
 
   modbus_close(mb);
   modbus_free(mb);
   
   
    return 0;
}