#include "serial_lora.hpp"


/** INIT CODE **/
void setup() {
    Serial.begin(BAUDRATE);
    loraInit();
}


/** COMMUNICATION CODE **/
void loop() {
    // wait for incoming signal
    if(Serial.available()){
      readSerial();
    }
}
