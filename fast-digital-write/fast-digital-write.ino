// #####################################################################################################################
// ######################################### FAST DIGITAL WRITE ########################################################
// ##################################################################################################################### 
/*
	This script shows how fast you actually can access a digital pin on the arduino.

	Therefore you need two commands:
		digitalWrite(Pin, HIGH);  -->  PORT{Port} |= _BV(PORT{Port}{Portnumber});
		digitalWrite(Pin, LOW);   -->  PORT{Port} &= ~_BV(PORT{Port}{Portnumber});

	{Port} and {Portnumber} are both described in the readme.
*/

#define LED 13

int startTime = 0;
int stopTime = 0;

void setup()
{
	// setup pins
	pinMode(LED, OUTPUT);
	// setup serial com
	Serial.begin(9600);
	Serial.println("ARDUINO WRITE-TIME COMPARISON");
}

void loop()
{
	// get time for slow writing
	Serial.print("\n  Slow access on pin 13: ");
	
	startTime = micros();
	for (int i = 0; i < 1000; i++)
	{
		digitalWrite(LED, HIGH);
		digitalWrite(LED, LOW);
	}
	stopTime = micros();

	Serial.println(stopTime - startTime);

	// get time for fast writing
	Serial.print("  Fast access on pin 13: ");
	
	startTime = micros();
	for (int i = 0; i < 1000; i++)
	{
		PORTB |= _BV(PORTB5);
		PORTB &= ~_BV(PORTB5);
	}
	stopTime = micros();

	Serial.println(stopTime - startTime);

	delay(5000);
}