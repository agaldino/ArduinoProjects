import serial
import smtplib
from email.mime.text import MIMEText

serialObj = serial.Serial('/dev/ttyACM0', 9600)

_from	= "andre.gs3@gmail.com"#raw_input("From: ")
_passwd = "YOUR EMAIL PASSWORD HERE"#raw_input("Type you password: ")
_to   	= " "#raw_input("To: ")
_msg 	= MIMEText("This is an alert. Someone approach less than 2 meters from your PC. (Arduino Uno with Ultrasonic sensor!)")
_msg["To"] = _to
_msg["Subject"] = "Arduino alert"

def  send_email():	
	server = smtplib.SMTP("smtp.gmail.com", 587)
	server.ehlo()
	server.starttls()
	server.ehlo()
	server.login(_from,_passwd)
	server.sendmail(_from,_to,_msg.as_string())
	server.quit()


def read_port():
	x = 1
	while x>0 :
		try:
			value = serialObj.readline()			
			print "valor = " ,value	
			if int(value) == 10:				
				send_email()
				print "EMAIL ENVIADO"							
		except serial.SerialException:
			serialObj.close()

if __name__ == '__main__':
	read_port()
