#include <dht11.h>
#define DHT11PIN A0

dht11 DHT11;

const int read = A0; //Sensor AO pin to Arduino pin A0
int value;          //Variable to store the incomming data
const int RELAY_MIST = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(RELAY_MIST, OUTPUT);
 
}
  
void loop()
{
  Serial.println();

  int chk = DHT11.read(DHT11PIN);
  
  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);
  Serial.println(DHT11.humidity);
  Serial.print("Temperature (C): ");
  Serial.println((float)DHT11.temperature, 2);
  delay(2000);
  
  value = analogRead(read); //Read data from analog pin and store it to value variable

  if (value > 60)
  {
    
    digitalWrite(RELAY_MIST, LOW); 
  }
  else
  {
    digitalWrite(RELAY_MIST, HIGH); 
  } 
}