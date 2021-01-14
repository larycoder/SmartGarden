import time

# define op mode
CLEAN_BUFF = 0x00
SET_BUFF   = 0x01
READ_BUFF  = 0x02
LORA_AVAI  = 0x03
LORA_SEND  = 0x04
LORA_RECV  = 0x05

WAIT_TIME  = 0.5 # second

# class protocol
class SerialProtocol():
    def __init__(self, con):
        self.con = con

    def sendCode(self, code, length=1, resp=0x00, excep_raise = True):
        self.con.write(bytearray(code))
        time.sleep(WAIT_TIME) # wait for transmiss
        ret = self.con.read(length)
        if ret != resp and excep_raise:
            print('DEBUG - code: ' + str(ret))
            raise Exception("send code error !")
        else:
            return ret

    def sendLora(self, data):
        length = bytes(len(data))

        # clean lora buff
        code = [CLEAN_BUFF, 0x00]
        self.sendCode(code)

        # set buff
        code = [SET_BUFF, 0x00]
        code += length
        code += bytearray(data)
        self.sendCode(code)

        # send data to lora
        code = [LORA_SEND, length]
        self.sendCode(code)

    def loraAvail(self):
        code = [LORA_AVAI]
        ret = self.sendCode(code, excep_raise = False)
        return True if ret == 0x00 else False
    
    def readLora(self):
        # read lora to buff
        code = [LORA_RECV]
        self.sendCode(code)

        # read lora data from buff
        code = [READ_BUFF, 0x00]
        data_length = self.sendCode(code, excep_raise = False)
        return self.con.read(data_length)

    def flush(self):
        self.con.reset_input_buffer()
        self.con.reset_output_buffer()
