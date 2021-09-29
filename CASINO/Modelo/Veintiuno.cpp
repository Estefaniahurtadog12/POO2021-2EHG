#include "Veintiuno.h"

float Veintiuno::jugar(float gonzosApostar)
{
    int opcion;
    float gonzosResultado;
    srand(time(NULL));
    venti1 = 1 + rand() % 10;  
    venti2 = 1 + rand() % 10; 
    venti3 = 1 + rand() % 10; 
    cout << "Resultado numeros random: " << venti1 << " " << venti2 << " " << venti3 << endl;
    gonzosResultado = calcularResultado(gonzosApostar);
    return gonzosResultado;
}

float Veintiuno::calcularResultado(float gonzosApostar)
{
    if (venti1 == venti2 && venti2 == venti3)
    {
        return 2 * gonzosApostar;
    }
    else if (venti1 == venti2 + 1 && venti2 == venti3 + 1)
    {
        return 1.5 * gonzosApostar;
    }
    else if (venti1 == venti2 - 1 && venti2 == venti3 - 1)
    {
        return 1.5 * gonzosApostar;
    }
    else if (venti1 == 10 && venti2 == 10 && venti3 == 10)
    {
        return 10 * gonzosApostar;
    }
    else
    {
        return 0;
    }
}

Veintiuno::~Veintiuno()
{
}
