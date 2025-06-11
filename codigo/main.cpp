#include "pedidos.h"
#include <iostream>

using namespace std;

int main() {
    inicializarProductos();
    int opcion;
    do {
        // Mostrar el menú principal
        mostrarMenu();
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1: nuevoPedido(); break;
            case 2: verPedidos(); break;
            case 3: verPedidos(false, true); break;
            case 4: verPedidos(true, false); break;
            case 5: marcarEntregado(false); break;
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