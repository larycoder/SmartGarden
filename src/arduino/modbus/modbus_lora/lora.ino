// Singleton instance of the radio driver
SoftwareSerial ss(LORA_RX_PIN, LORA_TX_PIN);
RH_RF95 rf95(ss);

bool loraInit() {
  if(!rf95.init()) {
      return false;
  } 
  // Defaults after init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on

  // The default transmitter power is 13dBm, using PA_BOOST.
  // If you are using RFM95/96/97/98 modules which uses the PA_BOOST transmitter pin, then 
  // you can set transmitter powers from 5 to 23 dBm:
  //rf95.setTxPower(13, false);
  if(!rf95.setFrequency(LORA_FREQ)) return false;
  return true;
}

MessStatus loraRecv() {
  if(rf95.available()) { // wait until partner send something
    // Should be a message for us now
    if(rf95.recv(lora_buff, &lora_buff_size)) {
      if(rf95.available()) return Avail;
      return End;
    }
    else return Fail;
  }
  return NotAvail;
}

void loraSend() {
  // send message
  rf95.send(lora_buff, lora_buff_size);
  rf95.waitPacketSent();
}
