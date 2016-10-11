#ifndef MAIN_H
#define MAIN_H


/**
* \brief Función principal del programa, llamada por el sistema operativo
*		 cuando crea el proceso.
* \param int argsc Es la cantidad de argumentos de la línea de comandos, por defecto es 1
* \param char **argsc Es una matriz o un puntero a un puntero, hace referencia a cada parámetro de la línea de comandos
* \return int Devuelve cero (0) al sistema operativo si todo salió bien, caso contrario el número de error
*
*/
int main(int argsc, char **argsv);

#endif // MAIN_H
