
/**
* \brief Suma los dos parametros de entrada y retorna el resultado
* \param operand1 int Es el primer operando a ser sumado
* \param operand2 int Es el segundo operando a ser sumado
* \return int El resultado de la suma de los dos operandos
*
*/

int addition(int operand1, int operand2){
	return operand1 + operand2;
}

/**
* \brief Realiza una resta entre los dos parametros de entrada y retorna el resultado
* \param operand1 int Es el primer operando al cual se le resta el segundo, o minuendo
* \param operand2 int Es el segundo operando el cual se resta del primero, o sustraendo
* \return int Retorna el resultado de la resta entre los dos operandos, o diferencia
*
*/

int subtraction(int operand1, int operand2){
	return operand1 - operand2;
}

/**
* \brief Multiplica los dos parametros de entrada y retorna el resultado
* \param operand1 int Es el primer operando a ser multiplicado
* \param operand2 int Es el segundo operando a ser multiplicado
* \return int El resultado de la multiplicacion entre los dos operandos, o producto
*
*/

int multiplication(int operand1, int operand2){
	return operand1 * operand2;
}

/**
* \brief Divide los dos parametros de entrada y retorna el resultado, en caso de ser cero
*        informa del error por consola y retorna cero
* \param operand1 int Es el primer operando o dividendo
* \param operand2 int Es el segundo operando o divisor
* \return int Devuelve el resultado de la division entre los dos operandos, o cociente
*
*/

int division(int operand1, int operand2){
	if(operand2){
		return operand1 / operand2;
	}else{
		printf("\n No existe la division por cero.\n\n");
		return 0;
	}
}

/**
* \brief Devuelve el resultado del factorial del operando de entrada operand1, en caso de ser cero
*        o negativo informa por consola del error y retorna (-1)
* \param operand1 int Es el operando de entrada
* \return int Devuelve el factorial del operando de entrada
*
*/

int factorial(int operand1){
	int res;
	int x;
	if(operand1<1){
        printf(" No existe el factorial de cero o numeros negativos.\n");
        return -1;
	}

	res = 1;
	for(x=1; x<=operand1; x++){
		res*=x;
	}
	return res;
}
