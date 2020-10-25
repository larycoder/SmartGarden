import requests
import time
import serial

#============================================
# input port and read value
try:
  arduino_port = input("input port ['default: /dev/ttyACM0']:")
except SyntaxError:
  arduino_port = '/dev/ttyACM0'

try:
  arduino_pin = input("input pin ['default: A']:")
except SyntaxError:
  arduino_pin = 'A'

#============================================


ser = serial.Serial(port= arduino_port, baudrate=115200)

while(1):
  # wait a bit
  time.sleep(3)

  print("Cron data") # notify cron data

  # send and receive soid measure
  ser.write(arduino_pin)
  time.sleep(0.1) # wait for writing

  while ser.inWaiting():
    aMoisture = ser.read_until('\r\n')
    print('Solid: ', aMoisture)

  # flush data
  ser.flushInput()
  ser.flushOutput()

  print("Update thingspeak") # notify send data to server

  # send data to thinkspeak
  payload = {'api_key': 'K7OUBAGNAE3SZ02M', 'field1': aMoisture}
  req = requests.get('https://api.thingspeak.com/update', params=payload)
  print(req)
