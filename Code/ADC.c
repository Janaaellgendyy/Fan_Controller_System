/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Source file for the ADC driver
 *
 * Author: Jana Wael
 *
 *******************************************************************************/
#include "ADC.h"



void ADC_init(const ADC_ConfigType * Config_Ptr){

	/*
`	 * insert the required vref value in the last two bits (REFS1, REFS0)
	 * of ADMUX Register
	 */
	ADMUX |= (ADMUX & 0x3F) | (Config_Ptr ->ref_volt << 6);

	/*
	 * ADEN = 1 Enable ADC
	 */
	ADCSRA |= (1 << ADEN);

	/*
	 * insert the required clock value in the first three bits (ADPS2, ADPS1 and ADPS0)
	 * of ADCSRA Register
	 */

	ADCSRA = (ADCSRA & 0XF8)| (Config_Ptr ->prescaler);


}

uint16 ADC_readChannel(uint8 channel_num){

	/* (ADMUX & 0xE0) Clear first 5 bits in the ADMUX (MUX4,MUX3,MUX2,MUX1,MUX0) before set the required channel
	 * (ch_num & 0x07) Input channel number must be from 0 --> 7
	 *
	 */

	ADMUX = (ADMUX & 0xE0) | (channel_num & 0x07);

	/*
	 * Start conversion write '1' to ADSC
	 */

	SET_BIT(ADCSRA, ADSC);

	/*
	 * Wait for conversion to complete by polling until flag "ADIF" becomes '1'
	 */

	while (BIT_IS_CLEAR(ADCSRA, ADIF)){}

	/*
	 * Clear ADIF by write '1' to it
	 */

	SET_BIT(ADCSRA,ADIF);

	/*
	 * Read the digital value from the data register
	 */

return ADC;
}

