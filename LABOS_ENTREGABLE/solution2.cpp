#include <iostream>

void division(int &dividendo, int &divisor, int &cociente, int &resto){
	// Modificar el pasaje de parametros de ser necesario para que calcule el cociente y resto. Deben se por copia o referencia??
    /* COMPLETAR */
    int k =1;
    while ((k*divisor)<=dividendo){
        k=k+1;
    }
    cociente=k-1;
    resto=dividendo-(divisor*(k-1));
}

using namespace std;
int main() {
    /* No hace falta modificar el main */
    //Leo la entrada
    int divisor,dividendo,cociente,resto;
    cin >> dividendo>>divisor;
    
    //Calculo la division
    division(dividendo,divisor,cociente,resto);
    
    //Salida
    cout << cociente << " " << resto;
    
    return 0;
}
