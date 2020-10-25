import requests
import time
import serial

#============================================
# input port and read value
try: # port
  arduino_port = input("input port ['default: /dev/ttyACM0']:")
except SyntaxError:
  arduino_port = '/dev/ttyACM0'

try: # pin
  arduino_pin = input("input pin ['default: A']:")
except SyntaxError:
  arduino_pin = 'A'

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

  print("Cron data") # notify cron data

  # send and receive soid measure
  ser.write(arduino_pin)
  time.sleep(0.1) # wait for writing

  while ser.inWaiting():
    aMoisture = ser.read_until('\r\n')
    print('Solid: ', aMoisture.rstrip())

  # flush data
  ser.flushInput()
  ser.flushOutput()

  #===========================================================
  # send data to server

  print("send data to server") # notify send data to server

  # build payload
  value = aMoisture.rstrip() # remove carriage return and newline
  index = '0'
  payload = {
	'ss_index': index,
	'val': value
  }
  #req = requests.get(url, params = payload)
  #print(req.url) # inform server request
