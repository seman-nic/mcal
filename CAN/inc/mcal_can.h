#ifndef MCAL_CAN_H
#define MCAL_CAN_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stm32f4xx_hal_can.h"

typedef struct {
    uint32_t id;
    uint8_t dlc;
    uint8_t data[8];
    uint32_t timestamp;
} CAN_Frame_t;


/* Function: mcal_can_read
 * ----------------------
 * Reads a CAN frame from the internal buffer.
 * 
 * Parameters:
 * hcan: pointer to the CAN handle.
 * frame: pass CAN frame by reference.
 *
 * returns:
 * true  - if a frame was successfull read from the buffer.
 * false 
 *  - HAL Error
 *  - Frame DLC is less than 8
 */
bool mcal_can_read( CAN_HandleTypeDef *hcan,
                    CAN_Frame_t *rx_frame);

/* Function: mcal_can_timestamp_read
 * ----------------------
 * Reads a CAN frame from the internal buffer.
 * 
 * Parameters:
 * hcan: pointer to the CAN handle.
 * timestamp: the timestamp of the frame to read.
 * frame: pass CAN frame by reference.
 *
 * returns:
 * true  - if a frame was successfull read from the buffer.
 * false 
 *  - HAL Error
 *  - Frame DLC is less than 8
 */
bool mcal_can_timestamp_read( CAN_HandleTypeDef *hcan, 
                    uint32_t timestamp, 
                    CAN_Frame_t *frame);

#endif // MCAL_CAN_H
