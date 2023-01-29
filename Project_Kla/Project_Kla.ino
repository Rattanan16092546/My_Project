
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
const int trig = D1; //ประกาศขา trig
const int echo = D2; //ประกาศขา echo
int pump = D5;
long duration, distance; //ประกาศตัวแปรเก็บค่าระยะ













void setup()
{
  pinMode(echo, INPUT); //สั่งให้ขา echo ใช้งานเป็น input
  pinMode(trig, OUTPUT); //สั่งให้ขา trig ใช้งานเป็น output
  pinMode(D0,OUTPUT);
  pinMode(pump,OUTPUT);
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
   BlynkEdgent.run();


 digitalWrite(trig, LOW); 
 delayMicroseconds(5); 
 digitalWrite(trig, HIGH); 
 delayMicroseconds(5); 
 digitalWrite(trig, LOW); //ใช้งานขา tduration = pulseIn(echo, HIGH); //อ่านค่าของ echo
 distance = (duration/2) / 29.1; //คำนวณเป็น centimeters

  float percent = distance;
  float val1 = (percent - 3) / 17;
  float val2 = val1 *100;
  float result = (val2-100) *(-1);

  if(distance>=20){
    while(distance > 4){
    digitalWrite(pump,HIGH);
    Blynk.virtualWrite(V2, 1);
    }

  }
  else{
    digitalWrite(pump,LOW);
    Blynk.virtualWrite(V2, 0);
  }


if(distance <= 20 && distance >= 3){
  Blynk.virtualWrite(V1, result);
  Serial.print(result);
  Serial.print("%");
  Serial.println();

}
else{
  Blynk.virtualWrite(V1, 0);
}


}




