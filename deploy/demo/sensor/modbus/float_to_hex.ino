//=========================================================================================
//==============================split data to analysis=====================================
void splitData(unsigned int * data,unsigned int * data2){
  unsigned int len = data[2];
  debugMain.println("split data");
  for(int i=0; i< len; i++){
    data2[i] = data[i+3];
    debugMain.print(data2[i],HEX);
    debugMain.print(" ");
  }
}

//=========================================================================================
//==============================split data to analysis=====================================
float convertHexToFloat(unsigned int * data){
  int subExponent = 0;
  unsigned long subMantissa = 0;
  float finalDataConvert = 0;
  
//  data[0] = 0x3D;
//  data[1] = 0x4C;
//  data[2] = 0xCD;
//  data[3] = 0x52;
  
  //-------------------------------SIGN CALCULATION----------------------------------------
  sign =  ((data[0] & 0x80)>>7);      //sign of data (+/-)
  debugMain.print("SIGN :");
  debugMain.println(sign);
  
  //---------------------------------------------------------------------------------------
  //-----------------------------EXPONENT CALCULATION--------------------------------------
  subExponent = (((data[1] & 0x80) >>7) | ((data[0] & 0x7F)<<1)) - 127; 
//  debugMain.print("subExponent :");
//  debugMain.println(subExponent);
  exponent = pow(2,subExponent);
  debugMain.print("exponent :");
  debugMain.println(exponent);
  
  //---------------------------------------------------------------------------------------
  //-----------------------------MANTISSA CALCULATION--------------------------------------
  data[1] = data[1]&0x7F;
  //debugMain.print("data[1] :");
  //debugMain.println(data[1],HEX);
  
  subMantissa = (long(data[1])<<16) | (data[2]<<8) | (data[3]);
  //debugMain.print("mantissa :");
  //debugMain.println(subMantissa,BIN);
  for(int i=0;i<23;i++){
    unsigned long checkBit = ((subMantissa >> i) & 0x0001); delay(20);
    if(checkBit == 1){
      mantissa = mantissa + (1/pow(2,23-i));
      delay(20);
    }
  }
  debugMain.print("MANTISSA FILNAL : ");  
  debugMain.println(mantissa,10);
  //---------------------------------------------------------------------------------------
  //---------------------------FLOAT DATA CALCULATION--------------------------------------
  finalDataConvert = exponent*mantissa;
  if(sign == 1){
    finalDataConvert = 0 - finalDataConvert;
  }
  debugMain.print("final DATA: ");  
  debugMain.println(finalDataConvert,10);
  mantissa = 1;
  return finalDataConvert;
}

//=========================================================================================
//=======================================NH4-N=============================================
float NH4N_calculate(unsigned int * data){
  unsigned int NH4N_a[4] = {0};
  float SubNH4N = 0;
  NH4N_a[0] = data[2];
  NH4N_a[1] = data[3];  
  NH4N_a[2] = data[0];
  NH4N_a[3] = data[1];
  //---------------------
//  NH4N_a[0] = 0x3D;
//  NH4N_a[1] = 0x4C;
//  NH4N_a[2] = 0xCD;
//  NH4N_a[3] = 0x52;
  //---------------------
  SubNH4N = convertHexToFloat(NH4N_a);
  return SubNH4N;
}

//=========================================================================================
//=======================================Kion==============================================
float Kion_calculate(unsigned int * data){
  unsigned int Kion_a[4] = {0};
  float SubKion = 0;
  Kion_a[0] = data[16];
  Kion_a[1] = data[17];  
  Kion_a[2] = data[15];
  Kion_a[3] = data[14];
  //---------------------
//  Kion_a[0] = 0x44;
//  Kion_a[1] = 0x7A;
//  Kion_a[2] = 0x00;
//  Kion_a[3] = 0x00;
  //---------------------
  SubKion = convertHexToFloat(Kion_a);
  return SubKion;
}

//=========================================================================================
//========================================PH===============================================
float PH_calculate(unsigned int * data){
  unsigned int PH_a[4] = {0};
  float SubPH = 0;
  PH_a[0] = data[6];
  PH_a[1] = data[7];  
  PH_a[2] = data[4];
  PH_a[3] = data[5];
  //---------------------
//  PH_a[0] = 0x40;
//  PH_a[1] = 0xF3;
//  PH_a[2] = 0x59;
//  PH_a[3] = 0x09;
  //---------------------
  SubPH = convertHexToFloat(PH_a);
  return SubPH;
}


//=========================================================================================
//====================================TEMPARATURE==========================================
float TEMP_calculate(unsigned int * data){
  unsigned int TEMP_a[4] = {0};
  float SubTEMP = 0;
  TEMP_a[0] = data[12];
  TEMP_a[1] = data[13];  
  TEMP_a[2] = data[10];
  TEMP_a[3] = data[11];
  //---------------------
//  TEMP_a[0] = 0x41;
//  TEMP_a[1] = 0xC4;
//  TEMP_a[2] = 0x19;
//  TEMP_a[3] = 0x36;
  delay(20);
  //---------------------
  SubTEMP = convertHexToFloat(TEMP_a);
  return SubTEMP;
}
