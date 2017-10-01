#define CAYENNE_DEBUG         // Uncomment to show debug messages
#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space

#include "CayenneDefines.h"
#include "BlynkSimpleEsp8266.h"
#include "CayenneWiFiClient.h"
#define SERVO_VIRTUAL_PIN 1
#define SERVO_DIGITAL_PIN 4
#include <Servo.h>
Servo s1;
double lastPosition = 0;
// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "ts9no27ob1";
// Your network name and password.
char ssid[] = "DI-ext";
char password[] = "44332211";
void setup() {
pinMode(0, OUTPUT);
s1.attach(SERVO_DIGITAL_PIN);
  Serial.begin(9600);
  Cayenne.begin(token, ssid, password);
}
CAYENNE_IN(SERVO_VIRTUAL_PIN)
{
  // get value sent from dashboard
  double currentValue = getValue.asDouble();
  int position = currentValue * 200;
  // actually move the servo to the specified position
  s1.write(position);

  //update last position
  lastPosition = currentValue;
}



void loop() {
  
  Cayenne.run();
}

