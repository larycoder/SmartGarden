import requests
import time 

myfile = open('/Users/huyhoang8398/SmartGarden/system/labtest/cMoisture.txt','r')  #### path to your daily log file 
cMoisture = myfile.read()
print (cMoisture)
payload = {'api_key': 'K7OUBAGNAE3SZ02M', 'field1': cMoisture}

req = requests.get('https://api.thingspeak.com/update', params=payload)
print( req.url)
