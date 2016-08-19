#include "Arduino.h"
#include "sketch.h"

#define FW_VERSION "0.1.0"


void setup(void)
{
    Serial.begin(115200, SERIAL_8N1);
    printBanner();

    Serial.println("zeeduino basic sketch");
    Serial.print("firmware v");
    Serial.println(FW_VERSION);

    pinMode(LED_BUILTIN, OUTPUT);
}

int ledState = LOW;
byte byteRead;

void loop(void)
{
    if(timeLapseMillis(1000))
	{
		digitalWrite(LED_BUILTIN, ledState);
		ledState = ledState == LOW ? HIGH : LOW;
	}

    yield();
}

