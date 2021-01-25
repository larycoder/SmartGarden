# This file provide handler for lora protocol
import lib as pyrfm
from lib.customized_lib.serial_protocol import getSP
import serial, time

# TODO: define list of message variable
LORA_MAX_BUFF=255 # bytes
LORA_WAIT=0.5 # second


class LoraHandler():
    def __init__(self, conf):
        self.ll = pyrfm.getLL(conf['config'])
        self.modem = conf['modem']
        self.preamble = conf['preamble']
        self.freq = conf['freq']
        if self.ll == None:
            raise Exception("Could not connect to Lora :(")
    
    def printVersion(self):
        print('HW-Version: ', self.ll.getVersion())
    
    def setOpMode(self): # Following author example not sure what is it :(
        if self.ll.setOpModeSleep(True, True):
            # TODO: setup Lora configuration
            self.ll.setFiFo()
            self.ll.setOpModeIdle()
            self.ll.setModemConfig(self.modem) # Bw=125, Cr=4/5, Sf=128chips/symbol, CRC on -> default mode
            self.ll.setPreambleLength(self.preamble)
            self.ll.setTxPower(13)
        else:
            raise Exception("Could not set op mode to sleep :(")

    def send(self, mess):
        self.ll.sendStr(mess)
        self.ll.waitPacketSent()

    def recv(self, timeout):
        if self.ll.waitRX(timeout = timeout):
            return self.ll.recv()
        else:
            # TODO: implement log for receiving nothing
            return None


class LoraSerial():
    def __init__(self, conf):
        port = conf['config']['pl']['port']
        self.con = serial.Serial(port, baudrate=9600)
        mySP = getSP()
        self.lora = mySP(self.con)
        if self.con == None or self.lora == None:
            raise Exception('Could not open serial connection :(')

    def recv(self, timeout):
        start = time.time()
        while(True):
            if self.lora.loraAvail():
                # TODO: read data available
                time.sleep(LORA_WAIT) # wait for lora reading
                
                data = b''
                while(self.lora.loraAvail()):
                    data += self.lora.readLora()
                return data
            elif time.time() - start >= timeout:
                return None

    def send(self, data):
        data = [ord(c) for c in data] # convert string to data
        self.lora.sendLora(data)
        time.sleep(LORA_WAIT) # wait for lora sending 

    def flush(self):
        self.lora.flush()


# test only code
if __name__ == '__main__':
    import sys
    def printUsage():
        print("Usage:")
        print("--> lora   : testing LoraHandler")
        print("--> serial : testing SerialHandler")
    
    if len(sys.argv) != 2:
        printUsage()
        sys.exit(1)

    arg = sys.argv[1]
    if arg == 'lora':
        # TODO: lora protocol test code
        print("This code provide a wrapper class for lora protocol handler")
        print("Lora connection...")
        from config import config
        try:
            test_lora = LoraHandler(config['lora'])
            test_lora.printVersion()
            print("Lora setup OpMode...")
            test_lora.setOpMode()
            print("Done :)")
        except Exception as e:
            print("Oop !!! Something wrong happen with message:")
            print(e)
    elif arg == 'serial':
        # TODO: serial protocol test code
        print("This code provide a wrapper class for serial protocol handler")
        print("Serial connection...")
        from config import config
        try:
            test_serial = LoraSerial(config['lora'])
            print("Done :)")
        except Exception as e:
            print("Oop !!! Something wrong happen with message:")
            print(e)
    else:
        printUsage()
        sys.exit(1)
