#include <Arduino.h>
#include <TFT_eSPI.h>
#include "NotoSansBold15.h"
#include "cards.h"
#include "OneButton.h"
#include <WiFi.h>
#define up 14
#define down 0

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);
OneButton button(down, true);

const char *ssid = "Hartmann Private";
const char *password = "golden-apple-juice";

int textColor = TFT_RED;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void draw()
{
    sprite.fillSprite(TFT_BLACK);
    sprite.setTextDatum(0);
    sprite.loadFont(NotoSansBold15);
    sprite.setTextColor(textColor);

    sprite.drawString("WIFI SSID: " + String(ssid), 8, 3);
    // sprite.drawString("IP: " + String(WiFi.localIP()), 8, 24);
    sprite.pushSprite(0, 0);
}

void doubleClick()
{
    Serial.println("Double Click");
    textColor = TFT_MAGENTA;
}

void Click()
{
    Serial.println("Click");
    textColor = TFT_ORANGE;
}

void setup()
{
    Serial.begin(115200);

    pinMode(up, INPUT_PULLUP);
    pinMode(down, INPUT_PULLUP);
    pinMode(15, OUTPUT);
    digitalWrite(15, 1);

    tft.init();
    prite(320, 170);
    sprite.setSwapBytes(1);
    button.attachDoubleClick(doubleClick);
    button.attachClick(Click);

    ledcSetup(0, 10000, 8);
    ledcAttachPin(38, 0);
    ledcWrite(0, 160);

    // WiFi.mode(WIFI_STA); // Optional
    // WiFi.begin(ssid, password);
    // Serial.println("\nConnecting");

    // while (WiFi.status() != WL_CONNECTED)
    // {
    //     Serial.print(".");
    //     delay(100);
    // }

    // Serial.println("\nConnected to the WiFi network");
    // Serial.print("Local ESP32 IP: ");
    // Serial.println(WiFi.localIP());
}

void loop()
{
    draw();
    button.tick();
}
