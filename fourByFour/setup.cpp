#include "setup.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

QueueHandle_t kkk = NULL;
TimerHandle_t timer1 = NULL;

void peeping(TimerHandle_t xTimer)
{
    buzzerGPIO *buzzer = (buzzerGPIO *)pvTimerGetTimerID(xTimer);
    gpio_set_level(buzzer->pin, 0);
}

void setupMATRIXGPIO(matrixGPIOr *pinR, matrixGPIOc *pinC, buzzerGPIO *buzzer)
{
    for (int i = 0; i < 4; i++)
    {
        gpio_reset_pin(pinR->gpio[i]);
        gpio_set_direction(pinR->gpio[i], pinR->mode);
        gpio_reset_pin(pinC->gpio[i]);
        gpio_set_direction(pinC->gpio[i], pinC->mode);
        gpio_set_level(pinC->gpio[i], 1);
    }
    gpio_reset_pin(buzzer->pin);
    gpio_set_direction(buzzer->pin, GPIO_MODE_OUTPUT);

    kkk = xQueueCreate(5, sizeof(char));
    timer1 = xTimerCreate(
        "buzzer peep when matrix is pressed",
        pdMS_TO_TICKS(100),
        pdFALSE,
        (void *)buzzer,
        peeping);
    if (kkk == NULL || timer1 == NULL)
    {
        ESP_LOGE("ERROR", "Can't define queue or timer");
    }

    printf("Matrix 4x4 is ready\n");
}

void getMATRIX(matrixGPIOr *pinR, matrixGPIOc *pinC)
{
    for (int c = 0; c < 4; c++)
    {
        gpio_set_level(pinC->gpio[c], 0);
        for (int r = 0; r < 4; r++)
        {
            if (gpio_get_level(pinR->gpio[r]) == 0)
            {
                xQueueSend(kkk, &fourByFour[r][c], portMAX_DELAY);
                vTaskDelay(pdMS_TO_TICKS(100));
            }
            vTaskDelay(pdMS_TO_TICKS(5));
        }
        gpio_set_level(pinC->gpio[c], 1);
    }
}
void displayMATRIX(matrixGPIOr *pinR, matrixGPIOc *pinC, buzzerGPIO *buzzer)
{
    getMATRIX(pinR, pinC);
    char displayInformation;
    if (xQueueReceive(kkk, &displayInformation, 0) == pdTRUE)
    {
        printf("%c\n", displayInformation);
        gpio_set_level(buzzer->pin, 1);
        if (xTimerIsTimerActive(timer1) == pdTRUE)
        {
            xTimerReset(timer1, 0);
        }
        xTimerStart(timer1, 0);
    }
}
