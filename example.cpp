#include "setup.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

struct matrixGPIOr row =
    {
        .gpio = {GPIO_NUM_13, GPIO_NUM_12, GPIO_NUM_14, GPIO_NUM_27},
        .mode = GPIO_MODE_INPUT,
};
struct matrixGPIOc col =
    {
        .gpio = {GPIO_NUM_26, GPIO_NUM_25, GPIO_NUM_33, GPIO_NUM_32},
        .mode = GPIO_MODE_OUTPUT,
};

void printOutMatrix(void *arg)
{
    while (1)
    {
        displayMATRIX(&row, &col);
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

extern "C" void app_main()
{
    setupMATRIXGPIO(&row, &col);

    xTaskCreatePinnedToCore(printOutMatrix, "print out the pressing matrix value", 2048, NULL, 5, NULL, 1);
}
