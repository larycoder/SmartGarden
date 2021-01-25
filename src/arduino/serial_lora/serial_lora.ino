#include "serial_lora.hpp"


/** INIT CODE **/
void setup() {
    Serial.begin(BAUDRATE);
    if(loraInit()) ; //Serial.println("Init lora success");
    else Serial.println("Init lora failed");
}


/** COMMUNICATION CODE **/
void loop() {
    // process data from serial
    if(Serial.available()){
      delay(500); // wait for data writing
      memset(lora_buff, 0, MAX_BUFF); // clean buffer
      uint8_t len = Serial.readBytes(lora_buff, MAX_BUFF);
      loraSend(len);
      //Serial.print("Send data: ");
      //Serial.write(lora_buff, MAX_BUFF);
      //Serial.println("");  
      memset(lora_buff, 0, MAX_BUFF); // clear buffer
    }

    // process data from lora - wait 1 sec
    if(loraWait(1000)){
      memset(lora_buff, 0, MAX_BUFF); // clear buffer
      if(loraRecv()) decryptData();
      //else Serial.println("Error could not get data !!!");
      memset(lora_buff, 0, MAX_BUFF); // clear buffer
    }
}


void decryptData(){
    //Serial.println("Decrypted Data: ");
    int value;
    uint8_t *offset = lora_buff;

    /*
     * Message Rule: 
     * - first 4 bytes: number of bytes will be sent
     * - 1 sensor pack struct:
     *      + Sensor name : 15 bytes
     *      + Sensor ID   : 4  bytes
     *      + Sensor Value: 4  bytes
     *      -> total size : 23 bytes
     */

    // total bytes sended
    memcpy(&value, offset, 4);
    Serial.print("Num Bytes: ");
    Serial.println(value);

    // read all data
    offset += 4;
    int num = value/23;
    for(int i=0; i<num; i++){
        Serial.print("Sensor name  : "); Serial.write(offset, 15); Serial.println(""); offset+= 15;
        Serial.print("Sensor id    : "); memcpy(&value, offset, 4); Serial.println(value); offset+= 4;
        Serial.print("Sensor value : "); memcpy(&value, offset, 4); Serial.println(value); offset+= 4;
    }
    
    //Serial.println("");
}
