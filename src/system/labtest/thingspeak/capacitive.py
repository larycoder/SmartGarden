import requests
import time 
import serial 

ser = serial.Serial(port='/dev/ttyUSB0', baudrate=115200)
ser.write('D')

cMoisture = ser.read_until('\r')
print (cMoisture)
payload = {'api_key': 'K7OUBAGNAE3SZ02M', 'field2': cMoisture}
req = requests.get('https://api.thingspeak.com/update', params=payload)
print( req.url)
