# This file provide USTH server handler
# USTH DB INTERFACE:
# - protocol : Http
# - method   : get
# - payload  :
#   + ss_index(sensor_id)
#   + val     (sensor_value)
# NOTE: still following old system design

import requests as request
import os

class ServerHandler():
    def __init__(self, conf):
        self.url = conf['url']
        self.api = conf['action']
        self.resp = {}
        if request.get(self.url).status_code == 404:
            raise Exception('Could not connect to Server :(')

    def getPayload(self, *args,**kwargs):
        try:
            if args != None:
                return {
                    'ss_index': args[0],
                    'val': args[1]
                }
            else:
                data = kwargs
                return {
                    'ss_index': data['id'],
                    'val': data['val']
                }
        except Exception as e:
            raise Exception("Could not build payload, message:\n"+str(e))

    def send(self, payload):
        self.resp = request.get(self.url + '/' + self.api, params = payload)

    def getResponse(self):
        return self.resp


# Test code
if __name__ == '__main__':
    from config import config
    print("This file provide Handler for USTH server interaction")
    print("USTH Server URL: " + config['server']['url'])
    print("Connect to Server...")
    try:
        test_usth = ServerHandler(config['server'])
        print("Done :)")
    except Exception as e:
        print("Oops !!! Something wrong happen with message:")
        print(e)

