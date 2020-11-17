#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Adafruit_NeoPixel.h>

int r = 0;
int g = 0;
int b = 0;

//Define the pin of the NeoPixel strip connected to the Esp32 and The Numbers of Leds on the strip
#define PIN 33
#define NumLeds 50

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Blynk token";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Network Name";
char pass[] = "Network password";

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NumLeds, PIN, NEO_GRB + NEO_KHZ800);

BLYNK_WRITE(V1){  // This function gets called each time something changes on the widget
  r = param.asInt();  // This gets the 'value' of the Slider as an integer
  
  Serial.print(r);
  Serial.print("||");
  Serial.print(g);
  Serial.print("||");
  Serial.println(b);

}
BLYNK_WRITE(V2){  // This function gets called each time something changes on the widget
  g = param.asInt();  // This gets the 'value' of the Slider as an integer
  
  Serial.print(r);
  Serial.print("||");
  Serial.print(g);
  Serial.print("||");
  Serial.println(b);
  
}
BLYNK_WRITE(V3){  // This function gets called each time something changes on the widget
  b = param.asInt();  // This gets the 'value' of the Slider as an integer
  
  Serial.print(r);
  Serial.print("||");
  Serial.print(g);
  Serial.print("||");
  Serial.println(b);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  strip.begin();
  strip.show();
}

void loop()
{
  Blynk.run();

 for(int i=0; i<=NumLeds;i++){
  strip.setPixelColor(i, strip.Color(r, g, b));
 }
 strip.show();
}
