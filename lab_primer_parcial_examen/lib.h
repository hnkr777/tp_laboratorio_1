#ifndef LIB_H
#define LIB_H


/**
* \brief Agrega un nuevo elemento (asociado) al vector de estructuras asoc redimensionándolo
* \param structAsoc *asoc es el vector en el cual se agrega el asociado
* \param int *asocCount indica la cantidad actual de elementos en el vector
* \return structAsoc* devuelve la nueva dirección en memoria asignada al array asoc redimensionado
* \note La estructura de la función es extraña debido a un error en tiempo de ejecución que no pudo
*   	ser solucionado de otra manera, ya que se redimensiona antes de ver si el usuario
*		canceló o no el ingreso de datos, aunque igualmente funciona bien,
*		volviendo a redimensionar el array cuando el usuario ingresó datos correctamente
*/
structAsoc* addAsoc(structAsoc* asoc, int *asocCount);


/**
* \brief Da de baja un asociado (baja lógica) del vector, se selecciona el
*		 elemento a borrar mediante el número de ID, (asoc[x].id) el cual
*		 es único para cada elemento del array
* \param structAsoc *asoc es el vector de registros del cual se da de baja un elemento
* \param int asocCount indica la cantidad de elementos en el vector asoc
* \return int Devuelve SUCCESS en caso de haber dado de baja correctamente un asociado,
*		  en caso contrario devuelve ERROR
*/
int disableAsoc(structAsoc* asoc, int asocCount);


/**
* \brief Valida una nueva llamada en curso, solo si hay asociados y no hay otra llamada en curso
* \param structCall *calls es el array de registros de llamadas
* \param int *callsCount indica la cantidad de elementos actuales en el array calls
* \param structAsoc *asoc es el array de registros de asociados
* \param int asocCount indica la cantidad de elementos en el array asoc
* \return structCall Devuelve la nueva dirección en memoria del array de entrada calls, ya redimensionado
*		  en caso de ser válidos los datos de llamada ingresados
*/
structCall* newCall(structCall *calls, int *callsCount, structAsoc *asoc, int asocCount);


/**
* \brief Asigna una ambulancia (ID único) para cada llamada en curso,
* 		 solo si hay asociados y hay una llamada en curso
* \param structCall *calls es el array de registros de llamadas
* \param int *callsCount indica la cantidad de elementos actuales en el array calls
* \param structAsoc *asoc es el array de registros de asociados
* \param int asocCount indica la cantidad de elementos en el array asoc
* \return int Devuelve la SUCCESS si pudo asignar una ambulancia exitosamente,
*		  en caso contrario devuelve ERROR
*/
int asignAmbulance(structCall *calls, int callsCount, structAsoc *asoc, int asocCount);



/**
* \brief Evalua si dentro del array calls hay un elemento en el que su miembro
*		 .ambulanceID coincida con el parámetro id, si lo encuentra retorna SUCCESS
* \param structCall *calls Puntero a un vector de estructura de datos con las llamadas
* \param int callsCount cantidad de elementos del vector calls
* \param int ID identificador del elemento el cual buscar en el vector asoc
* \return int Devuelve SUCCESS si el id del parámetro existe dentro del vector calls
*		  caso contrario devuelve ERROR
*
*/
int existAmbulanceByID(structCall *calls, int callsCount, int id);


/**
* \brief Modifica los datos de un elemento del array asoc, determinando el elemento
*		 por su ID (asoc.id) y en caso de no existir lo indica
* \param structAsoc *asoc es el array en el cual modificar los datos de un elemento del mismo
* \param int asocCount es la cantidad de elementos en el array asoc
* \return int Devuelve SUCCESS en caso de haberse modificado algún dato, caso contrario ERROR
*
*/
int modifyAsoc(structAsoc* asoc, int asocCount);


/**
* \brief Muestra un informe por pantalla de todos los datos requeridos según la
* 		 consigna, ya que es un requerimiento tan específico se optó por dejar todo
*		 junto en la misma función...
* \param structAsoc *asoc es el array de registros de asociados
* \param int asocCount indica la cantidad de elementos en el array asoc
* \param structCall *calls es el array de registros de llamadas
* \param int *callsCount indica la cantidad de elementos actuales en el array calls
* \return void
*
*/
void inform(structAsoc* asoc, int asocCount, structCall *calls, int callsCount);


#endif // LIB_H
