

#include "View.h"

View::View(){
}

void View::agregarJugador()
{
    string nombreJugador;
    float dineroPesos;
    long idJugador;
    cout << "Ingrese el nombre del jugador \n";
    cin.ignore(100, '\n');
    getline(cin, nombreJugador);
    cout << "Ingrese el id del jugador \n";
    cin >> idJugador;
    do
    {
        cout << "Ingrese el dinero en pesos \n";
        cin >> dineroPesos;
    } while (dineroPesos <= 0);

    // Esta linea de codigo controla la excepcion que lanza el controller y lo muestra en pantalla
    try {
        casino.agregarJugador(idJugador, nombreJugador, dineroPesos);
    } catch (std::domain_error ex) {
        cout << "ERROR: " << ex.what();
    }
}

void View::jugarView(){
    try {
        long idJugador;
        float cantGonzos;
        int idJuego;
        bool resultado;
        cout << "Ingrese id del jugador \n";
        cin >> idJugador;
        cout << "Cual sera su apuesta \n";
        cin >> cantGonzos;

        cout << "Elija el juego: " << endl;
        cout << "1. Mayor a 13." << endl;
        cout << "2. Dos colores." << endl;
        cout << "3. Veintiuno" << endl;
        cout << "Opcion: ";
        cin >> idJuego;

        resultado = casino.jugar(idJuego, idJugador, cantGonzos);
        if(resultado)
        {
            cout << "Felicidades ha ganado" << endl;
        }
        else
        {
            cout << "Lo sentimos, ha perdido" << std::endl;
        }

    }catch (std::domain_error ex){
        // excepcion obtenida por programa
        cout << ex.what();
    }
}

int View::mostrarMenu()
{
    int opcion;
    cout << "Menu\n";
    cout << "1. Agregar jugador " << std::endl;
    cout << "2. Jugar" << std::endl;
    cout << "3. Consultar jugador  " << std::endl;
    cout << "4. Recargar gonzos " << std::endl;
    cout << "5. Retirar jugador casino " << std::endl;
    cout << "0. Salir\n"
         << std::endl;
    cout << "Digita el numero: ";
    cin >> opcion;
    return opcion;
}

void View::verPrincipal()
{
    int opcion;
    do
    {
        opcion = mostrarMenu();
        switch (opcion)
        {
            case 1: agregarJugador();
                break;
            case 2:
                jugarView();
                break;
            case 3:
                mostrarJugador();
                break;
            case 4:
                recargarGonzos();
                break;
            case 5:
                retirarJugador();
                break;
        }
    } while (opcion != 0);
}

void View::mostrarJugador() {
    long idJugador;
    try {
        cout << "Ingrese el id del jugador: ";
        cin >> idJugador;
        casino.verInfoJugador(idJugador);
    } catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

void View::retirarJugador() {
    long idJugador;
    try{
        cout << "Ingrese el id: ";
        cin >> idJugador;
        casino.verInfoJugador(idJugador);
        casino.retirarJugador(idJugador);
        cout << "Usted se ha retirado. " << std::endl;
    }catch(std::domain_error ex){
        cout << ex.what();
    }
}

void View::recargarGonzos()
{
    long idJugador;
    try
    {
        cout << "Ingrese el id: ";
        cin >> idJugador;
        casino.recargarGonzos(idJugador);
        cout << "Recarga realizada." << std::endl;
    }
    catch (std::domain_error ex)
    {
        // error si jugador no existe
        cout << ex.what();
    }
}