/* button_interface.c: Pushbutton Interfacing in C 
----------------------------------------------------------------
This program utilizes the push-button to turn on the LED when 
pressed, which is interfaced with TIVA Port C pin 6.
----------------------------------------------------------------
Hardware: TIVA C Series LaunchPad TM4C123GH6PM
IDE: Keil uVision v5.42 */

// Enable Clock
#define SYSCTL_RCGC_R *(( volatile unsigned long *)0x400FE608 )
#define SYSCTL_RCGC_GPIOCF 0x24				// enable clock on Port C and F

// GPIO Port C configuration
#define GPIO_PORTC_DATA_R *(( volatile unsigned long *)0x40006100 )
#define GPIO_PORTC_DIR_R *((volatile unsigned long *)0x40006400 )
#define GPIO_PORTC_DEN_R *((volatile unsigned long *)0x4000651C )
#define GPIO_PORTC_PIN6 0x40 // Mask for bit 6 on Port C

// GPIO Port F configuration
#define GPIO_PORTF_DATA_R *(( volatile unsigned long *)0x40025008 )
#define GPIO_PORTF_DIR_R *((volatile unsigned long *)0x40025400 )
#define GPIO_PORTF_DEN_R *((volatile unsigned long *)0x4002551C )
#define GPIO_PORTF_PIN1 0x02 // Mask for bit 1 on Port F

void delay(unsigned int ms) {          // declare Delay function
	volatile unsigned int count;
  unsigned int delayCount = ms * 1000;
  for (count = 0; count < delayCount; count++) {
	}
}

int main()
{
	// Enable the clock on both GPIO Poft C and F
	SYSCTL_RCGC_R |= SYSCTL_RCGC_GPIOCF;
	
	// Set Port C pin 6 as a digital input pin
	GPIO_PORTC_DEN_R |= GPIO_PORTC_PIN6;
	GPIO_PORTC_DIR_R &= ~GPIO_PORTC_PIN6;
	
	// Set Port F pin 1 as a digital output pin
	GPIO_PORTF_DEN_R |= GPIO_PORTF_PIN1;
	GPIO_PORTF_DIR_R |= GPIO_PORTF_PIN1;
	
	while(1) {
		GPIO_PORTF_DATA_R &= ~GPIO_PORTF_PIN1;				// clear bit 1 in Port f
		if(GPIO_PORTC_DATA_R == GPIO_PORTC_PIN6) {		// check if the button is pushed
			GPIO_PORTF_DATA_R |= GPIO_PORTF_PIN1;				// if so, turn on Led on Port F pin 1 and then delay (positive logic)
			delay(1000);
		}
	}
}