#include "unity.h"
#include "string.h"

#include "mcal_can.h"

/* Target source file for testing
 * mcal_can_<target>.c
 */
TEST_SOURCE_FILE("mcal_can_stm32.c")

static HAL_StatusTypeDef g_hal_status;
static CAN_RxHeaderTypeDef g_hal_header;
static uint8_t g_hal_data[8];


static void set_hal_frame(uint32_t id, uint8_t dlc,uint8_t data)
{
	g_hal_header.StdId = id;
	g_hal_header.ExtId = id;
	g_hal_header.IDE = 0;
	g_hal_header.DLC = dlc;

	for (uint8_t i = 0; i < 8; i++)
	{
		g_hal_data[i] = (uint8_t)(data + i);
	}
}

HAL_StatusTypeDef HAL_CAN_GetRxMessage(CAN_HandleTypeDef *hcan,
										uint32_t fifo,
										CAN_RxHeaderTypeDef *pHeader,
										uint8_t *aData)
{
	(void)hcan;
	(void)fifo;

	if (g_hal_status != HAL_OK)
	{
		return g_hal_status;
	}

	*pHeader = g_hal_header;
	memcpy(aData, g_hal_data, sizeof(g_hal_data));
	return HAL_OK;
}

static void flush_driver_queue(void)
{
	
}

void setUp(void)
{
    // This runs before every single test
}

void tearDown(void)
{
    // This runs after every single test
}

void test_can_driver_read_returns_false_when_buffer_is_empty(void)
{
	CAN_HandleTypeDef hcan;
	CAN_Frame_t frame;

	set_hal_frame(0x123, 8, 0xAA);

	bool result = mcal_can_read(&hcan, &frame);

	TEST_ASSERT_EQUAL_UINT32(0x123, frame.id);
	TEST_ASSERT_EQUAL_UINT8(8, frame.dlc);
	TEST_ASSERT_EQUAL_UINT8(0xAA, frame.data[0]);
	TEST_ASSERT_EQUAL_UINT8(0xAB, frame.data[1]);
	TEST_ASSERT_EQUAL_UINT8(0xAC, frame.data[2]);
	TEST_ASSERT_EQUAL_UINT8(0xAD, frame.data[3]);
	TEST_ASSERT_EQUAL_UINT8(0xAE, frame.data[4]);
	TEST_ASSERT_EQUAL_UINT8(0xAF, frame.data[5]);
	TEST_ASSERT_EQUAL_UINT8(0xB0, frame.data[6]);
	TEST_ASSERT_EQUAL_UINT8(0xB1, frame.data[7]);
	TEST_ASSERT_TRUE(result);
}

