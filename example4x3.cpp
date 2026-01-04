#include "setup.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// enter the 4 gpio for row into the struct bellow
struct matrixGPIOr3 row =
    {
        .gpio = {GPIO_NUM_13, GPIO_NUM_12, GPIO_NUM_14, GPIO_NUM_27},
        .mode = GPIO_MODE_INPUT,
};

// enter the 3 gpio for col into the struct bellow
struct matrixGPIOc3 col =
    {
        .gpio = {GPIO_NUM_26, GPIO_NUM_25, GPIO_NUM_33},
        .mode = GPIO_MODE_OUTPUT,
};

void printOutMatrix(void *arg)
{
    while (1)
    {
        displayMATRIX3(&row, &col);
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

extern "C" void app_main()
{
    setupMATRIXGPIO3(&row, &col);

    xTaskCreatePinnedToCore(printOutMatrix3, "print out the pressing matrix value", 2048, NULL, 5, NULL, 1);
}
