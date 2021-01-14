/*
 *  Lora header file
 */
#include <RH_RF95.h>

/*
 * Lora frequency
 * 
 */
#define LORA_FREQ 868.0

/*
 * Lora Message
 */
#define LORA_MAX_BUFF 255
uint8_t lora_buff[LORA_MAX_BUFF]; // max FIFO size: 251 bytes
uint8_t lora_buff_size = LORA_MAX_BUFF;
enum MessStatus{NotAvail, Fail, End, Avail};
