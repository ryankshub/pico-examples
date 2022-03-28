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
// Modified quadrature encoder for 2 encoders
//

int main() {
    int new_value1, delta1, old_value1 = 0;
    int new_value2, delta2, old_value2 = 0;
    // Base pin to connect the A phase of the encoder.
    // The B phase must be connected to the next pin
    const uint PIN_AB1 = 10;
    const uint PIN_AB2 = 14;

    stdio_init_all();

    PIO pio = pio0;
    const uint sm1 = 0;
    const uint sm2 = 1;

    uint offset = pio_add_program(pio, &quadrature_encoder_program);
    quadrature_encoder_program_init(pio, sm1, offset, PIN_AB1, 0);
    quadrature_encoder_program_init(pio, sm2, offset, PIN_AB2, 0);

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

        printf("position1 %8d, delta1 %6d;  position2 %8d, delta2 %6d\n", 
            new_value1, delta1, new_value2, delta2);
        sleep_ms(100);
    }
}

