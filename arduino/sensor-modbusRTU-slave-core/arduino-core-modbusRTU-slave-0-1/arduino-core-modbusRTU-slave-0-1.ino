/*Programa lê entrada analógica A0 e a transmite em modbus RTU
 * 
 * programador: Rafael Borges Batista
 * e-mail: rafael.eng.auto@gmail.com
 * versão: 0.1 beta 
 *
 *
 *(TESTADO)
 *(Funcionando)  :: Rafael Borges Batista
//inicio
*/
#include <Modbusino.h> //biblioteca Modbus (testada)


ModbusinoSlave modbusino_slave(1); //define objeto modbus e configura ID
uint16_t tab_reg[10];              //aloca 10 REGISTERS de tipo uint16_t

void setup() 
{
    modbusino_slave.setup(115200); //seta a velocidade de transmição
                                   // esta velocidade é mais indicada para a comunicação
                                   //com o ESP82660
}

void loop() 
{
    tab_reg[0] = (uint16_t)analogRead(0); //adiciona a leitura da entrada analógica A0 à tabela de registros
    /* Launch Modbus slave loop with:
       - pointer to the mapping
       - max values of mapping */
    modbusino_slave.loop(tab_reg, 10); //atualiza tabela
}

//fim
