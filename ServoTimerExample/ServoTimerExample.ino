#include <Servo.h>
#include <Time.h>
#include <TimeAlarms.h>

int pin = 13;

Servo myservo; // create servo object to control a servo
int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(pin, OUTPUT); // led to indicate that the program is running well
  setTime(8, 29, 0, 1, 1, 11); // set time to Saturday 8:29:00am Jan 1 2011
  Alarm.timerRepeat(30, moveServo);

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(pos);
}

void moveServo () {
  Serial.println("moving my servo");
  int pos =0;
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Serial.println("inside loop 1");
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
  }

  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    Serial.println("inside loop 2");
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
  }
   Serial.println("end loop");
}
void loop() {
  digitalClockDisplay();
  Alarm.delay(1000); // wait one second between clock display
}

void digitalClockDisplay()
{
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println();
}

void printDigits(int digits)
{
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

