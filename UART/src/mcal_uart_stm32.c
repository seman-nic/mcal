#include "mcal_uart.h"
#include <string.h>

#ifdef TEST
#define STATIC  /* Strips the static keyword for unit tests */
#else
#define STATIC static
#endif

STATIC UART_HandleTypeDef   *uartHandle[UART_MAX_CH_NUMBER];

void mcal_uart_init(UART_HandleTypeDef *huart, UART_Channel_t channel)
{
    uartHandle[channel] = huart;
}

bool mcal_uart_write(UART_Channel_t channel, const uint8_t *data, uint16_t length)
{
    UART_HandleTypeDef *huart = uartHandle[channel];
    if (huart == NULL) 
    {
        return false;
    }

    HAL_StatusTypeDef status = HAL_UART_Transmit(huart, (uint8_t *)data, length, HAL_MAX_DELAY);

    if (status != HAL_OK) {
        return false;
    }
    return true;
}
