#include <G25Shifter.h>
int firstSensor = 0;    // first analog sensor
int secondSensor = 0;   // second analog sensor
int thirdSensor = 0, forthSensor = 0, fifthSensor = 0;    // digital sensor
int inByte = 0;         // incoming serial byte
int xcalleft = 90;
int xcalright = 165;
int ycaldown = 60;
int ycalup = 140;
int gearr= 0;
G25Shifter G25(A4, A3, 2, 3, 4, 5);
void setup() {
  // start serial port at 9600 bps:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  establishContact();  // send a byte to establish contact until receiver responds
}

void loop() {
  G25.update();
  int rev = G25.getButton(1);
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    inByte = Serial.read();
    firstSensor = analogRead(A0) / 4;
    Serial.println(firstSensor);
    secondSensor = analogRead(A1) / 4;
    Serial.println(secondSensor);
    thirdSensor = analogRead(A2) / 4;
    Serial.println(thirdSensor);
    forthSensor = analogRead(3) / 4;
    fifthSensor = analogRead(4) / 4;
    if(fifthSensor < xcalleft){
      if(forthSensor >ycalup){
        gearr = 1;
        }
      else if(forthSensor < ycaldown){
        gearr = 2;
        }
      else{
        gearr = 0;
        }
      }
    else if(fifthSensor > xcalright){
      if(forthSensor >ycalup){
        gearr = 5;
        }
      else if(forthSensor < ycaldown){
        if (rev == 1){
          gearr = 7;
          }
          else{
            gearr = 6;
            }
        }
      else{
        gearr = 0;
        }
      
      }
    else{
      if(forthSensor >ycalup){
        gearr = 3;
        }
      else if(forthSensor < ycaldown){
        gearr = 4;
        }
      else{
        gearr = 0;
        }
      
      }
    Serial.println(gearr);}
    
    
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print('A');   // send a capital A
    delay(300);
  }
}
