#ifndef PEDIDOS_H
#define PEDIDOS_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// Definición de la estructura Pedido
struct Pedido {
    string producto;
    int cantidad;
    double precio;
    string cliente;
    string fechaEntrega;
    string detalles;
    bool entregado;
};

// Declaración de variables globales
extern vector<Pedido> pedidos;
extern map<string, double> productos;

// Declaración de funciones
void inicializarProductos();
bool validarFecha(const string& fecha);
void mostrarProductos();
void nuevoPedido();
void verPedidos(bool soloPendientes = false, bool soloEntregados = false);
void buscarPedido();
void editarPedido();
void eliminarPedido();
void marcarEntregado(bool deshacer = false);
void mostrarMenu();

#endif