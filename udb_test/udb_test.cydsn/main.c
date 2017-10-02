/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <stdint.h>
#include "project.h"

#define ELEMENTS(x)     (sizeof(x)/sizeof(x[0]))

uint16_t adcBuf[2][2000];
uint8_t currentAdcBuf = 0;
uint8 adcDMA_Chan;
uint8 adcDMA_TD[1];
 
void configureDMA(uint16_t * ptr)
{
    CyDmaTdSetConfiguration(adcDMA_TD[0], 1000, CY_DMA_DISABLE_TD, CY_DMA_TD_TERMIN_EN | CY_DMA_TD_INC_DST_ADR);
    CyDmaTdSetAddress(adcDMA_TD[0], LO16((uint32)ADC_SAR_SAR_WRK0_PTR), LO16((uint32)ptr));
    CyDmaChSetInitialTd(adcDMA_Chan, adcDMA_TD[0]);
    CyDmaChEnable(adcDMA_Chan, 1);    
}

CY_ISR(adc_isr)
{
    currentAdcBuf = currentAdcBuf ? 0 : 1;
    configureDMA(adcBuf[currentAdcBuf]);
}

uint32_t executeCIC(uint16_t *x, int32_t * y, uint32_t len)
{
    #define N 4
    #define R 10
    static int32_t sigma[N]  = {0};
    static int32_t delta[N]  = {0};
    static int32_t pDelta[N] = {0};

    for (uint32_t i = 0; i < len; i++)
    {
        pDelta[0] = sigma[3];
        pDelta[1] = delta[1];
        pDelta[2] = delta[2];
        pDelta[3] = delta[3];

        for (uint32_t n = 0; n < R; n++)
        {
            sigma[0] += x[(i*R)+n];
            sigma[1] += sigma[0];
            sigma[2] += sigma[1];
            sigma[3] += sigma[2];
        }

        delta[1] = sigma[3] - pDelta[0];
        delta[2] = delta[1] - pDelta[1];
        delta[3] = delta[2] - pDelta[2];
        y[i] = delta[3] - pDelta[3];
    }
    return len;
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    WaveDAC8_Start();
    ADC_SAR_Start();
    Timer_Start();
    
    /* Defines for adcDMA */
    #define adcDMA_BYTES_PER_BURST 2
    #define adcDMA_REQUEST_PER_BURST 1
    #define adcDMA_SRC_BASE (CYDEV_PERIPH_BASE)
    #define adcDMA_DST_BASE (CYDEV_SRAM_BASE)

    /* DMA Configuration for adcDMA */
    adcDMA_Chan = adcDMA_DmaInitialize(adcDMA_BYTES_PER_BURST, adcDMA_REQUEST_PER_BURST, 
        HI16(adcDMA_SRC_BASE), HI16(adcDMA_DST_BASE));
    adcDMA_TD[0] = CyDmaTdAllocate();
    configureDMA(adcBuf[0]);
    
    adcISR_StartEx(adc_isr);
    
    ADC_SAR_StartConvert();     
    
    int32_t y[100];
    volatile uint16_t start = Timer_ReadCounter();
    executeCIC(adcBuf[0], y, 100);
    volatile uint16_t stop = Timer_ReadCounter();
    volatile uint16_t diff = stop - start;
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
