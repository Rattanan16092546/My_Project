
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLzz0M7PIa"
#define BLYNK_DEVICE_NAME "Pump project"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
const int pingPin = D1;
int inPin = D2;
///20 cm///

BLYNK_WRITE(V0){
  int val = param.asInt();
  digitalWrite(D0,val);
}

void setup()
{
  pinMode(D0,OUTPUT);
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();



  long duration, cm;

pinMode(pingPin, OUTPUT);


digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(5);
digitalWrite(pingPin, LOW);
pinMode(inPin, INPUT);
duration = pulseIn(inPin, HIGH);

cm = microsecondsToCentimeters(duration);
int percent = 100 - ( (cm - 3) / (20 - 3) ) * 100;
if(cm < 20 && cm> 3){
  Blynk.virtualWrite(V1, percent);
  Serial.print(percent);
  Serial.print("%");
  Serial.println();
}
else{
  Blynk.virtualWrite(V1, 0);
}
Serial.print(cm);
Serial.print("cm");
Serial.println();

delay(100);
}



long microsecondsToCentimeters(long microseconds)
{
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
return microseconds / 29 / 2;
}
