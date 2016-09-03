
#include "defines.h"
#include "functions.h"


void addPerson(structPerson person[MAX_PERSON_LIST]){
	int x = 0;
	for(x=0; x<MAX_PERSON_LIST; x++){
		if(person[x].state==PERSON_STATUS_UNUSED){
			loadPersonData(&person[x]);
			if(validateDNI(person, person[x].dni)==DNI_STATUS_DUPLICATE){
				resetPerson(person, x);
				system("cls");
				printf("\n DNI duplicado, los datos recien ingresados se borraron.\n\n");
				system("pause");
			}
			break;
		}
	}
}

int deletePerson(structPerson person[MAX_PERSON_LIST]){
	int x = 0;
	unsigned long dni = 0;

	system("cls");
	printf("\nBorrar persona:\n\n Ingrese el numero de DNI a borrar: ");
	scanf("%10lu", &dni);
	fflush(stdin);

	for(x=0; x<MAX_PERSON_LIST; x++){
		if(person[x].state==PERSON_STATUS_VALID){
			if(person[x].dni==dni){
				resetPerson(person, x);
				printf("\n Persona borrada.\n\n");
				system("pause");
				return 0;
			}
		}
	}
	printf("\n El DNI ingresado no existe.\n\n");
	system("pause");
	return -1;
}

void resetPerson(structPerson person[MAX_PERSON_LIST], int index){
	strcpy(person[index].name, "\0");
	person[index].dni = 0;
	person[index].age = 0;
	person[index].state = PERSON_STATUS_UNUSED;
}

void sortPersonList(structPerson person[MAX_PERSON_LIST]){
	long x = 0;  // variable de control del bucle for
	structPerson tmp;  // estructura de almacen temporal

	for(x=0; x < MAX_PERSON_LIST; x++){
		if((strcmp(person[x].name, person[x+1].name)>0) && ((x+1) < MAX_PERSON_LIST) && (person[x+1].state==PERSON_STATUS_VALID)){
			tmp = person[x];
			person[x] = person[x+1];
			person[x+1] = tmp;
			x=-1;
		}
	}
}

void printPersonList(structPerson person[MAX_PERSON_LIST]){
	int x = 0;
	int counter = 0;
	system("cls");
	printf("\nImprimir lista ordenada por nombre:\n");

	for(x=0; x<MAX_PERSON_LIST; x++){
		if(person[x].state==PERSON_STATUS_VALID){
			counter++;
			printf("\nRegistro no. %d:\n\n Nombre: %s", counter, person[x].name);
			printf("\n DNI: %lu", person[x].dni);
			printf("\n Edad: %u\n", person[x].age);
		}
	}
	printf("\n");
}

void printGraphicBars(structPerson person[MAX_PERSON_LIST]){
	int x;
	unsigned int cEdadMenor18 = 0, cEdad18a35 = 0, cEdadMayor35 = 0;

	for(x=0; x<MAX_PERSON_LIST; x++){
		if(person[x].state==PERSON_STATUS_VALID){
			if(person[x].age<18){
				cEdadMenor18++;
			}else if(person[x].age>35){
				cEdadMayor35++;
			}else{
				cEdad18a35++;
			}
		}
	}

	system("cls");
	printf("   Imprimir grafico por edades:\n");
	printf(" +-------------------------------------------------+\n");

	for(x=MAX_PERSON_LIST; x>0; x--){
		printf(" |           %s", cEdadMenor18>=x?GRAPHIC_GLIPH:" ");
		printf("             %s", cEdad18a35>=x?GRAPHIC_GLIPH:" ");
		printf("              %s        |\n", cEdadMayor35>=x?GRAPHIC_GLIPH:" ");
	}
	printf(" +-------------------------------------------------+\n");
	printf("   Edad: Menor de 18 / Entre 18 y 35 / Mayor de 35\n");
}

void loadPersonData(structPerson* inputPerson){
	char tmp[MAX_BUF];

	system("cls");
	printf("\nAgregar persona:\n\n Ingrese el nombre: ");
    fflush(stdin);

	gets(tmp);
	strupr(tmp);
	strcpy(inputPerson->name, tmp);

	printf(" Ingrese el numero de DNI: ");
	scanf("%10lu", &inputPerson->dni);
	fflush(stdin);

	printf(" Ingrese la edad: ");
	scanf("%3u", &inputPerson->age);
	fflush(stdin);

	inputPerson->state = PERSON_STATUS_VALID;

	printf("\n\n   Nombre: %s\n   DNI: %lu\n   Edad: %u\n\n",
			inputPerson->name, inputPerson->dni, inputPerson->age);
	system("pause");
}

int validateDNI(structPerson person[MAX_PERSON_LIST], unsigned long dni){
	int x = 0;
	int duplicate = 0;

	for(x=0; x<MAX_PERSON_LIST; x++){
		if(person[x].state==PERSON_STATUS_VALID){
			if(person[x].dni==dni){
				duplicate++;
			}
			if(duplicate==2){
				return DNI_STATUS_DUPLICATE;
			}
		}
	}
	return DNI_STATUS_UNIQUE;
}
