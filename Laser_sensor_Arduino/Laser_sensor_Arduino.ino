

#include <TFMini.h>
#include <SoftwarSerial.h>



SoftwarSerial mySerial(10, 11);


TFMini laser;


void setup(){
Serial.begin(115200);

while (!Serial);

Serial.println("Beginning");

mySerial.begin(TFMINI_BAUDRATE);

tfmini.begin(&mySerial);



}

void loop(){
unit16_t dist = tfmini.getDistance();
uint16_t strength = tfmini.getrecentSignalStrength();

Serial.print(dist);
Serial.print( "cm sigstrength: ")
Serial.println(strength);
delay(25);
}
