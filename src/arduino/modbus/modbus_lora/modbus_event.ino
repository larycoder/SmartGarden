
//=====================================================================
//============================SETUP====================================
void modbusInit() {
  Serial.begin(19200);
  pinMode(EN_PIN,OUTPUT);
}

//==============================================================================
//==============================DATA RETRIEVE===================================
void modbusRun() {
  //-------------------------------------------------------------------
  //------------------------SENDING REQUEST----------------------------
  send485_command_Read(id_slave,cmd, 0,10);
  delay(300);

  //-------------------------------------------------------------------
  //------------------------TRIGGER EVENT------------------------------
  serialEvent();
  
  //-------------------------------------------------------------------
  //---------------------ANALYSIS RECEIVING DATA-----------------------
  while(flagProcess==1){
    if((buff[0] == id_slave) && buff[1] == cmd){
      int length_data = buff[2];
      int crc_code_check = crc16_modbus(buff,buff[2]+3);
      int crc_HIGH = getHIGHbyte(crc_code_check);
      int crc_LOW = getLOWbyte(crc_code_check);
      if((crc_HIGH == buff[buff[2]+3]) && (crc_LOW == buff[buff[2]+4])){
        // do something 
        splitData(buff,processData);
        
        NH4N = NH4N_calculate(processData);
        PH = PH_calculate(processData);
        TEMPARATURE = TEMP_calculate(processData);
        Kion = Kion_calculate(processData);
        //send485_command_Write(id_slave,16, 10,8,1);
      }//end crc
    }//end if id_slave
     
    
    //-------------------------------------------------------------------
    //-----------------------------DELETE--------------------------------
    for(int i=0;i<=index;i++){
      buff[i] = 0;
    }
    index = 0;
    flagProcess = 0;  
    //-------------------------------------------------------------------
     
  }//end while process
  
}//end loop

//=====================================================================
//=========================IRQ HANDLE==================================
void serialEvent(){
  while(Serial.available()){
    int data = Serial.read();
    if((index >= 2) && (index < MaxIndex)){
      buff[index] = data;
      index++;
    }//end if
    if((data == id_slave) && (index == 0)){
      buff[0] = data;
      index++;
    }//end if
    if((data == cmd) && (index == 1)){
      buff[1] = data;
      index++;
    }//end if
    if(((buff[2]+5)==index)){
      flagProcess = 1;
    }//end if
  }//end while 
}
