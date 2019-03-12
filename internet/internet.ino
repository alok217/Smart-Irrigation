
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

const char *ssid =  "nishant";     // replace with your wifi ssid and wpa2 key
const char *pass =  "nishant1234";

WiFiClient client;
int IN1=0;

 
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

    pinMode(IN1,OUTPUT);
    pinMode(D0,INPUT);
}
 
void loop() 
{      
   HTTPClient http;    //Declare object of class HTTPClient
 //soil
  String Soil, station, postData,Water;
  int soil=digitalRead(D0);  //Read Analog value of LDR
  Soil = String(soil);   //String to interger conversion
  station = "A"; //user name

  //water
  int water=analogRead(A0);
  Water = String(water);
  Serial.println(analogRead(A0));
  delay(100);

  
 
  //Post Data
  postData = "soil=" + Soil + "&water=" + Water ;
  
  http.begin("http://192.168.43.19/IOTProject/Server/server.php");              //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
 
  int httpCode = http.POST(postData);   //Send the request
  String payload = http.getString();    //Get the response payload
  if(payload=="1")
  {
    Serial.println("Motor On");
    digitalWrite(IN1,HIGH);
  }
  else{
    Serial.println("Motor Off");
    digitalWrite(IN1,LOW);
    }
  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload


  http.end();  //Close connection
  
  delay(5000);  //Post Data at every 5 seconds
}
