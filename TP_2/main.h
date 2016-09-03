#ifndef MAIN_H
#define MAIN_H

/**
* \brief Muestra el menú principal por consola y espera por la entrada
*		 de la opción seleccionada
* \param void
* \return int Devuelve el número de opción elegido por el usuario.
*/
int menu(void);

/**
* \brief Inicializa el vector (array) structPerson y setea valores iniciales
		 nulos en los miembros de cada estructura del vector
* \param structPerson input Vector o array al cual se le asignan valores predeterminados o iniciales
* \return void
*
*/
void initialize(structPerson input[MAX_PERSON_LIST]);

#endif // MAIN_H
