#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
* \brief Agrega una persona (datos) al vector estructura validando que
*		 no este repetido el número de DNI ni que la estructura ya este ocupada
* \param structPerson person es el vector en el cual se agrega, en el primer
*		 elemento sin usar, los datos de una nueva persona
* \return void
*
*/
void addPerson(structPerson person[MAX_PERSON_LIST]);

/**
* \brief Borra una persona (datos del registro) del vector, se selecciona el
*		 elemento a borrar mediante el número de DNI, el cual es único para cada elemento
* \param structPerson person es el vector de registros del cual se borra un elemento
* \return int si el número de DNI no existe en el vector de entrada retorna -1,
*		  en caso de encontrar el elemento a borrar retorna 0
*/
int deletePerson(structPerson person[MAX_PERSON_LIST]);

/**
* \brief Setea los valores del elemento indicado por el argumento index a los
*		 valores por defecto, sobre el vector de estructuras de entrada person
* \param structPerson person vector del cual borrar el elemento indicado por index
* \param int index variable de entrada que indica qué elemento borrar
* \return void
*
*/
void resetPerson(structPerson person[MAX_PERSON_LIST], int index);

/**
* \brief Ordena alfabéticamente por nombre (miembro name de cada registro del vector)
*		 cada elemento del vector de entrada person
* \param structPerson person el vector de entrada a ser ordenado
* \return void
*
*/
void sortPersonList(structPerson person[MAX_PERSON_LIST]);

/**
* \brief Imprime la lista de elementos con datos válidos ordenados alfabéticamente (previamente)
* \param structPerson person es el vector a ser impreso
* \return void
*
*/
void printPersonList(structPerson person[MAX_PERSON_LIST]);

/**
* \brief Imprime un "gráfico" de barras utilizando asteriscos, indicando la cantidad
*		 de elementos de cada rango de edad del vector de entrada person
* \param structPerson person es el vector de entrada del cual se imprime cada rango etario
* \return void
*
*/
void printGraphicBars(structPerson person[MAX_PERSON_LIST]);

/**
* \brief Le pide al usuario el ingreso de datos de cada estructura del vector,
*		 completando así un elemento como válido
* \param structPerson* inputPerson estructura en la cual se guardan los datos ingresados
*		 por el usuario
* \return void
*
*/
void loadPersonData(structPerson* inputPerson);

/**
* \brief Verifica que el número de DNI indicado en la variable de entrada dni no este
*		 más de una vez en el vector de entrada person. En caso de estar más de una
*		 vez devuelve el valor del macro DNI_STATUS_DUPLICATE, caso contrario
*		 devuelve DNI_STATUS_UNIQUE
* \param structPerson person es el vector de entrada en el cual se verifica que
*		 ya no haya un elemento del vector con un miembro dni con el mismo valor
* \param unsigned long dni número de DNI el cual se compara que no este repetido en
*		 el vector de entrada person
* \return int devuelve el valor del macro DNI_STATUS_DUPLICATE si el número en la
*		  variable de entrada dni coincide con el miembro dni de algún elemento
*		  del vector de entrada person, en caso de no encontrar coincidencias devuelve
*		  el valor del macro DNI_STATUS_UNIQUE
*
*/
int validateDNI(structPerson person[MAX_PERSON_LIST], unsigned long dni);

#endif // FUNCTIONS_H
