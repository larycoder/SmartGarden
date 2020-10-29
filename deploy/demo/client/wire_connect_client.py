import requests
import time
import serial

#============================================
# input port and read value
try: # port
  arduino_port = input("input port ['default: /dev/ttyUSB0']:")
except SyntaxError:
  arduino_port = '/dev/ttyUSB0'

try: # pin
  arduino_data = input("input pin ['default: a']:")
except SyntaxError:
  arduino_data = 'a'

try: # url
  url = input("input server url ['default: http://scg.songtg.net/insert.php']: ")
except SyntaxError:
  url = 'http://scg.sontg.net/insert.php'

try: # delay time
  delay = input("input cron delay ['default: 1']: ")
except SyntaxError:
  delay= 1

#============================================
# run cron and send data to server

ser = serial.Serial(port= arduino_port, baudrate=115200)

while True:
  # wait a bit
  time.sleep(delay)

  #==========================================================
  # cron data
  aMoisture = ''

  # send and receive soid measure
  ser.write(arduino_data)
  time.sleep(0.5) # wait for writing

  if not ser.inWaiting(): # beautify line
    print('|====== Could not received result =====|\n')

  while ser.inWaiting():
    print("|============== Cron data =============|") # notify cron data
    aMoisture = ser.readline().rstrip()
    print('Received: ', aMoisture)
    print('|======================================|\n')

    if aMoisture == '' or aMoisture == None:
	continue
    elif aMoisture == 'trigged':
	continue

    # flush data
    #ser.flushInput()
    #ser.flushOutput()

  #===========================================================
  # send data to server

    print("|======== send data to server =========|") # notify send data to server

    # build payload
    index = aMoisture.split(" ")[1]
    value = aMoisture.split(" ")[2]
    payload = {
  	  'ss_index': index,
	  'val': value
    }
    req = requests.get(url, params = payload)
    print(req.url) # inform server request
    print(req.status_code) # inform server status
    print(req.content)
    print("|======================================|\n")
