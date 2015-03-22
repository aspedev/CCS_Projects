#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "hw_types.h"
#include "hw_memmap.h"
#include "hw_ints.h"
#include "timer.h"
#include "gpio.h"
#include "interrupt.h"
#include "adm.h"
#include "sysctl.h"
#include "adc.h"
#include <../../srv/lcd/lcd.h>


void adm_configuration(void)
{
    ADCClockConfigSet(ADC0_BASE,ADC_CLOCK_SRC_PIOSC | ADC_CLOCK_RATE_FULL, 1);

    //
    // Enable the first sample sequencer to capture the value of channel 0 when
    // the processor trigger occurs.
    //
	ADCSequenceDisable(ADC0_BASE, 0);
    ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
    ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_TS);
    ADCSequenceStepConfigure(ADC0_BASE, 0, 1, ADC_CTL_CH0);
    ADCSequenceStepConfigure(ADC0_BASE, 0, 2, ADC_CTL_IE | ADC_CTL_END | ADC_CTL_CH1);
    ADCSequenceEnable(ADC0_BASE, 0);
    ADCIntClear(ADC0_BASE, 0);

    //ADCIntRegister(ADC0_BASE,0,&isr_adm_sequencer);

    //ADCIntClear(ADC0_BASE, 0);
    //ADCIntEnable(ADC0_BASE, 0);
    //
    // Trigger the sample sequence.
    //
   // ADCProcessorTrigger(ADC0_BASE, 0);

	//IntEnable(INT_ADC0SS0);
	//IntMasterEnable();
	//ADCProcessorTrigger(ADC0_BASE, 0);

}

void adm_getValue (){
	//ADCSequenceDisable(ADC0_BASE, 0);

	ADCProcessorTrigger(ADC0_BASE, 0);
	while(!ADCIntStatus(ADC0_BASE, 0, false))
	{
	}
	ADCIntClear(ADC0_BASE, 0);
	ADCSequenceDataGet(ADC0_BASE, 0, adc_sequencer);
	//ADCSequenceEnable(ADC0_BASE, 0);
}

/*void isr_adm_sequencer (void){
	ADCSequenceDisable(ADC0_BASE, 0);
	while(!ADCIntStatus(ADC0_BASE, 0, false))
	{
	}
	ADCIntClear(ADC0_BASE, 0);
	ADCSequenceDataGet(ADC0_BASE, 0, adc_sequencer);

	ADCSequenceEnable(ADC0_BASE, 0);
	ADCProcessorTrigger(ADC0_BASE, 0);

}*/
