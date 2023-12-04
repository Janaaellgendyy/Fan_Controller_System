/*
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the ADC driver
 *
 * Author: Jana Wael
 *
 *******************************************************************************/

#include "std_types.h"

#ifndef ADC_H_
#define ADC_H_

#include<avr/io.h>
#include"std_types.h"
#include"common_macros.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADC_MAXIMUM_VALUE 1023
#define ADC_Reference_Volt 2.56

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

/*
 * DESCRIPTION: enum responsible for vref values.
 */
typedef enum {

	AREF , AVCC , RESERVED , INTERNAL_VOLTAGE_REFERENCE

}ADC_ReferenceVolatge;


/*
 * DESCRIPTION: enum responsible for ADC prescaler values.
 */

typedef enum{

	ADC_Factor_2_1, ADC_Factor_2_2, ADC_Factor_4, ADC_Factor_8,
	ADC_Factor_16, ADC_Factor_32, ADC_Factor_64, ADC_Factor_128

}ADC_Prescaler;

/*
 * DESCRIPTION: struct responsible for ADC Configuration.
 */

typedef struct{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Function Name : ADC_init
 * Description : Function responsible for initialize the ADC driver.
 * Parameters : ADC_ConfigType : struct responsible for ADC Configuration.
 * Return : void.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Function Name : ADC_readChannel
 * Description : Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 * Parameters : ch_num : ADC channel number.
 * Return : uint16 : ADC value.
 */
uint16 ADC_readChannel(uint8 channel_num);


#endif /* ADC_H_ */
