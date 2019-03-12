#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

const char *ssid =  "Rahul";     // replace with your wifi ssid and wpa2 key
const char *pass =  "alokrp3328";

int IN1=0;
String motor="OFF";
WiFiClient client;
 
void setup() 
{
       Serial.begin(9600);
       delay(10);
               
       Serial.println("Connecting to ");
       Serial.println(ssid); 
 
       WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
      Serial.println("");
      Serial.println("WiFi connected"); 

      pinMode(IN1, OUTPUT);
}
 
void loop() 
{      
 
 int soil=digitalRead(D0);

 int water=analogRead(A0);
 
  
  HTTPClient http;    //Declare object of class HTTPClient
 
  String Soil, Water, postData,Motor;
 // int adcvalue=20;//analogRead(A0);  //Read Analog value of LDR
  Soil = String(soil);   //String to interger conversion
  Water = String(water); 
//  station = "A";
 
  //Post Data
  Motor=String(motor);
  postData = "soil=" + Soil + "&water=" + water;
  Serial.print("Data =");
  Serial.println(postData);
  
  http.begin("http://192.168.1.103/nodemcu/postdemo.php");              //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
 
  int httpCode = http.POST(postData);   //Send the request
  String payload = http.getString();    //Get the response payload
  Serial.print("Payload =   ");
  Serial.print(payload);
  if( payload =="1")
  {
    digitalWrite(IN1, HIGH);
    Serial.println("Motor status ON");
    delay(3000);
    digitalWrite(IN1, LOW);
    Serial.println("Motor status off");  
  }
  else
  {
   digitalWrite(IN1, LOW);
   Serial.println("Motor status off");  
  }
 
  //Serial.println(httpCode);   //Print HTTP return code
  //Serial.println(payload);    //Print request response payload
 
  http.end();  //Close connection
  
  delay(5000);  //Post Data at every 5 seconds
}
