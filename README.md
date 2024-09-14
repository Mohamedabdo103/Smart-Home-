# Smart-Home-
Smart Home /AVR microcontroller

Overview
This project implements a basic Smart Home System using an AVR microcontroller. The system allows the user to control two rooms, an alarm system, and a bell system through a user-friendly interface. A virtual terminal connected via USART protocol displays all actions taken.

Features
Room 1 Control:

Consists of LED and Fan.
Allows the user to turn the LED and fan on or off.
Room 2 Control:

Similar to Room 1, it consists of LED and Fan for control.
Alarm System:

Includes a temperature sensor, red LED, and buzzer.
If the temperature exceeds 40°C, the red LED turns on, the buzzer sounds, and the system halts with the message !Temp Above 40 displayed on the LCD.
Bell System:

Activated via a push button.
When the button is pressed, the system stops, and the LCD displays Bell Ringing.
System Workflow
Welcome Message:
The system starts by displaying a welcome message on the LCD.

User Authentication:

The user must enter a valid ID (IDs: 123, 456) and password (Passwords: 123, 456).
If the wrong password is entered 3 times, the system locks for 5 minutes and displays System Lock.
Room Selection:

After successful authentication, the user can choose to control Room 1 or Room 2.
Options:
1: LED
2: Fan
3: Back (return to previous menu)
4: Clear (reset and start from the beginning)
Device Control:

After selecting a device (LED or Fan), the system will prompt:
1: Turn On
2: Turn Off
3: Back
4: Clear
Virtual Terminal:

All actions are logged and displayed on the virtual terminal via the USART protocol.
Technologies Used
AVR Microcontroller
LCD Display
USART Protocol for virtual terminal display
Sensors and Actuators: LEDs, Fans, Temperature Sensor, Buzzer, Push Button
