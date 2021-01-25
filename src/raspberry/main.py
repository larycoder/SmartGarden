# This file provide main code allowing pi interact, process and transfer sensor data from lora to db

from config import config
from lora import LoraHandler, LoraSerial
from server import ServerHandler
import time, sys


def parseRecv(mess):
    # NOTE: Data will be decrypted on Arduino side, this func will collect info from string data only
    ## decode
    mess = mess.decode('UTF-8')

    ## get number of bytes
    data_list = mess.split('\r\n')
    num_bytes = int(data_list[0].replace('Num Bytes: ', ''))
    size = int(num_bytes / 23)

    data_list = data_list[1:] # get sensor info
    payload_list = []
    for i in range(size):
        try:
            payload = {
                    'id': int(data_list[1].replace('Sensor id', '').replace(':', '')),
                    'val':  float(data_list[2].replace('Sensor value', '').replace(':', ''))

            }
            payload_list.append(payload)
            data_list = data_list[3:]
        except:
            pass
    return payload_list


def run(lora, server): 
    # TODO: implementation for main service of Raspberry 
    ## DEMO ##
    lora.send('H') # send any signal
    time.sleep(0.5) # wait for data writting
    data = lora.recv(3) # timeout = 3s
    data_list = parseRecv(data) if data != b'' else []

    for data in data_list:
        print('Payload Sending: ', data)
        payload = server.getPayload(**data)
        server.send(payload)
        if server.getResponse().status_code != 200:
            raise Exception("Could not successfully send data to server")


# main code
if __name__ == '__main__':
    print("This file provide main services for pi")
    try:
        # TODO: init handlers
        print("Init Lora Connection...")
        lora = LoraSerial(config['lora'])
        lora.flush()

        print("Init Server Connection...")
        usth = ServerHandler(config['server'])
    except Exception as e:
        print("Oops !!! Some thing wrong in initialization, message: ")
        print(e)
        sys.exit(1) # stop program

    try:
        # TODO: loop process
        print("Service running...")
        while(True):
            run(lora, usth)
            pass
    except Exception as e:
        print("Oops !!! Some thing wrong during running, message: ")
        print(e)
        sys.exit(1) # stop program
