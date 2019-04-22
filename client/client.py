import serial 
import requests
import time 

# Connection
ser = serial.Serial("/dev/ttyACM0")
ser.baudrate = 9600 

# Get data from Arduino
data = ser.readline()
moisture = data 

addr = 'http://localhost/insert.php'

def meter():
    while True:
        requette = {'moisture': '+moisture+'}
        try:
            res = requests.post(addr, data=requette)
            print(res.text)
        except:
            print ("connection failed")
        break

#sleep for desired amount of time
if __name__ == "__main__":
        while True:
            meter()
            time.sleep(30)
