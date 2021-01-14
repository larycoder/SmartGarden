# This file provide main code allowing pi interact, process and transfer sensor data from lora to db

from config import config
from lora import LoraHandler, LoraSerial
from server import ServerHandler
import time, sys


def parseRecv(mess):
    # This function parse data received from arduino
    # message rule:
    # - first 4 bytes = record size of data content
    # - data content = include list of message packs
    # - the message pack = hold data of single sensors
    # - message pack construct:
    #   + name sensor  : 15 bytes (string)
    #   + id sensor    : 4  bytes (int)
    #   + value sensor : 4  bytes (float)
    #   + pack size    : 23 bytes
    
    # TODO: implementation for message parser
    mess_size = int(mess[0:4])
    mess = mess[4:len(mess)]
    pack_num = mess_size / 23
    pack_list = ()
    for i in range(pack_num):
        pack_data = mess[i*23+15:(i+1)*23]
        pack = {
            'id': int(pack_data[0:4]),
            'val': float(pack_data[4:8])
        }
        pack_list.append(pack)
    return pack_list


def run(lora, server): 
    # TODO: implementation for main service of Raspberry 
    ## DEMO ##
    lora.send('Hello world') # send any signal
    #time.sleep(1)
    data = lora.recv(3) # timeout = 3s
    #data_list = parseRecv(data) if data != None else ()
    
    # NOTE: code test
    print("Dubeg Mode -- Data: " + str(data))
    return

    for data in data_list:
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
