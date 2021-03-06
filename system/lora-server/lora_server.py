#!/usb/bin/env python

"""
	waits for incomming message and sends response
"""
__author__	= """Alexander Krause <alexander.krause@ed-solutions.de>"""
__date__ 		= "2016-12-28"
__version__	= "0.1.0"
__license__ = "GPL"

import sys
import os
import array
import requests 

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
		'port':	'/dev/ttyUSB0'
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
	
	while True:
		#ll.sendStr('Hello world!')
		#ll.waitPacketSent()
		
		if ll.waitRX(timeout=3):
			data=ll.recv()
			header=data[0:4]
			msg=data[4:]
			print('header: ',header)
			data = (array.array('b', msg).tostring())
			index = data.split(":")[0]
			print data.split(":")
			print index
			value = data.split(":")[1]
			print value
			payload = {'ss_index': index , 'val': value}
			req = requests.get('http://scg.sontg.net/insert.php', params=payload)
			print req.url