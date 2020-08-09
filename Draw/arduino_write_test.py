import serial
import time
import arduino_pb2
ser = serial.Serial('COM5', 9600)
ser.flushInput()
while True:
    try:
        data = arduino_pb2.Message()
        data.uniqueId = 55
        marshalled = data.SerializeToString()
        print(marshalled)
        print(len(marshalled))
        ser.write(marshalled)
        time.sleep(1)
    except Exception as e:
        print(e)
        break