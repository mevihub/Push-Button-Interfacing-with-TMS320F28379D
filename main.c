/*
 * main.c
 *
 *  Created on: 26-Nov-2021
 *      Author: Devilal
 */




#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#include "F28x_Project.h"
#include "F2837xD_device.h"
#include "F2837xD_Examples.h"

#include "device.h"
#include "driverlib.h"

void gpio_init();

void main(void)
{
    Device_init();
    Device_initGPIO();
    gpio_init();
    while(1)
    {
        if(GPIO_readPin(67) == 0)
        {
            GPIO_writePin(DEVICE_GPIO_PIN_LED2, 1);
            DEVICE_DELAY_US(10000);
            GPIO_writePin(DEVICE_GPIO_PIN_LED2, 0);
            DEVICE_DELAY_US(10000);
        }
        if(GPIO_readPin(67)==1)
        {
            GPIO_writePin(DEVICE_GPIO_PIN_LED2, 1);
            DEVICE_DELAY_US(10000);
        }
    }

}


void gpio_init()
{
    // select input gpio pin
    GPIO_setPinConfig(GPIO_67_GPIO67);
    GPIO_setDirectionMode(67, GPIO_DIR_MODE_IN);
    GPIO_setPadConfig(67, GPIO_PIN_TYPE_PULLUP);  //  Pull-up enable for input
    GPIO_setMasterCore(67, GPIO_CORE_CPU1);

    // select output gpio pin

    GPIO_setPinConfig(DEVICE_GPIO_PIN_LED2);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_LED2, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_LED2, GPIO_PIN_TYPE_STD);
    GPIO_setMasterCore(DEVICE_GPIO_PIN_LED2, GPIO_CORE_CPU1);

}
