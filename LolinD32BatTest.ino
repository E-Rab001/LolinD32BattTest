/*
 Name:		LolinD32BatTest.ino
 Created:	7/22/2018 10:12:51 AM
 Author:	rodri
*/

uint8_t batteryPin = 35;
uint8_t ledPin = 5;
uint8_t batteryPercent;

void setup() 
{
	Serial.begin(115200);
	pinMode(batteryPin, INPUT);
	pinMode(ledPin, OUTPUT);
}

void loop() 
{
	batteryPercent = 45; //BatteryPercent();
	if (batteryPercent > 50)
	{
		digitalWrite(ledPin, LOW);
	}
	else if (batteryPercent <= 50)
	{
		digitalWrite(ledPin, !digitalRead(ledPin));
	}
	Serial.print(batteryPercent);
	Serial.print("% | ");
	delay(3);
	Serial.println(BatteryVoltage());
	delay(500);
}

uint8_t BatteryPercent()
{
	return (analogRead(batteryPin) * 0.14881) - 250.0; //simplified the map functions formula...
}

double BatteryVoltage()
{
	return analogRead(batteryPin) / 560.0; //analogRead value divided by the Voltage gives roughly 560
}