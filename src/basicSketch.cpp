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

int timeStart = millis();
#define MAX_MILLIS 477218

bool timeLapseMillis(int deltaMs)
{
    int now;
    int delta = 0;

        now = millis();
        if(now < timeStart)
        {
            // this handles timer counter overflow
            // when counter overflows, 'now' becomes < 'start'
            delta = MAX_MILLIS - timeStart + now;
        }
        else
        {
            // regular situation is when 'start' comes before 'now'
            delta = now - timeStart;
        }

        if(delta < deltaMs)
            return false;

        timeStart = now;
        return true;
}

void loop(void)
{
    if(timeLapseMillis(1000))
	{
		digitalWrite(LED_BUILTIN, ledState);
		ledState = ledState == LOW ? HIGH : LOW;
	}
//    int now = millis();
//    if(now - time > 1000)
//	{
//    	time = now;
//		digitalWrite(LED_BUILTIN, ledState);
//		ledState = ledState == LOW ? HIGH : LOW;
//	}

    yield();
}

