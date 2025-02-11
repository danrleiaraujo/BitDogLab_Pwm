#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22  // GPIO onde o servo está conectado

const float DIVIDER_PWM = 125.0; // Valor encontrado em calculos na parte de anotações

#define MIN_PULSE 500  // Pulso mínimo em µs (0 graus)
#define MID_PULSE 1470 // Pulso médio em µs (90 graus)
#define MAX_PULSE 2400 // Pulso máximo em µs (180 graus)

#define INCREMENT 5    // Incremento para movimento suave

#define DELAY_MS_I 10    // Atraso entre cada incremento 0,010s
#define DELAY_MS_P 5000    // Atraso entre pulsos 5s

// Variavel
bool decremento = 0;
int pulso;

void mov_periodica(){
    if(pulso == MAX_PULSE){ // Verifica se o pulso atual está no valor max
        decremento = 1; // Liga o decremento
    }
    else if(pulso == MIN_PULSE){ // Verifica se o pulso atual está no valor min
        decremento = 0; // desliga o decremento
    }

    if(decremento){ // Verifica se o decremento está ativo
        pulso = pulso - INCREMENT; // Diminui o pulso atual em 5
    }
    else{
        pulso = pulso + INCREMENT; // Aumenta o pulso atual em 5
    }

    pwm_set_gpio_level(SERVO_PIN, pulso); // Manda o novo valor para o pino

}

int main() {
    stdio_init_all();
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(SERVO_PIN); //obter o canal (slice) PWM da GPIO

    pwm_set_clkdiv(slice, DIVIDER_PWM); //define o divisor de clock do PWM

    pwm_set_wrap(slice, MAX_PULSE); //definir o valor de wrap – valor máximo do contador PWM

    pwm_set_enabled(slice, 1); //habilitar o pwm no slice correspondente

    pwm_set_gpio_level(SERVO_PIN, MAX_PULSE); // Manda o valor do pulso maximo para o pino
    sleep_ms(DELAY_MS_P); //  5s

    pwm_set_gpio_level(SERVO_PIN, MID_PULSE); // Manda o valor do pulso medio para o pino
    sleep_ms(DELAY_MS_P); //  5s

    pwm_set_gpio_level(SERVO_PIN, MIN_PULSE); // Manda o valor do pulso minimo para o pino
    sleep_ms(DELAY_MS_P); //  5s

    pulso = MIN_PULSE; 

    // Loop para movimentação contínua do servo entre 0° e 180°
    while (1) {
        mov_periodica(pulso);
        sleep_ms(DELAY_MS_I);
    }
}

/* Anotacoes:
    Frequencia 50 hz
    Periodo 20 ms = 0,02 s
    Tensao Maxima = 3,3 v
    wrap = 20 000
    clock_div = 125.0

    FORUMULAS:
    frequencia = clock_freq / (wrap * clock_div)
    clock_div = 125 000 000 / 20 000 * 50
    Duty Cicle = (ciclo ativo / periodo) * 100
    Tensao Media = Tensao Max * Duty Cicle
    Tensão eficaz (Vrms) = Tensao Max * raiz_quadrada(Duty Cicle)

    ciclo ativo 1 = 2400 us = 0,0024 s
    Duty Cicle 1 = 0,12 ou 12 %
    Tensao Media 1 = 0,396
    Tensao eficaz 1 = 1,14 v
    
    ciclo ativo 2 = 1470 us = 0,00147 s
    Duty Cicle 2 = 0,0735 ou 7,35 %
    Tensao Media 2 = 0,24255
    Tensao eficaz 2 = 0,89 v

    ciclo ativo 3 = 500 us = 0,0005 s
    Duty Cicle 3 = 0,025 ou 2,5 %
    Tensao Media 3 = 0,0825
    Tensao eficaz 3 = 0,52 v
*/