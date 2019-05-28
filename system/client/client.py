import serial 
import requests
import time 


addr = 'http://localhost/insert.php'

req = requests.get( 'http://localhost/insert.php', params=moisture)
print( req.url)
