

#include "Mayor13.h"

float Mayor13::jugar(float gonzosApostar) {
    int opcion;
    float gonzosResultado;
    srand(time(NULL));
    numeroJugador = 1 + rand()%13;
    cout << "ingresa un numero aleatorio: " << numeroJugador << endl;
    cout << "Que desea hacer?" << endl;
    cout << "1. Dejar de jugar." << endl;
    cout << "2. Seguir jugando." << endl;
    cout << "Opcion: ";
    cin >> opcion;
    if (opcion == 1)
    {
        return 0.5 * gonzosApostar;
    }
    numeroCasino = 1 + rand() % 13; // numeros de 1 a 13
    cout << "Numero de la casa: " << numeroCasino << endl;
    gonzosResultado = calcularResultado(gonzosApostar);
    return gonzosResultado;
}


float Mayor13::calcularResultado(float gonzosApostar) {
    if(numeroJugador > numeroCasino)
    {
        return 2 * gonzosApostar;
    }
    else
    {
        return 0;
    }
}

Mayor13::~Mayor13() {

}
