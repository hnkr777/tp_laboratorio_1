
/*
Definir una estructura que represente una persona, con los campos nombre, edad, dni y un
flag de estado.
Hacer un programa que defina un array de 20 ítems de esta estructura y con un menú como el
siguiente:
1) Agregar una persona
2) Borrar una persona
3) Imprimir lista ordenada por nombre
4) Imprimir gráfico de edades
Se utilizará el campo de estado para indicar si el ítem del array esta ocupado o no.
El gráfico deberá ser un gráfico de barras en donde se agruparán 3 barras:
• Menores de 18
• De 18 a 35
• Mayores de 35.
En el eje Y se marcarán la cantidad de personas en el grupo, y en el eje X el grupo

Ejemplo:

  *
  *   *
  *   *    *
  *   *    *
  *   *    *
  *   *    *
<18 18-35 >35
Gráfico para una estadística de 6 personas con edad menor a 18, 4 personas con edades entre
18 y 35, y 5 personas con edades mayores a 35.

Autor: Federico Honeker
Fecha: 02 de Septiembre de 2016
*/

#include "defines.h"
#include "main.h"
#include "functions.h"

int main(int args, char** argsv){
	int option = 0;
	structPerson person[MAX_PERSON_LIST];
	initialize(person);

	do{
		option = menu();

		switch(option){
            case MENU_ADD:
				addPerson(person);
                break;

            case MENU_DELETE:
				deletePerson(person);
                break;

            case MENU_SORTED_LIST:
				sortPersonList(person);
				printPersonList(person);
				system("pause");
                break;

            case MENU_GRAPHIC_LIST:
                printGraphicBars(person);
                system("pause");
                break;
        }
    } while(option!=5);

    return 0;
}

int menu(void){
	char tmp[MAX_BUF]; // vector temporal donde almacenar la entrada por teclado

	system("cls");
	printf(MENU_LIST);
	scanf("%3s", tmp);

	if(isdigit(tmp[0])){
		return atoi(&tmp[0]);
	}else{
		return 0;
	}
}

void initialize(structPerson input[MAX_PERSON_LIST]){
	int x = 0;
	for(x=0; x<MAX_PERSON_LIST; x++){
		resetPerson(input, x);
	}
}
