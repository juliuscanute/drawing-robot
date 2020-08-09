import serial
import arduino_pb2
ser = serial.Serial('COM5', 9600)
ser.flushInput()
while True:
    try:
        data = arduino_pb2.Message()
        ser_bytes = data.ParseFromString(ser.read(2))
        print(data.uniqueId)
    except Exception as e:
        print(e)
        break