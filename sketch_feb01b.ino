
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define TRIGGERPIN D1
#define ECHOPIN    D2

char auth[] = "PiKEDbt-UrENVwDFgFgjATkOsDMlordM";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ANDROIDAPDP33";
char pass[] = "jainsahab1";

WidgetLCD lcd(V1);

void setup()
{
  // Debug console
  Serial.begin(9600);
pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

  lcd.clear();
  lcd.print(0, 0,"Distance in cm 0"); 
}

void loop()
{
  lcd.clear();
  lcd.print(0, 0, "Distance in cm 0"); // use: (position X: 0-15
  long duration, distance;
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(3); 
  
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12); 
  
  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  if(distance==0)
  {
    Serial.println(distance);
    lcd.print(0, 0, "Accident Detected");
  }
  else
  {
  Serial.println(distance);
  lcd.print(7, 1, distance);
  }
  Blynk.run();

  delay(1000);

}
