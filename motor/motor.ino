int IN1=0;

void setup() {
Serial.begin(9600);
pinMode(IN1, OUTPUT);
}

void loop() {
/*delay(10000);
Serial.println("High");
digitalWrite(IN1, HIGH);
delay(5000);
digitalWrite(IN1,LOW);
Serial.println("Low");*/

//int soil=digitalRead(D0);

Serial.println("Motor on");

digitalWrite(IN1,HIGH);
delay(2000);

Serial.println("Motor off");

digitalWrite(IN1,LOW);
delay(2000);
}
 
