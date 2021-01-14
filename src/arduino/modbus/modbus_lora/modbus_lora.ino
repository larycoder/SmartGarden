#include "header.hpp"
#include "lora.hpp"
#include "modbus.hpp"

void setup() {
  modbusInit();
  loraInit();
}

void loop() {
  switch(loraRecv()){
    case NotAvail:
      // TODO: do something when lora not available
      break;
    case Fail:
      // TODO: do something when lora failing to read data
      break;
    case End:
      // TODO: do something when lora done reading data
      //modbusRun();
      delay(300); // waiting for modbus process
      processMess();
      loraSend(); 
      break;
    case Avail:
      // TODO: do something when lora message available
      break;
    default:
      // TODO: do something when
      break;
  }
  
}

void processMess(){
    // preprocess data
    char data[lora_buff_size];
    memcpy(data, lora_buff, lora_buff_size);
    memset(lora_buff, 0, lora_buff_size);
    Serial.println((char*)data);
    
    // TODO: process message
    /*
     * Message Rule: 
     * - first 4 bytes: number of bytes will be sent
     * - 1 sensor pack struct:
     *      + Sensor name : 15 bytes
     *      + Sensor ID   : 4  bytes
     *      + Sensor Value: 4  bytes
     *      -> total size : 23 bytes
     */
     
    // DEMO message
    uint8_t *offset= lora_buff;
    int value = 23*4;
    memcpy(offset, &value, 4);
    offset += 4;

    value = 0;
    memcpy(offset, "PH", 3);
    memcpy(offset+15, &value, 4);
    memcpy(offset+19, &PH, 4);    
    offset += 23;

    value = 1;
    memcpy(offset, "TEMPARATURE", 12);
    memcpy(offset+15, &value, 4);
    memcpy(offset+19, &TEMPARATURE, 4);
    offset += 23;

    value = 2;
    memcpy(offset, "NH4N", 5);
    memcpy(offset+15, &value, 4);
    memcpy(offset+19, &NH4N, 4);
    offset += 23;

    value = 3;
    memcpy(offset, "Kion", 5);
    memcpy(offset+15, &value, 4);
    memcpy(offset+19, &Kion, 4);
}
