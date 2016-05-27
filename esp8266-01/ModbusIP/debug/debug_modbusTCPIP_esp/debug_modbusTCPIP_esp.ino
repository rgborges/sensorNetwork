/*
  Modbus-Arduino Example - Test Holding Register (Modbus IP ESP8266)
  Read Analog sensor on Pin ADC (ADC input between 0 ... 1V)
  Copyright by André Sarmento Barbosa
  http://github.com/andresarmento/modbus-arduino
*/

/*
 Rafael Borges
  Será padronizado para esse projeto 
  SSID =  IOTSENAI2016
  Password = IotModbusPro


To get help on usage run the following command:
modpoll -h
To retrieve continuously 10 Modbus holding registers starting from reference 500 of slave ID number 5 with Modbus RTU at 19200 baud, no parity on COM1 run:
modpoll -b 19200 -p none -m rtu -a 3 -r 500 -c 10 COM1
To retrieve once 5 floating point values starting from reference 100 with Modbus/TCP from slave device with IP 10.0.0.100:
modpoll -m tcp -t4:float -r 100 -c 5 -1 10.0.0.100

*/

#include <ESP8266WiFi.h>
#include <Modbus.h>
#include <ModbusIP_ESP8266.h>
#define _ssid  "TP-LINK_3E50"
#define _password  "02184319"
#define status_pin 2


//Modbus Registers Offsets (0-9999)
const int SENSOR_IREG = 100;

//ModbusIP object
ModbusIP mb;

long ts;

void setup() 
{
    Serial.begin(115200);   // velocidade indicada para o esp8266
   // pinMode(status_pin,OUTPUT);
    //Config Modbus IP
    mb.config(_ssid, _password);
    //espera até se conectar na rede wireless
    while (WiFi.status() != WL_CONNECTED)
     {
        delay(250);
        Serial.print(".");
     //   digitalWrite(status_pin, 1);
        delay(250);
       // digitalWrite(status_pin, 0);
     }
    //digitalWrite(status_pin, 1);
    Serial.println("");
    Serial.println("WiFi connected");  
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    // Add SENSOR_IREG register - Use addIreg() for analog Inputs
    mb.addIreg(SENSOR_IREG);

    ts = millis();
}

void loop() 
{
   //Call once inside loop() - all magic here
   mb.task();

   //Read each two seconds
   if (millis() > ts + 2000) {
       ts = millis();
       //Setting raw value (0-1024)
       mb.Ireg(SENSOR_IREG,analogRead(A0)); //debug var 
   }
}
