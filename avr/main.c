// Required AVR Libraries
#include <avr/io.h>
#include <avr/interrupt.h>

// User-Created Include Files
#include "my_lcd_h.h"

int main(void)
{
	// Configure Board I/O
	
		// LED Pins set to Outputs
		// Sensor Pins set to Inputs
		PORTB.DIR = 0xF0;
		PORTB.OUTSET = 0xF0; //4 LEDs Off
		
		// QTouch button pins, LCD Backlight pin,
		// and Power LED pin set to output
		// (QTouch buttons will not work in this configuration)
		PORTE.DIR = 0xFF;
		PORTE.OUTSET = 0xFF; //Power LED On, LCD Backlight On
	
	// Configure System and Peripheral Clocks

		CCP = CCP_IOREG_gc;              // disable register security for oscillator update
		OSC.CTRL = OSC_RC32MEN_bm;       // enable 32MHz oscillator
		while(!(OSC.STATUS & OSC_RC32MRDY_bm)); // wait for oscillator to be ready
		CCP = CCP_IOREG_gc;              // disable register security for clock update
		CLK.CTRL = CLK_SCLKSEL_RC32M_gc; // switch to 32MHz clock
		
		// The Real Time Counter Control Register (CLK.RTCCTRL) is used to define the source
		// for the RTC.  For this example, the 32kHz internal ULP oscillator was used as the 
		// RTC source.  The designer must ensure the RTC is enabled by setting the RTCEN bit 
		// in the CLK.RTCCTRL register.
		CLK.RTCCTRL = CLK_RTCSRC_ULP_gc | CLK_RTCEN_bm; // 0x01
	
	// Configure Interrupt Priority Level and Location of Vectors
	
		// LCD is updated using interrupts, more about interrupts on coming exercises
	
		// Enable all interrupt levels
		// Load Int vectors to application section of flash
		// Set interrupt priority to Static (lower address = higher priority)
		PMIC.CTRL = PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm; //0x07
	
	// Initialize the LCD Controller
	c42048a_init();
	
	// Enable interrupts
	sei();
	
	// Turn off backlight
	//lcd_backlight_off();
	
	// Write Test String
	uint8_t lcd_test_alpha_string[] = "XMEGA";
	lcd_write_alpha_packet(lcd_test_alpha_string);
	
	// Write a Test Number (0~19999)
	uint16_t lcd_test_num = 12345;
	c42048a_set_numeric_dec(lcd_test_num);
	
	// Turn on AVR Icon
	lcd_set_pixel(ICON_AVR);
	
	// Turn on each Bar segment
	lcd_set_pixel(ICON_LEVEL_1);
	lcd_set_pixel(ICON_LEVEL_2);
	lcd_set_pixel(ICON_LEVEL_3);
	lcd_set_pixel(ICON_LEVEL_4);
	lcd_set_pixel(ICON_LEVEL_5);
	lcd_set_pixel(ICON_LEVEL_6);
	lcd_set_pixel(ICON_LEVEL_7);
	lcd_set_pixel(ICON_LEVEL_8);
	
	lcd_set_pixel(ICON_DOT_1);
	lcd_set_pixel(ICON_DOT_2);
	lcd_set_pixel(ICON_DOT_3);
	lcd_set_pixel(ICON_DOT_4);
	lcd_set_pixel(ICON_MINUS);
	lcd_set_pixel(ICON_AM);
	lcd_set_pixel(ICON_PM);
	lcd_set_pixel(ICON_DEGREE_C);
	lcd_set_pixel(ICON_DEGREE_F);
	lcd_set_pixel(ICON_VOLT);
	lcd_set_pixel(ICON_MILLI_VOLT);
	lcd_set_pixel(ICON_LEVELBAR);
	lcd_set_pixel(ICON_USB);
	lcd_set_pixel(ICON_COLON);
	lcd_set_pixel(ICON_WARNING);
	lcd_set_pixel(ICON_IN);
	lcd_set_pixel(ICON_OUT);
	lcd_set_pixel(ICON_ERROR);
	
	while(1) {
		// Infinite Loop to add code and allow LCD
		// Frame Interrupt to continuously operate
	}
}