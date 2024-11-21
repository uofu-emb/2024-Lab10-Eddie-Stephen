/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#pragma GCC optimize ("O0")
#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"


bool on = false;
#define OUT_PIN 1
#define IN_PIN 0


#define MAIN_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )
#define BLINK_TASK_PRIORITY     ( tskIDLE_PRIORITY + 2UL )
#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define BLINK_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

void blink_task(__unused void *params) {


    while (true) {        
        gpio_put(OUT_PIN, on);

        uint32_t k; 
        for (int i = 0; i < 3000000; i++) { 
            uint32_t j = 0;
            j = ((~j >> i) + 1) * 27644437; 
            k = j; 
        } 
        


        on = !on;
        //vTaskDelay(500);
    }
}


void irq_callback(uint gpio, uint32_t event_mask)
{

    if (gpio != IN_PIN) return;
    if (event_mask & GPIO_IRQ_EDGE_RISE) {
        gpio_put(OUT_PIN, on);
        on = !on;
    }
    
}



int main( void )
{
    stdio_init_all();
    gpio_init(OUT_PIN);
    gpio_set_dir(OUT_PIN, GPIO_OUT);
    const char *rtos_name;
    rtos_name = "FreeRTOS";
    // TaskHandle_t task;
    // xTaskCreate(blink_task, "BlinkThread",
    //              BLINK_TASK_STACK_SIZE, NULL, BLINK_TASK_PRIORITY, NULL);
    // vTaskStartScheduler();
    gpio_set_irq_enabled_with_callback(IN_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL , true, irq_callback);
    while(1) __wfi();
    return 0;
}
