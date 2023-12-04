 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: header file for the LM35 Temperature Sensor driver
 *
 * Author: Jana Wael
 *
 *******************************************************************************/


#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_MAX_VOLT 1.5
#define SENSOR_MAX_TEMPERATURE 150
#define SENSOR_CHANNEL_ID 2

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Function Name : LM35_getTemperature
 * Description : Function responsible for calculate the temperature from the ADC digital value.
 * Parameters : void.
 * Return : uint8 : Temperature value.
 */

uint8 LM35_GetTemperature(void);



#endif /* LM35_SENSOR_H_ */
