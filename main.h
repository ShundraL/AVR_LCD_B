#include <avr/io.h>

#ifndef MAIN_H
#define MAIN_H

/* Function prototypes */
#define CMD      0b100
#define READ     0b110
#define WRITE    0b101
#define LCD_ON   0b100000000110
#define LCD_OFF  0b100000000100
//#define BIAS_COM 0b100000110000
#define BIAS_COM 0b100001000000   // BIAS 1\2
//#define BIAS_COM 0b100001000010     // BIAS 1\3
#define SYS_EN   0b100000000010
#define TONE_4K  0b100010000000
#define TONE_2K  0b100011000000
#define TONE_OFF 0b100000010000
#define TONE_ON  0b100000010010

#define CS       2
#define RD       3    
#define WR       4
#define DATA     5
#define LEDA     6
#define LEDB     7
#define SOUND    0
#define DOTS     1


#endif