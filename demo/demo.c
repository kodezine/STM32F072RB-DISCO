#include <stdbool.h>
#include <stdint.h>

#include "demo.h"
#include "main.h"
#include "stm32f0xx_hal.h"

extern CAN_HandleTypeDef hcan;
extern I2C_HandleTypeDef hi2c2;
extern SPI_HandleTypeDef hspi2;
extern TSC_HandleTypeDef htsc;
extern PCD_HandleTypeDef hpcd_USB_FS;

static volatile uint8_t RxBuffer[64];
static const uint8_t dot = '.';

__NO_RETURN void app_main(void)
{
    HAL_SetTickFreq(HAL_TICK_FREQ_1KHZ);
    do
    {
        HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin); /* Toggle pin after some delay */
        HAL_Delay(20);                              /* busy wait delay */
    } while (true);
}
