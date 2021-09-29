#ifndef CASINO_VEINTIUNO_H
#define CASINO_VEINTIUNO_H

/*
Veintiuno es un juego en el que una maquina escoge aleatoriamente 3 simbolos (en algunos
modelos son 5). Si caen los 3 simbolos iguales o alguna combinación especial el jugador
ganará cierta cantidad, de lo contrario perdera todo lo apostado.

En esta versión de Veintiuno se generaran 3 numeros entre 1 y 10. Si caen los 3 numeros
iguales el jugador ganará el doble de lo apostado, si consigue una escalera (numeros
sucesivos sea ascendente o descendente) ganará un tercio de lo apostado. Si llega
a conseguir el triple 10 ganará 10 veces lo apostado. Si no consigue ninguna perderá 
todo lo apostado.
*/
#include "Juego.h"
#include <cstdlib>
#include <ctime>

class Veintiuno : public Juego
{

protected:
    virtual float calcularResultado(float gonzosApostar) override;
    int venti1, venti2, venti3;

public:
    virtual ~Veintiuno();
    virtual float jugar(float gonzosApostar) override;
};

#endif //CASINO_VEINTIUNO_H
