  
/*  */

//Libraries
#include <DHT.h>

//Constants
#define L 36.1
#define H 37.4
#define DHTPIN 2     
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);

//Variables
float temp; //Stores temperature value
float tempprev; //Stores previous temperature value

void setup()
{
    Serial.begin(9600);
    dht.begin();
}
void loop()
{
    temp= dht.readTemperature();
    
    Serial.print("Vital Temp: ");
    Serial.print(temp);
    Serial.print(" Celsius");
    
    if(temp < L) {
      Serial.println(" Hypothermia Warning!");
      digitalWrite(LED_BUILTIN, HIGH);
    }
    
    else if(temp > H) {
      Serial.println(" Hyperthermia Warning!");
      digitalWrite(LED_BUILTIN, HIGH);

    }
    
    else {
      Serial.println(" Normal");
      digitalWrite(LED_BUILTIN, LOW);
    }

    if(temp - tempprev > 0.2 || temp - tempprev < -0.2 ) {
      Serial.println("Rapid Temp Change Detected!");
      digitalWrite(LED_BUILTIN, HIGH);
    }
    
    temp = tempprev; //Previous temp log
    
    delay(600000); 
}
