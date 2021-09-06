#ifndef TIENDA_H
//Guardas
#define TIENDA_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include "Producto.h"
#include "Factura.h"

// Inclusion de librerias
using std::cin;
using std::cout;
using std::getline;
using std::iterator;
using std::map;
using std::string;
using std::vector;

class Tienda
{
private: //Atributos
	string nombre;
	float ivaTotal, gananciaTotal;
	vector<Factura> facturas;
	map<int, Producto> inventario;
	map<int, TipoProducto> categorias;
	vector<Factura> facturas;
	int contCodFactura;
	void agregarDetalle(float &totalIVA, float &totalSinIVA, float &totalGeneral, Factura &factura);

public:		  
	Tienda(); 
	Tienda(string nombre);
	bool existeProductoPorCod(int cod);
	void agregarProducto();
	void mostrarProductos();
	void mostrarFacturas();
	void vender();
	void mostrarProductosCant();
	void mostrarProductosTipoVendido();
	float calcularGancia(Producto producto1, int cantidad);
	void mostrarUltimasGanancias();
	// Gets and sets
	string getNombre();
	void setNombre(string nombre);
	float getGananciaTotal();
	void setGanciaTotal(float gananciaTotal);
	float getIVATotal();
	void setIVATotal(float ivaTotal);
};
#endif 