#!/usb/bin/env python

"""
	send's a message and waits for a response
"""
__author__	= """Alexander Krause <alexander.krause@ed-solutions.de>"""
__date__ 		= "2016-12-28"
__version__	= "0.1.0"
__license__ = "GPL"

import sys
import os
import time
import array

sys.path.append(
	os.path.join(
		os.path.dirname(__file__),
		'..'
	)
)

import lib as pyrfm

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
    f = open("analog.txt", "r")
    aMoisture= f.read() 
    ll.sendStr(aMoisture)
    ll.waitPacketSent()
