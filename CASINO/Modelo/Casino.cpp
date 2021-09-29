

#include "Casino.h"

// Constructor que inicializa las ganancias y perdidas en cero
Casino::Casino() {
    cout << "Inicialice casino";
    // Inicia un jugador en el mapa para comenzar
    jugadoresMap.insert({1,new Jugador(1,"Estefania Hurtado", 500)});

    // Inicia  los juegos disponibles y los agrega al mapa de juegos
    Mayor13 * juego1 = new Mayor13();
    juegosDisponibles.push_back(juego1);
    DosColores * juego2 = new DosColores();
    juegosDisponibles.push_back(juego2);
    Veintiuno * juego3 = new Veintiuno();
    juegosDisponibles.push_back(juego3);

    // Agregar aqui los demas juegos
}

void Casino::agregarJugador(long id, string nombreJugador, double dinero)
{
    if (verExisteJugador(id) == false){
        float cantGonzos = convertirPesosAGonzos(dinero);
        Jugador *pJugador = new Jugador(id, nombreJugador, cantGonzos);
        jugadoresMap.insert({pJugador->getId(), pJugador});
    }
    else
    {
        throw std::domain_error("El jugador ya se encuentra registrado. \n");
    }
}

bool Casino::jugar(int idJuego, long idJugador, float gonzosApostar) {
    if (gonzosApostar < 1 ){
        throw std::domain_error("Debe apostar al menos 1 gonzo\n");
    }

    if (verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador no se encuentra registrado, por favor registrate.\n");
    }
    if (idJuego > juegosDisponibles.size()){
        throw std::domain_error("NO existe el juego.\n");
    }
    if (verPuedeContinuar(idJugador, gonzosApostar)== false){
        throw std::domain_error("No tienes saldo suficiente. \n");
    }
    int jugando = idJuego - 1; 
    Juego * pJuegoAJugar = juegosDisponibles.at(idJuego-1);
    Jugador * pJugador = jugadoresMap[idJugador];
    float gonzosGanados = pJuegoAJugar->jugar(gonzosApostar) - gonzosApostar;
    pJugador->actualizarGonzos(gonzosGanados);
    pJugador->aumentarJuegos();
    return (gonzosGanados >= 0);
}

void Casino::verInfoJugador(long idJugador){
    if(verExisteJugador(idJugador) == false){
        throw std::domain_error("Jugador no existe \n");
    }
    Jugador * pJugador = jugadoresMap[idJugador];
    pJugador->mostrarInfo();
}

bool Casino::verPuedeContinuar(int idJugador, float gonzosApostar) {
    if(verExisteJugador(idJugador) == false )
    {
        throw std::domain_error("Jugador no registrado");
    }
    Jugador *pJugador = jugadoresMap[idJugador];
    if(pJugador->getCantGonzos() < gonzosApostar)
    {
        return false;
    }
    return true;

}

void Casino::retirarJugador(long idJugador) {
    Jugador * pJugador = jugadoresMap[idJugador];
    delete pJugador;
    jugadoresMap.erase(idJugador);
}

void Casino::recargarGonzos(long idJugador) {
    if(verExisteJugador(idJugador) == false)
    {
        throw std::logic_error("JUgador no registrado");
    }
    float dinero;
    Jugador * pJugador = jugadoresMap[idJugador];
    do{
        cout << "Ingrese cuanto va a recargar: ";
        cin >> dinero;
    }while (dinero < 0);
    float gonzos = convertirPesosAGonzos(dinero);
    pJugador->actualizarGonzos(gonzos);   
}



bool Casino::verExisteJugador(long id){
    for (map<long, Jugador *>::iterator existe = jugadoresMap.begin(); existe != jugadoresMap.end(); existe++)
    {
        if (existe->first == id)
        {
            return true;
        }
    }
    return false;
}

double Casino::convertirPesosAGonzos(double dinero) 
{
    return (dinero / 100);
}


Casino::~Casino() {
    cout << "Llame al destructor de casino \n";
    // Se libera la memoria del jugadores y de juegos
    for(map<long, Jugador*>::iterator it = jugadoresMap.begin(); it != jugadoresMap.end(); it++)
    {
        Jugador * jugadorTemp = jugadoresMap[it->first];
        delete jugadorTemp;
    }

    for(int i=0; i< juegosDisponibles.size(); i++)
    {
        Juego * juegoTemp = juegosDisponibles.at(i);
        delete juegoTemp;
    }
}