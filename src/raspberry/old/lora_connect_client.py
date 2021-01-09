import sys
import os
import array
import request
import serial
import time
import lib as pyrfm

sys.path.append( # path config -> unnecessary
	os.path.join(
		os.path.dirname(__file__),
		'..'
	)
)

#============================================================
# first setup
try: # port
  port = input("enter lora port [default '/dev/ttyACM0']: ")
except SyntaxError:
  port = '/dev/ttyACM0'

try: # url
  url = input("enter recv server url[default 'http://scg.sontg.net/insert.php']: ")
except SyntaxError:
  url = 'http://scg.sontg.net/insert.php'

#===========================================================
# lora setup
conf={
        'll':{
                'type':'rfm95'
        },
        'pl':{
                'type': 'serial_seed',
                'port': port
        }
}

ll=pyrfm.getLL(conf)
print('HW-Version: ', ll.getVersion())

#===========================================================
# cron lora data then send to server

if ll.setOpModeSleep(True,True):
        ll.setFiFo()
        ll.setOpModeIdle()
        ll.setModemConfig('Bw125Cr45Sf128');
        ll.setPreambleLength(8)
        ll.setFrequency(868)
        ll.setTxPower(13)

	# cron data
	ll.sendStr('A')
	ll.waitPacketSent()

        while True:
	  if ll.waitRX(timeout = 3):
            data = ll.recv()
	    header = data[0:4]
	    msg = data[4:]
	    print('header: ', header) # inform recv head
	    data = (array.array('b', msg).toString())
	    index = data.split(":")[0]
	    print(data.split(":")) # inform recv data
	    print(index) # inform recv index
	    value = data.split(":")[1]
	    print(value) # inform recv value
	    payload = {
		'ss_index': index,
		'val': value
	    }

	    # send data to server
	    #req = requests.get(url, params = payload)
	    #print(req.url) # inform sending request

	    # re-cron data
	    ll.sendStr('A')
	    ll.waitPacketSent()
