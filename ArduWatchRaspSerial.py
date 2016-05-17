# @Author: Jhunu Fernandes Araújo <windsor>
# @Date:   17-05-2016
# @Email:  jhunu@gmail.com
# @Last modified by:   windsor
# @Last modified time: 17-05-2016

# Programa que envia os dados à placa

import serial
from datetime import datetime
import time

def int_str(leitura):
	if int(leitura) < 10:
		return('0'+leitura)
	else:
		return(str(leitura))

ser = serial.Serial('/dev/ttyUSB0',9600);

while True:
	t = datetime.now()
	hour = t.hour
	minutes = t.minute
	hour = int_str(hour)
	minute = int_str(minutes)
	ser.write(hour+minutes)
	time.sleep(2)
