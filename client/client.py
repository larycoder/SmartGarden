import serial 
import requests
import time 

# Connection
ser = serial.Serial("/dev/ttyACM0")
ser.baudrate = 9600 

# Get data from Arduino
data = ser.readline()
moisture = {'moisture_analog': data} 

addr = 'http://localhost/insert.php'

req = requests.get( 'http://localhost/insert.php', params=moisture)
print( req.url)
