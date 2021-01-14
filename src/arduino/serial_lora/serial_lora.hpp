#include <SoftwareSerial.h>
#include <RH_RF95.h>


/** PIN SETTING **/
#define S_RX              10
#define S_TX              11

#define BAUDRATE          115200
#define MAX_BUFF   255

#define LORA_FREQ         868.0


/** SYSTEM VARIABLE **/
SoftwareSerial ss(S_RX, S_TX);
RH_RF95 rf95(ss);


/** BUFFER **/
uint8_t lora_buff[MAX_BUFF];
uint8_t serial_buff[MAX_BUFF];
uint8_t f_buff[MAX_BUFF];

#define LORA_BUFF   0x00
#define SERIAL_BUFF 0x01
#define FREE_BUFF   0x02


/** MODE DEFINE **/
#define CLEAN_BUFF 0x00
#define SET_BUFF   0x01
#define READ_BUFF  0x02
#define LORA_AVAI  0x03
#define LORA_SEND  0x04
#define LORA_RECV  0x05


#define BUFF_WAIT 100


#define LORA_WAIT   3000 // 3s
#define L_AVAIL  0x00
#define L_NAVAIL 0x01
