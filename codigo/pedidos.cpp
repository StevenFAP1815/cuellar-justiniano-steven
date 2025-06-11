#include "pedidos.h"
#include <iostream>
#include <iomanip> // Para setprecision
#include <vector>
#include <limits> // Para evitar problemas con cin.ignore()
#include <algorithm> // Para usar advance
#include <map> // Para usar map (mas optimo para busqueda)
using namespace std;

// Definición de variables globales
vector<Pedido> pedidos;
map<string, double> productos;

// Función para inicializar productos
void inicializarProductos() {
    productos = {
        {"Pan francés", 1.20},
        {"Croissant", 2.50},
        {"Empanada de carne", 2.00},
        {"Torta de chocolate", 15.00},
        {"Docena de medialunas", 12.00}
    };
}

bool validarFecha(const string& fecha) {
    return fecha.size() == 10 && fecha[2] == '/' && fecha[5] == '/'; // Formato dd/mm/yyyy
}
// Función para mostrar los productos disponibles
void mostrarProductos() {
    cout << "\nPRODUCTOS DISPONIBLES:\n";
    int i = 1;
    for (auto& p : productos)
        cout << i++ << ". " << p.first << " - $" << fixed << setprecision(2) << p.second << endl;
}
// Función para crear un nuevo pedido
void nuevoPedido() {
    Pedido pedido;
    string nombre, detalles, fechaEntrega;
    int opcion, cantidad;

    cout << "\n=== NUEVO PEDIDO ===\n";
    cout << "Nombre del cliente: ";
    getline(cin, nombre);
    if (nombre.empty()) {
        cout << "❌ Nombre vacío. Pedido cancelado.\n";
        return;
    }

    mostrarProductos();
    cout << "Seleccione producto (0 para cancelar): ";
    cin >> opcion;
    cin.ignore();
    if (opcion == 0) {
        cout << "✅ Pedido cancelado por el usuario.\n";
        return;
    }
    if (opcion < 1 || opcion > productos.size()) {
        cout << "❌ Opción inválida. Pedido cancelado.\n";
        return;
    }

    auto it = productos.begin();
    advance(it, opcion - 1);
    pedido.producto = it->first;
    pedido.precio = it->second;

    cout << "Cantidad (mínimo 50): ";
    cin >> cantidad;
    cin.ignore();
    if (cantidad < 50) {
        cout << "❌ Cantidad inválida. Pedido cancelado.\n";
        return;
    }

    cout << "Fecha de entrega (dd/mm/yyyy): ";
    getline(cin, fechaEntrega);
    if (!validarFecha(fechaEntrega)) {
        cout << "❌ Formato de fecha inválido. Pedido cancelado.\n";
        return;
    }

    cout << "Detalles (máx. 100 caracteres): ";
    getline(cin, detalles);
    if (detalles.length() > 100) {
        cout << "❌ Los detalles exceden 100 caracteres. Pedido cancelado.\n";
        return;
    }

    pedido.cliente = nombre;
    pedido.cantidad = cantidad;
    pedido.fechaEntrega = fechaEntrega;
    pedido.detalles = detalles;
    pedido.entregado = false;

    // Confirmación final
    cout << "\n🔎 Confirmar pedido:\n";
    cout << "Cliente: " << pedido.cliente << "\n";
    cout << "Producto: " << pedido.producto << " x" << pedido.cantidad << "\n";
    cout << "Total: $" << fixed << setprecision(2) << pedido.precio * pedido.cantidad << "\n"; // Calcular total de productos agregados al carrito
    cout << "Fecha entrega: " << pedido.fechaEntrega << "\n";
    cout << "Observaciones: " << (pedido.detalles.empty() ? "Ninguna" : pedido.detalles) << "\n";

    char confirmar;
    cout << "¿Confirmar pedido? (s/n): ";
    cin >> confirmar;
    cin.ignore();

    if (confirmar == 's' || confirmar == 'S') {
        pedidos.push_back(pedido);
        cout << "✅ Pedido registrado correctamente.\n";
    } else {
        cout << "❌ Pedido cancelado por el usuario.\n";
    }
}
// Función para ver los pedidos
void verPedidos(bool soloPendientes, bool soloEntregados) {
    if (pedidos.empty()) {
        cout << "\nNo hay pedidos registrados.\n";
        return;
    }

    cout << "\n=== LISTA DE PEDIDOS ===\n";
    int index = 0;
    for (const auto& p : pedidos) {
        if ((soloPendientes && p.entregado) || (soloEntregados && !p.entregado)) continue;
        cout << "\nPedido #" << ++index << "\n";
        cout << "Cliente: " << p.cliente << "\n";
        cout << "Producto: " << p.producto << " x" << p.cantidad << "\n";
        cout << "Total: $" << fixed << setprecision(2) << (p.precio * p.cantidad) << "\n"; // Calcular total de productos agregados al carrito
        cout << "Fecha entrega: " << p.fechaEntrega << "\n";
        cout << "Detalles: " << (p.detalles.empty() ? "Ninguno" : p.detalles) << "\n";
        cout << "Estado: " << (p.entregado ? "✅ Entregado" : "🕒 Pendiente") << "\n";
    }
    if (index == 0)
        cout << "No hay pedidos con ese estado.\n";
}
// Función para buscar un pedido por cliente o producto
void buscarPedido() {
    string criterio;
    cout << "\nBuscar pedido por nombre de cliente o producto: ";
    getline(cin, criterio);
    bool encontrado = false;

    for (const auto& p : pedidos) {
        if (p.cliente == criterio || p.producto == criterio) {
            encontrado = true;
            cout << "\nCliente: " << p.cliente << ", Producto: " << p.producto 
                << ", Fecha entrega: " << p.fechaEntrega 
                << ", Estado: " << (p.entregado ? "Entregado" : "Pendiente") << "\n";
        }
    }

    if (!encontrado)
        cout << "❌ Pedido no encontrado.\n";
}
// Función para editar un pedido
void editarPedido() {
    verPedidos();
    int i;
    cout << "\nIngrese número de pedido a editar: ";
    cin >> i;
    cin.ignore();

    if (i < 1 || i > pedidos.size()) {
        cout << "❌ Pedido inválido.\n";
        return;
    }

    Pedido& p = pedidos[i - 1];

    cout << "Editar cantidad actual (" << p.cantidad << "): ";
    int nuevaCantidad;
    cin >> nuevaCantidad;
    cin.ignore();
    if (nuevaCantidad < 50) {
        cout << "❌ Cantidad inválida.\n";
    } else {
        p.cantidad = nuevaCantidad;
    }

    cout << "Editar fecha entrega actual (" << p.fechaEntrega << "): ";
    string nuevaFecha;
    getline(cin, nuevaFecha);
    if (validarFecha(nuevaFecha)) {
        p.fechaEntrega = nuevaFecha;
        cout << "✅ Fecha actualizada.\n";
    } else {
        cout << "❌ Fecha inválida. No se actualizó.\n";
    }
}
// Función para eliminar un pedido
void eliminarPedido() {
    verPedidos();
    int i;
    cout << "\nIngrese número de pedido a eliminar: ";
    cin >> i;
    cin.ignore();
    if (i < 1 || i > pedidos.size()) {
        cout << "❌ Pedido inválido.\n";
        return;
    }
    pedidos.erase(pedidos.begin() + i - 1);
    cout << "✅ Pedido eliminado.\n";
}
// Función para marcar un pedido como entregado o deshacer entrega
void marcarEntregado(bool deshacer) {
    verPedidos();
    int i;
    cout << "\nIngrese número de pedido: ";
    cin >> i;
    cin.ignore();
    if (i < 1 || i > pedidos.size()) {
        cout << "❌ Pedido inválido.\n";
        return;
    }

    Pedido& p = pedidos[i - 1];
    if (deshacer) {
        p.entregado = false;
        cout << "🔁 Pedido marcado como pendiente nuevamente.\n";
    } else {
        p.entregado = true;
        cout << "✅ Pedido marcado como entregado.\n";
    }
}
// Función para mostrar el menú principal
void mostrarMenu() {
    cout << "\n=== PANADERÍA DULCE AMANECER ===\n";
    cout << "1. Nuevo pedido\n";
    cout << "2. Ver todos los pedidos\n";
    cout << "3. Ver solo entregados\n";
    cout << "4. Ver solo pendientes\n";
    cout << "5. Marcar como entregado\n";
    cout << "6. Deshacer entrega\n";
    cout << "7. Editar pedido\n";
    cout << "8. Eliminar pedido\n";
    cout << "9. Buscar pedido\n";
    cout << "0. Salir\n";
    cout << "Seleccione: ";
}