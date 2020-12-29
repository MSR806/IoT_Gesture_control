#include "HC_SR04.h"

HC_SR04 left(6, 5);
HC_SR04 right(11, 10);

  int distance_left;
  int distance_right;
  int flag_r=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  left.begin();
  right.begin();
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
  distance_left = left.distance();
  distance_right = right.distance();

  long time = millis();

  distance_left = left.distance();
  distance_right = right.distance();

  if (distance_left >2 && distance_left <26)
  {
    distance_left = left.distance();
    if ((distance_left >0 && distance_left <11)){
        Serial.println("LeftNear");
        delay(600);
        Serial.print("LN");
        Serial.println(left.distance());
    }
    else if ((distance_left >11 && distance_left <26)){
      Serial.println("LeftFar");
      delay(600);
      Serial.print("LF");
      Serial.println(left.distance());
    }
  }

  if (distance_right >2 && distance_right <26)
  {
    distance_right = right.distance();
    if ((distance_right >0 && distance_right <11)){
        Serial.println("RightNear");
        delay(200);
    }
    else if ((distance_right >11 && distance_right <26)){
      Serial.println("RightFar");
      delay(200);
    }
  }



  //Serial.println("Void loop");
  //Serial.println(left.distance());
  //Serial.print(" ");
  //Serial.println(right.distance());
  //delay(10);
}
