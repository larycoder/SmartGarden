# This file provide handler for lora protocol
import lib as pyrfm


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
        self.ll.send(mess)
        self.ll.waitPacketSend()

    def recv(self, timeout):
        if self.ll.waitRx(timeout = timeout):
            return self.ll.recv()
        else:
            # TODO: implement log for receiving nothing
            pass


# test only code
if __name__ == '__main__':
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
