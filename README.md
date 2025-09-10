# LED Interfacing with Push Button on Tiva C Series LaunchPad (ARM Cortex-M4)

This beginner project demonstrates how to interface a push button with an LED on the TM4C123GH6PM microcontroller.
A pull-down resistor is used with the push button to achieve Positive Logic (HIGH state when pressed and LOW state when released).
When the button (connected to Port C, Pin 6) is pressed, the LED (connected to Port F, Pin 1) turns ON. Otherwise, the LED remains OFF.

The program is written in C and built using Keil uVision v5.42.

![pushbutton led 1](https://github.com/user-attachments/assets/1faf6c0b-ef02-46f0-bc12-9a8f9f2f87ea) ![pushbutton led 2](https://github.com/user-attachments/assets/3f75934f-7d7a-4e30-8921-e0c0b1c67b72)


## Hardware
- Tiva C Series TM4C123G LaunchPad (ARM Cortex-M4)
- Push Button
- LED (already included with the Tiva LaunchPad)
- 10kΩ pull-down resistor for push button
- Breadboard and jumper wires

## Circuit Connections

Push Button:
- One side of button -> PC6 (Port C Pin 6)
- Other side of button -> +3.3V
- Pull-down resistor (10kΩ) between PC6 and GND (ground)

![pull down resistor](https://github.com/user-attachments/assets/18a5a2a7-20e2-4a77-bf0e-34b869edbcd7)


LED:
- Anode -> PF1 (Port F Pin 1) as digital output pin
- Cathode -> GND

## Software Details

Clock Enable:
- Set bit 2 & 5 of RCGC_GPIO_R register to enable clock for Port C & Port F

GPIO Setup:
- PC6 configured as digital input
- PF1 configured as digital output

Logic:
- Reads PC6 input pin
- If button pressed -> PF1 state will be HIGH -> LED turns On
- Else -> PF1 state is LOW -> LED is OFF

## How to Run
1. Open the project in Keil uVision v5.42.
2. Connect the TM4C123G LaunchPad via USB.
3. Click Build Target in the Project tab and then Download the program to the microcontroller.
4. Press the button to turn the LED on.
5. Release the button to turn the LED off.
