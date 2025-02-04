#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 13
#define LED_YELLOW 12
#define LED_GREEN 11

#define SEMAFORO_INTERVALO_MS 3000
#define SERIAL_PRINT_INTERVALO_MS 1000
static volatile int estado_semaforo = 0;


bool repeating_timer_callback(struct repeating_timer *t) {
    gpio_put(LED_RED, 0);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 0);

    switch (estado_semaforo) {
        case 0:
            gpio_put(LED_RED, 1); 
            printf("🚦 Semáforo: VERMELHO\n");
            estado_semaforo = 1;
            break;
        case 1:
            // gpio_put(LED_RED, 1); // Amarelo ligado para a placa BitDogLab
            // gpio_put(LED_GREEN, 1); // Amarelo ligado para a placa BitDogLab
            gpio_put(LED_YELLOW, 1); 
            printf("🚦 Semáforo: AMARELO\n");
            estado_semaforo = 2;
            break;
        case 2:
            gpio_put(LED_GREEN, 1); 
            printf("🚦 Semáforo: VERDE\n");
            estado_semaforo = 0;
            break;
    }
    return true; 
}

int main() {
    stdio_init_all(); 

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    printf("\n🚦 Iniciando Simulador de Semáforo...\n");

    struct repeating_timer semaforo_timer;
    add_repeating_timer_ms(-SEMAFORO_INTERVALO_MS, repeating_timer_callback, NULL, &semaforo_timer);

    while (1) {
        printf("⌛ Tempo correndo...\n");
        sleep_ms(SERIAL_PRINT_INTERVALO_MS);
    }

    return 0;
}
