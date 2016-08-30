#ifndef DEFINE_H
#define DEFINE_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FLAG_NULL       0x00
#define FLAG_OPERAND_1  0x01
#define FLAG_OPERAND_2  0x02
#define FLAG_OPERANDS   0x03
#define FLAG_MENU_3     0x04
#define FLAG_MENU_4     0x08
#define FLAG_MENU_5     0x10
#define FLAG_MENU_6     0x20
#define FLAG_MENU_7     0x40
#define FLAG_MENU_8     0x80
#define FLAG_MENU_ALL   0xFC

#define MAX_BUF         0xFF


/* si se prefiere en binario, para ver mejor como trabaja la bandera binaria flag
#define FLAG_NULL       0b00000000
#define FLAG_OPERAND_1  0b00000001
#define FLAG_OPERAND_2  0b00000010
#define FLAG_OPERANDS   0b00000011
#define FLAG_MENU_3     0b00000100
#define FLAG_MENU_4     0b00001000
#define FLAG_MENU_5     0b00010000
#define FLAG_MENU_6     0b00100000
#define FLAG_MENU_7     0b01000000
#define FLAG_MENU_8     0b10000000
#define FLAG_MENU_ALL   0b11111100

#define MAX_BUF         0xFF
*/

#endif // DEFINE_H
