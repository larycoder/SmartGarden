/*
 *  modbus header file
 */

//=====================================================================
//--------------------------SLAVE VAR----------------------------------
int id_slave = 181;                    //ID slave device
int cmd = 3;                           //request funtion in modbus RTU
//-----------------------TRANSCEIVER VAR-------------------------------
unsigned int MaxIndex = 50;            //max buffer
unsigned int index = 0;                //index for receive new data from slave
unsigned int buff[50] = {0};           //buffer
unsigned int processData[50] = {0};    //float to hex prcoess array
//---------------------------FLAG VAR----------------------------------
byte flagProcess = 0;                  //allow process data var

//-----------------------CONVERT VAR-----------------------------------
byte sign = 0;
float exponent = 0;
float mantissa = 1;


//-----------------------CHEMICALS VAR-----------------------------------

float NH4N = 0;
float TEMPARATURE = 0;
float Kion = 0;
float PH = 0;
