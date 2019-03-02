

#include <TFMini.h>
#include <SoftwareSerial.h>



SoftwareSerial mySerial1(10, 11);


TFMini laser1;


void setup(){
Serial.begin(115200);

while (!Serial);

Serial.println("Beginning");

mySerial1.begin(TFMINI_BAUDRATE);

laser1.begin(&mySerial1);



}

void loop(){
  uint16_t dist1 = laser1.getDistance();
  uint16_t strength1 = laser1.getRecentSignalStrength();

Serial.print(dist1);
Serial.print( "cm sigstrength: ");
Serial.println(strength1);
delay(25);
}
