/* Copyright 2023 Cyboard LLC (@Cyboard-DigitalTailor)
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "dactyl_manuform_6x6_underglow.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    // left
    { 29,     30, 31, NO_LED, NO_LED, NO_LED, NO_LED }, \
    { 28,     27, 32, 38,     44,     50,     56     }, \
    { NO_LED, 22, 33, 39,     45,     51,     57     }, \
    { NO_LED, 23, 34, 40,     46,     52,     58     }, \
    { NO_LED, 24, 35, 41,     47,     53,     59     }, \
    { NO_LED, 25, 36, 42,     48,     54,     60     }, \
    { NO_LED, 26, 37, 43,     49,     55,     61     }, \
    // right
    { 91,     92, 93, NO_LED, NO_LED, NO_LED, NO_LED }, \
    { 90,     89, 94, 100,    106,    112,    118    }, \
    { NO_LED, 84, 95, 101,    107,    113,    119    }, \
    { NO_LED, 85, 96, 102,    108,    114,    120    }, \
    { NO_LED, 86, 97, 103,    109,    115,    121    }, \
    { NO_LED, 87, 98, 104,    110,    116,    122    }, \
    { NO_LED, 88, 99, 105,    111,    117,    123    } \
}, {
    // left underglow strip
    { 86, 43 },  { 86, 32 },  { 86, 21 },  { 86, 11 },  { 86, 0 },   { 86, 53 },  { 103, 53 }, { 103, 64 }, { 86, 64 },  { 69, 64 },
    { 69, 53 },  { 69, 43 },  { 69, 32 },  { 69, 21 },  { 69, 11 },  { 69, 0 },   { 52, 53 },  { 52, 43 },  { 52, 32 },  { 52, 21 },
    { 52, 11 },  { 52, 0 },
    // left per-key
    { 86, 43 },  { 86, 32 },  { 86, 21 },  { 86, 11 },  { 86, 0 },   { 86, 53 },  { 103, 53 }, { 103, 64 }, { 86, 64 },  { 69, 64 },
    { 69, 53 },  { 69, 43 },  { 69, 32 },  { 69, 21 },  { 69, 11 },  { 69, 0 },   { 52, 53 },  { 52, 43 },  { 52, 32 },  { 52, 21 },
    { 52, 11 },  { 52, 0 },   { 34, 53 },  { 34, 43 },  { 34, 32 },  { 34, 21 },  { 34, 11 },  { 34, 0 },   { 17, 53 },  { 17, 43 },
    { 17, 32 },  { 17, 21 },  { 17, 11 },  { 17, 0 },   { 0, 53 },   { 0, 43 },   { 0, 32 },   { 0, 21 },   { 0, 11 },   { 0, 0 },
    // right underglow strip
    { 138, 43 }, { 138, 32 }, { 138, 21 }, { 138, 11 }, { 138, 0 },  { 138, 53 }, { 121, 53 }, { 121, 64 }, { 138, 64 }, { 155, 64 },
    { 155, 53 }, { 155, 43 }, { 155, 32 }, { 155, 21 }, { 155, 11 }, { 155, 0 },  { 172, 53 }, { 172, 43 }, { 172, 32 }, { 172, 21 },
    { 172, 11 }, { 172, 0 },
    // right per-key
    { 138, 43 }, { 138, 32 }, { 138, 21 }, { 138, 11 }, { 138, 0 },  { 138, 53 }, { 121, 53 }, { 121, 64 }, { 138, 64 }, { 155, 64 },
    { 155, 53 }, { 155, 43 }, { 155, 32 }, { 155, 21 }, { 155, 11 }, { 155, 0 },  { 172, 53 }, { 172, 43 }, { 172, 32 }, { 172, 21 },
    { 172, 11 }, { 172, 0 },  { 190, 53 }, { 190, 43 }, { 190, 32 }, { 190, 21 }, { 190, 11 }, { 190, 0 },  { 207, 53 }, { 207, 43 },
    { 207, 32 }, { 207, 21 }, { 207, 11 }, { 207, 0 },  { 224, 53 }, { 224, 43 }, { 224, 32 }, { 224, 21 }, { 224, 11 }, { 224, 0 }
}, {
    //left underglow strip
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2,
    // left per-key
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    //right underglow strip
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2,
    // right per-key
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4
} };
#endif
