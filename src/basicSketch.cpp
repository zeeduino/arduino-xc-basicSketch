#include "Arduino.h"

#define FW_VERSION "0.1.0"

void setup(void)
{
    Serial.begin(115200, SERIAL_8N1);
    Serial.println("app name");
    Serial.print("v");
    Serial.println(FW_VERSION);

    pinMode(LED_BUILTIN, OUTPUT);
}

int ledState = LOW;
int time = 0;

void loop(void)
{
    int now = millis();
    if(now - time > 1000)
	{
    	time = now;
		digitalWrite(LED_BUILTIN, ledState);
		ledState = ledState == LOW ? HIGH : LOW;
	}

    yield();
}

