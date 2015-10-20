#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int val = 0;
int analogPin = 7;

int startAngle = 0;
int endAngle = 0;
int stepAngle = 0;

void parseAngles(String input) {
  int commaIndex1 = input.indexOf(',');
  int commaIndex2 = input.indexOf(',', commaIndex1 + 1);
  startAngle = input.substring(0, commaIndex1).toInt();
  endAngle = input.substring(commaIndex1 + 1, commaIndex2).toInt();
  stepAngle = input.substring(commaIndex2 + 1, input.length()).toInt();
  Serial.print("startAngle=");
  Serial.println(startAngle);
  Serial.print("endAngle=");
  Serial.println(endAngle);
  Serial.print("stepAngle=");
  Serial.println(stepAngle);
}

void getReadings() {
  for (int angle = startAngle; angle <= endAngle; angle += stepAngle) {
    myservo.write(angle);
    delay(50);
    val = analogRead(analogPin);
    Serial.print(angle);
    Serial.print(",");
    Serial.println(val);
  }
  Serial.println("End of Readings");
  Serial.println("Enter values:");
  Serial.println("");
}

char character;

void setup() {
  Serial.begin(9600);
  myservo.attach(12);  // attaches the servo on pin 12 to the servo object
  //Serial.print("");
  Serial.println("Enter values:");
}

void loop() {
  String content = "";

  while (Serial.available() > 0) {
    character = Serial.read();
    content.concat(character);
    delay(10);
  }
  if (content != "") {
    Serial.print("Setting angles: ");
    Serial.println(content);
    parseAngles(content);
    Serial.println("Starting readings:");
    delay(15);
    getReadings();
  }

  // Output rangefinder shit
  // val = analogRead(analogPin);
  // Serial.println(val);
  // delay(15);

  // for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  //   // in steps of 1 degree
  //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15ms for the servo to reach the position
  // }

  // // val = analogRead(analogPin);
  // // Serial.println(val);
  // for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15ms for the servo to reach the position
  // }
}
