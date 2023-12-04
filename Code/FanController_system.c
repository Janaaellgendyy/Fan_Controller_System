/******************************************************************************
 *
 * Module: Fan Controller System
 *
 * File Name:FanController_system.h
 *
 * Description: Temperature controlled fan using ATMEGA32 MicroController,
 * where the fan automatically turns ON or OFF according to the temperature.
 *
 * Author: Jana Wael
 *
 *******************************************************************************/


#include "ADC.h"
#include "DC_Motor.h"
#include "lcd.h"
#include "lm35_sensor.h"

#define ROW_0 0
#define ROW_1 1
#define COLUMN_0 0



int main(void){

	uint8 temp;

	/* Create configuration structure for The ICU driver */

	ADC_ConfigType ADC_Configs = {INTERNAL_VOLTAGE_REFERENCE, ADC_Factor_8};

	/* Call initialization function of ADC driver */

	ADC_init(&ADC_Configs);

	/* Call initialization function of LCD driver */

	LCD_init();

	/* Call initialization function of DC Motor driver */

	DcMotor_Init();

	/* Display the string "Fan is " only once at first row*/

	LCD_displayStringRowColumn(ROW_0,COLUMN_0,"Fan is  ");

	LCD_moveCursor(1,0); /* Move the cursor to the second row */

	LCD_displayStringRowColumn(ROW_1,COLUMN_0,"Temp =    C"); 	/* Display the string "Fan is " only once at second row*/

		while(1){

		   temp = LM35_GetTemperature();

		   LCD_moveCursor(1,7);
		   LCD_intgerToString(temp);
		   if (temp<100)
			   LCD_displayCharacter(' ');


		   if(temp < 30){

			   LCD_moveCursor(1, 7);
			   DcMotor_Rotate(STOP, 0);
			   LCD_moveCursor(0, 7);
			   LCD_displayString("OFF");
		   }
		   else if(temp >= 30 && temp < 60){

			   LCD_moveCursor(1, 7);
			   DcMotor_Rotate(CW, 25);
			   LCD_moveCursor(0,7);
			   LCD_displayString("ON");
		   }
		   else if(temp >= 60 && temp < 90){

			   LCD_moveCursor(1, 7);
			   DcMotor_Rotate(CW, 50);
			   LCD_moveCursor(0,7);
			   LCD_displayString("ON");
		   }
		   else if(temp >= 90 && temp < 120){

			   LCD_moveCursor(1, 7);
			   DcMotor_Rotate(CW, 75);
			   LCD_moveCursor(0,7);
			   LCD_displayString("ON");

		   }
		   else if (temp >= 120 && temp <= 150){
			LCD_moveCursor(1, 7);
			DcMotor_Rotate(CW, 100);
			LCD_moveCursor(0, 7);
			LCD_displayString("ON");


		   }
		}
	}

