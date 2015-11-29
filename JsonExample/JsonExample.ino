#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
#include <aJSON.h>

YunServer server;

void setup() {
  Serial.begin(9600);
  Bridge.begin();
  server.listenOnLocalhost();
  server.begin();
  Serial.println("Server Started");
}

void loop() {
  YunClient client = server.accept();
  if (client) {
    process(client);
    client.stop();
  }
}

void process(YunClient client) {
  if (client.read() == '#') {
    Serial.println(client.readString()); 
  }
}

void parseJson(char *jsonString) 
{
    char* value;

    aJsonObject* root = aJson.parse(jsonString);

    if (root != NULL) {
         aJsonObject* jname = aJson.getObjectItem(root, "name"); 
         String medication_name = jname->valuestring;
         Serial.println(medication_name);

         jname = aJson.getObjectItem(root, "dosage"); 
         int medication_dosage = jname->valueint;
         Serial.println(medication_dosage);

         jname = aJson.getObjectItem(root, "duration"); 
         String medication_duration = jname->valuestring;
         Serial.println(medication_duration);

         jname = aJson.getObjectItem(root, "time"); 
         String medication_time = jname->valuestring;
         Serial.println(medication_time);
         
          jname = aJson.getObjectItem(root, "no_of_tablets_filled"); 
         int medication_no_of_tablets_filled = jname->valueint;
         Serial.println(medication_no_of_tablets_filled);
    }else{
      Serial.println("Parsing JSON request failed");  
    }
}
