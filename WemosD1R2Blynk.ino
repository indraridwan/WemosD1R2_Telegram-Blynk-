
#include <Ethernet.h>     //modul ethernet
#include <Servo.h>             //modul servo
#include <ESP8266WiFi.h>    //modul esp8266
#define BLYNK_PRINT Serial   //modul blynk serial
#include <BlynkSimpleEsp8266.h>'     //modul blynk esp8266
#include "remap.h"       //modul soket wemos d1 r2
Servo servo;                  //deklarasi servo
int aksi = D3 ;  //deklarisi pinout
//cek email dan copy paste kan disini
char auth[] = "";  /// token blynk IOT
 
//isikan nama wifi dan passwordnya
char ssid[] = "";    ///SSID HOTSPOT WIFI
char pass[] = "";    ///PASSWORD HOTSPOT Wifi

BLYNK_WRITE(V0)                     //V0 dan V1 piout virtual
{
  digitalWrite(aksi , HIGH); /// kondisi nyala
  servo.write(0);
  delay(1000);
}
BLYNK_WRITE(V1)
{
  digitalWrite(aksi , LOW);   //kondisi mati
  servo.write(170);
  delay(1000);
}
 
void setup()
{
  Serial.begin(115200); //baudrate atau jangkauan  komunikasi
  Blynk.begin(auth, ssid, pass);
  pinMode (aksi , OUTPUT);
  servo.attach(D3);
}
 
void loop()
{
  Blynk.run();
}