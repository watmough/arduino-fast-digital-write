# Arduino: Fast Digital Write

## 1 Description

This script shows you how you can access the Arduino's pins faster than with the standard command (digitalWrite()).
For this you only need your Arduino (I've used the Nano v3) and your PC or Mac.

Basically you have to replace the Arduino commands with true c commands, which I show you now:

- digitalWrite(Pin, HIGH);  -->  PORT{Port} |= _BV(PORT{Port}{Portnumber});
- digitalWrite(Pin, LOW);   -->  PORT{Port} &= ~_BV(PORT{Port}{Portnumber});

{Port} and {Portnumber} are the ID's from the pins on the ATmega328, which are used in the Arduino UNO and Arduino Nano v3.
Which port is which index is mapped here:

Arduino Pin | {Port} | {Portnumber}
------------|--------|-------------
Pin 0		|D       |0
Pin 1		|D	     |1	 
Pin 2		|D       |2
Pin 3		|D       |3
Pin 4		|D       |4
Pin 5		|D       |5
Pin 6		|D       |6
Pin 7		|D       |7
Pin 8		|B       |0
Pin 9		|B       |1
Pin 10		|B       |2
Pin 11		|B       |3
Pin 12		|B       |4
Pin 13		|B       |5

To turn on pin 13 use `PORTB |= _BV(PORTB5);`  
And to turn it off use `PORTB &= ~_BV(PORTB5);`

For further information, please visit my website:

- [English](http://deloarts.com/de/scripts/arduino/fast-digital-write)
- [German](http://deloarts.com/de/scripts/arduino/fast-digital-write)

## 2 License

This project is licensed under the GNU GPLv3 open source license. Thus anybody is allowed to copy and modify the source code, provided all changes are open source too and the author is in knowledge of all done changes. This can happen either via eMail or directly on GitHub, in other words at this repository.

## 3 Disclaimer

I am not responsible for anything in conjunction with this project, including bugs, failure, fire, harm of equipment and harm of persons. Reasonably foreseeable misapplication:

- Bug in the code
- Failure of used parts due to a bug in the code or a wrong wiring diagram, including a wrong design.
- Fire due to a wrong wiring diagram, including a wrong design.
- Harm of equipment, meaning third party parts (cameras, flashes, etc.) due to a bug in the code or a wrong wiring diagram, including a wrong design.
- Harm of persons due to any failure of the system, a wrong wiring diagram or a wrong behaviour.

**It is your own responsibility to use these contents**. Be careful, this project includes lethal electrical voltage. Put yourself in knowledge about the risks before you start with this project.
