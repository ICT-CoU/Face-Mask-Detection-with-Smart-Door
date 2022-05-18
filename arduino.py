import serial
from time import sleep 

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
ser.flush()

def send_command(command):
    non = "nothing\n"
    command += "\n"
    ser.write(non.encode('utf-8'))
    print (ser.readline())
    sleep(1)
    ser.write(command.encode('utf-8'))
    print (ser.readline())







