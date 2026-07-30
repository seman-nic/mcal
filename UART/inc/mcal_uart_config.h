#ifndef MCAL_UART_CONFIG_H
#define MCAL_UART_CONFIG_H

/* Define the number of UART channels available in the system.
 * This can be adjusted based on the specific microcontroller 
 * and application requirements.
 */

typedef enum {
    UART_CH_1 = 0,
    UART_CH_2,
    UART_MAX_CH_NUMBER // Dynamically acts as the total count!
} UART_Channel_t;

#endif // MCAL_UART_CONFIG_H