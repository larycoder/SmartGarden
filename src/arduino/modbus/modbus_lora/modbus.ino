//=========================================================================================
//=============================SEND REQUEST TO DEVICE======================================
void send485_command_Read(int id_slave,int command, unsigned int address,unsigned int number){
  int dataModbus[8] = {0};
  unsigned int crc_code = 0;
  //get ID and command
  
  dataModbus[0] = id_slave;
  dataModbus[1] = command;
  // split Address to HI and LO byte
  dataModbus[2] = getHIGHbyte(address);
  dataModbus[3] = getLOWbyte(address);

  dataModbus[4] = getHIGHbyte(number);
  dataModbus[5] = getLOWbyte(number);

  crc_code=crc16_modbus(dataModbus,6);
  dataModbus[6] = getHIGHbyte(crc_code);
  dataModbus[7] = getLOWbyte(crc_code);
//  debugMain.println("----------------------");
  digitalWrite(EN_PIN,HIGH); delay(10);
  for(int i=0;i<8;i++){
    Serial.write(dataModbus[i]);
  }
  digitalWrite(EN_PIN,LOW); delay(10);
   
}
//=========================================================================================
//==================================WRITE TO DEVICE========================================
void send485_command_Write(int id_slave,int command, unsigned int address,unsigned int number,unsigned int output){
  //get ID and command
  int dataModbus[50] = {0};
  unsigned int crc_code = 0, i = 0, buf_out = 0;
  dataModbus[i=0] = id_slave;
  dataModbus[i=i+1] = command;
  // split Address to HI and LO byte
  dataModbus[i=i+1] = getHIGHbyte(address);
  dataModbus[i=i+1] = getLOWbyte(address);

  if(command != 6 ){
    dataModbus[i=i+1] = getHIGHbyte(number);
    dataModbus[i=i+1] = getLOWbyte(number);
  }
  
  if(command == 16 ){
    dataModbus[i=i+1] = 2*number;
    buf_out = getLOWbyte(output);
    for(int j=0;j<number;j++){
      dataModbus[i=i+1] = 0;
      dataModbus[i=i+1] = 0x01 & (buf_out>>j);
    }
  }

  if(command == 6){
    dataModbus[i=i+1] = 0;
    dataModbus[i=i+1] = output;
  }
  
  crc_code=crc16_modbus(dataModbus,i+1);
  dataModbus[i=i+1] = getHIGHbyte(crc_code);
  dataModbus[i=i+1] = getLOWbyte(crc_code);
//  debugMain.println("----------------------");
  
  digitalWrite(EN_PIN,HIGH); delay(10);
  for(int a=0;a<=i;a++){
    Serial.write(dataModbus[a]);
  }
  digitalWrite(EN_PIN,LOW); delay(10);
}

//=========================================================================================
//==================================GET HIGH BYTE==========================================
unsigned int getHIGHbyte(unsigned short input)
{
   return (input >> 8) & 255;
}
//=========================================================================================
//===================================GET LOW BYTE==========================================
unsigned char getLOWbyte(unsigned short input)
{
   return input & 255;
}

//=========================================================================================
//=================================CACULATING CRFC=========================================
unsigned short crc16_modbus(unsigned int * data,unsigned int len)
{
unsigned char c,i=0,flag;
unsigned short crc16=0xffff;
while(i<len) 
    {
    crc16= (crc16^data[i]);
        for(c=0;c<8;c++)
        {
            flag=(crc16 & 0x01);
            crc16= (crc16 >> 1);
            if (flag !=0) {
                crc16=(crc16 ^ 0xa001);
            }
        }
    i++;
    }
    crc16= ((crc16 >> 8) | (crc16 << 8));
return  crc16;    
}
