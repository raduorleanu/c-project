Standard I/O-Driver (Library)
=============================

This library contains a buffered and interrupt driven serial driver for the ATMEGA2560 MCU found on the STK600 board, the driver includes also code that sets up standard in- and output to use this driver to make it possible to use the functions in `stdio.h`.

Usage
-----

The Standard I/O-Driver have only one function that must be called during initialisation, and before any stdio.h functions are called.

```c
/*
Connects stdin and stdout to the usart_no given. The USART are setup like this: 57600 baud,
8 Data bits, 1 Stop bit and No parity.
After this is called function is called, it is possible to use printf(), scanf etc.
@note This function must be called before using printf(), scanf etc.
@note Remember to enable global interrupt by calling sei()ABC.
@param[in] usart_no no of the USART to setup and connect to stdin and stdout [0..3].
@param[in] f_cpu the CPU clock frequency [MHz].
*/
void init_stdio(uint8_t usart_no, long f_cpu);

```

After this function is called it is possible to use standard I/O functions like printf, puts, getchar, scanf etc. The in- and output of these functions will be redirected to the specified serial port (usart_no) on the MCU. In this assignment USART no 0 will be used; thus the call should be: 
```c
// Setup stdio to use USART0, and tell that 10 MHz is CPU frequency
init_stdio(0, 10000000L);

```
NOTE: Remember to enable interrupt (call `sei()`) when the total initialization of the application is finished.

Hardware Setup on the ATmega2560
--------------------------------

* *PORTE PE0* must be connected to *RS232 SPARE RXD*
* *PORTE PE1* must be connected to *RS232 SPARE TXD*
* A USB to Serial adaptor must be connected between another of your Laptop’s USB ports and the RS232 connector on the STK600 board.

Atmel Studio Project Setup
--------------------------
1. Extract the static library *libatmega2560_drivers.a* and the corresponding header file *atmega2560_drivers.h* somewhere on your hard drive.
1. Right click on the project (in the solution explorer) and select *Add Library*
1. Click *browse libraries* and then *Browse*
1. Navigate to the location where you extracted the library file and select *libatmega2560_drivers.a* and click *Open*.
1. Add the header file by right clicking the project, then select *Add -> Existing item...*

Example
-------

You can include the header and call the init function like this:
```c
#include <avr/interrupt.h>
#include "atmega2560_drivers.h"

int main(void)
{
    init_stdio(0, 10000000L);
    // you initialization code here...
    sei();
    // and then the rest of your program...
}

```