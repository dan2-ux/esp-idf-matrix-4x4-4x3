#pragma once

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern QueueHandle_t kkk;

const char fourByFour[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};

struct matrixGPIOr
{
    gpio_num_t gpio[4];
    gpio_mode_t mode;
};
struct matrixGPIOc
{
    gpio_num_t gpio[4];
    gpio_mode_t mode;
};

void setupMATRIXGPIO(matrixGPIOr *pinR, matrixGPIOc *pinC);
void getMATRIX(matrixGPIOr *pinR, matrixGPIOc *pinC);
void displayMATRIX(matrixGPIOr *pinR, matrixGPIOc *pinC);
