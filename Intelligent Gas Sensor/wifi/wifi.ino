#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <BlynkSimpleEsp8266.h>
#include <math.h>
int data=0;
int ctr=0;
int chk=1;
int tme=0;
/*************************** Sketch Code ************************************/
#define R_SSID       "Home Wifi"
#define PASS       "Abhishek1091921"

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "Sherlock149"
#define AIO_KEY         "aio_FsCL50FtDaW8GZ7gh7N530yU7JLs"
#define auth            "5Vx-q0j1KFcCCGe4AuCdA2CaroAGpmhL"

/************ Global State ******************/

WiFiClient client;
// or... use WiFiFlientSecure for SSL
//WiFiClientSecure client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/****************************** Feeds ***************************************/


Adafruit_MQTT_Publish Leakage = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/leak");

Adafruit_MQTT_Publish Graph = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/graph");
void setup(){
	Serial.begin(115200);
	//NodeMCU.begin(9600);
	//pinMode(D3,INPUT);
	//pinMode(D2,OUTPUT);
 delay(10);
  
  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(R_SSID);

  WiFi.begin(R_SSID, PASS);
  int counter=10;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    counter--;
    if(counter==0){
      // reset me
        ESP.reset();
    }
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());
  Blynk.begin(auth, R_SSID, PASS);
}

void loop(){
	//while(NodeMCU.available()>0){
  MQTT_connect();
  Blynk.run();
  int val = Serial.read()-48;
  if(val>=0 && ctr==0)
  {
    chk=0;
    data=0;
    Serial.println("");
  }
  if(val>=0)
  {
    if(ctr==0)
    data = data+int(val)*100;
    if(ctr==1)
    data = data+int(val)*10;
    if(ctr==2)
    data = data+int(val);
     
    //Serial.print(val);
    //val= -1;
    //Serial.print(ctr);
    
    ctr++;
  }
  else if(chk==0)
  {
    if(ctr==2)
    {
      data = data/10;
    }
    else if(ctr==1)
    {
      data = data/100;
    }
    Serial.println(data);
    Blynk.virtualWrite(V2, data);
    if(data>40)
    Blynk.notify("Gas Leak !");
    if(tme>=30)
    {
      if (! Leakage.publish(data)) { 
      Serial.println(F("Upload Failed"));
      }
      if (! Graph.publish(data)) { 
      Serial.println(F("Upload Failed"));
      }
      tme = 0;
    }
    ctr=0;
    chk=1;
  }
  else
  {
    Serial.print(".");
    ctr=0;
  }
  delay(500);
  tme++;
  
}
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 5;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // reset me
        ESP.reset();
       }
  }
  Serial.println("MQTT Connected!");
}
