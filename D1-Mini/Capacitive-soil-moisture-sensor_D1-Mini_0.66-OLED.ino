#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 22 // GPIO 22
Adafruit_SSD1306 display(OLED_RESET);

const int dry = 0; // value for dry sensor
const int wet = 100; // value for wet sensor

void setup()
{ 
  Serial.begin(9600);
  Wire.begin(8,10);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop()
{
  // Clear the buffer.
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(40, 10);
  display.setTextColor(WHITE);
  
  int sensorVal = analogRead(A0);

  // Sensor has a range of 0 to 100
  // We want to translate this to a scale or 0% to 100%
  int percentageHumididy = map(sensorVal, wet, dry, 100, 0); 

   display.println("Moisture: ");
   display.setTextSize(1);
   display.setCursor(40, 21);
   display.print(percentageHumididy);
   display.println("%");
   display.display();
   delay(1000);
}
