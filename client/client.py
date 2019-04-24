import serial 
import requests
import time 

# Connection
ser = serial.Serial(
    port = '/dev/ttyUSB0', 
    baudrate = 9600 
)
# Get data from Arduino
data = ser.readline()
moisture = {'moisture': data.replace('\r','').replace('\n','')[1::]} 

addr = 'http://localhost/insert.php'

req = requests.get( 'http://localhost/insert.php', params=moisture)
print( req.url)
