//the code test a bluetooth module 
// devices: arduino uno, led, hc 05 bluetooth module, connecting wires
// set up: arduino pins 2 - RX, 3 - TX, 8 - LED
// WHAT HAPPENS: the system receives data from a bluetooth module (stores it in byteRead variable)
// and based on this data it turns on / off an LED
// then it information to the bluetooth module on the state of the LED.

#include <SoftwareSerial.h>
SoftwareSerial MyBlue(2, 3); // RX | TX 

byte byteRead;
int LED = 8; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
MyBlue.begin(9600);
pinMode(LED, OUTPUT);
delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(MyBlue.available( )){
  byteRead = MyBlue.read();
  //byteRead = byteRead + 1;
  
  MyBlue.write(byteRead);
  }

  if(byteRead == '1'){
    MyBlue.write("\n TURN ON LED \n");
    digitalWrite(LED, HIGH);
  }
  else if(byteRead == '0'){
    MyBlue.write("\n TURN OFF LED \n");
    digitalWrite(LED, LOW);
  }else{
    MyBlue.write("\n UNKNOWN CMD \n");
  }
  delay(2000);
}
