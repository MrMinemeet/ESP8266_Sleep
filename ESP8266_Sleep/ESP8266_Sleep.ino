#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SSD1306_128_64

#define DHT11_PIN D5
#define OLED_ADR 0x3C


void setup() {
  Adafruit_SSD1306 display(-1);
  
  DHT dht(DHT11_PIN, DHT11);
  Serial.begin(9600);
  while(!Serial);
  
  Serial.println("Started!");
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADR);
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.display();

  
  display.clearDisplay();

  Serial.print("Temperature = ");
  Serial.println(dht.readTemperature());
  Serial.print("Humidity = ");
  Serial.println(dht.readHumidity());
  
  // Temp auf Display ausgeben
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temp.: ");
  display.setTextSize(2);
  display.print(dht.readTemperature());
  display.print("C");
    
  // humidity auf Display ausgeben
  display.setTextSize(1);
  display.setCursor(0,32);
  display.print("Feucht.: ");
  display.setTextSize(2);
  display.print(dht.readHumidity());
  display.print("%");

  display.display();
  // Sleep ESP8266 for 20^6 Microseconds
  ESP.deepSleep(20e6);
}

void loop() {
}
