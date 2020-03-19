import serial, time
from vjoy import *
vj.open()
ser = serial.Serial('COM17',9600, timeout=1,write_timeout=0)
x = ser.read()
xcalleft = 90
xcalright = 165
ycaldown = 60
ycalup = 140
gear = 0
prevgear = 1
print(x)
if x == b"A":
    ser.write(b"B")
    while(True):
        vj.setButton(gear,1)
        C = int(ser.readline().decode("utf-8"))
        B = int(ser.readline().decode("utf-8"))
        T = int(ser.readline() .decode("utf-8"))
        gear = int(ser.readline().decode("utf-8"))
        setJoy(T,C,B, 125)
        gear +=1
        if gear != prevgear:
            #print(gear)
            vj.setButton(gear,1)
        ser.write(b"B")
        prevgear == gear

