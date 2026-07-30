#ifndef MCAL_UART_H
#define MCAL_UART_H

#include "stm32f4xx_hal.h"
#include "mcal_uart_config.h"
#include <stdbool.h>
#include <stdint.h>

/* TODO : Add Parser and Frame structures
 * #define UART_MAX_FRAME_SIZE  64
 * 
 * 
 * typedef enum  {
 *     UART_DETECT_BY_SIZE,
 *     UART_DETECT_BY_TERMINATOR,
 * } UART_DetectMode_t;
 * 
 * typedef struct {
 *     UART_DetectMode_t detect_mode;
 *     uint8_t terminator;
 *     uint16_t frame_size;
 * } UART_Config_t;
 * 
 *typedef struct {
 *  uint8_t data[UART_MAX_FRAME_SIZE];
 *  uint16_t length;
 *  bool isReady;
 *} UART_Frame_t;
 */

/*
 * Function: mcal_uart_init
 * ----------------------
 * Initializes the UART driver for a specific channel.
 * 
 * Parameters:
 * huart: pointer to the UART handle.
 * channel: the UART channel to initialize.
 * 
 */
void mcal_uart_init(UART_HandleTypeDef *huart, UART_Channel_t channel);

/*
 * Function: mcal_uart_write
 * ----------------------
 * Writes data to the UART channel.
 * 
 * Parameters:
 * channel: the UART channel to write to.
 * data: pointer to the data buffer.
 * length: number of bytes to write.
 * 
 * Returns:
 * true if the write operation was successful, false otherwise.
 */
bool mcal_uart_write(UART_Channel_t channel, const uint8_t *data, uint16_t length);

#endif // MCAL_UART_H