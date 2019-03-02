

#include <TFMini.h>
#include <SoftwareSerial.h>



SoftwareSerial mySerial(10, 11);


TFMini laser;

SoftwareSerial mySerial2(5, 6);
TFMini laser2;

void setup(){
Serial.begin(115200);

while (!Serial);

Serial.println("Beginning");






}

void loop(){
  
  mySerial.begin(TFMINI_BAUDRATE);
  laser.begin(&mySerial);
  uint16_t dist = laser.getDistance();
  uint16_t strength = laser.getRecentSignalStrength();
  
  Serial.print(dist);
  Serial.print( "cm sigstrength: ");
  Serial.println(strength);
  delay(1000);

  mySerial2.begin(TFMINI_BAUDRATE);
  laser2.begin(&mySerial2);
  
  uint16_t dist2 = laser2.getDistance();
  uint16_t strength2 = laser2.getRecentSignalStrength();
  Serial.print(dist2);
  Serial.print( "cm sigstrength: ");
  Serial.println(strength2);
  delay(1000);

  Serial.print("Its working: ");
  Serial.println(dist);
}
