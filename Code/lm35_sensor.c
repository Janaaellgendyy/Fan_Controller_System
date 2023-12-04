 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.c
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Jana Wael
 *
 *******************************************************************************/


#include "ADC.h"
#include <util/delay.h>
#include "lm35_sensor.h"


uint8 LM35_GetTemperature(void){

	uint8 tempValue = 0;

	uint16 adcValue = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adcValue = ADC_readChannel(SENSOR_CHANNEL_ID);

	tempValue = (uint8)(((uint32)adcValue * SENSOR_MAX_TEMPERATURE * ADC_Reference_Volt) / (ADC_MAXIMUM_VALUE * SENSOR_MAX_VOLT));

	return tempValue;
}
