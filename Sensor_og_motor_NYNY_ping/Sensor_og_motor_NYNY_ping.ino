//For distansemåler og motor

#include <Servo.h>
#include <NewPing.h>
#include <DHT.h>
//motor object
Servo servo;

//Sensor object



//--------------------------------
#define MAX_DIST 400
//For temp og fuktmåler
#define DHTPIN 6
#define DHTTYPE DHT22

  DHT dht(DHTPIN,DHTTYPE);

//For sensor1 og to.
#define trigpin 12
#define echopin 11
NewPing sonar(trigpin, echopin, MAX_DIST);

#define trigpin2 9
#define echopin2 10
NewPing sonar2(trigpin2, echopin2, MAX_DIST);

//-------------------------------------------------

const int iterations = 10;

//tolleransen for feil
const float TOL = 0.5;

//-------------------------------------------------

//len = lengden på signalet som returneres fra sensoren.
//dist = avstanden i cm.

float len, dist, len2, dist2, x, y, compare, hum, temp, SpeedSound;

//-------------------------------------------------


void setup() {
  // serial.begin; viser input.
  //servo.attach viser hvilken pin den har.
  Serial.begin(9600);
  dht.begin();
  }

void loop() {
  
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  SpeedSound = getSpeed(temp, hum);
  servo.attach(7);
  dist = getDistance(trigpin, sonar.ping_median(iterations));
  x = dist;
  printDistance(1, x);

  dist2 = getDistance(trigpin2, sonar2.ping_median(iterations));
  y = dist2;
  printDistance(2, y);
  servo.write(1500);
  MotorDriver(x, y);


  //delay(2000);
}
float getSpeed(float temp, float hum){
  return (331.4 + (0.606 * temp) + (0.0124 * hum)) / 10000;
}

float getDistance(int trig,float echo){
    dist = (echo/2) * SpeedSound;
    if (dist >=400 || dist <= 2){
      Serial.println("Avstanden er unøyaktig.");
    }
    else{
      return dist;
    }
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
  
