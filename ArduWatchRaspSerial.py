# Programa que envia os dados à placa

import serial
from datetime import datetime
import time

def int_str(leitura):
	if (leitura == '0'):
		return('00':
	elif (leitura == '1')
		return('01')
	elif (leitura == '2')
		return('02')
	elif (leitura == '3')
		return('03')
	elif (leitura == '4')
		return('04')
	elif (leitura == '5')
		return('05')
	elif (leitura == '6')
		return('06')
	elif (leitura == '7')
		return('07')
	elif (leitura == '8')
		return('08')
	elif (leitura == '9')
		return('09')
	else:
		return(str(leitura))

ser = serial.Serial('/dev/ttyUSB0',9600);

while (1):
	t = datetime.now()
	hour = t.hour
	minutes = t.minute
	hour = str(hour)
	minute = str(minutes)
	ser.write(hour+minutes)
	time.sleep(2)
