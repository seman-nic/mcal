#include "unity.h"
#include "string.h"

#include "mcal_uart.h"

/* Target source file for testing
 * mcal_uart_<target>.c
 */
TEST_SOURCE_FILE("mcal_uart_stm32.c")

extern UART_HandleTypeDef *uartHandle[];

HAL_StatusTypeDef HAL_UART_Transmit ( UART_HandleTypeDef *huart, 
                                      const uint8_t *pData,
                                      uint16_t Size,
                                      uint32_t Timeout)
{

    return HAL_OK;
}

void clear_uart_handle(void)
{
    for (size_t i = 0; i < UART_MAX_CH_NUMBER; i++)
    {
        uartHandle[i] = NULL;
    }
}

void setUp(void)
{
    // This runs before every single test
    clear_uart_handle();
}

void tearDown(void)
{
    // This runs after every single test
}


void test_mcal_uart_init(void)
{
    UART_HandleTypeDef huart1;
    UART_HandleTypeDef huart2;

    mcal_uart_init(&huart1, UART_CH_1);
    mcal_uart_init(&huart2, UART_CH_2);

    // Verify that the handles are stored correctly
    TEST_ASSERT_EQUAL_PTR(&huart1, uartHandle[UART_CH_1]);
    TEST_ASSERT_EQUAL_PTR(&huart2, uartHandle[UART_CH_2]);
}

void test_mcal_uart_write_success(void)
{
    UART_HandleTypeDef huart;
    mcal_uart_init(&huart, UART_CH_1);

    const uint8_t data[] = "Hello, UART!";
    bool result = mcal_uart_write(UART_CH_1, data, sizeof(data) - 1);

    // Verify that the write operation was successful
    TEST_ASSERT_TRUE(result);
}

void test_mcal_uart_write_null_handle(void)
{
    // UART Initialization is not done for UART_CH_1, so the handle is NULL

    const uint8_t data[] = "Hello, UART!";
    bool result = mcal_uart_write(UART_CH_1, data, sizeof(data) - 1);

    // Verify that the write operation fails when the handle is NULL
    TEST_ASSERT_FALSE(result);
}

void test_mcal_uart_write_invalid_channel(void)
{
    UART_HandleTypeDef huart;
    mcal_uart_init(&huart, UART_CH_1);

    const uint8_t data[] = "Hello, UART!";
    bool result = mcal_uart_write((UART_Channel_t)99, data, sizeof(data) - 1); // Invalid channel

    // Verify that the write operation fails for an invalid channel
    TEST_ASSERT_FALSE(result);
}

