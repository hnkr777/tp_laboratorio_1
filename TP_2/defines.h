#ifndef DEFINES_H
#define DEFINES_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_BUF 0xFF
#define MAX_PERSON_LIST 20

#define MENU_ADD             1
#define MENU_DELETE          2
#define MENU_SORTED_LIST     3
#define MENU_GRAPHIC_LIST    4
#define MENU_EXIT            5

#define MENU_LIST "Ingrese una opcion:\n\n 1) Agregar persona\n 2) Borrar persona\n 3) Imprimir lista ordenada por nombre\n 4) Imprimir grafico por edades\n 5) Salir\n\nOpcion: "

#define GRAPHIC_GLIPH    "*"

#define PERSON_STATUS_UNUSED    100
#define PERSON_STATUS_VALID     101

#define DNI_STATUS_UNIQUE       1
#define DNI_STATUS_DUPLICATE    0

typedef struct structPerson{
    char name[MAX_BUF];
    unsigned int age;
    int state;
    unsigned long dni;

} structPerson;

#endif // DEFINES_H
