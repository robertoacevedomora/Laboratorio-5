import serial
import csv
import os


puerto = "COM6"
#serializamos
ser = serial.Serial(port = puerto,baudrate=9600,parity=serial.PARITY_NONE,stopbits=serial.STOPBITS_ONE,bytesize=serial.EIGHTBITS) 
current_directory = os.getcwd()

csv_path = os.path.join(current_directory, "flexion.csv")

with open(csv_path, mode ='w') as csv_file:
  writer = csv.writer(csv_file)
  writer.writerow(['aX', 'aY', 'aZ', 'gX', 'gY', 'gZ'])
  muestras = 1000
  cnt = 0
  while True:
    line = ser.readline().decode().strip()
    data = line.split('\t')
    ax = float(data[0])
    ay = float(data[1])
    az = float(data[2])
    gx = float(data[3])
    gy = float(data[4])
    gz = float(data[5])
    writer.writerow([ ax, ay, az, gx, gy, gz])
    print(f"aX: {ax}, aY: {ay}, aZ: {az}, gX: {gx}, gY: {gy}, gZ: {gz}")
    cnt += 1
    if cnt >= muestras:
      break
