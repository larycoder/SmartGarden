import requests
import time 
import serial 

ser = serial.Serial(port='/dev/ttyUSB0', baudrate=115200)
ser.write('C')

aMoisture = ser.read_until('\r')
print (aMoisture)
payload = {'api_key': 'K7OUBAGNAE3SZ02M', 'field1': aMoisture}
req = requests.get('https://api.thingspeak.com/update', params=payload)
print( req.url)