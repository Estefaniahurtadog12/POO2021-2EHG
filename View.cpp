#include "View.h"

View::View()
{
}

void View::mostrarMenuReportes()
{
    int opcion = -1;
    do
    {

        cout << "Reportes\n"
             << endl;
        cout << "0. Volver \n";
        std::cout << "Digita el numero: ";
        std::cin >> opcion;

        // TODO completar
        switch (opcion)
        {
        }

    } while (opcion != 0);
}

void View::mostrarMenu()
{
    int opcion;
    do
    {

        printf("Menu Reporte: \n"
         "1. Mostrar cantidad de productos \n"
         "2. Mostrar Productos de TipoProducto \n"
         "3. Mostrar ganancias \n"
         "4. Productos disponibles \n"
         "5. IVA DIAN Deuda \n"
         "0. Salir \n"
         "Digita la opcion: ");
        cin >> opcion;

        switch (opcion)
        {

        case 1:
            laFarra.mostrarProductosCant();
            break;
        case 2:
            laFarra.mostrarProductosTipoVendido();
            break;

        case 3:
            cout << "las ganancias fueron : " << laFarra.getGananciaTotal() << ".\n";
            break;

        case 4:
            break;

        case 5:
            cout << "El valor a pagar por del IVA es :" << laFarra.getIVATotal() << "\n";
            break;
        }

    } while (opcion != 0);
}