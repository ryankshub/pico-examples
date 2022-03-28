/**
 * Copyright (c) 2021 pmarques-dev @ github
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/timer.h"

#include "quadrature_encoder.pio.h"

//
// ---- quadrature encoder interface example
//
// Modified quadrature encoder example for 3 encoders
//

int main() {
    int new_value1, delta1, old_value1 = 0;
    int new_value2, delta2, old_value2 = 0;
    int new_value3, delta3, old_value3 = 0;
    // Base pin to connect the A phase of the encoder.
    // The B phase must be connected to the next pin
    const uint PIN_AB1 = 18;//10;
    const uint PIN_AB2 = 14;
    const uint PIN_AB3 = 10;//18;

    stdio_init_all();

    PIO pio = pio0;
    const uint sm1 = 0;
    const uint sm2 = 1;
    const uint sm3 = 2;

    uint offset = pio_add_program(pio, &quadrature_encoder_program);
    quadrature_encoder_program_init(pio, sm1, offset, PIN_AB1, 0);
    quadrature_encoder_program_init(pio, sm2, offset, PIN_AB2, 0);
    quadrature_encoder_program_init(pio, sm3, offset, PIN_AB3, 0);

    while (1) {
        // note: thanks to two's complement arithmetic delta will always
        // be correct even when new_value wraps around MAXINT / MININT
        new_value1 = quadrature_encoder_get_count(pio, sm1);
        new_value2 = quadrature_encoder_get_count(pio, sm2);
        new_value3 = quadrature_encoder_get_count(pio, sm3);
        delta1 = new_value1 - old_value1;
        delta2 = new_value2 - old_value2;
        delta3 = new_value3 - old_value3;
        old_value1 = new_value1;
        old_value2 = new_value2;
        old_value3 = new_value3;

        printf("%d,%d,%d", 
            delta1, delta2, delta3);
        sleep_ms(100);
    }
}

