# Fast Digital Write
This script shows you how you can access the Arduino's pins faster than with the standard command (digitalWrite()).
For this you only need your Arduino (I've used the Nano v3) and your PC or Mac.

Basically you have to replace the Arduino commands with true c commands, which I show you now:

- digitalWrite(Pin, HIGH);  -->  PORT{Port} |= _BV(PORT{Port}{Portnumber});
- digitalWrite(Pin, LOW);   -->  PORT{Port} &= ~_BV(PORT{Port}{Portnumber});

{Port} and {Portnumber} are the ID's from the pins on the ATmega328, which are used in the Arduino UNO and Arduino Nano v3.
Which port is which index is mapped here:

Arduino Pin | Port | Portnumber
------------|------|-----------
Pin 0		|D     |0
Pin 1		|D	   |1	 
Pin 2		|D     |2
Pin 3		|D     |3
Pin 4		|D     |4
Pin 5		|D     |5
Pin 6		|D     |6
Pin 7		|D     |7
Pin 8		|B     |0
Pin 9		|B     |1
Pin 10		|B     |2
Pin 11		|B     |3
Pin 12		|B     |4
Pin 13		|B     |5

For further information, please visit my blog:

--- currently no link ---