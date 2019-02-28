

#include <TFMini.h>
#include <SoftwareSerial.h>



SoftwareSerial mySerial(10, 11);


TFMini laser;


void setup(){
Serial.begin(115200);

while (!Serial);

Serial.println("Beginning");

mySerial.begin(TFMINI_BAUDRATE);

laser.begin(&mySerial);



}

void loop(){
  uint16_t dist = laser.getDistance();
  uint16_t strength = laser.getRecentSignalStrength();

Serial.print(dist);
Serial.print( "cm sigstrength: ");
Serial.println(strength);
delay(25);
}
