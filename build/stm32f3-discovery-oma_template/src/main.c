/*Name: testi.c*/
#
#include <stm32f30x.h>
#include <stm32f3_discovery.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void InitPeripheralDevices();

volatile uint32_t TickCount = 0;
volatile uint32_t DelayCount = 0;
uint32_t delay_value = 500;

void SysTick_Handler()
{
        TickCount++;
        DelayCount--;
}

void Delay(uint32_t ms)
{
        DelayCount = ms;
        while (DelayCount > 0);
}

int main()
{
        InitPeripheralDevices();
        
        while (1)
        {
    /* Clockwise rotation in 50ms steps */
                STM_EVAL_LEDToggle(LED3);
                Delay(delay_value);
                STM_EVAL_LEDToggle(LED5);
                Delay(delay_value);
                STM_EVAL_LEDToggle(LED7);
                Delay(delay_value);
                STM_EVAL_LEDToggle(LED9);
                Delay(delay_value);
                STM_EVAL_LEDToggle(LED10);
                Delay(delay_value);
                STM_EVAL_LEDToggle(LED8);
                Delay(delay_value);
                STM_EVAL_LEDToggle(LED6);
                Delay(delay_value);
                STM_EVAL_LEDToggle(LED4);
                Delay(delay_value);
        }
}

void InitPeripheralDevices()
{
  RCC_ClocksTypeDef rcc;

  /* Get the configured clock frequencies */
  RCC_GetClocksFreq(&rcc);

  /* Setup the SysTick timer */
  SysTick_Config(rcc.HCLK_Frequency / 1000);

  /* Initialize the LEDs on the discovery board */
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
  STM_EVAL_LEDInit(LED5);
  STM_EVAL_LEDInit(LED6);
  STM_EVAL_LEDInit(LED7);
  STM_EVAL_LEDInit(LED8);
  STM_EVAL_LEDInit(LED9);
  STM_EVAL_LEDInit(LED10);
}

