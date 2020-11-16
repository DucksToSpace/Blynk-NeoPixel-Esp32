#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Adafruit_NeoPixel.h>

int r = 0;
int g = 0;
int b = 0;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "a-XQEjMY39ShGB2hcW1XUao6bLqQw0cL";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Sagitarios";
char pass[] = "rigel123";

#define PIN 33

Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, PIN, NEO_GRB + NEO_KHZ800);

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if (WheelPos < 85) {
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 170;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

BLYNK_WRITE(V3){  // This function gets called each time something changes on the widget
  r = param.asInt();  // This gets the 'value' of the Widget as an integer
  Serial.print(r);
  Serial.print("||");
  Serial.print(g);
  Serial.print("||");
  Serial.println(b);

}
BLYNK_WRITE(V4){  // This function gets called each time something changes on the widget
  g = param.asInt();  // This gets the 'value' of the Widget as an integer
  Serial.print(r);
  Serial.print("||");
  Serial.print(g);
  Serial.print("||");
  Serial.println(b);
  
}
BLYNK_WRITE(V5){  // This function gets called each time something changes on the widget
  b = param.asInt();  // This gets the 'value' of the Widget as an integer
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
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  strip.begin();
  strip.show();
}

void loop()
{
  Blynk.run();

 for(int i=0; i<50;i++){
  strip.setPixelColor(i, strip.Color(r, g, b));
 }
 strip.show();
}
