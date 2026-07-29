#include "mcal_can.h"


bool mcal_can_read( CAN_HandleTypeDef *hcan,
                    CAN_Frame_t *rx_frame)
{
    CAN_Frame_t frame;
    CAN_RxHeaderTypeDef rxHeader;

    if (HAL_CAN_GetRxMessage(hcan,
                             CAN_RX_FIFO0,
                             &rxHeader,
                             frame.data) != HAL_OK)
    {
        return false;
    }

    if (rxHeader.DLC < 8)
    {
        return false;
    }

    frame.id = (rxHeader.IDE == CAN_ID_STD) ? rxHeader.StdId : rxHeader.ExtId;
    frame.dlc = (uint8_t)rxHeader.DLC;
    
    *rx_frame = frame;
    return true;
}

bool mcal_can_timestamp_read( CAN_HandleTypeDef *hcan,
                    uint32_t timestamp,
                    CAN_Frame_t *rx_frame)
{
    if (!mcal_can_read(hcan, rx_frame))
    {
        return false;
    }

    rx_frame->timestamp = timestamp;
    return true;
}
