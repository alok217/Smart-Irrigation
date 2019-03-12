

#include <DHT.h>

#define DHTTYPE DHT11   // DHT 11
#define DHTPIN 2

#define dht_dpin 0
DHT dht(DHTPIN, DHTTYPE); 
void setup(void)
{ 
  Serial.begin(115200);
  dht.begin();
  Serial.println("Humidity and temperature\n\n");
  delay(700);

}
void loop() {
//  
   float humidityData = dht.readHumidity();
    float TempData = dht.readTemperature();         
    if (isnan(humidityData) || isnan(TempData))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

    //Print to Serial monitor or Terminal of your chocice at 115200 Baud
  Serial.print("Humidity: ");
  Serial.print(humidityData);
  Serial.print(" %\t");
  Serial.print("Temperature in Cel: ");
  Serial.print(TempData);
  Serial.print(" *C ");
//    Serial.print("Current humidity = ");
//    Serial.print(h);
//    Serial.print("%  ");
//    Serial.print("temperature = ");
//    Serial.print(t); 
//    Serial.println("C  ");
  delay(800);
}
