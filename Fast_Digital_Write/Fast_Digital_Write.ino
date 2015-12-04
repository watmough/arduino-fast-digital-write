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

#define Output_Pin 13

int Start_Time = 0;
int Stop_Time = 0;
// ##################################################################################################################### 
// ######################################### SETUP #####################################################################
// ##################################################################################################################### 
void setup()
{
	// setup pins
	pinMode(Output_Pin, OUTPUT);
	// setup serial com
	Serial.begin(9600);
	Serial.println("ARDUINO WRITE-TIME COMPARISON");
}
// ##################################################################################################################### 
// ######################################### LOOP ######################################################################
// ##################################################################################################################### 
void loop()
{
	// get time for slow writing
	Serial.print("\n  Slow access on pin 13: ");
	
	Start_Time = micros();
	for (int i = 0; i < 1000; i++)
	{
		digitalWrite(Output_Pin, HIGH);
		digitalWrite(Output_Pin, LOW);
	}
	Stop_Time = micros();

	Serial.println(Stop_Time - Start_Time);

	// get time for fast writing
	Serial.print("  Fast access on pin 13: ");
	
	Start_Time = micros();
	for (int i = 0; i < 1000; i++)
	{
		PORTB |= _BV(PORTB5);
		PORTB &= ~_BV(PORTB5);
	}
	Stop_Time = micros();

	Serial.println(Stop_Time - Start_Time);

	delay(5000);
}
// ##################################################################################################################### 
// ######################################### END OF CODE ###############################################################
// ##################################################################################################################### 