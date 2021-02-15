
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

  // process event
  serialEvent();
  
  //-------------------------------------------------------------------
  //---------------------ANALYSIS RECEIVING DATA-----------------------
  while(flagProcess==1){
    //debugMain.println("PROCESS:");
    if((buff[0] == id_slave) && buff[1] == cmd){
      int length_data = buff[2];
      int crc_code_check = crc16_modbus(buff,buff[2]+3);
      int crc_HIGH = getHIGHbyte(crc_code_check);
      int crc_LOW = getLOWbyte(crc_code_check);
      //debugMain.print("CRC_HIGH:"); debugMain.println(crc_HIGH,HEX);
      //debugMain.print("CRC_LOW:");debugMain.println(crc_LOW,HEX);
      if((crc_HIGH == buff[buff[2]+3]) && (crc_LOW == buff[buff[2]+4])){
        // do something 
        //debugMain.println("DO SOMETHING/PROCESSING/ANALYSIS DATA HERE.........");
        splitData(buff,processData);
        
        NH4N = NH4N_calculate(processData);
        PH = PH_calculate(processData);
        TEMPARATURE = TEMP_calculate(processData);
        Kion = Kion_calculate(processData);
        //debugMain.print("======================================================= ");
        //debugMain.print("PH: ");  
        //debugMain.println(PH,10);
        //debugMain.print("TEMPARATURE: ");  
        //debugMain.println(TEMPARATURE,10);
        //debugMain.print("NH4N: ");  
        //debugMain.println(NH4N,10);
        //debugMain.print("Kion: ");  
        //debugMain.println(Kion,10);
        //debugMain.print("======================================================= ");
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
void modbusEvent(){
  //debugMain.println("-------------------------------------------------");
  //debugMain.println("RECEIVING...");
  while(Serial.available()){
    
    int data = Serial.read();
    if((index >= 2) && (index < MaxIndex)){
      buff[index] = data;
      index++;
    }//end if
    if((data == id_slave) && (index == 0)){
      buff[0] = data;
      index++;
      //debugMain.println("slave ID:");
      //debugMain.println(buff[0],HEX);
    }//end if
    if((data == cmd) && (index == 1)){
      buff[1] = data;
      index++;
      //debugMain.println("CMD:");
      //debugMain.println(buff[1],HEX);
    }//end if
    if(((buff[2]+5)==index)){
      flagProcess = 1;
      //debugMain.println("DONE:");
      //for(int i = 0;i<index;i++){
      //  debugMain.print(buff[i],HEX);
      //  debugMain.print(" ");
      //}
    }//end if
    //debugMain.println(data,HEX);
  }//end while 
}
