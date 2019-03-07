#include<SoftwareSerial.h>

SoftwareSerial gsm(14, 15);

int vib_pin=5;

void setup() {
  gsm.begin(9600);
  delay(1000);
  pinMode(vib_pin,INPUT);
}

void loop() {
  int val;
  val=digitalRead(vib_pin);
  if(val==1)
    SendMessage();
}

void SendMessage()
  {
    gsm.println("AT+CMGF=1"); 
    delay(1000);
    gsm.println("AT+CMGS=\"+918667036604\"\r");
    delay(1000);
    gsm.println("Level-1 is being attempted to breach - TREDOCK");
    delay(1000);
    gsm.println((char)26);
    delay(1000);
  }
