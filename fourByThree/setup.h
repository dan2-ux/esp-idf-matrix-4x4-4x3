#pragma once

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern QueueHandle_t kkk3;

const char fourByThree[4][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'},
};

struct matrixGPIOr3
{
    gpio_num_t gpio[4];
    gpio_mode_t mode;
};
struct matrixGPIOc3
{
    gpio_num_t gpio[4];
    gpio_mode_t mode;
};

void setupMATRIXGPIO3(matrixGPIOr3 *pinR, matrixGPIOc3 *pinC);
void getMATRIX3(matrixGPIOr3 *pinR, matrixGPIOc3 *pinC);
void displayMATRIX3(matrixGPIOr3 *pinR, matrixGPIOc3 *pinC);
