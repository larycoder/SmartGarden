/*
 *  Lora header file
 */
#include <RH_RF95.h>

/*
 * Lora Message
 */
uint8_t lora_buff[RH_RF95_MAX_MESSAGE_LEN]; // max FIFO size: 251 bytes
uint8_t lora_buff_size = RH_RF95_MAX_MESSAGE_LEN;
enum MessStatus{NotAvail, Fail, End, Avail};
