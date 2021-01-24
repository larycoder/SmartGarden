/** LORA **/
bool loraInit(){
  if(!rf95.init()) return false;
  if(!rf95.setFrequency(LORA_FREQ)) return false;
  return true;
}


void loraSend(uint8_t len){
  rf95.send(lora_buff, len);
  rf95.waitPacketSent();  
}


bool loraWait(int timeout){
  return rf95.waitAvailableTimeout(timeout);
}


bool loraRecv(){
  uint8_t len = MAX_BUFF;
  return rf95.recv(lora_buff, &len);
}


/** SERIAL MODE **/
/*
 * There are 6 mode:
 * - clean buff
 * - set buff
 * - read buff
 * - check lora available
 * - send lora signal
 * - recv lora signal
 * 
 */
uint8_t* getBuff(uint8_t op){
    switch(op){
    case LORA_BUFF:
      return lora_buff;
    case SERIAL_BUFF:
      return serial_buff;
    case FREE_BUFF:
      return f_buff;
    default:
      return NULL;
  }
}


void cleanBuff(){
  // read type of buff
  uint8_t op = Serial.read();
  uint8_t* buff = getBuff(op);
  if(buff==NULL){
    memset(lora_buff,0,MAX_BUFF);  
    memset(serial_buff,0,MAX_BUFF); 
    memset(f_buff,0,MAX_BUFF); 
  } else{
    memset(buff, 0, MAX_BUFF);
  }
}


uint8_t setBuff(){
  uint8_t op = Serial.read();
  uint8_t* buff = getBuff(op);
  if(buff==NULL) return 0x01; // could get buff
  
  uint8_t len = Serial.read();
  uint8_t t_buff[len];
  delay(BUFF_WAIT); // wait for buff send
  uint8_t r_len = Serial.readBytes(t_buff, len);
  if(r_len != len) return 0x02; // could not read enough data
  
  memcpy(buff, t_buff, r_len);
  return 0x00;
}


void readBuff(){
  uint8_t* buff = getBuff(Serial.read());
  Serial.write(f_buff[0]); // send len of buff
  Serial.write(buff, f_buff[0]);
}


void sendLora(){
  uint8_t len = Serial.read();
  loraSend(len);
}


void readSerial(){
  // read mode
  uint8_t mode = Serial.read();
  switch(mode){
    case CLEAN_BUFF:
      cleanBuff();
      Serial.write(0x00); // return 0
      break;
    case SET_BUFF:
      Serial.write(setBuff());
      break;
    case READ_BUFF:
      readBuff(); // do not need return
      break;
    case LORA_AVAI:
      Serial.write(loraWait(LORA_WAIT)?L_AVAIL:L_NAVAIL);
      break;
    case LORA_SEND:
      sendLora();
      Serial.write(0x00);
      break;
    case LORA_RECV:
      Serial.write(loraRecv()?0x00:0x01); // 0 mean received
      break;
    default:
      while(Serial.available()) Serial.read();
      break;
  }  
}
