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
      modbusRun();
      delay(1000); // waiting for modbus process
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
    char *offset= lora_buff;
    memcpy(offset, 23*4, 4);
    offset += 4;

    memcpy(offset, "PH", 3);
    memcpy(offset+15, 0, 4);
    memcpy(offset+19, &PH, 4);    
    offset += 23;

    memcpy(offset, "TEMPARATURE", 12);
    memcpy(offset+15, 1, 4);
    memcpy(offset+19, &TEMPARATURE, 4);
    offset += 23;

    memcpy(offset, "NH4N", 5);
    memcpy(offset+15, 1, 4);
    memcpy(offset+19, &NH4N, 4);
    offset += 23;

    memcpy(offset, "Kion", 5);
    memcpy(offset+15, 1, 4);
    memcpy(offset+19, &Kion, 4);
}
