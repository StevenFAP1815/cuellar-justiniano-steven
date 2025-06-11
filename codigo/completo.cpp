#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <limits>
#include <ctime>
#include <algorithm>

using namespace std;

// Definición de la estructura Pedido
struct Pedido {
    string producto;
    int cantidad;
    double precio;
    string cliente;
    string fechaEntrega;
    string detalles;
    bool entregado;  // Solo usamos este campo para el estado
};

vector<Pedido> pedidos;

// Mapa de productos con sus precios
map<string, double> productos = {
    {"Pan francés", 1.20},
    {"Croissant", 2.50},
    {"Empanada de carne", 2.00},
    {"Torta de chocolate", 15.00},
    {"Docena de medialunas", 12.00}
};

bool validarFecha(const string& fecha) {
    return fecha.size() == 10 && fecha[2] == '/' && fecha[5] == '/';
}
// Función para inicializar productos
void mostrarProductos() {
    cout << "\nPRODUCTOS DISPONIBLES:\n";
    int i = 1;
    for (auto& p : productos)
        cout << i++ << ". " << p.first << " - $" << fixed << setprecision(2) << p.second << endl;
}
// Función para mostrar los productos disponibles
void nuevoPedido() {
    Pedido pedido;
    string nombre, detalles, fechaEntrega;
    int opcion, cantidad;

    cout << "\n=== NUEVO PEDIDO ===\n";
    cout << "Nombre del cliente: ";
    getline(cin, nombre);
    if (nombre.empty()) {
        cout << "Nombre vacío. Pedido cancelado.\n";
        return;
    }

    mostrarProductos();
    cout << "Seleccione producto (0 para cancelar): ";
    cin >> opcion;
    cin.ignore(); // Limpiar el buffer de entrada
    if (opcion == 0) {
        cout << "✅ Pedido cancelado por el usuario.\n";
        return;
    }
    if (opcion < 1 || opcion > productos.size()) {
        cout << "Opción inválida. Pedido cancelado.\n";
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
        cout << "Cantidad inválida. Pedido cancelado.\n";
        return;
    }

    cout << "Fecha de entrega (dd/mm/yyyy): ";
    getline(cin, fechaEntrega);
    if (!validarFecha(fechaEntrega)) {
        cout << "Formato de fecha inválido. Pedido cancelado.\n";
        return;
    }

    cout << "Detalles (máx. 100 caracteres): ";
    getline(cin, detalles);
    if (detalles.length() > 100) {
        cout << "Los detalles exceden 100 caracteres. Pedido cancelado.\n";
        return;
    }

    pedido.cliente = nombre;
    pedido.cantidad = cantidad;
    pedido.fechaEntrega = fechaEntrega;
    pedido.detalles = detalles;
    pedido.entregado = false;  // Por defecto no está entregado

    // Confirmación final
    cout << "\n🔎 Confirmar pedido:\n";
    cout << "Cliente: " << pedido.cliente << "\n";
    cout << "Producto: " << pedido.producto << " x" << pedido.cantidad << "\n";
    cout << "Total: $" << fixed << setprecision(2) << pedido.precio * pedido.cantidad << "\n"; // Mostrar el total de productos agregados al carrito
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
        cout << "Pedido cancelado por el usuario.\n";
    }
}
// Función para ver los pedidos
void verPedidos(bool soloPendientes = false, bool soloEntregados = false) {
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
        cout << "Total: $" << fixed << setprecision(2) << (p.precio * p.cantidad) << "\n"; // Mostrar el total de productos agregados al carrito
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
        cout << "Pedido no encontrado.\n";
}
// Función para editar un pedido
void editarPedido() {
    verPedidos();
    int i;
    cout << "\nIngrese número de pedido a editar: ";
    cin >> i;
    cin.ignore();

    if (i < 1 || i > pedidos.size()) {
        cout << "Pedido inválido.\n";
        return;
    }

    Pedido& p = pedidos[i - 1];

    cout << "Editar cantidad actual (" << p.cantidad << "): ";
    int nuevaCantidad;
    cin >> nuevaCantidad;
    cin.ignore();
    if (nuevaCantidad < 50) {
        cout << "Cantidad inválida.\n";
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
        cout << "Fecha inválida. No se actualizó.\n";
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
        cout << "Pedido inválido.\n";
        return;
    }
    pedidos.erase(pedidos.begin() + i - 1);
    cout << "✅ Pedido eliminado.\n";
}
// Función para marcar un pedido como entregado o deshacer la entrega
void marcarEntregado(bool deshacer = false) {
    verPedidos();
    int i;
    cout << "\nIngrese número de pedido: ";
    cin >> i;
    cin.ignore();
    if (i < 1 || i > pedidos.size()) {
        cout << "Pedido inválido.\n";
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

int main() {
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1: nuevoPedido(); break;
            case 2: verPedidos(); break;
            case 3: verPedidos(false, true); break;
            case 4: verPedidos(true, false); break;
            case 5: marcarEntregado(); break;
            case 6: marcarEntregado(true); break;
            case 7: editarPedido(); break;
            case 8: eliminarPedido(); break;
            case 9: buscarPedido(); break;
            case 0: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
    return 0;
}