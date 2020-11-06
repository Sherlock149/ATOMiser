#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
#include<SoftwareSerial.h>

SoftwareSerial ArduinoUno(10,11);

//int gas = A0;
//int data = 0;
void setup() {
  // put your setup code here, to run once:
//randomSeed(analogRead(0));
ArduinoUno.begin(115200);
Serial.begin(115200);
lcd.begin(16,2);
pinMode(A5,INPUT);
lcd.print(" Gas Leakage ");
lcd.setCursor(0,1);
lcd.print("Detection System");
delay(3000);
lcd.clear();
pinMode(13, OUTPUT);
pinMode(12,OUTPUT);
pinMode(9, OUTPUT);  
pinMode(10,INPUT);
pinMode(11,OUTPUT);   
}

void loop() {
  // put your main code here, to run repeatedly:
int data = analogRead(A5)-285;
if(data<=0)
  data=0;
if(data>=100)
  data=100;
Serial.print("Gas Level: ");
Serial.println(data);
lcd.print ("Gas Scan is ON");
lcd.setCursor(0,1);
lcd.print("Gas Level: ");
lcd.print(data);
ArduinoUno.print(data);
//ArduinoUno.println("\n");
delay(1000);
 
if ( data > 40) //
{
//SendMessage();
Serial.println("Gas detect alarm");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Gas Level Exceed");
delay(5000);
digitalWrite(12, HIGH);
digitalWrite(13, LOW); 
digitalWrite(9, HIGH);
}
else
{
Serial.println("Gas Level Low");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Gas Level Normal");
delay(5000);
digitalWrite(13, HIGH);
digitalWrite(12, LOW);
digitalWrite(9, LOW);
}
 
lcd.clear();
}
