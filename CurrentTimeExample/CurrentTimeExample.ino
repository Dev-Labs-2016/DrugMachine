#include <Process.h>

Process date;                 // process used to get the date

void setup() {
  Bridge.begin();        // initialize Bridge
  Serial.begin(9600);    // initialize serial  

  Serial.println("Time Check");  // Title of sketch
  while(!Serial);               // wait for Serial Monitor to open

  Serial.println("Time Check");  // Title of sketch
}

void loop() {
  date.begin("/bin/date");
  date.run();
  
  //if there's a result from the date process, get it.
  while (date.available()>0) {
    // print the results we got.
    Serial.print(date.readString());
  }
  
  delay(5000); // wait 5000ms
}
