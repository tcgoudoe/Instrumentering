

#include "NewPing.h"

#define trigpin 12
#define echopin 11
#define MAX_DISTANCE 400

NewPing sonar(trigpin, echopin, MAX_DISTANCE);

float duration, distance;

int iterations = 5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  duration = sonar.ping_median(iterations);
  distance = (duration / 2) *0.0343;
  Serial.println("Distance = ");
  if (distance >= 400 || distance <= 2){
    Serial.println("Out of range");
  }
  else{
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }
  delay(500);
}
