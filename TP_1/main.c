


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "main.h"
#include "funciones.h"
#include "define.h"

/**
* \brief Función principal, con validación y menú
* \param args int Es la cantidad de argumentos de la línea de comandos
* \param argsv char** Es un puntero a un vector con cada comando
* \return int cero (0) al sistema operativo
*
*/

int main(int args, char** argsv){
	char flag = FLAG_NULL;  // bandera binaria
	int operand1 = 1;       // primer operando
	int operand2 = 1;       // segundo operando
	int option = 0;         // opcion de menu

	do{
		option = menu(operand1, operand2, flag);

		switch(option){
        		case 1:
				operand1 = loadOperator();
				if(flag==FLAG_NULL){
					flag=FLAG_OPERAND_1;
				}
				if(flag==FLAG_OPERAND_2){
					flag=FLAG_OPERANDS;
				}
				flag = flag&FLAG_OPERANDS;
				break;

			case 2:
				operand2 = loadOperator();
				if(flag==FLAG_NULL){
					flag=FLAG_OPERAND_2;
				}
				if(flag==FLAG_OPERAND_1){
					flag=FLAG_OPERANDS;
				}
				flag = flag&FLAG_OPERANDS;
				break;

			case 3:
				showOperation(operand1, operand2, flag|FLAG_MENU_3);
				break;

			case 4:
				showOperation(operand1, operand2, flag|FLAG_MENU_4);
				break;

			case 5:
				showOperation(operand1, operand2, flag|FLAG_MENU_5);
				break;

			case 6:
				showOperation(operand1, operand2, flag|FLAG_MENU_6);
				break;

			case 7:
				showOperation(operand1, 0, flag|FLAG_MENU_7);
				break;

			case 8:
				showOperation(operand1, operand2, flag|FLAG_MENU_ALL);
				break;
		}
	}while(option!=9);

	return 0;
}

/**
* \brief Solicita un número al usuario y devuelve el resultado
* \param void No tiene parámetros
* \return int El número ingresado por el usuario
*
*/

int loadOperator(void){
	char tmp[MAX_BUF]; // variable temporal donde almacenar el ingreso por teclado
	system("cls");
	printf("\n Ingrese un entero: ");
	scanf("%6s", &tmp); // se usa char* en vez de int para evitar overflow o datos indeseados

	return atoi(&tmp[0]);
}

/**
* \brief Muestra por consola, según el valor de cada bit de la variable char flag,
*        la/s operacion/es correspondientes entre operand1 y operand2
* \param operand1 int Primer operando
* \param operand2 int Segundo operando
* \param flag char Bandera binaria utilizada para decidir que mensaje/s mostrar,
         para evitar el paso de muchos parámetros a la función
* \return void
*
*/

void showOperation(int operand1, int operand2, char flag){
	printf("\n");

	if(flag&FLAG_OPERAND_1 && flag&FLAG_OPERAND_2){
		if(flag&FLAG_MENU_8){
			printf("Todas las operaciones:\n");
		}

		if(flag&FLAG_MENU_3){
			printf(" La suma de los numeros %i y %i es: %i\n", operand1, operand2, addition(operand1, operand2));
		}

		if(flag&FLAG_MENU_4){
			printf(" La resta de los numeros %i y %i es: %i\n", operand1, operand2, subtraction(operand1, operand2));
		}

		if(flag&FLAG_MENU_5 && operand2!=0){
			printf(" La division (entera) de los numeros %i y %i es: %i\n", operand1, operand2, division(operand1, operand2));
		}

		if(flag&FLAG_MENU_5 && operand2==0){
			printf(" No existe la division por cero.\n");
		}

		if(flag&FLAG_MENU_6){
			printf(" La multiplicacion de los numeros %i y %i es: %i\n", operand1, operand2, multiplication(operand1, operand2));
		}

		if((flag&FLAG_MENU_7) && factorial(operand1)>0){
			printf(" El factorial del numero %i es: %i\n", operand1, factorial(operand1));
		}
	}else if(flag&FLAG_OPERAND_1 && flag&FLAG_MENU_7 && !(flag&FLAG_MENU_8) && factorial(operand1)>0){
		printf(" El factorial del numero %i es: %i\n", operand1, factorial(operand1));
	}else{
		printf(" No se ingresaron todos los operandos.\n");
	}

	printf("\n");
	system("pause");
}

/**
* \brief Muestra por consola un menu, del cual el usuario elige una opcion para luego retornarla
* \param operand1 int Primer operando, en el caso de ser necesario se muestra en el menu el valor del mismo
* \param operand2 int Segundo operando, en el caso de ser necesario se muestra en el menu el valor del mismo
* \param flag char Bandera binaria utilizada para mostrar si ya se ingresaron valores para los operandos
* \return int entero con el numero de opcion seleccionada por el usuario
*
*/

int menu(int operand1, int operand2, char flag){
	char tmp[MAX_BUF]; // vector temporal donde almacenar la entrada por teclado

	system("cls");
	printf("Ingrese una opcion:\n\n");

	if(flag&FLAG_OPERAND_1){ // si todavía no se ingresó un valor para el operando, muestra x
		printf(" 1) Ingresar 1er operando (A=%d)\n", operand1);
	}else{
		printf(" 1) Ingresar 1er operando (A=x)\n");
	}

	if(flag&FLAG_OPERAND_2){
		printf(" 2) Ingresar 2do operando (B=%d)\n", operand2);
	}else{
		printf(" 2) Ingresar 2do operando (B=y)\n");
	}

	printf(" 3) Calcular la suma (A+B)\n");
	printf(" 4) Calcular la resta (A-B)\n");
	printf(" 5) Calcular la division (A/B)\n");
	printf(" 6) Calcular la multiplicacion (A*B)\n");
	printf(" 7) Calcular el factorial (A!)\n");
	printf(" 8) Calcular todas las operacione\n");
	printf(" 9) Salir\n\n");
	printf("Opcion: ");

	scanf("%3s", &tmp);

	if(isdigit(tmp[0])){
		return atoi(&tmp[0]);
	}else{
		return 0;
	}
}
