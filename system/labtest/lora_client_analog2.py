#!/usb/bin/env python
import sys
import os
import time
import array
import lib as pyrfm
import serial

# read data from zigbee 
ser = serial.Serial(port='/dev/ttyUSB0', baudrate=115200)
ser.write('C')
aMoisture = ser.read_until('\r')
ss_index = "3:"
print (aMoisture)
dataLora = ss_index + aMoisture 

sys.path.append(
	os.path.join(
		os.path.dirname(__file__),
		'..'
	)
)


conf={
	'll':{
		'type':'rfm95'
	},
	'pl':{
		'type':	'serial_seed',
		'port':	'/dev/ttyUSB1'
	}
}
ll=pyrfm.getLL(conf)

print('HW-Version: ', ll.getVersion())
if ll.setOpModeSleep(True,True):
    ll.setFiFo()
    ll.setOpModeIdle()
    ll.setModemConfig('Bw125Cr45Sf128');
    ll.setPreambleLength(8)
    ll.setFrequency(868)
    ll.setTxPower(13)

    ll.sendStr(dataLora)
    ll.waitPacketSent()
