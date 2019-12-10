import serial, subprocess, time 

# read Serial
ser = serial.Serial('COM6')
ser.timeout=0
ser.baudrate=9600

# detect signal, do something
while True:
    if ser.readline() == b'line67\r\n':
        print("\nDisco Time Disco Time Disco Time Disco Time")
        time.sleep(1)
        subprocess.call(["python", "light.py"], shell=True)
        break
