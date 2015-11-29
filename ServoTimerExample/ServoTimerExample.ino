#include <Servo.h>
#include "Timer.h"

Timer t;
int pin = 13;

Servo myservo; // create servo object to control a servo
int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(pin, OUTPUT);
  t.pulse(pin, 10 * 60 * 1000, HIGH); // 10 minutes
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
  }

  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
  }

  t.update();

}
