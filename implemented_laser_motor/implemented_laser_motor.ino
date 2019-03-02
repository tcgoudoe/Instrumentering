//For distansemåler og motor

#include <Servo.h>
#include <NewPing.h>
#include <DHT.h>
#include <TFMini.h>
#include <SoftwareSerial.h>


//motor object
Servo servo;

//Laser sensor object

SoftwareSerial myserial1(5, 6);
TFMini laser1;

SoftwareSerial myserial2(10, 11);
TFMini laser2;

//--------------------------------
#define MAX_DIST 1200
//For temp og fuktmåler
#define DHTPIN 3
#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);


//-------------------------------------------------

const int iterations = 10;

//tolleransen for feil
const float TOL = 10;

//-------------------------------------------------

//len = lengden på signalet som returneres fra sensoren.
//dist = avstanden i cm.

float len, dist, len2, dist2, x, y, compare, hum, temp, SpeedSound;

//-------------------------------------------------


void setup() {
  // serial.begin; viser input.
  //servo.attach viser hvilken pin den har.
  Serial.begin(115200);
	while(!Serial);

	Serial.print("Beginning mesurements");
	Serial.print(".");
	delay(1000);
	Serial.print(".");
	delay(500);
	Serial.println(".");

  dht.begin();
  }

void loop() {
  
  servo.attach(7);
	
	myserial1.begin(TFMINI_BAUDRATE);
	laser1.begin(&myserial1);

	uint16_t dist = laser1.getDistance();
  Serial.println(dist);
  x = dist;
  printDistance(1, x);

	myserial2.begin(TFMINI_BAUDRATE);
	laser2.begin(&myserial2);

  uint16_t dist2 = laser2.getDistance();
  Serial.println(dist2);
  y = dist2;
  printDistance(2, y);
  servo.write(1500);
  MotorDriver(x, y);


  //delay(2000);
}
  void printDistance(int Nr, float dist){
    Serial.print("Sensor nr ");
    Serial.print(Nr);
    Serial.print(" er: ");
    Serial.println(dist);
    delay(1000);
}
  void MotorDriver(float dist1, float dist2){
      servo.write(1500);
      compare = dist1-dist2;
      Serial.print("differansen er: ");
      Serial.println(compare);
    if (abs(compare) >= TOL && compare >= 0){
      Serial.println("Moving forwards");
      servo.write(0);
      //delay(4000);
      //servo.write(1500);
      //delay(2000);
    }
    else if(abs(compare) >= TOL && compare < 0){
      Serial.println("Moving backwards");
      servo.write(2000);
      //delay(4000);
      //servo.write(1500);
      //delay(2000);
      //servo.detach();
    }
    else{
      Serial.println("Stopp");
      
      servo.detach();
    }
  }
  
